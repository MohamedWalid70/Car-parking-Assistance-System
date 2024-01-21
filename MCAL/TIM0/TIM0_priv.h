/********************************************/
/*  author: Mohamed Walid                   */
/*  version: V01 							*/
/*  Date: 14 Aug 2022                      	*/
/********************************************/


#ifndef		TIM0_PRIV_H
#define 	TIM0_PRIV_H

#define 	TCCR0  		(*((volatile uint8 *) 0x53))
#define 	TCNT0  		(*((volatile uint8 *) 0x52))
#define 	OCR0			(*((volatile uint8 *) 0x5C))
#define 	TIMSK	  		(*((volatile uint8 *) 0x59))
#define 	TIFR		  		(*((volatile uint8 *) 0x58))


#define 	TIM0_NORMAL_MODE						0
#define 	TIM0_CTC_MODE							1
#define 	TIM0_FAST_PWM_MODE						9
#define 	TIM0_PHASE_CORRECT_PWM_MODE				8


#define 	TIM0_PRESCALER_CLK_IO_BY_1									1
#define 	TIM0_PRESCALER_CLK_IO_BY_8									2
#define 	TIM0_PRESCALER_CLK_IO_BY_64								3
#define 	TIM0_PRESCALER_CLK_IO_BY_256								4
#define 	TIM0_PRESCALER_CLK_IO_BY_1024							5
#define 	TIM0_PRESCALER_EXTERNAL_CLK_FALLING_EDGE		6
#define 	TIM0_PRESCALER_EXTERNAL_CLK_RISING_EDGE			7

#define     TIM0_INVERTING_PWM         3
#define     TIM0_NON_INVERTING_PWM     2
#define     TIM0_TOGGLE                1



#endif
