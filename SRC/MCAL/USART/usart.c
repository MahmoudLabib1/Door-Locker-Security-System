/*******************************************************************************
 *
 * Module: USART Modules
 *
 * File Name: usart.c
 *
 * Description: Source File For AVR_USART Module
 *
 * Author: Mahmoud_Labib
 *
 *******************************************************************************/

#include <avr/io.h>
#include <avr/interrupt.h>
#include "usart.h"
#include "../../utils/common_macros.h"


/*******************************************************************************
 *                               Global Variable
 *******************************************************************************/
/*
 * [Description]: This Pointer To Function Save the Address Of The function
 *                That will call when Event occur .
 */
static volatile void(*g_USART_Ptr_To_Fun)(void)= NULL_PTR;


/*******************************************************************************
 *                                 USART_ISR
 *******************************************************************************/

/*
 * [Description]: Here The ISR's For AVR_USART Module
 */
ISR( USART_TXC_vect){
	 /* Call the Call Back function in the application after the Event is Occur */

		if(g_USART_Ptr_To_Fun != NULL_PTR){
			/* This is called --> Call Back Notification */
			/* another method to call the function using pointer to function g_Ptr_To_Fun_0(); */
			(g_USART_Ptr_To_Fun)();
		}
}

ISR(USART_RXC_vect){
	 /* Call the Call Back function in the application after the Event is Occur */

			if(g_USART_Ptr_To_Fun != NULL_PTR){
				/* This is called --> Call Back Notification */
				/* another method to call the function using pointer to function g_Ptr_To_Fun_0(); */
				(g_USART_Ptr_To_Fun)();
			}
}

ISR(USART_UDRE_vect){
	 /* Call the Call Back function in the application after the Event is Occur */

			if(g_USART_Ptr_To_Fun != NULL_PTR){
				/* This is called --> Call Back Notification */
				/* another method to call the function using pointer to function g_Ptr_To_Fun_0(); */
				(g_USART_Ptr_To_Fun)();
			}
}



/*******************************************************************************
 *                                      MASK's
 *******************************************************************************/

/*------------------------------------------------------------------------------
 *                               [Masks For USART Mode]
 * -----------------------------------------------------------------------------*/

#define USART_Synchronous_Mode_msk                           0x40

/*------------------------------------------------------------------------------
 *                          [Masks For USART Interrupts]
 * -----------------------------------------------------------------------------*/
#define USART_TX_Complete_msk                                0x40
#define USART_RX_Complete_msk                                0x80
#define USART_Data_Empty_msk                                 0x20

/*------------------------------------------------------------------------------
 *                          [Masks For USART Parity Mode]
 * -----------------------------------------------------------------------------*/
#define USART_Parity_Clr_msk                                 0xCF
#define USART_Even_Parity_msk                                0x20
#define USART_Odd_Parity_msk                                 0x30

/*------------------------------------------------------------------------------
 *                          [Masks For USART Stop Bit]
 * -----------------------------------------------------------------------------*/
#define USART_2_bit_msk                                      0x08

/*------------------------------------------------------------------------------
 *                       [Masks For USART Character Size]
 * -----------------------------------------------------------------------------*/
#define USART_CharSize_clr_msk                               0xF9
#define USART_6_bit_CharSize_msk                             0X02
#define USART_7_bit_CharSize_msk                             0x04
#define USART_8_bit_CharSize_msk                             0x06

#define USART_9_bit_CharSize_Reg1_msk                        0x06
#define USART_9_bit_CharSize_Reg2_msk                        0x04

/*------------------------------------------------------------------------------
 *                       [Masks For USART Clock Polarity]
 * -----------------------------------------------------------------------------*/
#define USART_TX_Falling_RX_Rising_msk                       0x01



/*******************************************************************************
 *                            FUNCTION's Initialization
 *******************************************************************************/

/*
 * [FUNCTION NAME]: USART_Init
 * [DISCRIPTION]  : This function is responsible to initialization USART Module
 *                  Depend on Configuration .
 * [IN]    : Baud Rate
 * [OUT]   : void
 * [Args]  : uint32
 * [RUTURN]: Void
 */
void USART_Init(uint32 Baud_Rate){
	uint16 ubrr_value = 0;
	/* U2X = 1 for double transmission speed */
	UCSRA = (1<<U2X);

	/************************** UCSRB Description **************************
		 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
		 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
		 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
		 * RXEN  = 1 Receiver Enable
		 * TXEN  = 1 Transmitter Enable
		 * UCSZ2 = 0 For 8-bit data mode
		 * RXB8 & TXB8 not used for 8-bit data mode
		 ***********************************************************************/
	SET_BIT(UCSRB,RXEN);
	SET_BIT(UCSRB,TXEN);
#if USART_Interrupt_Selector == USART_TX_Complete_msk
	SET_BIT(UCSRB,TXCIE);

#elif USART_Interrupt_Selector == USART_RX_Complete_msk
	SET_BIT(UCSRB,RXCIE);

#elif USART_Interrupt_Selector == USART_Data_Empty_msk
	SET_BIT(UCSRB,UDRIE);
#endif


	/************************** UCSRC Description **************************
		 * URSEL   = 1 The URSEL must be one when writing the UCSRC
		 * UMSEL   = 0 Asynchronous Operation
		 * UPM1:0  = 00 Disable parity bit
		 * USBS    = 0 One stop bit
		 * UCSZ1:0 = 11 For 8-bit data mode
		 * UCPOL   = 0 Used with the Synchronous operation only
		 ***********************************************************************/
	SET_BIT(UCSRC,URSEL);

#if USART_Mode_Selector == USART_Synchronous_Mode_msk
	SET_BIT(UCSRC,USART_Synchronous_Mode_msk);
#endif

#if USART_Parity_Selector == USART_Even_Parity_msk
	SET_BIT(UCSRC,USART_Even_Parity_msk);
#elif USART_Parity_Selector == USART_Odd_Parity_msk
	SET_BIT(UCSRC,USART_Odd_Parity_msk);
#endif

#if USART_StopBit_Selector == USART_2_bit_msk
	SET_BIT(UCSRC,USART_2_bit_msk);
#endif

#if USART_CharSize_Selector == USART_6_bit_CharSize_msk
	SET_BIT(UCSRC,USART_6_bit_CharSize_msk);
#elif USART_CharSize_Selector == USART_7_bit_CharSize_msk
	SET_BIT(UCSRC,USART_7_bit_CharSize_msk);
#elif USART_CharSize_Selector == USART_8_bit_CharSize_msk
	//SET_BIT(UCSRC,USART_8_bit_CharSize_msk);
	SET_BIT(UCSRC,UCSZ0);
	SET_BIT(UCSRC,UCSZ1);
#elif USART_CharSize_Selector == USART_9_bit_CharSize_msk
	SET_BIT(UCSRC,USART_9_bit_CharSize_Reg1_msk);
	SET_BIT(UCSRB,USART_9_bit_CharSize_Reg2_msk);
#endif

#if USART_Clock_Polarity_Selector == USART_TX_Falling_RX_Rising_msk
	SET_BIT(UCSRC,USART_TX_Falling_RX_Rising_msk);
#endif


	/* Calculate the UBRR register value */
		ubrr_value = (uint16)(((F_CPU / (Baud_Rate * 8UL))) - 1);

		/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
		UBRRH = ubrr_value>>8;
		UBRRL = ubrr_value;
}



/*
 * [FUNCTION NAME]: USART_SendByte
 * [DISCRIPTION]  : This function is responsible to transmit data .
 *
 * [IN]    : Data
 * [OUT]   : void
 * [Args]  : uint8
 * [RUTURN]: Void
 */
void USART_SendByte(const uint8 Data){
	/*
		 * UDRE flag is set when the Tx buffer (UDR) is empty and ready for
		 * transmitting a new byte so wait until this flag is set to one
		 */
		while(BIT_IS_CLEAR(UCSRA,UDRE)){}

		/*
		 * Put the required data in the UDR register and it also clear the UDRE flag as
		 * the UDR register is not empty now
		 */
		UDR = Data;

		/************************* Another Method *************************
		UDR = data;
		while(BIT_IS_CLEAR(UCSRA,TXC)){} // Wait until the transmission is complete TXC = 1
		SET_BIT(UCSRA,TXC); // Clear the TXC flag
		*******************************************************************/
}


/*
 * [FUNCTION NAME]: USART_ReceiveByte
 * [DISCRIPTION]  : This function is responsible to receiving 1 byte data .
 *
 * [IN]    : void
 * [OUT]   : data that received from other device
 * [Args]  : void
 * [RUTURN]: uint16
 */
uint16 USART_ReceiveByte(void){

	/* RXC flag is set when the UART receive data so wait until this flag is set to one */
		while(BIT_IS_CLEAR(UCSRA,RXC)){}

		/*
		 * Read the received data from the Rx buffer (UDR)
		 * The RXC flag will be cleared after read the data
		 */
	    return UDR;
}


/*
 * [FUNCTION NAME]: USART_SendString
 * [DISCRIPTION]  : This function is responsible to transmit or send string .
 *
 * [IN]    : string
 * [OUT]   : void
 * [Args]  : pointer to char
 * [RUTURN]: void
 */
void USART_SendString(const uint8 *Str){

	     uint8 i = 0;

		/* Send the whole string */
		while(Str[i] != '\0')
		{
			USART_SendByte(Str[i]);
			i++;
		}
		/************************* Another Method *************************
		while(*Str != '\0')
		{
			UART_sendByte(*Str);
			Str++;
		}

		*******************************************************************/
}


/*
 * [FUNCTION NAME]: USART_ReceiveString
 * [DISCRIPTION]  : This function is responsible to receiving string and remove '#'
 *                  Receive the required string until the '#' symbol .
 *
 * [IN]    : String
 * [OUT]   : void
 * [Args]  : pointer to char
 * [RUTURN]: void
 */
void USART_ReceiveString(uint8 *Str){

	    uint8 i = 0;

		/* Receive the first byte */
		Str[i] = USART_ReceiveByte();

		/* Receive the whole string until the '#' */
		while(Str[i] != '#')
		{
			i++;
			Str[i] = USART_ReceiveByte();
		}

		/* After receiving the whole string plus the '#', replace the '#' with '\0' */
		Str[i] = '\0';
}


/*
 * [FUNCTION NAME]: USART_SetCallBack
 * [DISCRIPTION]  : This function is responsible call the required function when
 *                  The even (Interrupt) occur .
 *
 * [IN]    : take address function required to call
 * [OUT]   : void
 * [Args]  : pointer to fun
 * [RUTURN]: void
 */
void USART_SetCallBack(void(*ptr_to_fun)(void)){

	g_USART_Ptr_To_Fun = ptr_to_fun ;
}
