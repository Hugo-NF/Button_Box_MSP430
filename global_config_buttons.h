#ifndef GLOBAL_CONFIG_BUTTONS_H_
#define GLOBAL_CONFIG_BUTTONS_H_

#include <string.h>
#include "MSPack/MSPack.h"
#include "USB_app/keyboard.h"


#define PRESS_RELEASE   0
#define HOLD            1

#define SWITCH_MODE_DEFAULT     1
#define SWITCH_MODE_BUTTON      0

unsigned char switch_mode = SWITCH_MODE_DEFAULT;

/*
 *  MACROS PARA CONFIGURACAO DOS BOTOES
 */
#define LED_BLINK_TIME 100                  // Tempo para blink do led
#define DEBOUNCE_TIME 30                    // Tempo de debounce do botão

#define PULL_DOWN_LOGIC                   // Logica para botões de pull down
//#define PULL_UP_LOGIC                       // Logica para botões de pull up

#define LED_ACTIVE_PIN      P2_0            // Pino do LED de ativo
#define LED_SEND_PIN        P2_2            // Pino do LED de comunicação

//#define COMPOSE_KEY_COMMAND                 // Definir tecla para composição. EX: CTRL + command

const unsigned char buttons_addr[12]={
    P1_4,   /* B_1 */
    P1_5,   /* B_2 */ //(SWA_1)
    P2_4,   /* B_3 */ //(SWA_3)
    P6_6,   /* B_4 */ //(SWB_1)
    P6_2,   /* B_5 */ //(SWB_3)
    P8_1,   /* B_6 */
    P1_3,   /* B_7 */
    P1_2,   /* B_8 */
    P4_3,   /* B_9 */
    P4_0,   /* B_10 */
    P3_7,   /* B_11 */
    P8_2,   /* B_12 */
            /* B_13 */ //(SWA_2)
            /* B_14 */ //(SWB_2)
};

unsigned char buttons_old[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0}, buttons_new[14];

const unsigned char buttons_compose_command_buf[128] ={
   KEY_LEFT_SHIFT
   //Para adicionar mais composições
};

const unsigned char buttons_command_buf_1[14][128]={
   "0", /* B_1 */
   "1", /* SWA_1 */
   "2", /* SWA_3 */
   "3", /* SWB_1 */
   "4", /* SWB_3 */
   "5", /* B_6 */
   "6", /* B_7 */
   "7", /* B_8 */
   "8", /* B_9 */
   "9", /* B_10 */
   "+", /* B_11 */
   "=", /* B_12 */
   ",", /* SWA_2 */
   "." /* SWB_2 */
};

unsigned char buttons_press_release[14]={
   PRESS_RELEASE,   /* B_1 */
   HOLD,   /* B_2 */ //(SWA_1)
   HOLD,   /* B_3 */ //(SWA_3)
   HOLD,   /* B_4 */ //(SWB_1)
   HOLD,   /* B_5 */ //(SWB_3)
   PRESS_RELEASE,   /* B_6 */
   PRESS_RELEASE,   /* B_7 */
   PRESS_RELEASE,   /* B_8 */
   PRESS_RELEASE,   /* B_9 */
   PRESS_RELEASE,   /* B_10 */
   PRESS_RELEASE,   /* B_11 */
   PRESS_RELEASE,   /* B_12 */
   PRESS_RELEASE,   /* B_13 */ //(SWA_2)
   PRESS_RELEASE    /* B_14 */ //(SWB_2)
};


/*
 * FUNCOES PARA DEFINICAO EM RUN TIME DO BOTOES
 */
inline void toggle_switch_mode(){
    switch_mode = !switch_mode;

    if(switch_mode){
        buttons_press_release[2] = HOLD;
        buttons_press_release[3] = HOLD;
        buttons_press_release[4] = HOLD;
        buttons_press_release[5] = HOLD;
    }else{
        buttons_press_release[2] = PRESS_RELEASE;
        buttons_press_release[3] = PRESS_RELEASE;
        buttons_press_release[4] = PRESS_RELEASE;
        buttons_press_release[5] = PRESS_RELEASE;
    }
}


#endif /* GLOBAL_CONFIG_BUTTONS_H_ */
