 /******************************************************************************
 *
 * Module: Temperature Sensor
 *
 * File Name: lm35_sensor.h
 *
 * Description: source file for the LM35 Temperature Sensor driver
 *
 * Author: MahmoudLabib
 *
 *******************************************************************************/

#include <util/delay.h> /* For the delay functions */
#include "lm35.h"
#include "../../MCAL/ADC/adc.h"

uint16 g_ADC_var ;
/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */
uint8 LM35_getTemperature(void)
{
	uint8 temp_value = 0;

	/* Read ADC channel where the temperature sensor is connected */
	ADC_ReadChannel(SENSOR_CHANNEL_ID);

	/* Make delay for some time until g_adcResult value is updated with the ADC interrupt */
	_delay_ms(5);

	/* Calculate the temperature from the ADC value*/
	temp_value = (uint8)(((uint32)g_ADC_var*SENSOR_MAX_TEMPERATURE*ADC_REF_VOLT_VALUE)/(ADC_MAXIMUM_VALUE*SENSOR_MAX_VOLT_VALUE));

	return temp_value;
}

