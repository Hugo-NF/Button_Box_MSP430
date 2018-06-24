/*
 * io.h
 *
 *  Created on: 17 de jun de 2018
 *      Author: JoséLuiz
 */

#ifndef IO_H_
#define IO_H_

#include <stdint.h>

extern const uint16_t port_to_dir[];
extern const uint16_t port_to_in[];
extern const uint16_t port_to_out[];
extern const uint16_t port_to_ren[];
extern const uint16_t port_to_sel[];
extern const uint16_t port_to_ies[];
extern const uint16_t port_to_ie[];
extern const uint16_t port_to_ifg[];
extern const uint16_t inch_to_pin[];

//-----------CONVERTE ARRAY DE ENDEREÇOS-----------
#define Port(Pin)    (Pin >> 3)
#define Mask(Pin)    (1 << (Pin & 7))
#define portToDir(P) ((volatile uint8_t *) (port_to_dir[P]))
#define portToIn(P) ((volatile uint8_t *) (port_to_in[P]))
#define portToOut(P) ((volatile uint8_t *) (port_to_out[P]))
#define portToRen(P) ((volatile uint8_t *) (port_to_ren[P]))
#define portToSel(P) ((volatile uint8_t *) (port_to_sel[P]))
#define portToIes(P) ((volatile uint8_t *) (port_to_ies[P]))
#define portToIe(P) ((volatile uint8_t *) (port_to_ie[P]))
#define portToIfg(P) ((volatile uint8_t *) (port_to_ifg[P]))
#define inchToPin(A) inch_to_pin[A]


//-----------------FUNCOES IO--------------------
void setPin(unsigned char pin, unsigned char mode);
void writePin(unsigned char pin, unsigned char value);
void tooglePin(unsigned char pin);
unsigned char readPin(unsigned char pin);
void setInterrupt(unsigned char pin, unsigned char mode);
void disableInterrput(unsigned char pin);


//-----------------FUNCOES IO ANALOG---------------
int analogReadPin(unsigned char Apin);              // Retornar valor do pin de acordo com o setup do ADC12 (8 bits/ 10 bits/ 12 bits)
int analogReadTemp();                               // Retornar o valor da temperatura do sensor interno (já convertido)
void setupADC_single_mode(unsigned char Apin);      // Inicializa o ADC12 para 1 leitura de 1 canal

#include "pins.h"

#endif /* IO_H_ */
