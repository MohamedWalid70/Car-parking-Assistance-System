#ifndef   LCD_PRIV_H
#define   LCD_PRIV_H



#define   LCD_FOUR_BIT_MODE   0
#define   LCD_EIGHT_BIT_MODE  16

#define   LCD_2_LINES         8
#define   LCD_1_LINE          0

#define   LCD_5X7_FONT        0
#define   LCD_5X10_FONT       4

#define   LCD_CURSOR_DISPLAYED		2
#define   LCD_CURSOR_HIDDEN         0

#define	  LCD_CURSOR_BLINK		1
#define   LCD_CURSOR_STATIC     0


static void  LCD_void_EXCUTE_CMD(uint8 copy_LCD_CMD);

#endif
