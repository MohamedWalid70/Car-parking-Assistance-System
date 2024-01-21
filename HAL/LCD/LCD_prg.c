#include  "STD_Types.h"
#include  "BIT_MATH.h"

#include  "DIO_int.h"
#include  "LCD_int.h"
#include  "LCD_priv.h"
#include  "LCD_config.h"
#include  "TIM0_int.h"

static uint8 Local_var, Local_F_result;

void LCD_void_init(){

	TIM0_void_init();
#if LCD_INTERFACE_MODE==LCD_EIGHT_BIT_MODE

	TIM0_voidSetBusyWait(30);
	LCD_void_WRITE_CMD(32|LCD_INTERFACE_MODE|LCD_ACTIVATED_LINES|LCD_FONT_SIZE);
	TIM0_voidSetBusyWait(1);
	LCD_void_WRITE_CMD(12|LCD_CURSOR_OPERATION|LCD_CURSOR_APPEARANCE);
	TIM0_voidSetBusyWait(1);
	LCD_void_WRITE_CMD(0b00000001);
	TIM0_voidSetBusyWait(1);
	LCD_void_WRITE_CMD(0b00000110);

#else





#endif

}

void LCD_void_WRITE_CMD(uint8 copy_uint8_CMD){

   DIO_voidSetPin(LCD_pin_RS, DIO_PIN_LOW);

   LCD_void_EXCUTE_CMD(copy_uint8_CMD);

}

void LCD_void_WRITE_CHARACTER(uint8 copy_uint8_CHARACTER){

    DIO_voidSetPin(LCD_pin_RS, DIO_PIN_HIGH);

	LCD_void_EXCUTE_CMD(copy_uint8_CHARACTER);

}

void LCD_void_WRITE_STRING(uint8 * copy_uint8_STRING){

	DIO_voidSetPin(LCD_pin_RS, DIO_PIN_HIGH);

	Local_var = 0;

	while(copy_uint8_STRING[Local_var]!='\0'){

	   LCD_void_WRITE_CHARACTER(copy_uint8_STRING[Local_var]);

		Local_var ++;
	}

}

void LCD_void_GoToRowColmun(uint8 copy_uint8_Row , uint8 copy_uint8_colmun){


	if(copy_uint8_Row == 1){

		Local_F_result = 0x00 + copy_uint8_colmun;


	}else if (copy_uint8_Row == 2){

		Local_F_result = 0x40 + copy_uint8_colmun;

	}

	LCD_void_WRITE_CMD(Local_F_result | 0x80);

}

void LCD_void_CLEARSCREEN(){

	LCD_void_WRITE_CMD(0b00000001);

}


void LCD_void_EXCUTE_CMD(uint8 copy_LCD_CMD){

	DIO_voidSetPin(LCD_pin_RW , DIO_PIN_LOW);
	TIM0_voidSetBusyWait(1);
	DIO_voidSetPin(LCD_pin_E, DIO_PIN_HIGH);
    TIM0_voidSetBusyWait(1);

	if(GET_BIT(copy_LCD_CMD, 0 )){

		DIO_voidSetPin(LCD_pin_D0 , DIO_PIN_HIGH);

	}else{

		DIO_voidSetPin(LCD_pin_D0 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 1 )){

		DIO_voidSetPin(LCD_pin_D1 , DIO_PIN_HIGH);

	}else{

		DIO_voidSetPin(LCD_pin_D1 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 2 )){

		DIO_voidSetPin(LCD_pin_D2 , DIO_PIN_HIGH);

	}else{

		DIO_voidSetPin(LCD_pin_D2 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 3 )){

		DIO_voidSetPin(LCD_pin_D3 , DIO_PIN_HIGH);

	}else{

		DIO_voidSetPin(LCD_pin_D3 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 4 )){

		DIO_voidSetPin(LCD_pin_D4 , DIO_PIN_HIGH);

	}else{

		DIO_voidSetPin(LCD_pin_D4 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 5 )){

		DIO_voidSetPin(LCD_pin_D5 , DIO_PIN_HIGH);

	}else{

		DIO_voidSetPin(LCD_pin_D5 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 6 )){

		DIO_voidSetPin(LCD_pin_D6 , DIO_PIN_HIGH);

	}else{

		DIO_voidSetPin(LCD_pin_D6 , DIO_PIN_LOW);

	}

	if(GET_BIT(copy_LCD_CMD, 7 )){

		DIO_voidSetPin(LCD_pin_D7 , DIO_PIN_HIGH);

	}else{

		DIO_voidSetPin(LCD_pin_D7 , DIO_PIN_LOW);

	}

	TIM0_voidSetBusyWait(1);
    DIO_voidSetPin(LCD_pin_E, DIO_PIN_LOW);
    TIM0_voidSetBusyWait(2);

}
// max of 5 digits to print
void LCD_voidWriteNumber(uint32 copy_uint16No){

	uint32 divisor;
	uint32 modFact=10;

	while((copy_uint16No%modFact)!=copy_uint16No){

		modFact*=10;
	}
	divisor=modFact/10;
	while(divisor!=0){

		LCD_void_WRITE_CHARACTER(((copy_uint16No%modFact)/divisor)+48);
		divisor/=10;
		modFact/=10;
	}
}
//max of 3 digits after . sign and 6 digits before

void LCD_voidWriteFloatingNumber(f32 copy_uintf32No){

	uint32 divisor;
	uint32 modFact=10;
	uint32 NOtoPrint = copy_uintf32No*100;

	while((NOtoPrint%modFact)!=NOtoPrint){

		modFact*=10;
	}

	divisor=modFact/10;
	while(divisor!=0){

		LCD_void_WRITE_CHARACTER(((NOtoPrint%modFact)/divisor)+48);
		divisor/=10;
		modFact/=10;
		if(modFact==100){
			LCD_void_WRITE_CHARACTER('.');
		}
	}
}

void LCD_voidWriteToCGRAM(uint8 *copy_uint8Charcontent, uint8 copy_uint8CGRAMCharAddress){

	copy_uint8CGRAMCharAddress*=8;

	LCD_void_WRITE_CMD(0x40+copy_uint8CGRAMCharAddress);

	for(uint8 i=0;i<LCD_CUSTOM_CHAR_ROWS_NO;i++){

		LCD_void_WRITE_CHARACTER(copy_uint8Charcontent[i]);

	}
	LCD_void_EXCUTE_CMD(0x80+copy_uint8CGRAMCharAddress);
}

