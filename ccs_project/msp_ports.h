#include <msp430.h>

/*
 * msp_ports.h
 *
 *  Created on: 20 de abr de 2018
 *      Author: JoséLuiz
 */

#ifndef MSP_PORTS_H_
#define MSP_PORTS_H_

//----------------VALORES DE SAIDA----------------
#define HIGH            |=                  // Auxilia macro de saida para 1
#define LOW             &= ~                // auxilia macro de saida para 0

//------------SETS DAS PORTAS---------------------
#define SET_OUTPUT(port,pin)              (port##DIR |= pin)                                              // Seta pino como saida
#define SET_INPUT(port,pin)               (port##DIR &= ~(pin))                                           // Seta pino como entrada
#define SET_INPUT_PULL_UP(port, pin)      SET_INPUT(port, pin); (port##REN |= pin); (port##OUT |= pin)    // Seta pin = input + pull-up
#define SET_INPUT_PULL_DOWN(port, pin)    SET_INPUT(port, pin); (port##REN |= pin); (port##OUT &= ~(pin)) // Seta pin = input + pull-down

//-------MACRO DE MANIPULACAO DAS GPIOs-----------
// mode = (OUTPUT; INPUT; INPUT_PULL_UP; INPUT_PULL_DOWN)
#define SET_PIN(port,pin,mode)      SET_##mode(port,pin)    // Seta o pino com o modo escolhido
#define WRITE_PIN(port,pin,value)   (port##OUT value pin)   // Escreve a saida no pino no valor (High ou low)
#define READ_PIN(port,pin)          (port##IN & pin)        // Le o valor no registro de saida do pino
#define TOOGLE_PIN(port,pin)        (port##OUT ^= pin)      // Alterna valor do pino escolhido


//-------MACROS PARA MANIPULAÇÂO DE REGISTRO------
#define SET_REGISTER(reg, bit)      reg |= bit
#define CLEAR_REGISTER(reg, bit)    reg &= ~(bit)
#define TOOGLE_REGISTER(reg, bit)   reg ^= bit


#endif /* MSP_PORTS_H_ */
