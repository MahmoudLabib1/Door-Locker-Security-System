/*******************************************************************************
 *
 * Module: Input Capture unit
 *
 * File Name: icu.c
 *
 * Description: Header file for ICU
 *
 * Author: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_MCAL_ICU_ICU_H_
#define SRC_MCAL_ICU_ICU_H_

#include "../../utils/std_types.h"

/*******************************************************************************
 *                                  Types
 *******************************************************************************/
typedef enum
{
	FALLING_Edge,RISING_Edge
}ICU_EdgeType;

typedef enum
{
	NO_Clk,F_CPU_Clk,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_CLock;

typedef struct
{
	ICU_EdgeType edge ;
	ICU_CLock clk ;
}ICU_ConfigType;

/*******************************************************************************
 *                            Function Prototypes
 *******************************************************************************/

/*
 * Description: Function to Initialize The ICU module
 * 1- Set the required clk .
 * 2- Set the required edge detection .
 * 3- Enable the ICU Interrupt .
 * 4- Initialize Timer1 Registers .
 *
 */

void ICU_Init(const ICU_ConfigType *config_Ptr);

/*
 * Description: Function take Address fun (void function(void)) To set callback fun
 *              It used to Make Lower Layer like "MCAL"  call function at Upper layer like "OS" .
 *              CallBack Fun Usually is function with no arguments and no return value .
 *
 */
void ICU_SetCallBack(void(*Ptr_To_Fun)(void));

/*
 * Description: Function To get the Timer1 Value when the Input is capture
 *              The Value is loaded or stored at ICR1 register (16 bit register) .
 *
 */

uint16 ICU_GetInputCaptureValue(void);

/*
 * Description: Function To set the required edge detection  (Rising or Falling)
 */
void ICU_SetEdgeDetectionType(const ICU_EdgeType edge);

/*
 * Description: Function to clear the Timer1 value to start count from ZERO
 */
void ICU_ClearTimerValue(void);

/*
 * Description: Function To Disable Timer1 to stop the ICU Driver or module
 */
void ICU_DeInit(void);


#endif /* SRC_MCAL_ICU_ICU_H_ */
