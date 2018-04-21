#include <msp430.h> 

#include "msp_ports.h"

void setup();
void loop();

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// para watchdog timer
	
	setup();                    // Configuracoes, (realizado somente na inicializacao da placa)

	while(1){
	    loop();                     // Loop principal
	}
}

void setup(){
                                // Configura porta P2.1 (Switch 1)
    SET_PIN(P2,BIT1,INPUT_PULL_UP);

                                // Configura porta P4.7 (LED verde)
    SET_PIN(P4,BIT7,OUTPUT);
    WRITE_PIN(P4,BIT7,LOW);
}


void loop(){
    if(READ_PIN(P2,BIT1) != 0){     // Se P2.1 != 0 -> true (aberto)
       WRITE_PIN(P4,BIT7,LOW);        // Desativa P4.7
    }else{                      // Se P2.1 == 0 -> false (fechado)
       WRITE_PIN(P4,BIT7,HIGH);           // Ativa P4.7
    }
}
