 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: header file for the LM35 Temperature Sensor driver
 *
 * Author: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_EHAL_TEMP_SENSOR_LM35_H_
#define SRC_EHAL_TEMP_SENSOR_LM35_H_

#include "../../utils/std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define SENSOR_CHANNEL_ID         2
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void);


#endif /* SRC_EHAL_TEMP_SENSOR_LM35_H_ */
