#ifndef  LCD_INT_H
#define  LCD_INT_H


void LCD_void_init();

void LCD_void_WRITE_CMD(uint8 copy_uint8_CMD);

void LCD_void_WRITE_CHARACTER(uint8 copy_uint8_CHARACTER);

void LCD_voidWriteToCGRAM(uint8 *copy_uint8Charcontent, uint8 copy_uint8CGRAMCharAddress);

void LCD_void_WRITE_STRING(uint8 * copy_uint8_STRING);

void LCD_void_GoToRowColmun(uint8 copy_uint8_Row , uint8 copy_uint8_colmun);

void LCD_void_CLEARSCREEN();

void LCD_voidWriteNumber(uint32 copy_uint16No);

void LCD_voidWriteFloatingNumber(f32 copy_uintf32No);

#endif
