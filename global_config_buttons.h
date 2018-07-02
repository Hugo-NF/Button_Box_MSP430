#ifndef GLOBAL_CONFIG_BUTTONS_H_
#define GLOBAL_CONFIG_BUTTONS_H_

#include <string.h>
#include "MSPack/MSPack.h"
#include "USB_app/keyboard.h"

#define LED_BLINK_TIME 100                  // Tempo para blink do led
#define DEBOUNCE_TIME 30                    // Tempo de debounce do botão

#define PULL_DOWN_LOGIC                   // Logica para botões de pull down
//#define PULL_UP_LOGIC                       // Logica para botões de pull up

#define LED_ACTIVE_PIN      P2_0            // Pino do LED de ativo
#define LED_SEND_PIN        P2_2            // Pino do LED de comunicação

//#define COMPOSE_KEY_COMMAND                 // Definir tecla para composição. EX: CTRL + command

unsigned char buttons_addr[12]={
    P1_4,   /* B_1 */
    P1_5,   /* B_2 */ //(SWA_1)
    P2_4,   /* B_3 */ //(SWA_3)
    P6_6,   /* B_4 */ //(SWB_1)
    P6_2,   /* B_5 */ //(SWB_3)
    P8_1,   /* B_6 */
    P1_3,   /* B_7 */
    P3_1,   /* B_8 */
    P3_0,   /* B_9 */
    P4_0,   /* B_10 */
    P3_7,   /* B_11 */
    P8_2,   /* B_12 */
            /* B_13 */ //(SWA_2)
            /* B_14 */ //(SWB_2)
};

unsigned char buttons_old[14], buttons_new[14];

unsigned char buttons_compose_command_buf[128] ={
   KEY_LEFT_SHIFT
   //Para adicionar mais composições
};

unsigned char buttons_command_buf_1[14][128]={
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


#endif /* GLOBAL_CONFIG_BUTTONS_H_ */
