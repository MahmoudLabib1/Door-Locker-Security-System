/*******************************************************************************
 *
 *  Module: Common-Macros
 *
 *  File Name: common_macros.h
 *
 *  Description: Commonly Used Macros
 *
 *  Author: Mahmoud_Labib
 *
 *******************************************************************************/

#ifndef SRC_UTILS_COMMON_MACROS_H_
#define SRC_UTILS_COMMON_MACROS_H_

/* Write one at a certain bit in any Register */
#define SET_BIT(REG,BIT) (REG|=(1<<BIT))

/* Write Zero at a certain bit in any Register */
#define CLEAR_BIT(REG,BIT) (REG &=(~(1<<BIT)))

/* Change the status of a certain bit in any Register */
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))

/* Rotate right the register value with a specific number of rotates */
#define ROR(REG,BIT) (REG=(REG>>BIT)|(REG<<(8-BIT)))

/* Rotate left the register value with a specific number rotates*/
#define ROL(REG,BIT) (REG=(REG<<BIT)|(REG>>(8-BIT)))

/* Check if a specific bit is written ONE */
#define BIT_IS_SET(REG,BIT) (REG & (1<<BIT))

/* Check if a specific bit is written ZERO */
#define BIT_IS_CLEAR(REG,BIT) (!(REG & (1<<BIT)))

/* Shift right the register value with a specific number of shift */
#define SHR(REG,BIT) (REG=(REG>>BIT))

/* Shift left the register value with a specific number of shift*/
#define SHL(REG,BIT) (REG=(REG<<BIT))

#endif /* SRC_UTILS_COMMON_MACROS_H_ */
