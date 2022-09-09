/*******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: external keypad
 *
 * Author: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_EHAL_KEYPAD_KEYPAD_H_
#define SRC_EHAL_KEYPAD_KEYPAD_H_

#include "../../utils/std_types.h"

/*==============================================================================
 *                             Definitions
 *==============================================================================*/
/* Keypad configurations number of rows and columns */
#define KEYPAD_NUM_OF_ROWS           4
#define KEYPAD_NUM_OF_COLUMNS        4

/* Keypad Port Configurations */
#define KEYPAD_PORT_ID               PORTB_ID
#define KEYPAD_FIRST_ROW_PIN_ID      PIN0_ID
#define KEYPAD_FIRST_COLUMN_PIN_ID   PIN4_ID

/* Keypad Button configurations */
#define KEYPAD_BUTTON_PRESSED        LOGIC_LOW
#define KEYPAD_BUTTON_RELEASED       LOGIC_HIGH

/*==============================================================================
 *                         Functions Prototypes
 *==============================================================================*/

/*
 * Description:
 * Get the keypad pressed button
 * */
uint8 KEYPAD_getPressedKey(void);

#endif /* SRC_EHAL_KEYPAD_KEYPAD_H_ */
