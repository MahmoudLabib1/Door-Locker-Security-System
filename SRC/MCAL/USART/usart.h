/*******************************************************************************
 *
 *  Module: USART Module
 *
 *  File Name: usart.h
 *
 *  Description: Header File for AVR_USART Module
 *
 *  Author: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_MCAL_USART_USART_H_
#define SRC_MCAL_USART_USART_H_

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/
#include "../../utils/std_types.h"

/*******************************************************************************
 *                      Definitions and Configuration
 *******************************************************************************/

/*------------------------------------------------------------------------------
 *                                 [CONFIGURE USART]
 * -----------------------------------------------------------------------------*/
/*
 * [Description]:Easy to configure USART Mode just copy Mask of Mode and Past it in Mode selector .
 *
 * [Example]    : #define USART_Mode_Selector   USART_Asynchronous_Mode_msk
 *            like this you configure USART to work with Asynchronous Mode .
 *
 * [Mode_Selector]:
 *  --> [USART_Synchronous_Mode_msk]
 *
 * [DEFUALT]: Asynchronous_Mode
 */
#define USART_Mode_Selector           DESABLE

/*
 * [Description]:Easy to configure USART Interrupt just copy Mask of interrupt and Past it in interrupt selector .
 *
 * [Example]    : #define USART_Interrupt_Selector   USART_TX_Complete_msk
 *
 * [Interrupt Selector]:
 *  --> [USART_TX_Complete_msk]
 *  --> [USART_RX_Complete_msk]
 *  --> [USART_Data_Empty_msk]
 */
#define USART_Interrupt_Selector           DESABLE

/*
 * [Description]:Easy to configure USART Parity just copy Mask of Parity and Past it in Parity selector .
 *
 * [Example]    : #define USART_Parity_Selector   USART_Even_Parity_msk
 *               like this you configure USART to work with Even Parity .
 *
 * [Parity Selector]:
 *  --> [USART_Even_Parity_msk]
 *  --> [USART_Odd_Parity_msk]
 *
 *  [DEFUALT]: Disable parity bit
 */
#define USART_Parity_Selector    DESABLE

/*
 * [Description]:Easy to configure USART stop bit just copy Mask of stop bit and Past it in stop bit selector .
 *
 * [Example]    : #define USART_StopBit_Selector   USART_1_bit_msk
 *               like this you configure USART to work with one bit Stop bit.
 *
 * [Stop Bit Selector]:
 *  --> [USART_2_bit_msk]
 *
 *  [DEFUALT]: 1_bit STOP BIT
 */
#define USART_StopBit_Selector       DESABLE

/*
 * [Description]:Easy to configure USART Character Size just copy Mask of CharSize and Past it in CharSize selector .
 *
 * [Example]    : #define USART_CharSize_Selector   USART_8_bit_CharSize_msk
 *               like this you configure USART to work with 8 bits Character Size .
 *
 * [Character Size Selector]:
 *  --> [USART_6_bit_CharSize_msk]
 *  --> [USART_7_bit_CharSize_msk]
 *  --> [USART_8_bit_CharSize_msk]
 *  --> [USART_9_bit_CharSize_msk]
 *
 *  [DEFUALT]: 5_bit Character Size
 */
#define USART_CharSize_Selector    USART_8_bit_CharSize_msk


/*
 * [Description]:Easy to configure USART Clock Polarity just copy Mask of Clock Polarity and Past it in Clock Polarity selector .
 *
 * [Example]    : #define USART_Clock_Polarity_Selector   USART_TX_Rising_RX_Falling_msk
 *               like this you configure USART to work with Behavior
 *               Transmitted Data Changed with Rising and Received Data Sampled with Falling .
 *
 * [NOTE] ----->: THIS IS ONLY WORK WITH Synchronous MODE .
 *
 * [Clock Polarity Selector]:
 *  --> [USART_TX_Falling_RX_Rising_msk]
 *
 *  [DEFUALT]: TX_Rising_RX_Falling
 */
#define USART_Clock_Polarity_Selector    DESABLE


/*******************************************************************************
 *                         FUNCTIONS AND DECLARATIONS
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
void USART_Init(uint32 Baud_Rate);

/*
 * [FUNCTION NAME]: USART_SendByte
 * [DISCRIPTION]  : This function is responsible to transmit data .
 *
 * [IN]    : Data
 * [OUT]   : void
 * [Args]  : uint8
 * [RUTURN]: Void
 */
void USART_SendByte(const uint8 Data);

/*
 * [FUNCTION NAME]: USART_ReceiveByte
 * [DISCRIPTION]  : This function is responsible to receiving 1 byte data .
 *
 * [IN]    : void
 * [OUT]   : data that received from other device
 * [Args]  : void
 * [RUTURN]: uint16
 */
uint16 USART_ReceiveByte(void);

/*
 * [FUNCTION NAME]: USART_SendString
 * [DISCRIPTION]  : This function is responsible to transmit or send string .
 *
 * [IN]    : string
 * [OUT]   : void
 * [Args]  : pointer to char
 * [RUTURN]: void
 */
void USART_SendString(const uint8 *Str);

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
void USART_ReceiveString(uint8 *Str);

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
void USART_SetCallBack(void (*ptr_to_fun)(void));
#endif /* SRC_MCAL_USART_USART_H_ */
