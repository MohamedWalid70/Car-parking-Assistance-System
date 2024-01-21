/********************************************/
/*  author: Mohamed Walid                   */
/*  version: V02 							*/
/*  Date:  30 SEP 2022                      */
/********************************************/

#include "BIT_MATH.h"
#include "STD_Types.h"

#include "ULTRASS_int.h"
#include "ULTRASS_config.h"
#include "ULTRASS_priv.h"
#include "DIO_int.h"
#include "TIM1_int.h"

static uint16 objectDistance;

uint16  ULTRASS_uint16GetObjectAwayDistanceICU(){

	DIO_voidSetPin(ULTRASS_TRIGGER_PIN, DIO_PIN_HIGH);
	TIM1_voidSetBusyWait_us(10);
	DIO_voidSetPin(ULTRASS_TRIGGER_PIN, DIO_PIN_LOW);

	objectDistance = TIM1_voidGetUSHighTime();

	if(objectDistance<=ULTRASS_MAX_COUNTER_RANGE){

		objectDistance = ((objectDistance) * ULTRASS_FACTOR);
	}
	else{

		objectDistance = OBJECT_NOT_DETECTED;
	}

	return objectDistance;
}
/*
uint16  ULTRASS_uint16GetObjectAwayDistanceEXT(){

	DIO_voidSetPin(ULTRASS_TRIGGER_PIN, DIO_PIN_HIGH);
	TIM1_voidSetBusyWait_us(15);
	DIO_voidSetPin(ULTRASS_TRIGGER_PIN, DIO_PIN_LOW);

}

*/
