/******************************************************************************
 *
 * Module: ADC
 *
 * File Name: ADC.h
 *
 * Description: Header file for the ADC driver
 *
 * Author: Ahmed khaled
 *
 *******************************************************************************/

#ifndef ADC_H_
#define ADC_H_

#include"micro_config.h"
#include"common_macros.h"
#include"std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/

#define POLLING 1

#define INTERRUPT 0


/* Extern Public global variables to be used by other modules */

extern volatile uint16 g_adcResult;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * Description :
 * Function responsible for initialize the ADC driver.
 */
void ADC_init(void);


/*
 * Description :
 * Function responsible for read analog data from a certain ADC channel
 * and convert it to digital using the ADC driver.
 */

#if(POLLING==1)
uint16 ADC_readChannel(uint8 channel_num);
#endif

#if(INTERRUPT==1)
void ADC_readChannel(uint8 channel_num);
#endif

#endif /* ADC_H_ */

