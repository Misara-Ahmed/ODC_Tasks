///*
// * KPAD.c
// *
// *  Created on: Sep 5, 2024
// *      Author: Misara
// */
//
//#include <util/delay.h>
//#include <stdint.h>
//#include <stdio.h>
//#include "Dio.h"
//#include "bit_math.h"
//#include "Keypad_config.h"
//#include "Kpad.h"
//
//uint8_t col_arr[4] = {KPAD_COL_PIN0,KPAD_COL_PIN1,KPAD_COL_PIN2,KPAD_COL_PIN3};
//uint8_t row_arr[4] = {KPAD_ROW_PIN0,KPAD_ROW_PIN1,KPAD_ROW_PIN2,KPAD_ROW_PIN3};
//
//void KPAD_Init()
//{
//	// col output
//	// col high
//	// row input
//	// enable internal pull up
//	for(uint8_t i=0 ; i<4 ; i++)
//	{
//		DIO_SetPinDirection(KPAD_COL_PORT, col_arr[i], OUTPUT);
//		DIO_SetPinValue(KPAD_COL_PORT, col_arr[i], HIGH);
//
//		DIO_SetPinDirection(KPAD_ROW_PORT, row_arr[i], INPUT);
//		DIO_EnablePullup(KPAD_ROW_PORT,row_arr[i]);
//	}
//}
//
//uint8_t KPAD_GetKeyPressed(void)
//{
//	uint8_t res = 0xff;
//	for(uint8_t i = 0 ; i<4 ; i++)
//	{
//		DIO_SetPinvalue(KPAD_COL_PORT, col_arr[i], LOW);
//		for(uint8_t j = 0 ; j< 4 ; j++)
//		{
//			uint8_t btn = NULL;
////			read value ?
//			DIO_GetPinValue(KPAD_ROW_PORT, row_arr[j], &btn);
//			if(btn == 0)
//			{
//				res = KPAD_matrix[i][j];
//			}
////			if (value == 0 )
////			res = KPAD_matrix[i][j];
////			break
//
//		}
//		DIO_SetPinvalue(KPAD_COL_PORT, col_arr[i], HIGH);
//
//	}
//	return res ;
//}
