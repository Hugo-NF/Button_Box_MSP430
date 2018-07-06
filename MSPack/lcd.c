#include "lcd.h"
#include "i2c.h"

void lcd_init(unsigned char address){
    lcd_address = address;
    I2C_master_init(address);

    delay(15);
    lcd_write_command(LCD_INIT_BYTE, 0);

    delay(5);
    lcd_write_command(LCD_INIT_BYTE, 0);

    delayMicrosseconds(150);
    lcd_write_command(LCD_INIT_BYTE, 0);
    lcd_write_command(LCD_BUS_WIDTH_4BIT, 0);

    lcd_write_command(LCD_4BITS_2LINES_5x8FONT, 1);
    lcd_write_command(LCD_DISPLAY_OFF_CURSOR_OFF_BLINK_OFF, 1);
    lcd_write_command(LCD_CLEAR, 1);
    lcd_write_command(LCD_INCREMENT_NO_SHIFT, 1);
    lcd_write_command(LCD_DISPLAY_ON_CURSOR_OFF, 1);
}

void lcd_write_command(unsigned char data, unsigned char cmdtype) {

    TX_data = (HI_NIBBLE(data) | LCD_BL) | LCD_EN;
    I2C_transmit();

    TX_data = (HI_NIBBLE(data) | LCD_BL) & ~LCD_EN;
    I2C_transmit();

    if (cmdtype) {
        TX_data = (LO_NIBBLE(data) | LCD_BL) | LCD_EN;
        I2C_transmit();
        TX_data = (LO_NIBBLE(data) | LCD_BL) | ~LCD_EN;
        I2C_transmit();
    }
    if(data == LCD_CLEAR || data == LCD_HOME)
        delay(2);
    else
        delayMicrosseconds(50);

    //lcd_set_position(1,1);
}

void lcd_write_char(unsigned char data) {

    TX_data = (HI_NIBBLE(data) | LCD_BL | LCD_RS) | LCD_EN;
    I2C_transmit();

    TX_data = (HI_NIBBLE(data) | LCD_BL | LCD_RS) & ~LCD_EN;
    I2C_transmit();

    TX_data = (LO_NIBBLE(data) | LCD_BL | LCD_RS) | LCD_EN;
    I2C_transmit();

    TX_data = (LO_NIBBLE(data) | LCD_BL | LCD_RS) & ~LCD_EN;
    I2C_transmit();
}

void lcd_write_string(char *s) {
    while (*s != '\0')
        lcd_write_char(*s++);
}

void lcd_set_position(unsigned char row, unsigned char column) {
    switch(row) {
        case 1: 
            lcd_write_command(LCD_LINE1 + (column - 1), 1);
            break;
        case 2:
            lcd_write_command(LCD_LINE2 + (column - 1), 1);
            break;
        case 3:
            lcd_write_command(LCD_LINE3 + (column - 1), 1);
            break;
        case 4:
            lcd_write_command(LCD_LINE4 + (column - 1), 1);
            break;
        default:
            lcd_write_command(LCD_LINE1 + (column - 1), 1);
    }
}

void lcd_create_arrows(){
    unsigned char up_arrow[8] = {
        0b00000,
        0b00100,
        0b01110,
        0b10101,
        0b00100,
        0b00100,
        0b00100,
        0b00000
    };
    unsigned char down_arrow[8] = {
        0b00000,
        0b00100,
        0b00100,
        0b00100,
        0b10101,
        0b01110,
        0b00100,
        0b00000
    };
    int i;
    for(i = 0; i< 8; i++){
        lcd_write_command(0x40+i, 1);
        lcd_write_char(up_arrow[i]);
        lcd_write_command(0x40+i+8, 1);
        lcd_write_char(down_arrow[i]);
    }

    lcd_set_position(1,1);
}

static void handle_x_axis(int16_t axis) {
    for (current_range = LOWER_BOUND_ADC; current_range < MIDDLE_RANGE; current_range += RANGE_STEPS){
        if(axis <= current_range)
            lcd_write_char(BL_CHAR);
        else
            lcd_write_char(WH_SPACE);
    }

    lcd_write_char(LEFT_ARROW);
    lcd_write_char(RIGHT_ARROW);

    for (current_range = MIDDLE_RANGE+4; current_range < UPPER_BOUND_ADC; current_range += RANGE_STEPS){
        if(axis >= current_range)
            lcd_write_char(BL_CHAR);
        else
            lcd_write_char(WH_SPACE);
    }
}

static void handle_y_axis(int16_t axis) {
    for (current_range = UPPER_BOUND_ADC-RANGE_STEPS; current_range > MIDDLE_RANGE; current_range -= RANGE_STEPS){
        if(axis <= current_range)
            lcd_write_char(WH_SPACE);
        else
            lcd_write_char(BL_CHAR);
    }

    lcd_write_char(DOWN_ARROW);
    lcd_write_char(UP_ARROW);

    for (current_range = MIDDLE_RANGE-4; current_range > LOWER_BOUND_ADC; current_range -= RANGE_STEPS){
        if(axis >= current_range)
            lcd_write_char(WH_SPACE);
        else
            lcd_write_char(BL_CHAR);
    }
}

void lcd_handler(int16_t x_axis, int16_t y_axis) {
    switch(current_view){
        case 1:
            snprintf(line1_buffer, LEN_LINE, "X axis: %d       ", x_axis);
            snprintf(line2_buffer, LEN_LINE, "Y axis: %d       ", y_axis);
            lcd_write_string(line1_buffer);
            lcd_set_position(2, 1);
            lcd_write_string(line2_buffer);
            lcd_set_position(1, 1);
            break;
        case 2:
            snprintf(line1_buffer, LEN_LINE, "LCD Addr: 0x%x", lcd_address);
            snprintf(line2_buffer, LEN_LINE, "Baud Rate: %d   ", UCB0BRW);
            lcd_write_string(line1_buffer);
            lcd_set_position(2, 1);
            lcd_write_string(line2_buffer);
            lcd_set_position(1, 1);
            break;
        default:
        case 0:
            handle_x_axis(x_axis);
            lcd_set_position(2, 1);
            handle_y_axis(y_axis);
            lcd_set_position(1, 1);
            break;
    }

}

void lcd_toogle_view(){
    if(current_view >= NO_OF_VIEWS)
        current_view = 0;
    else
        current_view++;
}
