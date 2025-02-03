#include "inc/ws2812b.h"
#include "inc/rgb.h"
#include "pico/stdlib.h"
#include "inc/push_button.h"
#include "hardware/clocks.h"
#include <stdio.h>
#include "pico/bootrom.h"

// Definição do pino do botão do joystick
#define JOYSTICK_SW 22

// Definição do tempo de debounce para os botões
#define DELAY_MS 200

// Macro para entrar no modo de boot USB
#define set_bootsel_mode() reset_usb_boot(0, 0)

// Índice atual do glifo exibido
static volatile int8_t glyph_index = 0;
// Última vez que um evento foi tratado (para debounce)
static volatile uint32_t last_time = 0;

// Definição de cores para os LEDs WS2812B
const uint8_t COLORS[] = {YELLOW, GREEN, BLUE, YELLOW, PURPLE, WHITE, BLUE_MARINE, RED, BLUE_MARINE, PURPLE};
// Intensidade do LED para cada índice de glifo
const uint8_t LED_INTENSITY[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

// Função que verifica se um valor está dentro do intervalo válido (1 a 9)
static bool is_whitin_range(volatile int8_t value) { return (value > 0 && value < 10 ? true : false); }

// Função que ajusta o índice do glifo caso ele saia dos limites (ciclo entre 0 e 9)
static void set_bounds(volatile int8_t *value) { *value = (*value < 0) ? 9 : 0; }

// Manipulador de interrupção para os botões
void gpio_irq_handler(uint gpio, uint32_t event)
{
    uint32_t current_time = to_ms_since_boot(get_absolute_time()); // Obtém o tempo atual em milissegundos
    if(current_time - last_time >= DELAY_MS) // Verifica o tempo desde a última interrupção (debounce)
    {
        if(gpio == JOYSTICK_SW) set_bootsel_mode(); // Se for o botão do joystick, entra no modo de boot USB
        
        // Atualiza o índice do glifo com base no botão pressionado
        glyph_index = (gpio == BUTTON_A ? glyph_index + 1 : glyph_index - 1);
        
        // Verifica se o índice está dentro do intervalo permitido, senão ajusta os limites
        if(!is_whitin_range(glyph_index)) set_bounds(&glyph_index);
        
        // Atualiza o display dos LEDs WS2812B
        ws2812b_draw_b(NUMERIC_GLYPHS[glyph_index], COLORS[glyph_index], LED_INTENSITY[glyph_index]);
        
        last_time = current_time; // Atualiza o tempo da última interrupção
    }
}

int main()
{
    // Configuração dos pinos RGB
    rgbpins rgb = {.red = 13, .green = 12, .blue = 11};
    PIO pio = pio0;
    ws2812b_t *ws;

    // Configura o clock do sistema para 128 MHz
    set_sys_clock_khz(128000, false);

    // Inicializa os LEDs WS2812B e o módulo RGB
    ws = init_ws2812b_default(pio0);
    rgb_init(&rgb);
    
    // Configuração dos botões
    pb_config_btn_a();
    pb_config_btn_b();
    pb_config(JOYSTICK_SW, true);

    // Associa a função de interrupção aos botões
    pb_set_irq_callback(&gpio_irq_handler);
    pb_enable_irq(BUTTON_A_PIN);
    pb_enable_irq(BUTTON_B_PIN);
    pb_enable_irq(JOYSTICK_SW);

    // Inicializa a comunicação serial padrão
    stdio_init_all();
    
    // Desliga todos os LEDs WS2812B antes de iniciar
    ws2812b_turn_off_all(ws);
    sleep_ms(50);
    
    // Exibe o primeiro glifo com cor roxa e intensidade mínima
    ws2812b_draw_b(NUMERIC_GLYPHS[glyph_index], PURPLE, 1);
    
    uint8_t k;
    while(true)
    {
        k = 5;
        while(k--)
        {
            // Pisca o LED vermelho 5 vezes com a intensidade correspondente ao índice do glifo
            rgb_turn_on_red(&rgb, LED_INTENSITY[glyph_index]);
            sleep_ms(100);
            rgb_turn_off_red(&rgb);
            sleep_ms(100);
        }
    }
    return 0;
}
