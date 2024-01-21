#ifndef  DIO_PRIV_H
#define  DIO_PRIV_H


#define DIO_PIN_OUTPUT  1
#define DIO_PIN_INPUT   0


#define DDRA  (*((volatile uint8 *) 0x3A))
#define DDRB  (*((volatile uint8 *) 0x37))
#define DDRC  (*((volatile uint8 *) 0x34))
#define DDRD  (*((volatile uint8 *) 0x31))

#define PORTA (*((volatile uint8 *) 0x3B))
#define PORTB (*((volatile uint8 *) 0x38))
#define PORTC (*((volatile uint8 *) 0x35))
#define PORTD (*((volatile uint8 *) 0x32))

#define PINA  (*((volatile uint8 *) 0x39))
#define PINB  (*((volatile uint8 *) 0x36))
#define PINC  (*((volatile uint8 *) 0x33))
#define PIND  (*((volatile uint8 *) 0x30))

#define  DIO_direction_Reg_A    CONC_BIT(DIO_DIR_PIN_NO_7 ,DIO_DIR_PIN_NO_6 ,DIO_DIR_PIN_NO_5 ,DIO_DIR_PIN_NO_4 ,DIO_DIR_PIN_NO_3 ,DIO_DIR_PIN_NO_2 ,DIO_DIR_PIN_NO_1 ,DIO_DIR_PIN_NO_0)
#define  DIO_direction_Reg_B    CONC_BIT(DIO_DIR_PIN_NO_15 ,DIO_DIR_PIN_NO_14 ,DIO_DIR_PIN_NO_13 ,DIO_DIR_PIN_NO_12 ,DIO_DIR_PIN_NO_11 ,DIO_DIR_PIN_NO_10 ,DIO_DIR_PIN_NO_9 ,DIO_DIR_PIN_NO_8)
#define  DIO_direction_Reg_C    CONC_BIT(DIO_DIR_PIN_NO_23 ,DIO_DIR_PIN_NO_22 ,DIO_DIR_PIN_NO_21 ,DIO_DIR_PIN_NO_20 ,DIO_DIR_PIN_NO_19 ,DIO_DIR_PIN_NO_18 ,DIO_DIR_PIN_NO_17 ,DIO_DIR_PIN_NO_16)
#define  DIO_direction_Reg_D    CONC_BIT(DIO_DIR_PIN_NO_31 ,DIO_DIR_PIN_NO_30 ,DIO_DIR_PIN_NO_29 ,DIO_DIR_PIN_NO_28 ,DIO_DIR_PIN_NO_27 ,DIO_DIR_PIN_NO_26 ,DIO_DIR_PIN_NO_25 ,DIO_DIR_PIN_NO_24)

#define SIZE      8

#define DIO_PORT_A_START   0
#define DIO_PORT_A_END     7

#define DIO_PORT_B_START   8
#define DIO_PORT_B_END     15

#define DIO_PORT_C_START   16
#define DIO_PORT_C_END     23

#define DIO_PORT_D_START   24
#define DIO_PORT_D_END     31


#endif
