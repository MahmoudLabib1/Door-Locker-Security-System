/*
 * AMIT_Final_Project.c
 *
 *  Created on: Mar 17, 2022
 *      Author: MahmoudLabib
 */


#include <avr/delay.h>
#include "../EHAL/LCD/lcd.h"
#include "../../SRC/EHAL/KEYPAD/keypad.h"

void AMIT_Project(void){
  uint8 key ;
	//sei();
	//USART_Init(9600);
	LCD_init();
	LCD_displayString("ENTER The PASS: ");



	while(1){

		        key = KEYPAD_getPressedKey(); /* get the pressed key number */
		      //  LCD_writeCmd(key);
				if((key <= 9) && (key >= 0))
				{

					LCD_intgerToString(key); /*display the pressed keypad switch*/
				}
				else
				{
					LCD_displayCharacter(key);  /*display the pressed keypad switch*/
				}
				_delay_ms(500);  /*Press time*/




	}
}
