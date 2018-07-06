#ifndef LCD_MSG_ICON_H_
#define LCD_MSG_ICON_H_

#include "MSPack/lcd.h"

inline void lcd_clear(){
    lcd_set_position(1, 1);
    lcd_write_string("                 ");
    lcd_set_position(2, 1);
    lcd_write_string("                 ");
    lcd_set_position(1, 1);
}

inline void lcd_print_setting(){
    unsigned char settingsChar[8][8] = {{
        0b00000,
        0b00000,
        0b00011,
        0b00100,
        0b01000,
        0b11111,
        0b00000,
        0b00000
    },{
       0b00000,
       0b00000,
       0b11000,
       0b00100,
       0b00010,
       0b10001,
       0b01000,
       0b01000
    },{
       0b00000,
       0b00000,
       0b00011,
       0b00100,
       0b01000,
       0b10001,
       0b00010,
       0b00010
    },{
       0b00000,
       0b00000,
       0b11000,
       0b00100,
       0b00010,
       0b11111,
       0b00000,
       0b00000
    },{
       0b00000,
       0b00000,
       0b00000,
       0b00000,
       0b11111,
       0b01000,
       0b00100,
       0b00011
    },{
       0b01000,
       0b01000,
       0b01000,
       0b01000,
       0b10001,
       0b00010,
       0b00100,
       0b11000
    },{
       0b00010,
       0b00010,
       0b00010,
       0b00010,
       0b10001,
       0b01000,
       0b00100,
       0b00011
    },{
       0b00000,
       0b00000,
       0b00000,
       0b00000,
       0b11111,
       0b00010,
       0b00100,
       0b11000
    }};

    int i;
    for(i = 0; i< 8; i++){
        lcd_write_command(0x40+i, 1);
        lcd_write_char(settingsChar[0][i]);

        lcd_write_command(0x40+i+8, 1);
        lcd_write_char(settingsChar[1][i]);

        lcd_write_command(0x40+i+16, 1);
        lcd_write_char(settingsChar[2][i]);

        lcd_write_command(0x40+i+24, 1);
        lcd_write_char(settingsChar[3][i]);

        lcd_write_command(0x40+i+32, 1);
        lcd_write_char(settingsChar[4][i]);

        lcd_write_command(0x40+i+40, 1);
        lcd_write_char(settingsChar[5][i]);

        lcd_write_command(0x40+i+48, 1);
        lcd_write_char(settingsChar[6][i]);

        lcd_write_command(0x40+i+56, 1);
        lcd_write_char(settingsChar[7][i]);
    }

    lcd_clear();

    lcd_set_position(1,5);
    lcd_write_char(0x00);
    lcd_write_char(0x01);
    lcd_write_char(0x5F);lcd_write_char(0x5F);lcd_write_char(0x5F);lcd_write_char(0x5F);
    lcd_write_char(0x02);
    lcd_write_char(0x03);


    lcd_set_position(2, 5);
    lcd_write_char(0x04);
    lcd_write_char(0x05);
    lcd_write_char(0x2D);lcd_write_char(0x2D);lcd_write_char(0x2D);lcd_write_char(0x2D);
    lcd_write_char(0x06);
    lcd_write_char(0x07);

    lcd_set_position(1, 1);
}

#endif /* LCD_MSG_ICON_H_ */
