/********************************************/
/*  author: Mohamed Walid                   */
/*  version: V01 							*/
/*  Date: 14 Aug 2022                      	*/
/********************************************/

#ifndef		TIM0_CONFIG_H
#define 	TIM0_CONFIG_H

/* you can choose between:-

* TIM0_NORMAL_MODE						
* TIM0_CTC_MODE								
* TIM0_FAST_PWM_MODE					
* TIM0_PHASE_CORRECT_PWM_MODE
*/


#define 	TIM0_MODE 		TIM0_NORMAL_MODE


/* you can choose between:-

TIM0_PRESCALER_CLK_I/O_BY_1							
TIM0_PRESCALER_CLK_I/O_BY_8							
TIM0_PRESCALER_CLK_I/O_BY_64						
TIM0_PRESCALER_CLK_I/O_BY_256						
TIM0_PRESCALER_CLK_I/O_BY_1024					
TIM0_PRESCALER_EXTERNAL_CLK_FALLING_EDGE
TIM0_PRESCALER_EXTERNAL_CLK_RISING_EDGE	
*/


#define 	TIM0_PRESCALER_CHOICE		TIM0_PRESCALER_CLK_IO_BY_1



#if TIM0_MODE==TIM0_FAST_PWM_MODE

/*
 * options:
 * TIM0_INVERTING_PWM
 * TIM0_NON_INVERTING_PWM
 */

#define TIM0_FAST_PWM_SIGNAL	 TIM0_NON_INVERTING_PWM


#elif TIM0_MODE == TIM0_CTC_MODE




#endif





#endif
