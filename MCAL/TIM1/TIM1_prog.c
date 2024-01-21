/********************************************/
/*  author: Mohamed Walid                   */
/*  version: V01 							*/
/*  Date: 14 Aug 2022                      	*/
/********************************************/
#include "STD_Types.h"
#include "BIT_MATH.h"


#include "TIM1_int.h"
#include "TIM1_priv.h"
#include "TIM1_config.h"

uint16 initialCount=57535; // by 1 prescaler
uint16 Tu;


static void (*OVFcallBackFun)(void);

void TIM1_voidInit(){
	
	
#if	TIM1_OPERTAION_MODE == TIM1_NORMAL_MODE

TIM1_TCCR1A=0;

#elif TIM1_OPERTAION_MODE == TIM1_FAST_PWM_MODE

	switch (TIM1_FAST_PWM_RESOLUTION) {

	case TIM1_8_BIT_PWM:

		SET_BIT(TIM1_TCCR1A, 0);
		CLEAR_BIT(TIM1_TCCR1A, 1);
		SET_BIT(TIM1_TCCR1B, 3);
		CLEAR_BIT(TIM1_TCCR1B, 4);
		TOP = 0x00FF;
		break;

	case TIM1_9_BIT_PWM:

		CLEAR_BIT(TIM1_TCCR1A, 0);
		SET_BIT(TIM1_TCCR1A, 1);
		SET_BIT(TIM1_TCCR1B, 3);
		CLEAR_BIT(TIM1_TCCR1B, 4);
		TOP = 0x01FF;
		break;

	case TIM1_10_BIT_PWM:

		SET_BIT(TIM1_TCCR1A, 0);
		SET_BIT(TIM1_TCCR1A, 1);
		SET_BIT(TIM1_TCCR1B, 3);
		CLEAR_BIT(TIM1_TCCR1B, 4);
		TOP = 0x03FF;
		break;

	case TIM1_ICR1_PWM:

		CLEAR_BIT(TIM1_TCCR1A, 0);
		SET_BIT(TIM1_TCCR1A, 1);
		SET_BIT(TIM1_TCCR1B, 3);
		SET_BIT(TIM1_TCCR1B, 4);
		break;

	case TIM1_OCR1A_PWM:

		SET_BIT(TIM1_TCCR1A, 0);
		SET_BIT(TIM1_TCCR1A, 1);
		SET_BIT(TIM1_TCCR1B, 3);
		SET_BIT(TIM1_TCCR1B, 4);
		break;

	}

#if TIM1_FAST_PWM_CHANNEL==TIM1_PWM_CHANNEL_A

	TIM1_TCCR1A |= TIM1_FAST_PWM_SIGNAL<<6;

#elif TIM1_FAST_PWM_CHANNEL==TIM1_PWM_CHANNEL_B

	TIM1_TCCR1A |= TIM1_FAST_PWM_SIGNAL<<4;

#else

	TIM1_TCCR1A |= TIM1_FAST_PWM_A_SIGNAL<<6;
	TIM1_TCCR1A |= TIM1_FAST_PWM_B_SIGNAL<<4;

#endif


#elif TIM1_OPERTAION_MODE == TIM1_PHASE_PWM_MODE


#elif TIM1_OPERTAION_MODE == TIM1_PHASE_FREQ_PWM_MODE


#elif TIM1_OPERTAION_MODE == TIM1_CTC_MODE


#endif

#if (TIM1_CLK_CONFIG == TIM1_INT_CLK_BY_8) && (TIM1_OPERTAION_MODE == TIM1_NORMAL_MODE)
	
initialCount = 64535;
	
#elif (TIM1_CLK_CONFIG == TIM1_INT_CLK_BY_64) && (TIM1_OPERTAION_MODE == TIM1_NORMAL_MODE)

initialCount = 65410;
	
#elif (TIM1_CLK_CONFIG == TIM1_INT_CLK_BY_256) && (TIM1_OPERTAION_MODE == TIM1_NORMAL_MODE)
	
initialCount = 65410;			// mimimun desired period 4ms
	
#elif (TIM1_CLK_CONFIG == TIM1_INT_CLK_BY_1024) && (TIM1_OPERTAION_MODE == TIM1_NORMAL_MODE)
	
initialCount = 65410;			// mimimun desired period 16ms
	
#endif
	
}

#if TIM1_OPERTAION_MODE==TIM1_NORMAL_MODE
void TIM1_voidSetBusyWait(uint16 copy_uint16DesiredPeriodInMilli){

	TIM1_TCCR1B |= TIM1_CLK_CONFIG;		// timer prescaler , internal or external clk

	if(TIM1_CLK_CONFIG==TIM1_INT_CLK_BY_256){

		copy_uint16DesiredPeriodInMilli/=4;
	}else if(TIM1_CLK_CONFIG==TIM1_INT_CLK_BY_1024){
		copy_uint16DesiredPeriodInMilli/=16;
	}

	for(uint16 k=0;k<copy_uint16DesiredPeriodInMilli;k++){
		
		//TIM1_TCNT1H = 0x00FF & (initialCount>>8);
		//TIM1_TCNT1L = 0x00FF & initialCount;
		TIM1_TCNT1 = initialCount;
		
		while(GET_BIT(TIM1_TIFR,2)==0);

		SET_BIT(TIM1_TIFR,2);			// clearing the TOV1 bit
	}
	TIM1_TCCR1B=0;
}

void TIM1_voidSetBusyWait_us(uint8 copy_uint8_periodInMicroSeconds){

	initialCount = 65536 - copy_uint8_periodInMicroSeconds;

	TIM1_TCCR1B = TIM1_CLK_CONFIG;

	TIM1_TCNT1 = initialCount;

	while(GET_BIT(TIM1_TIFR,2)==0);			// waiting for the TOV0 to be set
	SET_BIT(TIM1_TIFR,2);					// clearing the TOV0 flag

	TIM1_TCCR1B=0;
}

void TIM1_voidSetIntervalSingle(uint16 copy_uint16DesiredPeriod, void(*Copy_voidTaskToBeDone)(void)){
	
	
}

void TIM1_voidSetIntervalPeriodic(uint16 copy_uint16DesiredPeriod, void(*Copy_voidTaskToBeDone)(void)){
	
	
}


void TIM1_voidReset(){

	TIM1_TCNT1=0;
}

uint16 TIM1_uint16ReadCounter(){

	return TIM1_TCNT1;
}

void TIM1_voidSetOVFCallBackFun(void (*voidCBP)(void)){

	OVFcallBackFun = voidCBP;
}


void TIM1_voidEnableOVFINT(){

	SET_BIT(TIM1_TIMSK,2);
}

void TIM1_voidDisableOVFINT(){

	CLEAR_BIT(TIM1_TIMSK,2);
}

#if TIM1_ICU_OPERATION==TIM1_ICU_ON

uint16 TIM1_voidGetUSHighTime(){

	TIM1_TCNT1=0;
	SET_BIT(TIM1_TIFR, 5);
	TIM1_TCCR1B = 0b01000000 | TIM1_CLK_CONFIG;

	while (GET_BIT(TIM1_TIFR,5) == 0);

	TIM1_TCNT1=0;

	SET_BIT(TIM1_TIFR, 5);

	TIM1_TCCR1B = TIM1_CLK_CONFIG;

	while (GET_BIT(TIM1_TIFR,5) == 0);

	Tu = TIM1_ICR1;

	SET_BIT(TIM1_TIFR, 5);

	TIM1_TCCR1B = 0;

	return (Tu);
}


void TIM1_voidEnableICUINT(){

//	SET_BIT(TIM1_ACSR,2);
	SET_BIT(TIM1_TIMSK,5);
}

void TIM1_voidDisableICUINT(){

	CLEAR_BIT(TIM1_TIMSK,5);
}
#endif

#endif

#if TIM1_OPERTAION_MODE==TIM1_FAST_PWM_MODE

void TIM1_voidGeneratePWM(uint8 *copy_uint8dutyCycle ){
	
#if TIM1_FAST_PWM_CHANNEL==TIM1_PWM_CHANNEL_A

if(TIM1_FAST_PWM_SIGNAL==TIM1_NON_INVERTING_PWM){

	TIM1_OCR1A = ((copy_uint8dutyCycle[0]*(TOP+1))/100)-1;
}
else{
	TIM1_OCR1A = TOP-((copy_uint8dutyCycle[0]*(TOP+1))/100);
}

	
#elif TIM1_FAST_PWM_CHANNEL==TIM1_PWM_CHANNEL_B

if(TIM1_FAST_PWM_SIGNAL==TIM1_NON_INVERTING_PWM){

	TIM1_OCR1B = ((copy_uint8dutyCycle[1]*(TOP+1))/100)-1;
}
else{
	TIM1_OCR1B = TOP-((copy_uint8dutyCycle[1]*(TOP+1))/100);
}

#else

if(TIM1_FAST_PWM_A_SIGNAL==TIM1_NON_INVERTING_PWM){

	TIM1_OCR1A = ((copy_uint8dutyCycle[0]*(TOP+1))/100)-1;
}
else{
	TIM1_OCR1A = TOP-((copy_uint8dutyCycle[0]*(TOP+1))/100);
}

if(TIM1_FAST_PWM_B_SIGNALL==TIM1_NON_INVERTING_PWM){

	TIM1_OCR1B = ((copy_uint8dutyCycle[1]*(TOP+1))/100)-1;
}
else{
	TIM1_OCR1B = TOP-((copy_uint8dutyCycle[1]*(TOP+1))/100);
}

	
#endif
}
#endif

void __vector_6(void) __attribute__((signal , used));
void __vector_6(void)
{

}

void __vector_9(void) __attribute__((signal , used));
void __vector_9(void)
{
	OVFcallBackFun();

}
