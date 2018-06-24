#ifndef GLOBAL_CONFIG_BUTTONS_H_
#define GLOBAL_CONFIG_BUTTONS_H_

#include <string.h>
#include "MSPack/MSPack.h"
#include "USB_app/keyboard.h"

#define LED_BLINK_TIME 100
#define DEBOUNCE_TIME 30

//#define PULL_DOWN_LOGIC
#define PULL_UP_LOGIC

#define LED_ACTIVE_PIN      P1_0
#define LED_SEND_PIN        P4_7

unsigned char buttons_addr[12]={
    P2_3,   /* B_4 */ //(SB_1)
    P1_1, //Botão de teste
//    P8_1,   /* B_6 */
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
            /* B_13 */ //(SA_2)
            /* B_14 */ //(SB_2)
};

unsigned char buttons_old[14], buttons_new[14];

unsigned char buttons_command_buf_1[14][128]={
   "1 ",
   "2 ",
   "3 ",
   "4 ",
   "5 ",
   "6 ",
   "7 ",
   "8 ",
   "9 ",
   "10 ",
   "11 ",
   "12 ",
   "13 ",
   "14 "
};


#endif /* GLOBAL_CONFIG_BUTTONS_H_ */
