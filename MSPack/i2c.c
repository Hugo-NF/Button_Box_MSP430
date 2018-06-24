#include "i2c.h"

void I2C_master_init(unsigned char slave_address) {
    P3SEL = BIT0 | BIT1;                            // Assigning I2C pins to USCI_B0
    P3DIR &= ~(BIT0 | BIT1);                        // Setting up a fake input pin
    P3REN |= (BIT0 | BIT1);
    P3OUT |= (BIT0 | BIT1);

    UCB0CTL1    = UCSWRST;                         // Enable SW reset
    UCB0CTL0    = UCMST + UCMODE_3 + UCSYNC;       // Setting the interface as I2C master with single master environment, synchronous mode
    UCB0CTL1   |= UCSSEL_2;                        // Selecting SMCLK
    UCB0I2CSA   = slave_address;                   // Setting slave address
    UCB0BR0     = PRESCALE;                        // Set prescaler - SMCLK/12
    UCB0BR1     = 0;
    UCB0CTL1   &= ~UCSWRST;                        // Clear SW reset
}

void I2C_transmit() {
    while((UCB0STAT & UCBBUSY) !=  0);    // Verifying SDA availability

    UCB0CTL1 |= UCTR + UCTXSTT;           // Transmit I2C Start Condition

    while((UCB0IFG & UCTXIFG) == 0);      // Wait for TXBUFF Interruption (SCL is hold)

    UCB0TXBUF = TX_data;                  // Copy byte to TXBUFF

    while((UCB0CTL1 & UCTXSTT) != 0);     // Wait for Slave Answer (Can be ACK or NACK)

    UCB0CTL1 |= UCTXSTP;                  // Transmit I2C Stop Condition
    while((UCB0CTL1 & UCTXSTP) != 0);     // Wait for Stop Condition
}
