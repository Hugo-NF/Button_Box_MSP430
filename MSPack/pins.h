/*
 * buttons.h
 *
 *  Created on: 22 de abr de 2018
 *      Author: JoséLuiz
 */

#ifndef PINS_H_
#define PINS_H_

#include <msp430.h>
#include <stdint.h>

//-------MACROS PARA MANIPULAÇÂO DE REGISTRO------
#define SET_REG(reg, bit)      (reg |= bit)
#define CLEAR_REG(reg, bit)    (reg &= ~(bit))
#define TOOGLE_REGR(reg, bit)   (reg ^= bit)
#define READ_REG(reg, bit)     (reg & bit)


//------------VALUE OUTPUT----------
#define HIGH    1
#define LOW     0

//-------------MOD PORTS-----------
#define OUTPUT          0
#define INPUT           1
#define INPUT_PULL_UP   2
#define INPUT_PULL_DOWN 3

//------------INTERUPT MODS--------
#define LOW_TO_HIGH 0
#define HIGH_TO_LOW 1

//---------------PORTS------------------
#define P1  0
#define P2  1
#define P3  2
#define P4  3
#define P5  4
#define P6  5
#define P7  6
#define P8  7

//-------------PINS----------------
#define NOT_PIN -1
#define P1_0    0
#define P1_1    1
#define P1_2    2
#define P1_3    3
#define P1_4    4
#define P1_5    5
#define P1_6    6
#define P1_7    7
#define P2_0    8
#define P2_1    9
#define P2_2    10
#define P2_3    11
#define P2_4    12
#define P2_5    13
#define P2_6    14
#define P2_7    15
#define P3_0    16
#define P3_1    17
#define P3_2    18
#define P3_3    19
#define P3_4    20
#define P3_5    21
#define P3_6    22
#define P3_7    23
#define P4_0    24
#define P4_1    25
#define P4_2    26
#define P4_3    27
#define P4_4    28
#define P4_5    29
#define P4_6    30
#define P4_7    31
#define P5_0    32
#define P5_1    33
#define P5_2    34
#define P5_3    35
#define P5_4    36
#define P5_5    37
#define P5_6    38
#define P5_7    39
#define P6_0    40
#define P6_1    41
#define P6_2    42
#define P6_3    43
#define P6_4    44
#define P6_5    45
#define P6_6    46
#define P6_7    47
#define P7_0    48
#define P7_1    49
#define P7_2    50
#define P7_3    51
#define P7_4    52
#define P7_5    53
#define P7_6    54
#define P7_7    55
#define P8_0    56
#define P8_1    57
#define P8_2    58

//-----------ANALOG PIN---------------
#define A0 ADC12INCH_0
#define A1 ADC12INCH_1
#define A2 ADC12INCH_2
#define A3 ADC12INCH_3
#define A4 ADC12INCH_4
#define A5 ADC12INCH_5
#define A6 ADC12INCH_6
#define A7  ADC12INCH_7
#define A8  ADC12INCH_8
#define A9  ADC12INCH_9
#define A10 ADC12INCH_10    // Sensor Temperatura
#define A11 ADC12INCH_11
#define A12 ADC12INCH_12
#define A13 ADC12INCH_13
#define A14 ADC12INCH_14
#define A15 ADC12INCH_15


#ifndef PORT_MAPS

const uint16_t port_to_dir[]={
    (uint16_t) &P1DIR,
    (uint16_t) &P2DIR,
    (uint16_t) &P3DIR,
    (uint16_t) &P4DIR,
    (uint16_t) &P5DIR,
    (uint16_t) &P6DIR,
    (uint16_t) &P7DIR,
    (uint16_t) &P8DIR
};

const uint16_t port_to_in[]={
    (uint16_t) &P1IN,
    (uint16_t) &P2IN,
    (uint16_t) &P3IN,
    (uint16_t) &P4IN,
    (uint16_t) &P5IN,
    (uint16_t) &P6IN,
    (uint16_t) &P7IN,
    (uint16_t) &P8IN
};

const uint16_t port_to_out[]={
    (uint16_t) &P1OUT,
    (uint16_t) &P2OUT,
    (uint16_t) &P3OUT,
    (uint16_t) &P4OUT,
    (uint16_t) &P5OUT,
    (uint16_t) &P6OUT,
    (uint16_t) &P7OUT,
    (uint16_t) &P8OUT
};

const uint16_t port_to_ren[]={
    (uint16_t) &P1REN,
    (uint16_t) &P2REN,
    (uint16_t) &P3REN,
    (uint16_t) &P4REN,
    (uint16_t) &P5REN,
    (uint16_t) &P6REN,
    (uint16_t) &P7REN,
    (uint16_t) &P8REN
};

const uint16_t port_to_sel[]={
    (uint16_t) &P1SEL,
    (uint16_t) &P2SEL,
    (uint16_t) &P3SEL,
    (uint16_t) &P4SEL,
    (uint16_t) &P5SEL,
    (uint16_t) &P6SEL,
    (uint16_t) &P7SEL,
    (uint16_t) &P8SEL
};

const uint16_t port_to_ies[]={
    (uint16_t) &P1IES,
    (uint16_t) &P2IES
};

const uint16_t port_to_ie[]={
    (uint16_t) &P1IE,
    (uint16_t) &P2IE
};

const uint16_t port_to_ifg[]={
    (uint16_t) &P1IFG,
    (uint16_t) &P2IFG
};

const uint16_t inch_to_pin[]={
    (uint16_t) P6_0,        // A0
    (uint16_t) P6_1,        // A1
    (uint16_t) P6_2,        // A2
    (uint16_t) P6_3,        // A3
    (uint16_t) P6_4,        // A4
    (uint16_t) P6_5,        // A5
    (uint16_t) P6_6,        // A6
    (uint16_t) P6_7,        // A7
    (uint16_t) P5_0,        // A8
    (uint16_t) P5_1,        // A9
    (uint16_t) NOT_PIN,     // A10
    (uint16_t) NOT_PIN,     // A11
    (uint16_t) P7_0,        // A12
    (uint16_t) P7_1,        // A13
    (uint16_t) P7_2,        // A14
    (uint16_t) P7_3         // A15

};

#endif //PORT_MAPS

#endif /* PINS_H_ */
