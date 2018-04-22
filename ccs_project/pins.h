/*
 * buttons.h
 *
 *  Created on: 22 de abr de 2018
 *      Author: JoséLuiz
 */

#ifndef PINS_H_
#define PINS_H_

#include <msp430.h>


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
const unsigned char pin_to_bit_mask[] = {
    BIT0,   /*0, &P1*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*8, &P2*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*16, &P3*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*24, &P4*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*32, &P5*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*40, &P6*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*48, &P7*/
    BIT1,
    BIT2,
    BIT3,
    BIT4,
    BIT5,
    BIT6,
    BIT7,
    BIT0,   /*56, &P8*/
    BIT1,
    BIT2
};

volatile unsigned char* pin_to_dir_port[] = {
    &P1DIR,   /*0, &P1DIR*/
    &P1DIR,
    &P1DIR,
    &P1DIR,
    &P1DIR,
    &P1DIR,
    &P1DIR,
    &P1DIR,
    &P2DIR,   /*8, &P2DIR*/
    &P2DIR,
    &P2DIR,
    &P2DIR,
    &P2DIR,
    &P2DIR,
    &P2DIR,
    &P2DIR,
    &P3DIR,   /*16, &P3DIR*/
    &P3DIR,
    &P3DIR,
    &P3DIR,
    &P3DIR,
    &P3DIR,
    &P3DIR,
    &P3DIR,
    &P4DIR,   /*24, &P4DIR*/
    &P4DIR,
    &P4DIR,
    &P4DIR,
    &P4DIR,
    &P4DIR,
    &P4DIR,
    &P4DIR,
    &P5DIR,   /*32, &P5DIR*/
    &P5DIR,
    &P5DIR,
    &P5DIR,
    &P5DIR,
    &P5DIR,
    &P5DIR,
    &P5DIR,
    &P6DIR,   /*40, &P6DIR*/
    &P6DIR,
    &P6DIR,
    &P6DIR,
    &P6DIR,
    &P6DIR,
    &P6DIR,
    &P6DIR,
    &P7DIR,   /*48, &P7DIR*/
    &P7DIR,
    &P7DIR,
    &P7DIR,
    &P7DIR,
    &P7DIR,
    &P7DIR,
    &P7DIR,
    &P8DIR,   /*56, &P8DIR*/
    &P8DIR,
    &P8DIR

};

//-----------------IN PORTS--------------------
volatile const unsigned char* pin_to_in_port[] = {
    &P1IN,   /*0, &P1IN*/
    &P1IN,
    &P1IN,
    &P1IN,
    &P1IN,
    &P1IN,
    &P1IN,
    &P1IN,
    &P2IN,   /*8, &P2IN*/
    &P2IN,
    &P2IN,
    &P2IN,
    &P2IN,
    &P2IN,
    &P2IN,
    &P2IN,
    &P3IN,   /*16, &P3IN*/
    &P3IN,
    &P3IN,
    &P3IN,
    &P3IN,
    &P3IN,
    &P3IN,
    &P3IN,
    &P4IN,   /*24, &P4IN*/
    &P4IN,
    &P4IN,
    &P4IN,
    &P4IN,
    &P4IN,
    &P4IN,
    &P4IN,
    &P5IN,   /*32, &P5IN*/
    &P5IN,
    &P5IN,
    &P5IN,
    &P5IN,
    &P5IN,
    &P5IN,
    &P5IN,
    &P6IN,   /*40, &P6IN*/
    &P6IN,
    &P6IN,
    &P6IN,
    &P6IN,
    &P6IN,
    &P6IN,
    &P6IN,
    &P7IN,   /*48, &P7IN*/
    &P7IN,
    &P7IN,
    &P7IN,
    &P7IN,
    &P7IN,
    &P7IN,
    &P7IN,
    &P8IN,   /*56, &P8IN*/
    &P8IN,
    &P8IN
};

//-----------------OUT PORTS--------------------
volatile unsigned char* pin_to_out_port[] = {
    &P1OUT,   /*0, &P1OUT*/
    &P1OUT,
    &P1OUT,
    &P1OUT,
    &P1OUT,
    &P1OUT,
    &P1OUT,
    &P1OUT,
    &P2OUT,   /*8, &P2OUT*/
    &P2OUT,
    &P2OUT,
    &P2OUT,
    &P2OUT,
    &P2OUT,
    &P2OUT,
    &P2OUT,
    &P3OUT,   /*16, &P3OUT*/
    &P3OUT,
    &P3OUT,
    &P3OUT,
    &P3OUT,
    &P3OUT,
    &P3OUT,
    &P3OUT,
    &P4OUT,   /*24, &P4OUT*/
    &P4OUT,
    &P4OUT,
    &P4OUT,
    &P4OUT,
    &P4OUT,
    &P4OUT,
    &P4OUT,
    &P5OUT,   /*32, &P5OUT*/
    &P5OUT,
    &P5OUT,
    &P5OUT,
    &P5OUT,
    &P5OUT,
    &P5OUT,
    &P5OUT,
    &P6OUT,   /*40, &P6OUT*/
    &P6OUT,
    &P6OUT,
    &P6OUT,
    &P6OUT,
    &P6OUT,
    &P6OUT,
    &P6OUT,
    &P7OUT,   /*48, &P7OUT*/
    &P7OUT,
    &P7OUT,
    &P7OUT,
    &P7OUT,
    &P7OUT,
    &P7OUT,
    &P7OUT,
    &P8OUT,   /*56, &P8OUT*/
    &P8OUT,
    &P8OUT
};

//-----------------REN PORTS--------------------
volatile unsigned char* pin_to_ren_port[] = {
    &P1REN,   /*0, &P1REN*/
    &P1REN,
    &P1REN,
    &P1REN,
    &P1REN,
    &P1REN,
    &P1REN,
    &P1REN,
    &P2REN,   /*8, &P2REN*/
    &P2REN,
    &P2REN,
    &P2REN,
    &P2REN,
    &P2REN,
    &P2REN,
    &P2REN,
    &P3REN,   /*16, &P3REN*/
    &P3REN,
    &P3REN,
    &P3REN,
    &P3REN,
    &P3REN,
    &P3REN,
    &P3REN,
    &P4REN,   /*24, &P4REN*/
    &P4REN,
    &P4REN,
    &P4REN,
    &P4REN,
    &P4REN,
    &P4REN,
    &P4REN,
    &P5REN,   /*32, &P5REN*/
    &P5REN,
    &P5REN,
    &P5REN,
    &P5REN,
    &P5REN,
    &P5REN,
    &P5REN,
    &P6REN,   /*40, &P6REN*/
    &P6REN,
    &P6REN,
    &P6REN,
    &P6REN,
    &P6REN,
    &P6REN,
    &P6REN,
    &P7REN,   /*48, &P7REN*/
    &P7REN,
    &P7REN,
    &P7REN,
    &P7REN,
    &P7REN,
    &P7REN,
    &P7REN,
    &P8REN,   /*56, &P8REN*/
    &P8REN,
    &P8REN
};


//-----------CONVERTE ARRAY DE ENDEREÇOS-----------
#define pinToBitMask(P) *(pin_to_bit_mask + P)
#define pinToDirPort(P) **(pin_to_dir_port + P)
#define pinToInPort(P) **(pin_to_in_port + P)
#define pinToOutPort(P) **(pin_to_out_port + P)
#define pinToRenPort(P) **(pin_to_ren_port + P)


//----------FUNCOES DE MANIPULACAO DE GPIO----------
inline void setPin(unsigned char pin, unsigned char mode){
    switch(mode){
        case 0:
            pinToDirPort(pin) |= pinToBitMask(pin);
            break;
        case 1:
            pinToDirPort(pin) &= ~(pinToBitMask(pin));
            break;
        case 2:
            pinToDirPort(pin) &= ~(pinToBitMask(pin));
            pinToRenPort(pin) |= pinToBitMask(pin);
            pinToOutPort(pin) |= pinToBitMask(pin);
            break;
        case 3:
            pinToDirPort(pin) &= ~(pinToBitMask(pin));
            pinToRenPort(pin) |= pinToBitMask(pin);
            pinToOutPort(pin) &= ~(pinToBitMask(pin));
            break;
        default:
            break;
    }
}

inline void writePin(unsigned char pin, unsigned char value){
    if(!value) pinToOutPort(pin) &= ~(pinToBitMask(pin));
    else      pinToOutPort(pin) |= pinToBitMask(pin);
}

inline void tooglePin(unsigned char pin){
    pinToOutPort(pin) ^= pinToBitMask(pin);
}

inline unsigned char readPin(unsigned char pin){
    return pinToInPort(pin) & pinToBitMask(pin);
}

#endif /* PINS_H_ */
