/********************************************/
/*  author: Mohamed Walid                   */
/*  version: V01 							*/
/*  Date: 14 Aug 2022                      	*/
/********************************************/

#ifndef		TIM0_INT_H
#define 	TIM0_INT_H


void TIM0_void_init();

void TIM0_void_stop();

void TIM0_voidSetBusyWait(uint16 copy_uint16_periodInMilliSeconds);

void TIM0_voidCount();

void TIM0_voidDisableTOVInt();

void TIM0_voidEnableTOVInt();

void TIM0_voidSetCallbackFunc( void (*copy_voidCallbackFun)(void));

uint8 TIM0_uint8ReadCounter();

void TIM0_void_resume();

void TIM0_voidGeneratePWM(uint8 copy_uint8dutyCycle);

#endif
