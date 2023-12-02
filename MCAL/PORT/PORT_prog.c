#include "STD_TYPES.h"         /*ORDER OF FILES INCLUDED IS A MUST*/
#include "PORT_prv.h"
#include "PORT_cfg.h"
#include "PORT_interface.h"
#include "PORT_reg.h"			/* will include register definition at initialization but DIO_reg.h will be used to change it during run time*/


void PORT_voidinit(void)
{
	DDRA = PORTA_DIR;	
	DDRB = PORTB_DIR;	
	DDRC = PORTC_DIR;	
	DDRD = PORTD_DIR;	
	
	
	PORTA = PORTA_INIT_VAL;
	PORTA = PORTB_INIT_VAL;
    PORTA = PORTC_INIT_VAL;
    PORTA = PORTD_INIT_VAL;
}