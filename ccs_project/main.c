#include <msp430.h> 
#include <stdbool.h>
#include "pins.h"
#include "msp_timers.h"

void setup();
void loop();

void handlerButton(unsigned char n_button, unsigned char tmp);

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// para watchdog timer
	
	setup();                    // Configuracoes, (realizado somente na inicializacao da placa)

	while(1){
	    loop();                 // Loop principal
	}
}

unsigned char buttons_addr[12]={
    P2_3,   /* B_4 */ //(SB_1)
    P8_1,   /* B_6 */
    P2_5,   /* B_5 */ //(SB_3)
    P2_4,   /* B_3 */ //(SA_3)
    P1_5,   /* B_2 */ //(SA_1)
    P1_4,   /* B_1 */
    P1_3,   /* B_7 */
    P1_2,   /* B_8 */
    P4_3,   /* B_9 */
    P4_0,   /* B_10 */
    P3_7,   /* B_11 */
    P8_2    /* B_12 */
            /* B_12 */ //(SA_2)
            /* B_14 */ //(SB_2)
};

unsigned char buttons_old[14], buttons_new[14];

void setup(){
    // Configura porta P1.0 (LED vermelho) - SINAL DE LIGADO
    setPin(P1_0,OUTPUT);
    writePin(P1_0, LOW);

    // Configura porta p4.7 (LED verde) - SINAL p/ BOTOES
    setPin(P4_7, OUTPUT);
    writePin(P4_7, LOW);

    unsigned char i=12;
    while(i--){
        setPin(buttons_addr[i], INPUT_PULL_DOWN);
    }
}

void loop(){
    writePin(P1_0, HIGH);           // Ativa led de ligado

    // Leitura das entradas dos pinos
    unsigned char i=12;
    while(i--){
        buttons_new[i] = readPin(buttons_addr[i]);
    }
    // Inferencia do switch no estado de desligado
    buttons_new[12] = !buttons_new[3] && !buttons_new[4];  // SA_1 = 0 e SA_3=0 -> SA_2=1
    buttons_new[13] = !buttons_new[0] && !buttons_new[2];  // SB_1 = 0 e SB_3=0 -> SB_2=1

    // Lida com os sinais sinais dos botoes
    i=14;
    while(i--){
        handlerButton(i,100);
    }

}

void handlerButton(unsigned char n_button, unsigned char tmp){
    if(buttons_old[n_button] != buttons_new[n_button]){
        if(buttons_new[n_button]){
            tooglePin(P4_7);
        }
        buttons_old[n_button] = buttons_new[n_button];
        debounce(tmp);
    }
}
