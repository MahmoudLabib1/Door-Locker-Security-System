/*
 * Module: Input Capture Unit
 *
 * File Name: icu.c
 *
 * Description: Source file for AVR ICU driver
 */

#include "icu.h"
#include <avr/io.h>
#include <avr/interrupt.h>
static volatile void (*g_CallBack_ptr)(void)= NULL_PTR;

/*******************************************************************************
 *                                ISR
 *******************************************************************************/
ISR(TIMER1_CAPT_vect){

	/* Call the Call Back function in the application after the edge is detected */
	if(g_CallBack_ptr != NULL_PTR){
		/* Call Back Notification */
		/* another method to call the function using pointer to function g_callBackPtr(); */
		(g_CallBack_ptr)();
	}
}

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/

/*
 * Description: Function to Initialize The ICU module
 * 1- Set the required clk .
 * 2- Set the required edge detection .
 * 3- Enable the ICU Interrupt .
 * 4- Initialize Timer1 Registers .
 *
 */

void ICU_Init(const ICU_ConfigType *config_Ptr){

	/* Configure ICP1/(PD6) as Input pin direction */
	DDRD &=~(1<<PD6);

	/* always Timer1 operates in normal mode ( default mode )
	 * but need to set FOC1A/FOC1B pins in non-pwm mode
	 * */
	TCCR1A = (1<<FOC1B) | (1<<FOC1A);

	/* configure the required edge detection */
	TCCR1B = (TCCR1B & 0xBF)| ((config_Ptr->edge) << 6 );

	/* configure the required Clock */
	TCCR1B = (TCCR1B & 0xF8)| (config_Ptr->clk);

	/* Initiate Timer1 value (TCNT1 register) */
	TCNT1=0;

	/* Initiate ICR value */
	ICR1=0;

	/* Enable ICU interrupt
	 * Will generate an interrupt when edge is detected on ICP1/PD6 pin
	 */
	TIMSK |=(1<< TICIE1);

}


/*
 * Description: Function take Address fun (void function(void)) To set callback fun
 *              It used to Make Lower Layer like "MCAL"  call function at Upper layer like "OS" .
 *              CallBack Fun Usually is function with no arguments and no return value .
 *
 */
void ICU_SetCallBack(void(*Ptr_To_Fun)(void)){

	/* save the address of the call back function in a static global variable */
	g_CallBack_ptr = Ptr_To_Fun;
}


/*
 * Description: Function To get the Timer1 Value when the Input is capture
 *              The Value is loaded or stored at ICR1 register (16 bit register) .
 *
 */

uint16 ICU_GetInputCaptureValue(void){

	/* return the value of ICR1 register */
	return (uint16)ICR1;
}


/*
 * Description: Function To set the required edge detection  (Rising or Falling)
 */
void ICU_SetEdgeDetectionType(const ICU_EdgeType edge){

	/* Set the required edge detection */
	TCCR1B = (TCCR1B & 0xBF)| ((edge) << 6 );
}


/*
 * Description: Function to clear the Timer1 value to start count from ZERO
 */
void ICU_ClearTimerValue(void){

	/* Clear Timer1 value to make it count from Zero */
	TCNT1 =0;
}


/*
 * Description: Function To Disable Timer1 to stop the ICU Driver or module
 */
void ICU_DeInit(void){

	/* Clear All Timer1 Registers
	 * Will return Timer1 registers for default state
	 */

	TCCR1A =0;
	TCCR1B =0;
	TCNT1=0;
	ICR1=0;

	/* Disable the Input Capture interrupt */
	TIMSK &= ~(1<<TICIE1);

}










