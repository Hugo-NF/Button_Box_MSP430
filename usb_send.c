#include "usb_send.h"

/*********** Application specific globals **********************/
volatile uint8_t keySendComplete = TRUE;
volatile uint8_t bHID_DataReceived_event = FALSE;
volatile uint8_t bCDC_DataReceived_event = FALSE; // Indicates data has been rx'ed
                                              // without an open rx operation
volatile uint8_t is_Setting = FALSE;


// Set/declare toggle delays
uint16_t SlowToggle_Period = 20000 - 1;
uint16_t FastToggle_Period = 1000 - 1;
Timer_A_initUpModeParam Timer_A_params = {0};
char wholeString[MAX_STR_LENGTH] = ""; // Entire input str from last 'return'


void setup_usb_send(){
    // Minumum Vcore setting required for the USB API is PMM_CORE_LEVEL_2 .
    PMM_setVCore(PMM_CORE_LEVEL_2);

    Keyboard_init();       // Init keyboard report
    USB_setup(TRUE, TRUE); // Init USB & events; if a host is present, connect
    initTimer();           // Prepare timer for LED toggling
    initClocks(25000000);   // Config clocks. MCLK=SMCLK=FLL=25MHz; ACLK=REFO=32kHz

    __enable_interrupt();  // Enable global interrupts


}

void send_string(uint8_t* buff){
    send(buff, 1, 1);
}

void start_compose_command(uint8_t* buff){
    send(buff, 1, 0);
}

void finish_compose_command(uint8_t* buff){
    send(buff, 0, 1);
}

void send(uint8_t* buff, uint8_t press, uint8_t release){
    uint8_t i;
    uint8_t buttonStringLength = strlen((const char *)buff);

    switch(USB_getConnectionState()){

    // This case is executed while your device is enumerated on the
    // USB host
    case ST_ENUM_ACTIVE:
        for (i=0; i<buttonStringLength; i++) {

            if(press){
                Keyboard_press(buff[i]);
                while(!keySendComplete);
                keySendComplete = FALSE;
            }

            if(release){
                Keyboard_release(buff[i]);
                while(!keySendComplete);
                keySendComplete = FALSE;
            }
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

void checkConfigCDC(){
    char* msg_received = "";

    msg_received = send_receiveCDC("",0);

    if(!strcmp(msg_received, "START")){
        send_receiveCDC("\nMODO DE CONFIGURACAO\n\n",1);
        writePin(P2_0, LOW);
    }

    if(!strcmp(msg_received, "EXIT")){
        writePin(P2_0, HIGH);
    }
}

void handlerSettingCDC(){

}

char* send_receiveCDC(char* msg, uint8_t send_receive){
    uint8_t i;
    char* ret = "";

    // Check the USB state and directly main loop accordingly
    switch (USB_getConnectionState())
    {
    // This case is executed while your device is enumerated on the
    // USB host
    case ST_ENUM_ACTIVE:

    // If true, some data is in the buffer; begin receiving a cmd
    if (bCDC_DataReceived_event){

        // Holds the new addition to the string
        char pieceOfString[MAX_STR_LENGTH] = "";

        // Holds the outgoing string
        char outString[MAX_STR_LENGTH];
        strcpy(outString, msg);


        // Add bytes in USB buffer to the string
                            USBCDC_receiveDataInBuffer((uint8_t*)pieceOfString,
                                MAX_STR_LENGTH,
                                CDC0_INTFNUM); // Get the next piece of the string

                            // Append new piece to the whole
                            strcat(wholeString,pieceOfString);

                            // Echo back the characters received
                            USBCDC_sendDataInBackground((uint8_t*)pieceOfString,
                                strlen(pieceOfString),CDC0_INTFNUM,0);

                            // Has the user pressed return yet?
                            if (retInString(wholeString)){

                                // Compare to string #1, and respond
                                if (!(strcmp(wholeString, "LED ON"))){

                                    // Turn off timer; no longer toggling LED
                                    Timer_A_stop(TIMER_A0_BASE);

                                    // Turn on LED P1.0
                                    GPIO_setOutputHighOnPin(LED_PORT, LED_PIN);

                                    // Prepare the outgoing string
                                    strcpy(outString,"\r\nLED is ON\r\n\r\n");

                                    // Send the response over USB
                                    USBCDC_sendDataInBackground((uint8_t*)outString,
                                        strlen(outString),CDC0_INTFNUM,0);

                                // Compare to string #2, and respond
                                } else if (!(strcmp(wholeString, "LED OFF"))){

                                    // Turn off timer; no longer toggling LED
                                    Timer_A_stop(TIMER_A0_BASE);

                                    // Turn off LED P1.0
                                    GPIO_setOutputLowOnPin(LED_PORT, LED_PIN);

                                    // Prepare the outgoing string
                                    strcpy(outString,"\r\nLED is OFF\r\n\r\n");

                                    // Send the response over USB
                                    USBCDC_sendDataInBackground((uint8_t*)outString,
                                        strlen(outString),CDC0_INTFNUM,0);

                                // Compare to string #3, and respond
                                } else if (!(strcmp(wholeString, "LED TOGGLE - SLOW"))){

                                    // Turn off timer while changing toggle period
                                    Timer_A_stop(TIMER_A0_BASE);

                                    // Set timer period for slow LED toggle
                                    Timer_A_params.timerPeriod = SlowToggle_Period;

                                    Timer_A_initUpMode(TIMER_A0_BASE, &Timer_A_params);

                                    // Start timer for toggling
                                    Timer_A_startCounter(TIMER_A0_BASE,
                                        TIMER_A_UP_MODE);

                                    // Prepare the outgoing string
                                    strcpy(outString,
                                        "\r\nLED is toggling slowly\r\n\r\n");

                                    // Send the response over USB
                                    USBCDC_sendDataInBackground((uint8_t*)outString,
                                        strlen(outString),CDC0_INTFNUM,0);

                                // Compare to string #4, and respond
                                } else if (!(strcmp(wholeString,"LED TOGGLE - FAST"))){

                                    // Turn off timer
                                    Timer_A_stop(TIMER_A0_BASE);

                                    // Set timer period for fast LED toggle
                                    Timer_A_params.timerPeriod = FastToggle_Period;

                                    Timer_A_initUpMode(TIMER_A0_BASE, &Timer_A_params);

                                    // Start timer for toggling
                                    Timer_A_startCounter(TIMER_A0_BASE,
                                        TIMER_A_UP_MODE);

                                    // Prepare the outgoing string
                                    strcpy(outString,
                                        "\r\nLED is toggling fast\r\n\r\n");

                                    // Send the response over USB
                                    USBCDC_sendDataInBackground((uint8_t*)outString,
                                        strlen(outString),CDC0_INTFNUM,0);

                                // Handle other
                                } else {

                                    // Prepare the outgoing string
                                    strcpy(outString,"\r\nNo such command!\r\n\r\n");

                                    // Send the response over USB
                                    USBCDC_sendDataInBackground((uint8_t*)outString,
                                        strlen(outString),CDC0_INTFNUM,0);
                                }

                                // Clear the string in preparation for the next one
                                for (i = 0; i < MAX_STR_LENGTH; i++){
                                    wholeString[i] = 0x00;
                                }
        }
    bCDC_DataReceived_event = FALSE;

    return ret;
    }
    break;

    // These cases are executed while your device is disconnected from
    // the host (meaning, not enumerated); enumerated but suspended
    // by the host, or connected to a powered hub without a USB host
    // present.
    case ST_PHYS_DISCONNECTED:
    case ST_ENUM_SUSPENDED:
    case ST_PHYS_CONNECTED_NOENUM_SUSP:
    break;

        // The default is executed for the momentary state
        // ST_ENUM_IN_PROGRESS.  Usually, this state only last a few
        // seconds.  Be sure not to enter LPM3 in this state; USB
        // communication is taking place here, and therefore the mode must
        // be LPM0 or active-CPU.
        case ST_ENUM_IN_PROGRESS:
        default:;
    }

    return "ERROR";
}

/*
 * ======== retInString ========
 */
// This function returns true if there's an 0x0D character in the string; and if
// so, it trims the 0x0D and anything that had followed it.
uint8_t retInString (char* string)
{
    uint8_t retPos = 0,i,len;
    char tempStr[MAX_STR_LENGTH] = "";

    strncpy(tempStr,string,strlen(string));  // Make a copy of the string
    len = strlen(tempStr);

    // Find 0x0D; if not found, retPos ends up at len
    while ((tempStr[retPos] != 0x0A) && (tempStr[retPos] != 0x0D) &&
           (retPos++ < len)) ;

    // If 0x0D was actually found...
    if ((retPos < len) && (tempStr[retPos] == 0x0D)){
        for (i = 0; i < MAX_STR_LENGTH; i++){ // Empty the buffer
            string[i] = 0x00;
        }

        //...trim the input string to just before 0x0D
        strncpy(string,tempStr,retPos);

        //...and tell the calling function that we did so
        return ( TRUE) ;

    // If 0x0D was actually found...
    } else if ((retPos < len) && (tempStr[retPos] == 0x0A)){
        // Empty the buffer
        for (i = 0; i < MAX_STR_LENGTH; i++){
            string[i] = 0x00;
        }

        //...trim the input string to just before 0x0D
        strncpy(string,tempStr,retPos);

        //...and tell the calling function that we did so
        return ( TRUE) ;
    } else if (tempStr[retPos] == 0x0D){
        for (i = 0; i < MAX_STR_LENGTH; i++){  // Empty the buffer
            string[i] = 0x00;
        }
        // ...trim the input string to just before 0x0D
        strncpy(string,tempStr,retPos);
        // ...and tell the calling function that we did so
        return ( TRUE) ;
    } else if (retPos < len){
        for (i = 0; i < MAX_STR_LENGTH; i++){  // Empty the buffer
            string[i] = 0x00;
        }

        //...trim the input string to just before 0x0D
        strncpy(string,tempStr,retPos);

        //...and tell the calling function that we did so
        return ( TRUE) ;
    }

    return ( FALSE) ; // Otherwise, it wasn't found
}


/*
 * ======== setTimer_A_Parameters ========
 */
// This function sets the timer A parameters
void setTimer_A_Parameters()
{
    Timer_A_params.clockSource = TIMER_A_CLOCKSOURCE_ACLK;
    Timer_A_params.clockSourceDivider = TIMER_A_CLOCKSOURCE_DIVIDER_1;
    Timer_A_params.timerInterruptEnable_TAIE = TIMER_A_TAIE_INTERRUPT_DISABLE;
    Timer_A_params.captureCompareInterruptEnable_CCR0_CCIE =
               TIMER_A_CAPTURECOMPARE_INTERRUPT_ENABLE;
    Timer_A_params.timerClear = TIMER_A_DO_CLEAR;
    Timer_A_params.startTimer = false;
}

/*
 * ======== initTimer ========
 */
void initTimer (void)
{
    // Configure timer parameters
    setTimer_A_Parameters();

    // Start timer
    Timer_A_clearTimerInterrupt(TIMER_A0_BASE);

    // Set timer period to zero
    Timer_A_params.timerPeriod = 0;

    Timer_A_initUpMode(TIMER_A0_BASE, &Timer_A_params);
}

/*
 * ======== initClocks ========
 */
void initClocks(uint32_t mclkFreq)
{
    UCS_initClockSignal(
       UCS_SMCLK,
       UCS_REFOCLK_SELECT,
       UCS_CLOCK_DIVIDER_1);

    UCS_initClockSignal(
       UCS_ACLK,
       UCS_REFOCLK_SELECT,
       UCS_CLOCK_DIVIDER_1);

    UCS_initFLLSettle(
        mclkFreq/1000,
        mclkFreq/32768);
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

/*
 * ======== TIMER1_A0_ISR ========
 */
#if defined(__TI_COMPILER_VERSION__) || (__IAR_SYSTEMS_ICC__)
#pragma vector=TIMER0_A0_VECTOR
__interrupt void TIMER0_A0_ISR (void)
#elif defined(__GNUC__) && (__MSP430__)
void __attribute__ ((interrupt(TIMER0_A0_VECTOR))) TIMER0_A0_ISR (void)
#else
#error Compiler not found!
#endif
{
    GPIO_toggleOutputOnPin(LED_PORT, LED_PIN);
}
