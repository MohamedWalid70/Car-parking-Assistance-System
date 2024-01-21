/********************************************/
/*  author: Mohamed Walid                   */
/*  version: V01 							*/
/*  Date: 14 Aug 2022                      	*/
/********************************************/

#ifndef			TIM1_PRIV_H
#define			TIM1_PRIV_H

#define		TIM1_TCCR1A    *(( volatile uint8*)0x4F )
#define		TIM1_TCCR1B    *(( volatile uint8*)0x4E )
#define		TIM1_TCNT1H    *(( volatile uint8*)0x4D )
#define		TIM1_TCNT1L    *(( volatile uint8*)0x4C )
#define		TIM1_TCNT1     *(( volatile uint16*)0x4C )
#define		TIM1_OCR1AH    *(( volatile uint8*)0x4B )
#define		TIM1_OCR1AL    *(( volatile uint8*)0x4A )
#define		TIM1_OCR1A	   *(( volatile uint16*)0x4A )
#define		TIM1_OCR1BH    *(( volatile uint8*)0x49 )
#define		TIM1_OCR1BL    *(( volatile uint8*)0x48 )
#define		TIM1_OCR1B	   *(( volatile uint16*)0x48 )
#define		TIM1_ICR1H     *(( volatile uint8*)0x47 )
#define		TIM1_ICR1L     *(( volatile uint8*)0x46 )
#define		TIM1_ICR1	   *(( volatile uint16*)0x46 )
#define		TIM1_TIMSK     *(( volatile uint8*)0x59 )
#define		TIM1_TIFR      *(( volatile uint8*)0x58 )
#define		TIM1_ACSR	   *(( volatile uint8*)0x28 )


#define         TIM1_NORMAL_MODE  				0
#define         TIM1_FAST_PWM_MODE				1
#define         TIM1_PHASE_PWM_MODE 			3
#define         TIM1_PHASE_FREQ_PWM_MODE	 	5
#define         TIM1_CTC_MODE 					7

#define			TIM1_INT_CLK_BY_1               1
#define			TIM1_INT_CLK_BY_8               2
#define			TIM1_INT_CLK_BY_64              3
#define			TIM1_INT_CLK_BY_256             4
#define			TIM1_INT_CLK_BY_1024            5
#define			TIM1_EXT_CLK_ON_FALLING         6
#define         TIM1_EXT_CLK_ON_RISING          7



#define 	    TIM1_ICU_IO_CLK_PRESCALER_BY_1			1
#define 	    TIM1_ICU_IO_CLK_PRESCALER_BY_8		    8
#define 	    TIM1_ICU_IO_CLK_PRESCALER_BY_64		    64
#define 	    TIM1_ICU_IO_CLK_PRESCALER_BY_256	    256
#define 	    TIM1_ICU_IO_CLK_PRESCALER_BY_1024	    1024


#define         TIM1_ICU_ON      1
#define         TIM1_ICU_OFF     0


#define         TIM1_8_BIT_PWM                  0
#define         TIM1_9_BIT_PWM                  1
#define         TIM1_10_BIT_PWM                 3
#define         TIM1_OCR1A_PWM                  5
#define         TIM1_ICR1_PWM                   7


#define         TIM1_PWM_CHANNEL_A              0
#define         TIM1_PWM_CHANNEL_B              1
#define         TIM1_PWM_BOTH_CHANNELS          3

#define         TIM1_NON_INVERTING_PWM			2
#define         TIM1_INVERTING_PWM				3

#define  		CPU_FREQ 	8000000

#endif
