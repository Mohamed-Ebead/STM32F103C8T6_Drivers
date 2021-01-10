/*
 * ADC_config.h
 *
 *  Created on: Aug 21, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_



/** ADC Configuration */

/*--------------------------------------------------------------------------------*/
/** @ADC_CHANNELS
 *  18 channels : 16 external and 2 internal
 *  OPTIONS :
 *  		ADC_CHANNEL_0 >> ADC_CHANNEL_7 for GPIOA input pins PA0 >> PA7
 *  		ADC_CHANNEL_8 ,  ADC_CHANNEL_9 for GPIOB input pins PB0 , PB1
 */

#define ADC_CHANNEL_NUM    ADC_CHANNEL_8      // PB0
/*--------------------------------------------------------------------------------*/

/** ADC SAMPLE TIME */
/**
 *  OPTIONS :    ADC_SAMPLE_1_CYCLES
 *  			 ADC_SAMPLE_7_CYCLES
 *               ADC_SAMPLE_13_CYCLES
 *               ADC_SAMPLE_28_CYCLES
 *               ADC_SAMPLE_41_CYCLES
 *               ADC_SAMPLE_55_CYCLES
 *               ADC_SAMPLE_71_CYCLES
 *               ADC_SAMPLE_239_CYCLES
 *  a 0.5 cycle is subtracted from each MACRO to simplify the fraction part
 *  it means for example ADC_SAMPLE_1_CYCLES means 1.5 cycles , and so on ...  */
#define ADC_SAMPLE_TIME         ADC_SAMPLE_28_CYCLES     // 1.5 CYCLES
/*--------------------------------------------------------------------------------*/

/** ADC DATA ALIGNMENT */
/**
 * OPTIONS : ADC_LEFT_ALIGNMENT
 * 			 ADC_RIGHT_ALIGNMENT
 */
#define ADC_ALIGNMENT       ADC_RIGHT_ALIGNMENT
/*--------------------------------------------------------------------------------*/
/** ADC CONVERSION MODE */
/**
 * 	OPTIONS :  ADC_CONVMODE_CONTINOUS
			   ADC_CONVMODE_SCAN
			   ADC_CONVMODE_SINGLE
*/
#define ADC_CONVERSION_MODE 	ADC_CONVMODE_SINGLE

/*--------------------------------------------------------------------------------*/
/** @ADC_CONVERSION_NUMBER  */
/**
 * there are 17 conversion but we will not use more than 6 in our applications
 * more conversions in version 2.0
 */
/**
 * OPTIONS :  ADC_CONVERSION_0
 *            ADC_CONVERSION_1
 *            ADC_CONVERSION_2
 *            ADC_CONVERSION_3
 *            ADC_CONVERSION_4
 *            ADC_CONVERSION_5
 *            ADC_CONVERSION_6
 *
 */

#define ADC_CONVERSION_NUM  ADC_CONVERSION_0







/*--------------------------------------------------------------------------------*/





#endif /* ADC_CONFIG_H_ */












