//Variaveis globais para configuração dos botoes
#include "global_config_buttons.h"

#include <msp430.h> 
#include <stdbool.h>

#include "usb_send.h"
#include "MSPack/MSPack.h"

/*
 * =========== VARIAVEIS GLOBAIS ===============
 * */
extern volatile uint8_t is_Setting;

void setup();
void loop();

void handlerButton(unsigned char n_button);
void sendCommandButton(unsigned char n_button);

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// para watchdog timer
	
	setup();                    // Configuracoes, (realizado somente na inicializacao da placa)

	//setPin(P1_1, INPUT_PULL_UP);

	while(1){
	    loop();                 // Loop principal
	}
}

void setup(){

    setup_usb_send();

    // Configura porta (LED vermelho) - SINAL DE LIGADO
    setPin(LED_ACTIVE_PIN,OUTPUT);
    writePin(LED_ACTIVE_PIN, HIGH);

    // Configura porta (LED verde) - SINAL p/ BOTOES
    setPin(LED_SEND_PIN, OUTPUT);
    writePin(LED_SEND_PIN, HIGH);

    unsigned char i=12;
    while(i--){
#if defined PULL_DOWN_LOGIC
        setPin(buttons_addr[i], INPUT_PULL_DOWN);
#elif defined PULL_UP_LOGIC
        setPin(buttons_addr[i], INPUT_PULL_UP);
#endif
    }
    writePin(LED_ACTIVE_PIN, LOW);           // Ativa led de ligado
}

void loop(){

    if(is_Setting){
        handlerSettingCDC();
    }else{
        checkConfigCDC();
    }

    // Leitura das entradas dos pinos
    unsigned char i=12;
    while(i--){
#if defined PULL_DOWN_LOGIC
        buttons_new[i] = readPin(buttons_addr[i]);
#elif defined PULL_UP_LOGIC
        buttons_new[i] = !readPin(buttons_addr[i]);
#endif
    }

    // Inferencia do switch no estado de desligado
    buttons_new[12] = !buttons_new[1] && !buttons_new[2];  // SWA_1 = 0 e SWA_3=0 -> SWA_2=1
    buttons_new[13] = !buttons_new[3] && !buttons_new[4];  // SWB_1 = 0 e SWB_3=0 -> SWB_2=1

    // Lida com os sinais sinais dos botoes
    i=14;
    while(i--){
       handlerButton(i);
    }

}

void handlerButton(unsigned char n_button){
    if(buttons_new[n_button] && buttons_press_release[n_button] == HOLD){
        sendCommandButton(n_button);

        if(buttons_old[n_button] != buttons_new[n_button]){
            buttons_old[n_button] = buttons_new[n_button];

            writePin(LED_SEND_PIN, LOW);
            delay(LED_BLINK_TIME);
            writePin(LED_SEND_PIN, HIGH);

            delay(100);
        }

    }else if(buttons_old[n_button] != buttons_new[n_button]){

        buttons_old[n_button] = buttons_new[n_button];

        if(buttons_new[n_button]){
            writePin(LED_SEND_PIN, LOW);

            sendCommandButton(n_button);

            delay(LED_BLINK_TIME);
            writePin(LED_SEND_PIN, HIGH);
        }else{
            delay(DEBOUNCE_TIME); //debounce
        }
    }
}

void sendCommandButton(unsigned char n_button){

    if(buttons_compose[n_button]){
        start_compose_command(buttons_compose_command_buf[n_button]);
    }

    send_string((uint8_t*) buttons_command_buf[n_button]);

    if(buttons_compose[n_button]){
        finish_compose_command(buttons_compose_command_buf[n_button]);
    }
}
