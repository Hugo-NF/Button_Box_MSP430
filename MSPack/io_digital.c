/*
 * io_digital.c
 *
 *  Created on: 17 de jun de 2018
 *      Author: JoséLuiz
 */

#include "io.h"
#include "pins.h"


//----------FUNCOES DE MANIPULACAO DE GPIO DIGITAL----------
void setPin(unsigned char pin, unsigned char mode){
    uint8_t bit = Mask(pin);
    uint8_t port = Port(pin);

    volatile uint8_t *dir = portToDir(port);
    volatile uint8_t *ren = portToRen(port);
    volatile uint8_t *out = portToOut(port);
    volatile uint8_t *sel = portToSel(port);

    *sel &= ~(bit);

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

void writePin(unsigned char pin, unsigned char value){
    uint8_t bit = Mask(pin);
    uint8_t port = Port(pin);

    volatile uint8_t *out = portToOut(port);

    if(!value) *out &= ~(bit);
    else       *out |= bit;
}

void tooglePin(unsigned char pin){
    uint8_t bit = Mask(pin);
    uint8_t port = Port(pin);

    volatile uint8_t *out = portToOut(port);

    *out ^= bit;
}

unsigned char readPin(unsigned char pin){
    uint8_t bit = Mask(pin);
    uint8_t port = Port(pin);

    volatile uint8_t *in = portToIn(port);

    return *in & bit;
}

void setInterrupt(unsigned char pin, unsigned char mode){
    uint8_t bit = Mask(pin);
    uint8_t port = Port(pin);

    if(port > 2) return;

    volatile uint8_t *ies = portToIes(port);
    volatile uint8_t *ie = portToIe(port);

    if(mode == LOW_TO_HIGH){
        *ies |= bit;
    }else{
        *ies &= ~(bit);
    }

    *ie |= bit;
}

void disableInterrput(unsigned char pin){
    uint8_t bit = Mask(pin);
    uint8_t port = Port(pin);

    if(port > 2) return;

    volatile uint8_t *ie = portToIe(port);

    *ie &= ~(bit);
}
