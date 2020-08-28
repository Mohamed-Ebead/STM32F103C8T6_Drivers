/*
 * ADC_interface.h
 *
 *  Created on: Aug 21, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define _RW_  volatile               //  Read / Write
#define _WO_  volatile               //  Write Only
#define _RO_  volatile const         //  Read Only


#include "ADC_private.h"

/*--------------------------------------------------------------------------------*/
typedef struct
{
	_RW_ u32 SR      ;
	_RW_ u32 CR1     ;
	_RW_ u32 CR2     ;
	_RW_ u32 SMPR1   ;
	_RW_ u32 SMPR2   ;
	_RW_ u32 JOFR1   ;
	_RW_ u32 JOFR2   ;
	_RW_ u32 JOFR3   ;
	_RW_ u32 JOFR4   ;
	_RW_ u32 HTR     ;
	_RW_ u32 LTR     ;
	_RW_ u32 SQR1    ;
	_RW_ u32 SQR2    ;
	_RW_ u32 SQR3    ;
	_RW_ u32 JSQR    ;
	_RO_ u32 JDR1    ;
	_RO_ u32 JDR2    ;
	_RO_ u32 JDR3    ;
	_RO_ u32 JDR4    ;
	_RO_ u32 DR      ;

}ADC_RegDef_t;

#define ADC1 	( (ADC_RegDef_t*)ADC1_BASEADDR )
#define ADC2 	( (ADC_RegDef_t*)ADC2_BASEADDR )
#define ADC3 	( (ADC_RegDef_t*)ADC3_BASEADDR )

/*--------------------------------------------------------------------------------*/

typedef struct
{
	u8 Channel          ;   /** ADC Channel 	  	  @ADC_CHANNELS          */
	u8 SampleTime       ;   /** ADC Sample Time 	  @ADC_SAMPLE_TIME       */
	u8 DataAlign        ;	/** ADC data alignment    @ADC_DATA_ALIGNMENT    */
	u8 ConversionMode   ;   /** ADC Conversion Mode   @ADC_CONVERSION_MODE   */
	u8 ConversionNum    ;   /** ADC conversion number @ADC_CONVERSION_NUMBER */
	u8 NBOfConversions  ;   /** In Scan mode only                            */
	u8 ClockPreScaler   ;
	u8 Resolution       ;
	u8 EOCType          ;

}ADC_Config_t;


typedef struct
{
	ADC_RegDef_t *pADCx ;
	ADC_Config_t ADC_Config ;

}ADC_Handle_t;


/*--------------------------------------------------------------------------------*/
/** @ADC_CHANNELS
 *  18 channels : 16 external and 2 internal
 */
/** PORTA RELATED CHANNELS */
#define ADC_CHANNEL_0   0     // PA0
#define ADC_CHANNEL_1   1     // PA1
#define ADC_CHANNEL_2   2     // PA2
#define ADC_CHANNEL_3   3     // PA3
#define ADC_CHANNEL_4   4     // PA4
#define ADC_CHANNEL_5   5     // PA5
#define ADC_CHANNEL_6   6     // PA6
#define ADC_CHANNEL_7   7     // PA7
/** PORTB RELATED CHANNELS */
#define ADC_CHANNEL_8   8     // PB0
#define ADC_CHANNEL_9   9     // PB1

#define ADC_CHANNEL_10  10
#define ADC_CHANNEL_11  11
#define ADC_CHANNEL_12  12
#define ADC_CHANNEL_13  13
#define ADC_CHANNEL_14  14
#define ADC_CHANNEL_15  15
#define ADC_CHANNEL_16  16   // INTERNAL TEMPERATURE SENSOR
#define ADC_CHANNEL_17  17
#define ADC_CHANNEL_18  18

/*--------------------------------------------------------------------------------*/
/** @ADC_SAMPLE_TIME */
/** a 0.5 cycle is subtracted from each MACRO to simplify the fraction part
 *  it means for example ADC_SAMPLE_1_CYCLES means 1.5 cycles , and so on ...  */
#define ADC_SAMPLE_1_CYCLES     0b000     // 1.5 CYCLES     FOR ONE SAMPLE
#define ADC_SAMPLE_7_CYCLES     0b001     // 7.5 CYCLES     FOR ONE SAMPLE
#define ADC_SAMPLE_13_CYCLES    0b010     // 13.5 CYCLES    FOR ONE SAMPLE
#define ADC_SAMPLE_28_CYCLES    0b011     // 28.5 CYCLES    FOR ONE SAMPLE
#define ADC_SAMPLE_41_CYCLES    0b100     // 41.5 CYCLES    FOR ONE SAMPLE
#define ADC_SAMPLE_55_CYCLES    0b101     // 55.5 CYCLES    FOR ONE SAMPLE
#define ADC_SAMPLE_71_CYCLES    0b110     // 71.5 CYCLES    FOR ONE SAMPLE
#define ADC_SAMPLE_239_CYCLES   0b111     // 239.5 CYCLES   FOR ONE SAMPLE

/*--------------------------------------------------------------------------------*/
/** @ADC_DATA_ALIGNMENT */
#define ADC_LEFT_ALIGNMENT       0
#define ADC_RIGHT_ALIGNMENT      1
/*--------------------------------------------------------------------------------*/
/** @ADC_CONVERSION_MODE */
#define ADC_CONVMODE_CONTINOUS   0
#define ADC_CONVMODE_SCAN        1
#define ADC_CONVMODE_SINGLE      2

/*--------------------------------------------------------------------------------*/
/** @ADC_CONVERSION_NUMBER  */
/**
 * there are 17 conversion but we will not use more than 6 in our applications
 * more conversions in version 2.0
 */

#define ADC_CONVERSION_0        0
#define ADC_CONVERSION_1        1
#define ADC_CONVERSION_2        2
#define ADC_CONVERSION_3        3
#define ADC_CONVERSION_4        4
#define ADC_CONVERSION_5        5
#define ADC_CONVERSION_6        6


/*--------------------------------------------------------------------------------*/


/**----------------------------- ADC RELATED APIs -----------------------------  **/

void ADC_vidPeriClockControl (ADC_RegDef_t *pADCx , u8 EnorDi  ) ;

void ADC_vidInit (ADC_Handle_t *pADC_Handle ) ;

u32 ADC_u16ReadBlocking    ( ADC_Handle_t *pADC_Handle ) ;
u32 ADC_u16ReadNonBlocking ( ADC_Handle_t *pADC_Handle ) ;

/*--------------------------------------------------------------------------------*/






















#endif /* ADC_INTERFACE_H_ */



