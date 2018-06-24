#include "usb_send.h"

/*********** Application specific globals **********************/
volatile uint8_t keySendComplete = TRUE;

void setup_usb_send(){
    // Minumum Vcore setting required for the USB API is PMM_CORE_LEVEL_2 .
    PMM_setVCore(PMM_CORE_LEVEL_2);

    Keyboard_init();       // Init keyboard report
    USB_setup(TRUE, TRUE); // Init USB & events; if a host is present, connect

    __enable_interrupt();  // Enable global interrupts


}

void send_string(uint8_t* buff){

    uint8_t i;
    uint8_t buttonStringLength = strlen((const char *)buff);

    switch(USB_getConnectionState()){

    // This case is executed while your device is enumerated on the
    // USB host
    case ST_ENUM_ACTIVE:
        for (i=0; i<buttonStringLength; i++) {

            Keyboard_press(buff[i]);
            while(!keySendComplete);
            keySendComplete = FALSE;

            Keyboard_release(buff[i]);
            while(!keySendComplete);
            keySendComplete = FALSE;
        }

        break;
    // These cases are executed while your device is disconnected from
    // the host (meaning, not enumerated); enumerated but suspended
    // by the host, or connected to a powered hub without a USB host
    // present.
    case ST_PHYS_DISCONNECTED:
    case ST_ENUM_SUSPENDED:
    case ST_PHYS_CONNECTED_NOENUM_SUSP:
        _NOP();
        break;

    // The default is executed for the momentary state
    // ST_ENUM_IN_PROGRESS.  Usually, this state only last a few
    // seconds.  Be sure not to enter LPM3 in this state; USB
    // communication is taking place here, and therefore the mode must
    // be LPM0 or active-CPU.
    case ST_ENUM_IN_PROGRESS:
    default:;
    }
}


/*
 * ======== UNMI_ISR ========
 */
#if defined(__TI_COMPILER_VERSION__) || (__IAR_SYSTEMS_ICC__)
#pragma vector = UNMI_VECTOR
__interrupt void UNMI_ISR (void)
#elif defined(__GNUC__) && (__MSP430__)
void __attribute__ ((interrupt(UNMI_VECTOR))) UNMI_ISR (void)
#else
#error Compiler not found!
#endif
{
    switch (__even_in_range(SYSUNIV, SYSUNIV_BUSIFG))
    {
        case SYSUNIV_NONE:
            __no_operation();
            break;
        case SYSUNIV_NMIIFG:
            __no_operation();
            break;
        case SYSUNIV_OFIFG:
             UCS_clearFaultFlag(UCS_XT2OFFG);
            UCS_clearFaultFlag(UCS_DCOFFG);
            SFR_clearInterrupt(SFR_OSCILLATOR_FAULT_INTERRUPT);
            break;
        case SYSUNIV_ACCVIFG:
            __no_operation();
            break;
        case SYSUNIV_BUSIFG:
            // If the CPU accesses USB memory while the USB module is
            // suspended, a "bus error" can occur.  This generates an NMI.  If
            // USB is automatically disconnecting in your software, set a
            // breakpoint here and see if execution hits it.  See the
            // Programmer's Guide for more information.
            SYSBERRIV = 0; //clear bus error flag
            USB_disable(); //Disable
    }
}
