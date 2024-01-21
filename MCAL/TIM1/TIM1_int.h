/********************************************/
/*  author: Mohamed Walid                   */
/*  version: V01 							*/
/*  Date: 14 Aug 2022                      	*/
/********************************************/

#ifndef			TIM1_INT_H
#define			TIM1_INT_H

/*
 * Note:- to use TIM1_voidSetBusyWait_us, the prescaler should be 8
 */


void TIM1_voidInit();

void TIM1_voidSetBusyWait(uint16 copy_uint16DesiredPeriodInMilli);

void TIM1_voidSetBusyWait_us(uint8 copy_uint8_periodInMicroSeconds);

void TIM1_voidSetIntervalSingle(uint16 copy_uint16DesiredPeriod, void(*Copy_voidTaskToBeDone)(void));

void TIM1_voidSetIntervalPeriodic(uint16 copy_uint16DesiredPeriod, void(*Copy_voidTaskToBeDone)(void));

void TIM1_voidReset();

uint16 TIM1_uint16ReadCounter();

void TIM1_voidGeneratePWM(uint8 *copy_uint8dutyCycle);

void TIM1_voidEnableICUINT();

void TIM1_voidDisableICUINT();
void TIM1_voidGetSignalInfo(uint8 *copy_uint8DutyCycle, uint16 *copy_uint16Freq);

void TIM1_voidSetOVFCallBackFun(void (*voidCBP)(void));

void TIM1_voidEnableOVFINT();
void TIM1_voidDisableOVFINT();

uint16 TIM1_voidGetUSHighTime();

#endif

