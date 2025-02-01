#include "inc/mlt8530.h"
#include "inc/ws2812b.h"
#include "inc/rgb.h"
#include "pico/stdlib.h"
#include "inc/push_button.h"
#include "hardware/clocks.h"
#include <stdio.h>
#include "pico/bootrom.h"

#define JOYSTICK_SW 22

#define set_bootsel_mode() reset_usb_boot(0, 0)

static volatile int8_t glyph_index = 0;
static volatile uint32_t last_time = 0;
const uint8_t COLORS[] = {YELLOW, GREEN, BLUE, YELLOW, PURPLE, WHITE, BLUE_MARINE, RED, BLUE_MARINE, PURPLE};

void efeito_bolha_explodindo() {
    buzzer_beep_default(5000, 10);
}
static bool is_whitin_range(volatile int8_t value) { return (value > 0 && value < 10 ? true : false); }

static void set_bounds(volatile int8_t *value) { *value = (*value < 0) ? 9 : 0; }

static void debounce()
{
    return; // TO DO
}

void gpio_irq_handler(uint gpio, uint32_t event)
{
    uint32_t current_time = to_ms_since_boot(get_absolute_time());
    if(current_time - last_time >= 200)
    {
        if(gpio == JOYSTICK_SW) set_bootsel_mode();
        glyph_index = (gpio == BUTTON_A ? glyph_index + 1 : glyph_index - 1);
        if(!is_whitin_range(glyph_index)) set_bounds(&glyph_index);
        ws2812b_draw_b(NUMERIC_GLYPHS[glyph_index], COLORS[glyph_index], 1);
        last_time = current_time;
    }
}

int main()
{
    rgbpins rgb = {.red = 13, .green = 12, .blue = 11};
    PIO pio = pio0;
    ws2812b_t *ws;
    
    set_sys_clock_khz(128000, false);

    ws = init_ws2812b_default(pio0);
    rgb_init(&rgb);
    buzzer_init_default();
    pb_config_btn_a();
    pb_config_btn_b();
    pb_config(JOYSTICK_SW, true);

    pb_set_irq_callback(&gpio_irq_handler);
    pb_enable_irq(BUTTON_A_PIN);
    pb_enable_irq(BUTTON_B_PIN);
    pb_enable_irq(JOYSTICK_SW);

    stdio_init_all();
    ws2812b_turn_off_all(ws);
    sleep_ms(50);
    ws2812b_draw_b(NUMERIC_GLYPHS[glyph_index], WHITE, 1);
    uint8_t k;
    while(true)
    {
        k = 5;
        while(k--)
        {
            rgb_turn_on_red(&rgb);
            sleep_ms(100);
            rgb_turn_off_red(&rgb);
            sleep_ms(100);
        }

    }
    return 0;
}