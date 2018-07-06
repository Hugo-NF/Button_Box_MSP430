#ifndef CDC_MESSAGES_H_
#define CDC_MESSAGES_H_

#include "usb_send.h"

#define OP_CONFIG                   "0"
#define OP_TOGGLE_SWITCH_MODE       "1"
#define OP_TOGGLE_LED_FAST          "2"
#define OP_TOGGLE_LED_SLOW          "3"
#define OP_CONFIG_BUTTONS           "4"
#define OP_EXIT                     "0"
#define NONE                        ""

inline print_home_menu(){
    send_CDC("\n\r**********MENU**********\n");
    send_CDC("(0) Config\n\n");
}

inline print_config_menu(){
    send_CDC("\n\r******CONFIG MENU*******\n");
    send_CDC("(1) Toggle Switch Mode\n");
    send_CDC("(2) Toggle LED Fast\n");
    send_CDC("(3) Toggle LED slow\n");
    send_CDC("(4) Config Buttons\n");
    send_CDC("(0) EXIT\n\n");
}

inline print_invalid_command(){
    send_CDC("\rNo such command!\n");
}

#endif /* CDC_MESSAGES_H_ */
