/*******************************************************************************
 *
 * Module: Analog Digital Converter (ADC)
 *
 * File Name: ADC.h
 *
 * Description: Header File ADC Module for AVR
 *
 * Author: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_MCAL_ADC_ADC_H_
#define SRC_MCAL_ADC_ADC_H_

/*******************************************************************************
 *                                  INCLUDES
 *******************************************************************************/
#include "../../utils/std_types.h"

/*******************************************************************************
 *                       Definitions & Configurations
 *******************************************************************************/
#define ADC_Use_Interrupt         DISABLE
#define ADC_Use_Poling            ENABLE
#define ADC_MAXIMUM_VALUE         1023
#define ADC_REF_VOLT_VALUE        5

/*******************************************************************************
 *                             Structures & Types
 *******************************************************************************/


/*------------------------------------------------------------------------------
 * [Enum Name]: ADC_Vref
 * [Description]: It's responsible for Maintaining information about reference
 *                Voltage for ADC
 *-----------------------------------------------------------------------------*/
typedef enum{
	External_AREF,AVCC,Reserved,Internal
}ADC_Vref;



/*------------------------------------------------------------------------------
 * [Enum Name]: ADC_Clock
 * [Description]: It's responsible for Maintaining information about Clk for ADC
 *-----------------------------------------------------------------------------*/
typedef enum{
	Defult,F_CPU_2,F_CPU_4,F_CPU_8,F_CPU_16,F_CPU_32,F_CPU_64,F_CPU_128
}ADC_Clock;



/*------------------------------------------------------------------------------
 * [Struct Name]: ADC_Config
 * [Description]: It's responsible for Maintaining information about
 *                 Vref and Clk for ADC Module
 *-----------------------------------------------------------------------------*/
typedef struct{
	ADC_Vref vref;
	ADC_Clock clk;
}ADC_Config;

/*******************************************************************************
 *                           FUNCITON DECLARATIONS
 *******************************************************************************/



/*------------------------------------------------------------------------------
 *[Function Name]: ADC_Init
 *[Description]: It's responsible for Initialization The registers for ADC Module.
 *[Arg]   : Pointer to structure
 *[IN]    : Vref and Clk
 *[OUT]   : void
 *[Return]: void
 ------------------------------------------------------------------------------*/
void ADC_Init(ADC_Config *config);



/*------------------------------------------------------------------------------
 *[Function Name]: ADC_ReadChannel
 *[Description]: It's responsible for read analog data get to ADC pin from sensor
 *               And convert it to Digital.
 *[Arg]   : integer number (uint8)
 *[IN]    : number of ADC_pin
 *[OUT]   :
 *[Return]: number versus value Read from sensor (uint16)
 ------------------------------------------------------------------------------*/
uint16 ADC_ReadChannel(uint8 Channel_Num);



/*------------------------------------------------------------------------------
 *[Function Name]: ADC_SetCallBack
 *[Description]: It's responsible for calling a specific function when interrupt occur
 *[Arg]   : Pointer to Function
 *[IN]    : Address the function
 *[OUT]   : void
 *[Return]: void
 ------------------------------------------------------------------------------*/
void ADC_SetCallBack(void (*Ptr_To_Fun)(void));
#endif /* SRC_MCAL_ADC_ADC_H_ */
