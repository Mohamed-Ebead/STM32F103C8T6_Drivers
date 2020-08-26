/*
 * VNIC_private.h
 *
 *  Created on: Aug 23, 2020
 *      Author: Mohamed  Ebead
 */

#ifndef VNIC_PRIVATE_H_
#define VNIC_PRIVATE_H_


#define NVIC_ISER0       (*((volatile u32*)0xE000E100))
#define NVIC_ISER1       (*((volatile u32*)0xE000E104))

#define NVIC_ICER0       (*((volatile u32*)0xE000E180))
#define NVIC_ICER1       (*((volatile u32*)0xE000E184))

#define NVIC_ISPR0       (*((volatile u32*)0xE000E200))
#define NVIC_ISPR1       (*((volatile u32*)0xE000E204))

#define NVIC_ICPR0       (*((volatile u32*)0xE000E280))
#define NVIC_ICPR1       (*((volatile u32*)0xE000E284))

#define NVIC_IABR0       (*((volatile u32*)0xE000E300))
#define NVIC_IABR1       (*((volatile u32*)0xE000E304))

#define NVIC_IPR         ((  volatile u32*)0xE000E400)

#define SCB_AIRCR        (*((volatile u32*)0xE000ED00 + 0x0C))
/**
 *
 * Priority Groups
 */

/* in (SCB => AIRCR) 4 bits for group and 0 sub => 4bits in (IPR) to determine group number	*/
#define		PRIGROUP_4		0x05FA0300
/* in (SCB => AIRCR) 3 bits for Group and 1 bit for sub										*/
#define		PRIGROUP_3		0x05FA0400
/* in (SCB => AIRCR) 2 bits for Group and 2 bit for sub										*/
#define		PRIGROUP_2		0x05FA0500
/* in (SCB => AIRCR) 1 bits for Group and 3 bit for sub										*/
#define		PRIGROUP_1		0x05FA0600
/* in (SCB => AIRCR) 0 group for 4 bits for sub												*/
#define		PRIGROUP_0		0x05FA0700


/**
 * Vector table for connectivity line devices
 */

#define NVIC_INTERRUPT_NUM_0       0
#define NVIC_INTERRUPT_NUM_1       1
#define NVIC_INTERRUPT_NUM_2       2
#define NVIC_INTERRUPT_NUM_3       3
#define NVIC_INTERRUPT_NUM_4       4
#define NVIC_INTERRUPT_NUM_5       5
#define NVIC_INTERRUPT_NUM_6       6
#define NVIC_INTERRUPT_NUM_7       7
#define NVIC_INTERRUPT_NUM_8       8
#define NVIC_INTERRUPT_NUM_9       9
#define NVIC_INTERRUPT_NUM_10      10
#define NVIC_INTERRUPT_NUM_11      11
#define NVIC_INTERRUPT_NUM_12      12
#define NVIC_INTERRUPT_NUM_13      13
#define NVIC_INTERRUPT_NUM_14      14
#define NVIC_INTERRUPT_NUM_15      15
#define NVIC_INTERRUPT_NUM_16      16
#define NVIC_INTERRUPT_NUM_17      17
#define NVIC_INTERRUPT_NUM_18      18
#define NVIC_INTERRUPT_NUM_19      19
#define NVIC_INTERRUPT_NUM_20      20
#define NVIC_INTERRUPT_NUM_21      21
#define NVIC_INTERRUPT_NUM_22      22
#define NVIC_INTERRUPT_NUM_23      23
#define NVIC_INTERRUPT_NUM_24      24
#define NVIC_INTERRUPT_NUM_25      25
#define NVIC_INTERRUPT_NUM_26      26
#define NVIC_INTERRUPT_NUM_27      27
#define NVIC_INTERRUPT_NUM_28      28
#define NVIC_INTERRUPT_NUM_29      29
#define NVIC_INTERRUPT_NUM_30      30
#define NVIC_INTERRUPT_NUM_31      31
#define NVIC_INTERRUPT_NUM_32      32
#define NVIC_INTERRUPT_NUM_33      33
#define NVIC_INTERRUPT_NUM_34      34
#define NVIC_INTERRUPT_NUM_35      35
#define NVIC_INTERRUPT_NUM_36      36
#define NVIC_INTERRUPT_NUM_37      37
#define NVIC_INTERRUPT_NUM_38      38
#define NVIC_INTERRUPT_NUM_39      39
#define NVIC_INTERRUPT_NUM_40      40
#define NVIC_INTERRUPT_NUM_41      41
#define NVIC_INTERRUPT_NUM_42      42
/**
 *  // RESERVED
#define NVIC_INTERRUPT_NUM_43      43
#define NVIC_INTERRUPT_NUM_44      44
#define NVIC_INTERRUPT_NUM_45      45
#define NVIC_INTERRUPT_NUM_46      46
#define NVIC_INTERRUPT_NUM_47      47
#define NVIC_INTERRUPT_NUM_48      48
#define NVIC_INTERRUPT_NUM_49      49
*/

#define NVIC_INTERRUPT_NUM_50      50
#define NVIC_INTERRUPT_NUM_51      51
#define NVIC_INTERRUPT_NUM_52      52
#define NVIC_INTERRUPT_NUM_53      53
#define NVIC_INTERRUPT_NUM_54      54
#define NVIC_INTERRUPT_NUM_55      55
#define NVIC_INTERRUPT_NUM_56      56
#define NVIC_INTERRUPT_NUM_57      57
#define NVIC_INTERRUPT_NUM_58      58
#define NVIC_INTERRUPT_NUM_59      59
#define NVIC_INTERRUPT_NUM_60      60
#define NVIC_INTERRUPT_NUM_61      61
#define NVIC_INTERRUPT_NUM_62      62
#define NVIC_INTERRUPT_NUM_63      63
#define NVIC_INTERRUPT_NUM_64      64
#define NVIC_INTERRUPT_NUM_65      65
#define NVIC_INTERRUPT_NUM_66      66
#define NVIC_INTERRUPT_NUM_67      67



// UP TO 67



#endif /* VNIC_PRIVATE_H_ */







