#ifndef RGB_H
#define RGB_H

#define RED         0             /**< Define a cor vermelha para os LEDs */
#define GREEN       1             /**< Define a cor verde para os LEDs */
#define BLUE        2             /**< Define a cor azul para os LEDs */
#define YELLOW      3             /**< Define a cor amarela para os LEDs */
#define PURPLE      4             /**< Define a cor roxa para os LEDs */
#define WHITE       5             /**< Define a cor branca para os LEDs */
#define BLUE_MARINE 6             /**< Define a cor azul-marinho para os LEDs */

#include "pico/stdlib.h"

/** 
 * @file rgb.h
 * @brief Este arquivo contém declarações de funções e definições relacionadas a um
 *        LED RGB conectado aos pinos GPIO
 *
 * @author Carlos Valadao
 * @date 17/01/2025
 */


typedef struct
{
    uint red;
    uint green;
    uint blue;
} rgbpins;


void rgb_init(const rgbpins *pins);
void rgb_turn_on_red(const rgbpins *pins, uint8_t intensity);
void rgb_turn_off_red(const rgbpins *pins);
void rgb_turn_on_green(const rgbpins *pins, uint8_t intensity);
void rgb_turn_off_green(const rgbpins *pins);
void rgb_turn_on_blue(const rgbpins *pins, uint8_t intensity);
void rgb_turn_off_blue(const rgbpins *pins);
void rgb_turn_on_white(const rgbpins *pins, uint8_t intensity);
void rgb_turn_off_white(const rgbpins *pins);

#endif