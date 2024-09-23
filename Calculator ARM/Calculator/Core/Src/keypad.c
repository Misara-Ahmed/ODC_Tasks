 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Source file for the KEYPAD driver
 *
 * Author: Misara Ahmed
 *
 * Date: 17/9/2024
 *
 *******************************************************************************/

#include <stdint.h>
#include <stdio.h>
#include "stm32f1xx_hal.h"
#include "bit_math.h"
#include "keypad_config.h"
#include "keypad.h"

uint8_t col_arr[4] = {KPAD_COL_PIN0,KPAD_COL_PIN1,KPAD_COL_PIN2,KPAD_COL_PIN3};
uint8_t row_arr[4] = {KPAD_ROW_PIN0,KPAD_ROW_PIN1,KPAD_ROW_PIN2,KPAD_ROW_PIN3};

void KPAD_Init()
{
	for(uint8_t i=0 ; i<4 ; i++)
	{
		// Initialize the column pins to be HIGH
		HAL_GPIO_WritePin(KPAD_COL_PORT, col_arr[i], GPIO_PIN_SET);
	}
}

uint8_t KPAD_GetKeyPressed(void)
{
	// Initialize a variable to hold the result
	uint8_t res = 0xff;

	// Make each column low and check for the corresponding row if any button in it is pressed
	for(uint8_t i = 0 ; i<4 ; i++)
	{
		HAL_GPIO_WritePin(KPAD_COL_PORT, col_arr[i], GPIO_PIN_RESET);

		// Loop on the rows and check if any button is pressed
		for(uint8_t j = 0 ; j< 4 ; j++)
		{
			uint8_t btn = NULL;

			// Read value of the buttons
			btn = HAL_GPIO_ReadPin(KPAD_ROW_PORT, row_arr[j]);
			HAL_Delay(10);
			if(btn == 0)
			{
				// If pressed return the value of it using the predefined matrix
				res = KPAD_matrix[j][i];
				break;
			}
		}

		// Return the specific column to be high again to check another column
		HAL_GPIO_WritePin(KPAD_COL_PORT, col_arr[i], GPIO_PIN_SET);
	}
	return res;
}
