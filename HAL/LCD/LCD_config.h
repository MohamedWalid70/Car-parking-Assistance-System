

#ifndef  LCD_CONFIG_H
#define  LCD_CONFIG_H


#define  LCD_pin_RS     DIO_PIN_NO_2
#define  LCD_pin_RW     DIO_PIN_NO_3
#define  LCD_pin_E      DIO_PIN_NO_4

#define  LCD_pin_D0     DIO_PIN_NO_5
#define  LCD_pin_D1     DIO_PIN_NO_6
#define  LCD_pin_D2     DIO_PIN_NO_7
#define  LCD_pin_D3     DIO_PIN_NO_19
#define  LCD_pin_D4     DIO_PIN_NO_20
#define  LCD_pin_D5     DIO_PIN_NO_16
#define  LCD_pin_D6     DIO_PIN_NO_17
#define  LCD_pin_D7     DIO_PIN_NO_18

/*
 * options:
 * LCD_FOUR_BIT_MODE
 * LCD_EIGHT_BIT_MODE
 */

#define LCD_INTERFACE_MODE   LCD_EIGHT_BIT_MODE


/*
 * options:
 * LCD_5x7_FONT 		>> corresponds to 8 characters written to CGRAM
 * LCD_5X10_FONT        >> corresponds to 4 characters written to CGRAM
 */

#define	LCD_FONT_SIZE 		LCD_5X7_FONT

/*
 * options:
 * LCD_2_LINES
 * LCD_1_LINE
 */
#if LCD_FONT_SIZE == LCD_5X7_FONT

#define LCD_CUSTOM_CHAR_ROWS_NO 	7

#else

#define LCD_CUSTOM_CHAR_ROWS_NO     10

#endif

#define LCD_ACTIVATED_LINES		LCD_2_LINES

/*
 * options:
 * LCD_CURSOR_DISPLAYED
 * LCD_CURSOR_HIDDEN
 */

#define	LCD_CURSOR_OPERATION  	LCD_CURSOR_HIDDEN


/*options:
 * LCD_CURSOR_BLINK
 * LCD_CURSOR_STATIC
 */

#define	LCD_CURSOR_APPEARANCE	LCD_CURSOR_STATIC


#endif
