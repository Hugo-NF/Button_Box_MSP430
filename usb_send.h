#ifndef USB_SEND_H_
#define USB_SEND_H_

#include <string.h>

#include "driverlib.h"

#include "USB_config/descriptors.h"
#include "USB_API/USB_Common/device.h"
#include "USB_API/USB_Common/usb.h"                  // USB-specific functions
#include "USB_API/USB_HID_API/UsbHid.h"

#include "USB_app/keyboard.h"

void setup_usb_send();
void send_string(uint8_t* buff);


#endif /* USB_SEND_H_ */
