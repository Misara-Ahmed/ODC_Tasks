/*
 * Dio.h
 *
 *  Created on: Sep 5, 2024
 *      Author: Misara
 */

#ifndef DIO_H_
#define DIO_H_

typedef enum{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}PORT_T;

typedef enum{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7,
}PIN_T;

typedef enum{
	INPUT,
	OUTPUT
}DIR_T;

typedef enum{
	OK,
	NOK
}ERR_T;

typedef enum{
	LOW,
	HIGH
}VAL_T;

ERR_T DIO_SetPinDirection(PORT_T port, PIN_T pin, DIR_T dir);
ERR_T DIO_SetPinValue(PORT_T port, PIN_T pin, VAL_T val);
ERR_T DIO_GetPinValue(PORT_T port, PIN_T pin, uint8_t * val);

ERR_T DIO_SetPortDirection(PORT_T port, uint8_t dir);
ERR_T DIO_SetPortValue(PORT_T port, uint8_t val);
ERR_T DIO_GetPortValue(PORT_T port, uint8_t * val);

ERR_T DIO_EnablePullup   (PORT_T port , PIN_T pin );

#endif /* DIO_H_ */
