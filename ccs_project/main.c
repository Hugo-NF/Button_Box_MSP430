#include <msp430.h> 

#include "msp_ports.h"

void setup();
void loop();

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	setup();                    // Configuracoes, (realizado somente na inicializacao da placa)

	while(1) loop();                     // Loop principal
}

void setup(){

}

void loop(){

}
