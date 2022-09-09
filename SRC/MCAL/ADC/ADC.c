/*
 * Module: Analog Digital Converter (ADC)
 *
 * File Name: ADC.c
 *
 * Description: Source File ADC Module for AVR
 *
 * Author: Mahmoud_Labib
 *
 */

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/
#include <avr/io.h>                        /* To use the ADC Registers */
#include <avr/interrupt.h>                 /* For ADC ISR */
#include "ADC.h"
#include "../../utils/common_macros.h"     /* To use the macros like SET_BIT */

/*******************************************************************************
 *                               Global Variable
 *******************************************************************************/
static volatile void(*g_ADC_CallBack_Fun)(void)= NULL_PTR;
extern volatile uint16 g_ADC_var = 0;
/*******************************************************************************
 *                                   ISR
 *******************************************************************************/
ISR(ADC_vect){
	 /* Save data from ADC data register in Extern global variable */
	g_ADC_var =ADC;
	 /* Call the Call Back function in the application after the edge is detected */
	if(g_ADC_CallBack_Fun != NULL_PTR){

		/* This is called --> Call Back Notification */
		/* another method to call the function using pointer to function g_callBackPtr(); */
		(g_ADC_CallBack_Fun)();
	}
}



/*******************************************************************************
 *                            Function Declaration
 *******************************************************************************/


/*------------------------------------------------------------------------------
 *[Function Name]: ADC_Init
 *[Description]: It's responsible for Initialization The registers for ADC Module.
 *[Arg]   : Pointer to structure
 *[IN]    : Vref and Clk
 *[OUT]   : void
 *[Return]: void
 ------------------------------------------------------------------------------*/
void ADC_Init(ADC_Config *config){
	/* ADMUX Register Bits Description:
     * REFS1:0 = configured by user
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX |= (config->vref << 6);

	/* ADCSRA Register Bits Description:
	 * ADEN    = 1 Enable ADC
	 * ADIE    = 0 Disable ADC Interrupt
	 * ADATE   = 0 Disable Auto Trigger
	 * ADPS2:0 = configured by user  --> ADC must operate in range 50-200Khz
	 */
	ADCSRA |= (config->clk);
	ADCSRA |= (1<<ADEN);

	/* SFIOR Register Bits Description:
	 * ADTS7:5 = 000 free running mode
	 *         = 001 Analog comparator
	 *         = 010 External Interrupt Request 0
	 *         = 011 Timer0 compare match
	 *         = 100 Timer0 Overflow
	 *         = 101 Timer1 compare match B
	 *         = 110 Timer1 Overflow
	 *         = 111 Timer1 Capture Event
	 */
	SFIOR = 0x00;  /* if you want use SFIOR must enable 'ADATE bit' from ADCSRA register */
}




/*------------------------------------------------------------------------------
 *[Function Name]: ADC_ReadChannel
 *[Description]: It's responsible for read analog data get to ADC pin from sensor
 *               And convert it to Digital.
 *[Arg]   : integer number (uint8)
 *[IN]    : number of ADC_pin
 *[OUT]   :
 *[Return]: number versus value Read from sensor (uint16)
 ------------------------------------------------------------------------------*/
uint16 ADC_ReadChannel(uint8 Channel_Num){
	Channel_Num &=0x07;     /* Input channel number must be from 0 --> 7 */

	/* ADMUX Register Bits Description:
     * REFS1:0 = configured by user
	 * ADLAR   = 0 right adjusted
	 * MUX4:0  = 00000 to choose channel 0 as initialization
	 */
	ADMUX &= 0xE0;         /* Clear first 5 bits in the ADMUX before set the required channel */
	ADMUX |= (Channel_Num);/* Set the required channel */

#if ADC_Use_Interrupt == ENABLE
	ADCSRA |= (1<<ADIE);   /* Enable ADC Interrupt */
#endif
	ADCSRA |= (1<<ADSC);   /* Start Conversion */

#if ADC_Use_Poling == ENABLE
	ADCSRA &= ~(1<<ADIE);               /* To be sure that ADC Interrupt Disable */
	while(BIT_IS_CLEAR(ADCSRA,ADIF)){}  /* I can wait The conversion to complete (just take 5 clk cycles) */
	  return ADC;                       /* This is ADC Data Register */
#endif
}



/*------------------------------------------------------------------------------
 *[Function Name]: ADC_SetCallBack
 *[Description]: It's responsible for calling a specific function when interrupt occur
 *[Arg]   : Pointer to Function
 *[IN]    : Address the function
 *[OUT]   : void
 *[Return]: void
 ------------------------------------------------------------------------------*/
void ADC_SetCallBack(void (*Ptr_To_Fun)(void)){
	g_ADC_CallBack_Fun = Ptr_To_Fun;
}
