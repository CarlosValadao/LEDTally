#include "rgb.h"
#include "hardware/pwm.h"

static uint16_t calculate_led_intensity_value(uint8_t intensity)
{
    intensity = (intensity == 0) ? 1 : intensity;
    uint16_t MAX_LED_INTENSITY = 0xFF00;
    return (uint16_t) ((MAX_LED_INTENSITY*intensity)/100u);
}

void rgb_init(const rgbpins *pins)
{
    uint slice_r, slice_g, slice_b;
    gpio_set_function(pins->red, GPIO_FUNC_PWM);
    gpio_set_function(pins->green, GPIO_FUNC_PWM);
    gpio_set_function(pins->blue, GPIO_FUNC_PWM);

    slice_r = pwm_gpio_to_slice_num(pins->red);
    slice_g = pwm_gpio_to_slice_num(pins->green);
    slice_b = pwm_gpio_to_slice_num(pins->blue);

    pwm_config config = pwm_get_default_config();
    pwm_config_set_clkdiv(&config, 4.f);
    pwm_init(slice_r, &config, true);
    pwm_init(slice_g, &config, true);
    pwm_init(slice_b, &config, true);
}

void rgb_turn_on_red(const rgbpins *pins, uint8_t intensity)
{
    //Ligar o LED vermelho
    uint16_t led_intensity = calculate_led_intensity_value(intensity);
    pwm_set_gpio_level(pins->red, led_intensity);
}

void rgb_turn_off_red(const rgbpins *pins)
{
    //Desligar o LED vermelho
    pwm_set_gpio_level(pins->red, 0);
}

void rgb_turn_on_green(const rgbpins *pins, uint8_t intensity)
{
     //Ligar o LED Verde
    uint16_t led_intensity = calculate_led_intensity_value(intensity);
    pwm_set_gpio_level(pins->green, 1);
}

void rgb_turn_off_green(const rgbpins *pins)
{
     //Desligar o LED Verde
    pwm_set_gpio_level(pins->green, 0);
}

void rgb_turn_on_blue(const rgbpins *pins, uint8_t intensity)
{
     //Ligar o LED azul
    uint16_t led_intensity = calculate_led_intensity_value(intensity);
    gpio_put(pins->blue, 1);
}

void rgb_turn_off_blue(const rgbpins *pins)
{
    //Desligar o LED Azul
    pwm_set_gpio_level(pins->blue, 0);
}

void rgb_turn_on_white(const rgbpins *pins, uint8_t intensity) {
    uint16_t led_intensity = calculate_led_intensity_value(intensity/3u);
    pwm_set_gpio_level(pins->red, led_intensity);
    pwm_set_gpio_level(pins->green, led_intensity);
    pwm_set_gpio_level(pins->blue, led_intensity);
}

void rgb_turn_off_white(const rgbpins *pins) {
    pwm_set_gpio_level(pins->red, 0);
    pwm_set_gpio_level(pins->green, 0);
    pwm_set_gpio_level(pins->blue, 0);
}
