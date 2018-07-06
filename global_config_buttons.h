#ifndef GLOBAL_CONFIG_BUTTONS_H_
#define GLOBAL_CONFIG_BUTTONS_H_

#include <string.h>
#include "MSPack/MSPack.h"
#include "USB_app/keyboard.h"


#define PRESS_RELEASE   0
#define HOLD            1

#define SWITCH_MODE_DEFAULT     1
#define SWITCH_MODE_BUTTON      0

static unsigned char switch_mode = SWITCH_MODE_DEFAULT;

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

/*
 * VARIAVEIS GLOBAIS DE CONFIGURAÇÃO (global_config_buttons.c)
 */
extern const unsigned char buttons_addr[12];
extern unsigned char buttons_old[14], buttons_new[14], buttons_compose[14];
extern unsigned char buttons_compose_command_buf[14][6];
extern unsigned char buttons_command_buf[14][12];
extern unsigned char buttons_press_release[14];


/*
 * FUNCOES PARA DEFINICAO EM RUN TIME DO BOTOES
 */
void toggle_switch_mode();
void set_button_compose(uint8_t n_button, uint8_t set_reset, unsigned char* commands);
void set_button_command(uint8_t n_button, unsigned char* commands);
void append_button_command(uint8_t n_button, unsigned char* commands);
void get_button_command(uint8_t n_button, char* ret_command);
void get_command(unsigned char command);


#endif /* GLOBAL_CONFIG_BUTTONS_H_ */
