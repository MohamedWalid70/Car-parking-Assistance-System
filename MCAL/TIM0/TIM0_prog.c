/********************************************/
/*  author: Mohamed Walid                   */
/*  version: V01 							*/
/*  Date: 14 Aug 2022                      	*/
/********************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "TIM0_int.h"
#include "TIM0_priv.h"
#include "TIM0_config.h"

uint8 count;
static void (*TIM0_voidCallbackFunc)(void);

void TIM0_void_init(){
	
	TCCR0 |= TIM0_MODE<<3;

#if TIM0_MODE == TIM0_FAST_PWM_MODE
	TCCR0 |= TIM0_FAST_PWM_SIGNAL<<4;
#endif

#if TIM0_PRESCALER_CHOICE==TIM0_PRESCALER_CLK_IO_BY_1
	
	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	count = 31;
	
#elif TIM0_PRESCALER_CHOICE==TIM0_PRESCALER_CLK_IO_BY_8
	
	CLEAR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	count = 4;
	
#elif TIM0_PRESCALER_CHOICE==TIM0_PRESCALER_CLK_IO_BY_64
	
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	count = 125;
	
#elif TIM0_PRESCALER_CHOICE==TIM0_PRESCALER_CLK_IO_BY_256

	CLEAR_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);	
	count = 31;			// 31.25
	
#elif TIM0_PRESCALER_CHOICE==TIM0_PRESCALER_CLK_IO_BY_1024
		
	SET_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);	
	count = 8;			// 7.8125
	
#elif TIM0_PRESCALER_CHOICE==TIM0_PRESCALER_EXTERNAL_CLK_FALLING_EDGE
	
	CLEAR_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);	
	
#else
	
	SET_BIT(TCCR0,0);
	SET_BIT(TCCR0,1);
	SET_BIT(TCCR0,2);
	
#endif
	
	
}


void TIM0_voidSetBusyWait(uint16 copy_uint16_periodInMilliSeconds){
	
	TCCR0 = TIM0_PRESCALER_CHOICE;

	if(TIM0_PRESCALER_CHOICE==TIM0_PRESCALER_CLK_IO_BY_8||TIM0_PRESCALER_CHOICE==TIM0_PRESCALER_CLK_IO_BY_1){

	TCNT0=0;
	
	for(uint16 j=0;j<copy_uint16_periodInMilliSeconds;j++){
		
		for(uint16 i=0;i<count;i++){
		
			while(GET_BIT(TIFR,0)==0);			// waiting for the TOV0 to be set
			SET_BIT(TIFR,0);							// clearing the TOV0 flag
														// counting a millisecond
		}	
	}

	}else{

		for(uint16 j=0;j<copy_uint16_periodInMilliSeconds;j++){

			TCNT0 = 256-count;
			while(GET_BIT(TIFR,0)==0);			// waiting for the TOV0 to be set
			SET_BIT(TIFR,0);							// clearing the TOV0 flag
													// counting a millisecond
		}
	}
	TCCR0 = 0;

}

#if TIM0_MODE==TIM0_FAST_PWM_MODE

void TIM0_voidGeneratePWM(uint8 copy_uint8dutyCycle ){

if(TIM0_FAST_PWM_SIGNAL==TIM0_NON_INVERTING_PWM){

	OCR0 = ((copy_uint8dutyCycle*(256))/100)-1;
}
else{
	OCR0 = 255-((copy_uint8dutyCycle*(256))/100);
}

}
#endif

void TIM0_voidCount(){

//	TIM0_void_stop();
	TCNT0=0;
//	TIM0_void_resume();
}

uint8 TIM0_uint8ReadCounter(){

	return TCNT0;
}

void TIM0_void_stop(){
	
	CLEAR_BIT(TCCR0,0);
	CLEAR_BIT(TCCR0,1);
	CLEAR_BIT(TCCR0,2);
	
}

void TIM0_void_resume(){
	
	TCCR0|=TIM0_PRESCALER_CHOICE;
	
}

void TIM0_voidEnableTOVInt(){

	SET_BIT(TIMSK,0);
}

void TIM0_voidDisableTOVInt(){

	CLEAR_BIT(TIMSK,0);
}

void TIM0_voidSetCallbackFunc( void (*copy_voidCallbackFun)(void)){

	TIM0_voidCallbackFunc = copy_voidCallbackFun;

}

void __vector_11(void) __attribute__((signal , used));
void __vector_11(void)
{

	TIM0_voidCallbackFunc();

}

