/*
 * gpio.c
 *
 *  Created on: Feb 16, 2022
 *      Author: MahmoudLabib
 */

#include "gpio.h"
#include "../../utils/common_macros.h"


/*
 * Description:
 * Setup the direction of a certain pin in a certain port  .
 * The direction of pin required input/output .
 * If the port number or pin number are not correct , the function will not handle the request.
 */
void GPIO_setPinDir(uint8 port_num ,uint8 pin_num ,GPIO_PinDirection direction)
{
	if((port_num >= NUM_OF_PORTS) || (pin_num >= NUM_OF_PINS_PER_PORT))
	{
		/* Do nothing */
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(direction==LOGIC_HIGH)
			{
				SET_BIT(DDRA,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRA,pin_num);
			}

			break;
		case PORTB_ID:
			if(direction==LOGIC_HIGH)
			{
				SET_BIT(DDRB,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRB,pin_num);
			}

			break;
		case PORTC_ID:
			if(direction==LOGIC_HIGH)
			{
				SET_BIT(DDRC,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRC,pin_num);
			}

			break;
		case PORTD_ID:
			if(direction==LOGIC_HIGH)
			{
				SET_BIT(DDRD,pin_num);
			}
			else
			{
				CLEAR_BIT(DDRD,pin_num);
			}

			break;
		}
	}
}


/*
 * Description:
 * Read and return the value of pin , should the value be logic high or logic low .
 * If the port number or pin number are not correct , the function can not handle the request.
 */
/*STD_LevelType GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	STD_reg_8bits data;
	data.BITS.BIT0=LOGIC_LOW;
	if((port_num >= NUM_OF_PORTS)||(pin_num >= NUM_OF_PINS_PER_PORT))
	{
		 Do nothing
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(PINA,pin_num))
			{
				data.BITS.BIT0=LOGIC_HIGH;
			}
			else
			{
				data.BITS.BIT0=LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB,pin_num))
			{
				data.BITS.BIT0=LOGIC_HIGH;
			}
			else
			{
				data.BITS.BIT0=LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC,pin_num))
			{
				data.BITS.BIT0=LOGIC_HIGH;
			}
			else
			{
				data.BITS.BIT0=LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND,pin_num))
			{
				data.BITS.BIT0=LOGIC_HIGH;
			}
			else
			{
				data.BITS.BIT0=LOGIC_LOW;
			}
			break;
		}
	}
	return data.BITS.BIT0;
}*/

STD_LevelType GPIO_readPin(uint8 port_num, uint8 pin_num)
{
	uint8 data;
	if((port_num >= NUM_OF_PORTS)||(pin_num >= NUM_OF_PINS_PER_PORT))
	{
		/* Do nothing */
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(BIT_IS_SET(PINA,pin_num))
			{
				data =LOGIC_HIGH;
			}
			else
			{
				data =LOGIC_LOW;
			}
			break;
		case PORTB_ID:
			if(BIT_IS_SET(PINB,pin_num))
			{
				data=LOGIC_HIGH;
			}
			else
			{
				data=LOGIC_LOW;
			}
			break;
		case PORTC_ID:
			if(BIT_IS_SET(PINC,pin_num))
			{
				data=LOGIC_HIGH;
			}
			else
			{
				data=LOGIC_LOW;
			}
			break;
		case PORTD_ID:
			if(BIT_IS_SET(PIND,pin_num))
			{
				data=LOGIC_HIGH;
			}
			else
			{
				data=LOGIC_LOW;
			}
			break;
		}
	}
	return data;
}
/*
 * Description:
 * Write value on the pin , should the value be logic high or logic low .
 * If the port number or pin number are not correct , the function can not handle the request.
 */
void GPIO_writePin(uint8 port_num ,uint8 pin_num , STD_LevelType level)
{
	if((port_num >= NUM_OF_PORTS)||(pin_num >= NUM_OF_PINS_PER_PORT))
	{
		/* Do nothing */
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(level==LOGIC_HIGH){
				SET_BIT(PORTA,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTA,pin_num);
			}
			break;
		case PORTB_ID:
			if(level==LOGIC_HIGH){
				SET_BIT(PORTB,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTB,pin_num);
			}
			break;
		case PORTC_ID:
			if(level==LOGIC_HIGH){
				SET_BIT(PORTC,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			break;
		case PORTD_ID:
			if(level==LOGIC_HIGH){
				SET_BIT(PORTD,pin_num);
			}
			else
			{
				CLEAR_BIT(PORTD,pin_num);
			}
			break;
		}
	}
}



/*
 * Description:
 * Setup the direction of a certain Port.
 * The direction of port required input/output .
 * If the port number is not correct , the function will not handle the request.
 */
void GPIO_setPortDir(uint8 port_num, GPIO_PortDirection direction)
{
	if((port_num >= NUM_OF_PORTS))
	{
		/* Do nothing */
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			if(direction==LOGIC_HIGH)
			{
				DDRA= direction;
			}
			else
			{
				DDRA= direction;
			}

			break;
		case PORTB_ID:
			if(direction==LOGIC_HIGH)
			{
				DDRB= direction;
			}
			else
			{
				DDRB= direction;
			}

			break;
		case PORTC_ID:
			if(direction==LOGIC_HIGH)
			{
				DDRC= direction;
			}
			else
			{
				DDRC= direction;
			}

			break;
		case PORTD_ID:
			if(direction==LOGIC_HIGH)
			{
				DDRD= direction;
			}
			else
			{
				DDRD= direction;
			}

			break;
		}
	}
}



/*
 * Description:
 * Read and return the value of port , should the value will be (0..255) .
 * If the port number or pin number are not correct , the function can not handle the request.
 */
uint8 GPIO_readPort(uint8 port_num)
{
	STD_reg_8bits data;
	if((port_num >= NUM_OF_PORTS))
	{
		/* Do nothing */
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			data.Data=PINA;
			break;
		case PORTB_ID:
			data.Data=PINB;
			break;
		case PORTC_ID:
			data.Data=PINC;
			break;
		case PORTD_ID:
			data.Data=PIND;
			break;
		}
	}
	return data.Data;
}



/*
 * Description:
 * Write value on the Port , should the value be (0..255) .
 * If the port number is not correct , the function can not handle the request.
 */
void GPIO_writePort(uint8 port_num , uint8 value)
{
	if((port_num >= NUM_OF_PORTS))
	{
		/* Do nothing */
	}
	else
	{
		switch(port_num)
		{
		case PORTA_ID:
			PORTA=value;
			break;
		case PORTB_ID:
			PORTB=value;
			break;
		case PORTC_ID:
			PORTC=value;
			break;
		case PORTD_ID:
			PORTD=value;
			break;
		}
	}
}




/*
 * Description:
 * Flip the value of pin , if value of pin High will be LOW and vice versa .
 * If the port number and pin number are not correct , the function can not handle the request.
 */
void GPIO_flibPin(uint8 port_num , uint8 pin_num)
{
	if((port_num >= NUM_OF_PORTS)||(pin_num >= NUM_OF_PINS_PER_PORT))
	{
		/* Do nothing */
	}
	else
	{
		switch(port_num){
		case PORTA_ID:
			TOGGLE_BIT(PORTA,pin_num);
			break;
		case PORTB_ID:
			TOGGLE_BIT(PORTB,pin_num);
			break;
		case PORTC_ID:
			TOGGLE_BIT(PORTC,pin_num);
			break;
		case PORTD_ID:
			TOGGLE_BIT(PORTD,pin_num);
			break;
		}
	}
}




/*
 * Description:
 * Flip the value of port , if value of port High will be LOW and vice versa (0x0F=>0xF0) .
 * If the port number is not correct , the function can not handle the request.
 */
void GPIO_flibPort(uint8 port_num)
{
	if((port_num >= NUM_OF_PORTS))
	{
		/* Do nothing */
	}
	else
	{
		switch(port_num){
		case PORTA_ID:
			PORTA=~PORTA;
			break;
		case PORTB_ID:
			PORTB=~PORTB;
			break;
		case PORTC_ID:
			PORTC=~PORTC;
			break;
		case PORTD_ID:
			PORTD=~PORTD;
			break;
		}
	}
}
