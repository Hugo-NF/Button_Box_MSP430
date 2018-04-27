/*
 * buttons.h
 *
 *  Created on: 22 de abr de 2018
 *      Author: Jos�Luiz
 */

#ifndef PINS_H_
#define PINS_H_

#include <stdint.h>

//-------MACROS PARA MANIPULA��O DE REGISTRO------
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


//-----------------BIT MASK----------------------
//IMPLEMENTA��O ALTERNATIVA = MACRO -> pintToBitMask(x) 1 << (x & 7)
const uint8_t pin_to_bit_mask[] = {
    BIT0,   /*0, P1*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*8, P2*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*16, P3*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*24, P4*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*32, P5*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*40, P6*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*48, P7*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*56, P8*/
    BIT1,
    BIT2
};

const uint8_t pin_to_port[] = {
    P1,     /*0 , P1*/
    P1,
    P1,
    P1,
    P1,
    P1,
    P1,
    P2,     /*8, P2*/
    P2,
    P2,
    P2,
    P2,
    P2,
    P2,
    P3,     /*16, P3*/
    P3,
    P3,
    P3,
    P3,
    P3,
    P3,
    P4,     /*24, P4*/
    P4,
    P4,
    P4,
    P4,
    P4,
    P4,
    P5,     /*32, P5*/
    P5,
    P5,
    P5,
    P5,
    P5,
    P5,
    P6,     /*40, P6*/
    P6,
    P6,
    P6,
    P6,
    P6,
    P6,
    P7,     /*48, P7*/
    P7,
    P7,
    P7,
    P7,
    P7,
    P7,
    P8,     /*56, P8*/
    P8,
    P8,
};


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


//-----------CONVERTE ARRAY DE ENDERE�OS-----------
#define Port(Pin)    (pin_to_port[Pin])
#define Mask(Pin) (pin_to_bit_mask[Pin])
#define portToDir(P) ((volatile uint8_t *) (port_to_dir[P]))
#define portToIn(P) ((volatile uint8_t *) (port_to_in[P]))
#define portToOut(P) ((volatile uint8_t *) (port_to_out[P]))
#define portToRen(P) ((volatile uint8_t *) (port_to_ren[P]))


//----------FUNCOES DE MANIPULACAO DE GPIO----------
inline void setPin(unsigned char pin, unsigned char mode){
    uint8_t bit = Mask(pin);
    uint8_t port = Port(pin);

    volatile uint8_t *dir = portToDir(port);
    volatile uint8_t *ren = portToRen(port);
    volatile uint8_t *out = portToOut(port);

    switch(mode){
        case 0:
            *dir |= bit;
            break;
        case 1:
            *dir &= ~(bit);
            break;
        case 2:
            *dir &= ~(bit);
            *ren |= bit;
            *out |= bit;
            break;
        case 3:
            *dir &= ~(bit);
            *ren |= bit;
            *out |= bit;
            break;
        default:
            break;
    }
}

inline void writePin(unsigned char pin, unsigned char value){
    uint8_t bit = Mask(pin);
    uint8_t port = Port(pin);

    volatile uint8_t *out = portToOut(port);

    if(!value) *out &= ~(bit);
    else       *out |= bit;
}

inline void tooglePin(unsigned char pin){
    uint8_t bit = Mask(pin);
    uint8_t port = Port(pin);

    volatile uint8_t *out = portToOut(port);

    *out ^= bit;
}

inline unsigned char readPin(unsigned char pin){
    uint8_t bit = Mask(pin);
    uint8_t port = Port(pin);

    volatile uint8_t *in = portToIn(port);

    return *in & bit;
}

#endif /* PINS_H_ */
