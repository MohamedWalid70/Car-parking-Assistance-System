/********************************************/
/*  author: Mohamed Walid                   */
/*  version: V02 							*/
/*  Date: 9 OCT 2022                      	*/
/********************************************/

#include "STD_Types.h"
#include "BIT_MATH.h"

#include "DIO_int.h"
#include "TIM0_int.h"
#include "LCD_int.h"
#include "ULTRASS_int.h"
#include "TIM1_int.h"

int main() {

	DIO_void_init();
	LCD_void_init();
	TIM1_voidInit();
	TIM0_void_init();

	uint16 distance, pReading = 0, ppReading = 0;
	LCD_void_WRITE_STRING("Distance = ");
	LCD_void_GoToRowColmun(1, 14);
	LCD_void_WRITE_STRING("CM");

	while (1) {

		distance = ULTRASS_uint16GetObjectAwayDistanceICU();
		if (distance != OBJECT_NOT_DETECTED) {
			LCD_void_GoToRowColmun(1, 11);
			if (ppReading != 0) {

				if ((distance == 89) && ((distance - pReading) > 40)
						&& ((distance - ppReading) > 40)) {
					distance = pReading;
				}
			}
			LCD_voidWriteNumber(distance);

			if (distance <= 80) {

				LCD_void_GoToRowColmun(2, 7);
				LCD_void_WRITE_CHARACTER(255);
				LCD_void_WRITE_CHARACTER(255);
				if (distance <= 60) {

					LCD_void_GoToRowColmun(2, 6);
					LCD_void_WRITE_CHARACTER(255);
					LCD_void_GoToRowColmun(2, 9);
					LCD_void_WRITE_CHARACTER(255);

					if (distance <= 40) {

						LCD_void_GoToRowColmun(2, 5);
						LCD_void_WRITE_CHARACTER(255);
						LCD_void_GoToRowColmun(2, 10);
						LCD_void_WRITE_CHARACTER(255);

						if (distance > 20) {

							DIO_voidSetPin(DIO_PIN_NO_1, DIO_PIN_HIGH);
							TIM0_voidSetBusyWait(50);
							DIO_voidSetPin(DIO_PIN_NO_1, DIO_PIN_LOW);
							TIM0_voidSetBusyWait(50);
						}

						if (distance <= 20) {

							LCD_void_GoToRowColmun(2, 0);
							for (uint8 i = 0; i < 5; i++) {
								LCD_void_WRITE_CHARACTER(255);
							}
							LCD_void_GoToRowColmun(2, 11);
							for (uint8 i = 0; i < 5; i++) {
								LCD_void_WRITE_CHARACTER(255);
							}
							DIO_voidSetPin(DIO_PIN_NO_1, DIO_PIN_HIGH);
						}

					}
				}
			} else {

				LCD_void_GoToRowColmun(2, 0);
				for (uint8 i = 0; i < 16; i++) {
					LCD_void_WRITE_CHARACTER(16);
				}
				DIO_voidSetPin(DIO_PIN_NO_1, DIO_PIN_LOW);

			}
			TIM0_voidSetBusyWait(250);
			ppReading = pReading;		// taking the second previous reading
			pReading = distance;			// taking the first previous reading
			LCD_void_GoToRowColmun(1, 11);
			LCD_void_WRITE_CHARACTER(16);
			LCD_void_WRITE_CHARACTER(16);
			LCD_void_WRITE_CHARACTER(16);	// clearing the screen digit places

		}

	}

	return 0;
}

