/*
 * VNIC_interface.h
 *
 *  Created on: Aug 23, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef VNIC_INTERFACE_H_
#define VNIC_INTERFACE_H_



typedef struct
{
	s8 InterruptID    ;
	u8 GroupPriority  ;
	u8 SubPriority    ;

}NVIC_Config_t;

/**
 * Vector table for connectivity line devices
 * 		Interrupt Number to be used in APIs
 */
#define NVIC_WWDG              NVIC_INTERRUPT_NUM_0
#define NVIC_PVD               NVIC_INTERRUPT_NUM_1
#define NVIC_TAMPER            NVIC_INTERRUPT_NUM_2
#define NVIC_RTC               NVIC_INTERRUPT_NUM_3
#define NVIC_FLASH             NVIC_INTERRUPT_NUM_4
#define NVIC_RCC               NVIC_INTERRUPT_NUM_5
#define NVIC_EXTI0             NVIC_INTERRUPT_NUM_6
#define NVIC_EXTI1             NVIC_INTERRUPT_NUM_7
#define NVIC_EXTI2             NVIC_INTERRUPT_NUM_8
#define NVIC_EXTI3             NVIC_INTERRUPT_NUM_9
#define NVIC_EXTI4             NVIC_INTERRUPT_NUM_10
#define NVIC_DMA1_Channel1     NVIC_INTERRUPT_NUM_11
#define NVIC_DMA1_Channel2     NVIC_INTERRUPT_NUM_12
#define NVIC_DMA1_Channel3     NVIC_INTERRUPT_NUM_13
#define NVIC_DMA1_Channel4     NVIC_INTERRUPT_NUM_14
#define NVIC_DMA1_Channel5     NVIC_INTERRUPT_NUM_15
#define NVIC_DMA1_Channel6     NVIC_INTERRUPT_NUM_16
#define NVIC_DMA1_Channel7     NVIC_INTERRUPT_NUM_17
#define NVIC_ADC1_2            NVIC_INTERRUPT_NUM_18
#define NVIC_CAN1_TX           NVIC_INTERRUPT_NUM_19
#define NVIC_CAN1_RX0          NVIC_INTERRUPT_NUM_20
#define NVIC_CAN1_RX1          NVIC_INTERRUPT_NUM_21
#define NVIC_CAN1_SCE          NVIC_INTERRUPT_NUM_22
#define NVIC_EXTI9_5           NVIC_INTERRUPT_NUM_23
#define NVIC_TIM1_BRK          NVIC_INTERRUPT_NUM_24
#define NVIC_TIM1_UP           NVIC_INTERRUPT_NUM_25
#define NVIC_TIM1_TRG_COM      NVIC_INTERRUPT_NUM_26
#define NVIC_TIM1_CC           NVIC_INTERRUPT_NUM_27
#define NVIC_TIM2              NVIC_INTERRUPT_NUM_28
#define NVIC_TIM3              NVIC_INTERRUPT_NUM_29
#define NVIC_TIM4              NVIC_INTERRUPT_NUM_30
#define NVIC_I2C1_EV           NVIC_INTERRUPT_NUM_31
#define NVIC_I2C1_ER           NVIC_INTERRUPT_NUM_32
#define NVIC_I2C2_EV           NVIC_INTERRUPT_NUM_33
#define NVIC_I2C2_ER           NVIC_INTERRUPT_NUM_34
#define NVIC_SPI1              NVIC_INTERRUPT_NUM_35
#define NVIC_SPI2              NVIC_INTERRUPT_NUM_36
#define NVIC_USART1            NVIC_INTERRUPT_NUM_37
#define NVIC_USART2            NVIC_INTERRUPT_NUM_38
#define NVIC_USART3            NVIC_INTERRUPT_NUM_39
#define NVIC_EXTI15_10         NVIC_INTERRUPT_NUM_40
#define NVIC_RTCAlarm          NVIC_INTERRUPT_NUM_41
#define NVIC_OTG_FS_WKUP       NVIC_INTERRUPT_NUM_42
/**  RESERVED
#define NVIC_                  NVIC_INTERRUPT_NUM_43
#define NVIC_                  NVIC_INTERRUPT_NUM_44
#define NVIC_                  NVIC_INTERRUPT_NUM_45
#define NVIC_                  NVIC_INTERRUPT_NUM_46
#define NVIC_                  NVIC_INTERRUPT_NUM_47
#define NVIC_                  NVIC_INTERRUPT_NUM_48
#define NVIC_                  NVIC_INTERRUPT_NUM_49*/

#define NVIC_TIM5              NVIC_INTERRUPT_NUM_50
#define NVIC_SPI3              NVIC_INTERRUPT_NUM_51
#define NVIC_UART4             NVIC_INTERRUPT_NUM_52
#define NVIC_UART5             NVIC_INTERRUPT_NUM_53
#define NVIC_TIM6              NVIC_INTERRUPT_NUM_54
#define NVIC_TIM7              NVIC_INTERRUPT_NUM_55
#define NVIC_DMA2_Channel1     NVIC_INTERRUPT_NUM_56
#define NVIC_DMA2_Channel2     NVIC_INTERRUPT_NUM_57
#define NVIC_DMA2_Channel3     NVIC_INTERRUPT_NUM_58
#define NVIC_DMA2_Channel4     NVIC_INTERRUPT_NUM_59
#define NVIC_DMA2_Channel5     NVIC_INTERRUPT_NUM_60
#define NVIC_ETH               NVIC_INTERRUPT_NUM_61
#define NVIC_ETH_WKUP          NVIC_INTERRUPT_NUM_62
#define NVIC_CAN2_TX           NVIC_INTERRUPT_NUM_63
#define NVIC_CAN2_RX0          NVIC_INTERRUPT_NUM_64
#define NVIC_CAN2_RX1          NVIC_INTERRUPT_NUM_65
#define NVIC_CAN2_SCE          NVIC_INTERRUPT_NUM_66
#define NVIC_OTG_FS            NVIC_INTERRUPT_NUM_67





/**
 *		Interrupt Enable and Disable APIs
 */
void NVIC_voidEnableInterrupt  (u8 Copy_u8IntNumber);
void NVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);


void NVIC_voidSetPendingFlag   (u8 Copy_u8IntNumber);
void NVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);


u8   NVIC_u8GetActiveFlag        (u8 Copy_u8IntNumber);


void NVIC_voidSetPriority (NVIC_Config_t *pNVIC ) ;


#endif /* VNIC_INTERFACE_H_ */
