/*
 * bit_math.h
 *
 *  Created on: Sep 17, 2024
 *      Author: Misara
 */

#ifndef INC_BIT_MATH_H_
#define INC_BIT_MATH_H_

#define SET_BIT(reg,pin)		reg |= 1<<pin
#define CLR_BIT(reg,pin)		reg &= ~(1<<pin)
#define TOG_BIT(reg,pin)		reg ^= 1<<pin
#define GET_BIT(reg,pin)		(reg>>pin)&1

#endif /* INC_BIT_MATH_H_ */
