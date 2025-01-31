#include "pico/stdlib.h"
#include "inc/mlt8530.h"
#include "inc/ws2812b.h"
#include "hardware/clocks.h"

int main()
{
    PIO pio = pio0;
    ws2812b_t *ws;
    const uint8_t COLORS[] = {RED, GREEN, BLUE, YELLOW, PURPLE, BLUE_MARINE};

    ws = init_ws2812b_default(pio0);
    set_sys_clock_khz(128000, false);

    uint8_t k;
    while(true)
    {
        k = 10;
        while(k--)
        {
            ws2812b_draw(ws, NUMERIC_GLYPHS[k], YELLOW, 1);
            sleep_ms(500);
        }
    }
    return 0;
}