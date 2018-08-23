#include "global_config_buttons.h"
#include "memory.h"

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

unsigned char buttons_compose[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char buttons_old[14] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned char buttons_new[14];

unsigned char buttons_compose_command_buf[14][6] ={
   {KEY_LEFT_SHIFT},
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   "",
   ""
};

unsigned char buttons_command_buf[14][12]={
   "0", /* B_1 */
   {KEY_UP_ARROW}, /* SWA_1 */
   {KEY_DOWN_ARROW}, /* SWA_3 */
   {KEY_LEFT_ARROW}, /* SWB_1 */
   {KEY_RIGHT_ARROW}, /* SWB_3 */
   "5", /* B_6 */
   "6", /* B_7 */
   "7", /* B_8 */
   "8", /* B_9 */
   "9", /* B_10 */
   "+", /* B_11 */
   "=", /* B_12 */
   "", /* SWA_2 */
   "" /* SWB_2 */
};

unsigned char buttons_press_release[14]={
   HOLD,   /* B_1 */
   HOLD,   /* B_2 */ //(SWA_1)
   HOLD,   /* B_3 */ //(SWA_3)
   HOLD,   /* B_4 */ //(SWB_1)
   HOLD,   /* B_5 */ //(SWB_3)
   HOLD,   /* B_6 */
   HOLD,   /* B_7 */
   HOLD,   /* B_8 */
   HOLD,   /* B_9 */
   HOLD,   /* B_10 */
   HOLD,   /* B_11 */
   HOLD,   /* B_12 */
   HOLD,   /* B_13 */ //(SWA_2)
   HOLD    /* B_14 */ //(SWB_2)
};


/*
 * ============FUNCOES DE CONFIGURACAO RUN TIME=============
 */

char command_returned_converted[20] = "";

uint8_t check_pressed_button(){

}

void toggle_switch_mode(){
    switch_mode = !switch_mode;

    if(switch_mode){
        /*save_string(HOLD, &buttons_press_release[1]);
        save_string(HOLD, &buttons_press_release[2]);
        save_string(HOLD, &buttons_press_release[3]);
        save_string(HOLD, &buttons_press_release[4]);
        */buttons_press_release[1] = HOLD;
        buttons_press_release[2] = HOLD;
        buttons_press_release[3] = HOLD;
        buttons_press_release[4] = HOLD;
    }else{
        /*save_string(PRESS_RELEASE, &buttons_press_release[1]);
        save_string(PRESS_RELEASE, &buttons_press_release[2]);
        save_string(PRESS_RELEASE, &buttons_press_release[3]);
        save_string(PRESS_RELEASE, &buttons_press_release[4]);
        */buttons_press_release[1] = PRESS_RELEASE;
        buttons_press_release[2] = PRESS_RELEASE;
        buttons_press_release[3] = PRESS_RELEASE;
        buttons_press_release[4] = PRESS_RELEASE;
    }
}

void set_button_compose(uint8_t n_button, uint8_t set_reset, unsigned char* commands){
    if(set_reset){
        buttons_compose[n_button] = 1;
        strcpy((char*) buttons_compose_command_buf[n_button], (char*)commands);
    }else{
        buttons_compose[n_button] = 0;
    }
}

void set_button_command(uint8_t n_button, unsigned char* commands){
    strcpy((char*) buttons_command_buf[n_button], (char*) commands);
}

void append_button_command(uint8_t n_button, unsigned char* commands){
    strcat((char*) commands, (char*) buttons_compose_command_buf[n_button]);
}

void get_button_commands(uint8_t n_button, char* ret_command){
    char* ret = "";
    int i = 6;

    if(buttons_compose[n_button]){
        while(i--){
            get_command(buttons_compose_command_buf[n_button][i]);
            strcat(command_returned_converted, ret);
            strcat("+", ret);
        }
    }

    i=12;

    while(i--){
        get_command(buttons_command_buf[n_button][i]);
        strcat(command_returned_converted, ret);
    }

    strcpy(ret_command, ret);
}

void get_command(unsigned char command){
    switch(command){
    case KEY_LEFT_CTRL:
        strcpy(command_returned_converted, "+Left_CTRL");
        break;
    case KEY_LEFT_SHIFT:
        strcpy(command_returned_converted, "+Left_SHIFT");
        break;
    case KEY_LEFT_ALT:
        strcpy(command_returned_converted, "+Left_ALT");
        break;
    case KEY_LEFT_GUI:
        strcpy(command_returned_converted, "+Left_GUI");
        break;
    case KEY_RIGHT_CTRL:
        strcpy(command_returned_converted, "+Right_CTRL");
        break;
    case KEY_RIGHT_SHIFT:
        strcpy(command_returned_converted, "+Right_SHIFT");
        break;
    case KEY_RIGHT_ALT:
        strcpy(command_returned_converted, "+Right_ALT");
        break;
    case KEY_RIGHT_GUI:
        strcpy(command_returned_converted, "+Right_GUI");
        break;
    case KEY_UP_ARROW:
        strcpy(command_returned_converted, "+Up_Arrow");
        break;
    case KEY_DOWN_ARROW:
        strcpy(command_returned_converted, "+Down_Arrow");
        break;
    case KEY_LEFT_ARROW:
        strcpy(command_returned_converted, "+Left_Arrow");
        break;
    case KEY_RIGHT_ARROW:
        strcpy(command_returned_converted, "+Right_Arrow");
        break;
    case KEY_BACKSPACE:
        strcpy(command_returned_converted, "+Backspace");
        break;
    case KEY_TAB:
        strcpy(command_returned_converted, "+Tab");
        break;
    case KEY_RETURN:
        strcpy(command_returned_converted, "+Return");
        break;
    case KEY_ESC:
        strcpy(command_returned_converted, "+ESC");
        break;
    case KEY_INSERT:
        strcpy(command_returned_converted, "+Insert");
        break;
    case KEY_DELETE:
        strcpy(command_returned_converted, "+Delete");
        break;
    case KEY_PAGE_UP:
        strcpy(command_returned_converted, "+Page_Up");
        break;
    case KEY_PAGE_DOWN:
        strcpy(command_returned_converted, "+Page_Down");
        break;
    case KEY_HOME:
        strcpy(command_returned_converted, "+Home");
        break;
    case KEY_END:
        strcpy(command_returned_converted, "+End");
        break;
    case KEY_CAPS_LOCK:
        strcpy(command_returned_converted, "+Caps_Lock");
        break;
    case KEY_F1:
        strcpy(command_returned_converted, "+F1");
        break;
    case KEY_F2:
        strcpy(command_returned_converted, "+F2");
        break;
    case KEY_F3:
        strcpy(command_returned_converted, "+F3");
        break;
    case KEY_F4:
        strcpy(command_returned_converted, "+F4");
        break;
    case KEY_F5:
        strcpy(command_returned_converted, "+F5");
        break;
    case KEY_F6:
        strcpy(command_returned_converted, "+F6");
        break;
    case KEY_F7:
        strcpy(command_returned_converted, "+F7");
        break;
    case KEY_F8:
        strcpy(command_returned_converted, "+F8");
        break;
    case KEY_F9:
        strcpy(command_returned_converted, "+F9");
        break;
    case KEY_F10:
        strcpy(command_returned_converted, "+F10");
        break;
    case KEY_F11:
        strcpy(command_returned_converted, "+F11");
        break;
    case KEY_F12:
        strcpy(command_returned_converted, "+F12");
        break;
    default:
        strcpy(command_returned_converted, (char*)command);
        break;
    }
}

