/*
 * EXTI_interface.h
 *
 *  Created on: Aug 23, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_


typedef struct
{

	u8 Line       ;  /** @EXTI_Lines      */
	u8 Trigger    ;  /** @EXTI_Trigger    */
	u8 SWTrigger  ;  /** @EXTI_SW_Trigger */

}EXTI_config_t;

/** @EXTI_Lines      */
#define	LINE_0 				0
#define	LINE_1 				1
#define	LINE_2 				2
#define	LINE_3 				3
#define	LINE_4 				4
#define	LINE_5 				5
#define	LINE_6 				6
#define	LINE_7 				7
#define	LINE_8 				8
#define	LINE_9 				9
#define	LINE_10				10
#define	LINE_11				11
#define	LINE_12				12
#define	LINE_13				13
#define	LINE_14				14
#define	LINE_15				15

/** @EXTI_Trigger    */
#define	RISING				0
#define	FALLING				1
#define	ON_CHANGE			2

/** @EXTI_SW_Trigger */
#define SW_TRIG_DISABLE     0
#define SW_TRIG_ENABLE      1


/**
 *  EXTI  Related APIs
 */
void EXTI_voidInit(EXTI_config_t *pEXTI ) ;

void EXTI_voidEnableEXTI(u8 Copy_u8Line);
void EXTI_voidDisableEXTI(u8 Copy_u8Line);
void EXTI_voidSwTrigger(u8 Copy_u8Line);
void EXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode);

#endif /* EXTI_INTERFACE_H_ */
