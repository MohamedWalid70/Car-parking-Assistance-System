#include "STD_Types.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_priv.h"
#include "DIO_config.h"


void DIO_void_init(void){

	DDRA =  DIO_direction_Reg_A;
	DDRB =  DIO_direction_Reg_B;
	DDRC =  DIO_direction_Reg_C;
	DDRD =  DIO_direction_Reg_D;

}


void DIO_voidSetPin(uint8 copy_uint8_pinNO , uint8 copy_uint8_pinVALUE){

	if(copy_uint8_pinNO>=DIO_PORT_A_START && copy_uint8_pinNO<=DIO_PORT_A_END ){

       if(copy_uint8_pinVALUE==DIO_PIN_HIGH){

    	   SET_BIT(PORTA , copy_uint8_pinNO);

       }else{

    	   CLEAR_BIT(PORTA , copy_uint8_pinNO);
       }

	}else if(copy_uint8_pinNO>=DIO_PORT_B_START && copy_uint8_pinNO<=DIO_PORT_B_END ){

		copy_uint8_pinNO = copy_uint8_pinNO - SIZE;

	       if(copy_uint8_pinVALUE==DIO_PIN_HIGH){

	    	   SET_BIT(PORTB , copy_uint8_pinNO);

	       }else{

	    	   CLEAR_BIT(PORTB , copy_uint8_pinNO);
	       }

	}else if(copy_uint8_pinNO>=DIO_PORT_C_START && copy_uint8_pinNO<=DIO_PORT_C_END ){

		copy_uint8_pinNO = copy_uint8_pinNO - (SIZE*2);

	       if(copy_uint8_pinVALUE==DIO_PIN_HIGH){

	    	   SET_BIT(PORTC , copy_uint8_pinNO);

	       }else{

	    	   CLEAR_BIT(PORTC , copy_uint8_pinNO);
	       }

	}else if(copy_uint8_pinNO>=DIO_PORT_D_START && copy_uint8_pinNO<=DIO_PORT_D_END ){

		copy_uint8_pinNO = copy_uint8_pinNO - (SIZE*3);

	       if(copy_uint8_pinVALUE==DIO_PIN_HIGH){

	    	   SET_BIT(PORTD , copy_uint8_pinNO);

	       }else{

	    	   CLEAR_BIT(PORTD , copy_uint8_pinNO);
	       }
	}

}


uint8 DIO_uint8GetPin(uint8 copy_uint8_pinNO){

	uint8 Local_var;

      if(copy_uint8_pinNO>=DIO_PORT_A_START && copy_uint8_pinNO<=DIO_PORT_A_END ){

    	  if(GET_BIT(PINA , copy_uint8_pinNO)==DIO_PIN_HIGH){

    		  Local_var=DIO_PIN_HIGH;

    	  }else{

    		  Local_var=DIO_PIN_LOW;

    	  }

      }else if(copy_uint8_pinNO>=DIO_PORT_B_START && copy_uint8_pinNO<=DIO_PORT_B_END ){

    	  copy_uint8_pinNO = copy_uint8_pinNO - SIZE;

    	  if(GET_BIT(PINB , copy_uint8_pinNO)==DIO_PIN_HIGH){

    		  Local_var=DIO_PIN_HIGH;

    	  }else{

    		  Local_var=DIO_PIN_LOW;

    	  }

      }else if(copy_uint8_pinNO>=DIO_PORT_C_START && copy_uint8_pinNO<=DIO_PORT_C_END ){

    	  copy_uint8_pinNO = copy_uint8_pinNO - (2*SIZE);

    	  if(GET_BIT(PINC , copy_uint8_pinNO)==DIO_PIN_HIGH){

    		  Local_var=DIO_PIN_HIGH;

    	  }else{

    		  Local_var=DIO_PIN_LOW;

    	  }

      }else if(copy_uint8_pinNO>=DIO_PORT_D_START && copy_uint8_pinNO<=DIO_PORT_D_END ){

    	  copy_uint8_pinNO = copy_uint8_pinNO - (3*SIZE);

    	  if(GET_BIT(PIND , copy_uint8_pinNO)==DIO_PIN_HIGH){

    		  Local_var=DIO_PIN_HIGH;

    	  }else{

    		  Local_var=DIO_PIN_LOW;

    	  }

      }

      return Local_var;
}
