#ifndef USB_SEND_H_
#define USB_SEND_H_

#include <string.h>

#include "driverlib.h"

#include "USB_config/descriptors.h"
#include "USB_API/USB_Common/device.h"
#include "USB_API/USB_Common/usb.h"                  // USB-specific functions
#include "USB_API/USB_HID_API/UsbHid.h"
#include "USB_API/USB_CDC_API/UsbCdc.h"

#include "USB_app/usbConstructs.h"
#include "USB_app/keyboard.h"

#include "MSPack/MSPack.h"
#include "MSPack/i2c.h"
#include "MSPack/lcd.h"

#define LED_PORT    GPIO_PORT_P2
#define LED_PIN     GPIO_PIN2

#define MAX_STR_LENGTH 64

void checkConfigCDC();
void handlerSettingCDC();
void receive_CDC();
void send_CDC(char* message_send);
void receive_send_CDC(char* message, uint8_t receive_send); // receive = 1   send = 0

uint8_t retInString (char* string);
void initTimer(void);
void setTimer_A_Parameters(void);
void initClocks(uint32_t mclkFreq);

void setup_usb_send();
void send(uint8_t* buff, uint8_t press, uint8_t release);
void send_string(uint8_t* buff);
void start_compose_command(uint8_t* buff);
void finish_compose_command(uint8_t* buff);


#endif /* USB_SEND_H_ */
