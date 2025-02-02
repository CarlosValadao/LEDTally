#include "push_button.h"
#include "pico/stdlib.h"

volatile bool FIRST_IRQ_USE = true;
volatile gpio_irq_callback_t PB_IRQ_CALLBACK = NULL;

void pb_config(uint8_t button_pin, bool pullup)
{
    gpio_init(button_pin);
    if(pullup) gpio_pull_up(button_pin);
}

void pb_set_irq_callback(gpio_irq_callback_t callback) { PB_IRQ_CALLBACK = callback; }

void pb_enable_irq(uint button_pin)
{
    if(FIRST_IRQ_USE) gpio_set_irq_enabled_with_callback(button_pin, GPIO_IRQ_EDGE_FALL, true, PB_IRQ_CALLBACK);
    else gpio_set_irq_enabled(button_pin, GPIO_IRQ_EDGE_FALL, true);    
}