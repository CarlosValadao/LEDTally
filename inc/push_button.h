#ifndef PUSH_BUTTON_C
#define PUSH_BUTTON_C

#include <stdint.h>
#include "pico/stdlib.h"

#define BUTTON_A_PIN 5
#define BUTTON_B_PIN 6
#define BUTTON_A 5
#define BUTTON_B 6

#define pb_config_btn_a() pb_config(BUTTON_A_PIN, true)
#define pb_config_btn_b() pb_config(BUTTON_B_PIN, true)

/**
 * @file push_button.c
 * @brief Este arquivo contém funções e definições que permitem
 *          operar e gerenciar push buttons, configurando os 
 *          botões conectados ao GPIO e manipulando-os com interrupção
 * 
 * @author Carlos Valadao
 * @date 31/01/2025
 *  
 * */

extern volatile bool FIRST_IRQ_USE;
extern volatile gpio_irq_callback_t PB_IRQ_CALLBACK;

void pb_config(uint8_t button_pin, bool pullup);
void pb_set_irq_callback(gpio_irq_callback_t callback);
void pb_debounce(uint8_t button_pin, uint8_t debounce_time);
void pb_enable_irq(uint button_pin);

#endif //PUSH_BUTTON_H
