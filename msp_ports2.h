#include <msp430.h>

/*
 * msp_ports.h
 *
 *  Created on: 20 de abr de 2018
 *      Author: JoséLuiz
 */

#ifndef MSP_PORTS_H_
#define MSP_PORTS_H_

#define B1      P2,BIT3
#define B2      P8,BIT1
#define B3      P2,BIT5
#define B4      P2,BIT4
#define B5      P1,BIT5
#define B6      P1,BIT4
#define B7      P1,BIT3
#define B8      P1,BIT2
#define SA1     P4,BIT3
#define SA2     P4,BIT0
#define SB1     P3,BIT7
#define SB2     P8,BIT2
#define LED_ON_OFF  P1,BIT0
//#define LED_IN_OUT

//-------MACROS PARA MANIPULAÇÂO DE REGISTRO------
#define SET_REGISTER(reg, bit)      (reg |= bit)
#define CLEAR_REGISTER(reg, bit)    (reg &= ~(bit))
#define TOOGLE_REGISTER(reg, bit)   (reg ^= bit)
#define READ_REGISTER(reg, bit)     (reg & bit)

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

//------------------DEBOUNCE---------------------
inline void debounce(unsigned short int t_mili){
    //Seta timer: Clock = ACLK dividido por 9, modo de subida.
    TA1CTL = (TASSEL__ACLK | MC__UP | ID__8);

    //Divide o valor do clock por 4
    TA1EX0 = TAIDEX_4;

    //Seta modo de saida para SET
    TA1CCTL0 = OUTMOD_1;

    //Limiar da contagem
    TA1CCR0 = t_mili;

    // Reseta o timer A1 e inicia a contagem
    SET_REGISTER(TA1CTL, TACLR);

    // Enquanto o tempo for menor aguarda o delay
    while(!READ_REGISTER(TA1CCTL0,CCIFG));
}

#endif /* MSP_PORTS_H_ */
