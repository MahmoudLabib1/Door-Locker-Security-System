/*******************************************************************************
 *
 * Module: GPIO prototypes
 *
 * File Name: gpio.h
 *
 * Description: Header File For AVR GPIO
 *
 * Author: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_MCAL_GPIO_GPIO_H_
#define SRC_MCAL_GPIO_GPIO_H_

#include "../../utils/std_types.h"
/*==============================================================================*/
/*                         Hardware Definitions                                 */
/*==============================================================================*/

#define DDRA     (*((volatile uint8*)0x3A))
#define DDRB     (*((volatile uint8*)0x37))
#define DDRC     ((*(volatile uint8*)0x34))
#define DDRD     (*((volatile uint8*)0x31))

#define PORTA    (*((volatile uint8*)0x3B))
#define PORTB    (*((volatile uint8*)0x38))
#define PORTC    (*((volatile uint8*)0x35))
#define PORTD    (*((volatile uint8*)0x32))

#define PINA     (*((const volatile uint8*)0x39))
#define PINB     (*((const volatile uint8*)0x36))
#define PINC     (*((const volatile uint8*)0x33))
#define PIND     (*((const volatile uint8*)0x30))

/*==============================================================================*/
/*                              Definitions                                     */
/*==============================================================================*/

#define NUM_OF_PORTS              4
#define NUM_OF_PINS_PER_PORT      8

#define PORTA_ID                  0
#define PORTB_ID                  1
#define PORTC_ID                  2
#define PORTD_ID                  3

#define PIN0_ID                   0
#define PIN1_ID                   1
#define PIN2_ID                   2
#define PIN3_ID                   3
#define PIN4_ID                   4
#define PIN5_ID                   5
#define PIN6_ID                   6
#define PIN7_ID                   7

/*==============================================================================*/
/*                            Types Declaration                                 */
/*==============================================================================*/

typedef enum
{
	INPUT_PIN,OUTPUT_PIN
}GPIO_PinDirection;

typedef enum
{
	INPUT_PORT,OUTPUT_PORT =0xFF
}GPIO_PortDirection;

/*==============================================================================*/
/*                            Functions Prototypes                              */
/*==============================================================================*/


/*
 * Description:
 * Setup the direction of a certain pin in a certain port  .
 * The direction of pin required input/output .
 * If the port number or pin number are not correct , the function will not handle the request.
 */
void GPIO_setPinDir(uint8 port_num ,uint8 pin_num ,GPIO_PinDirection direction);


/*
 * Description:
 * Read and return the value of pin , should the value be logic high or logic low .
 * If the port number or pin number are not correct , the function can not handle the request.
 */
STD_LevelType GPIO_readPin(uint8 port_num, uint8 pin_num);

/*
 * Description:
 * Write value on the pin , should the value be logic high or logic low .
 * If the port number or pin number are not correct , the function can not handle the request.
 */
void GPIO_writePin(uint8 port_num ,uint8 pin_num , STD_LevelType level);

/*
 * Description:
 * Setup the direction of a certain Port.
 * The direction of port required input/output .
 * If the port number is not correct , the function will not handle the request.
 */
void GPIO_setPortDir(uint8 port_num, GPIO_PortDirection direction);

/*
 * Description:
 * Read and return the value of port , should the value will be (0..255) .
 * If the port number or pin number are not correct , the function can not handle the request.
 */
uint8 GPIO_readPort(uint8 port_num);

/*
 * Description:
 * Write value on the Port , should the value be (0..255) .
 * If the port number is not correct , the function can not handle the request.
 */
void GPIO_writePort(uint8 port_num , uint8 value);

/*
 * Description:
 * Flip the value of pin , if value of pin High will be LOW and vice versa .
 * If the port number and pin number are not correct , the function can not handle the request.
 */
void GPIO_flibPin(uint8 port_num , uint8 pin_num);

/*
 * Description:
 * Flip the value of port , if value of port High will be LOW and vice versa (0x0F=>0xF0) .
 * If the port number is not correct , the function can not handle the request.
 */
void GPIO_flibPort(uint8 port_num);

#endif /* SRC_MCAL_GPIO_GPIO_H_ */
