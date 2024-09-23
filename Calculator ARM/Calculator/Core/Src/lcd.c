 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Misara Ahmed
 *
 * Date: 17/9/2024
 *
 *******************************************************************************/

#include <stdint.h>
#include "lcd.h"
#include "lcd_config.h"
#include "stm32f1xx_hal.h"

void LCD_Init(void)
{
	// Wait more than 30ms
	HAL_Delay(40);

	// Send function set instruction
	// 0b00111000
	LCD_SendInst(0b00111000);

	// Send on/off instruction
	// 0b00001100
	LCD_SendInst(0b00001100);

	// Clear display
	LCD_SendInst(1);

	// Send entry mode
}

void LCD_SendData(uint8_t data)
{
	// Send data on data port
	uint8_t bit;
	uint16_t pin = LCD_DATA_PIN;

	// Get the first bit(0) and write it on the port
	bit = (data>>0)&1;
	HAL_GPIO_WritePin(LCD_DATA_PORT, pin, bit);

	// Loop on the remaining bits in the data and write it on the corresponding pins
	for(uint8_t i=1 ; i<8 ; i++)
	{
		bit = (data>>i)&1;
		pin *= 2;
		HAL_GPIO_WritePin(LCD_DATA_PORT, pin, bit);
	}

	// Set RS to high
	HAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_SET);

	// Clr RW to low
	HAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);

	// Send enable pulse
	HAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_SET);

	HAL_Delay(10);

	HAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_RESET);

}

void LCD_SendInst(uint8_t inst)
{
	// Send instruction on data port
	uint8_t bit;
	uint16_t pin = LCD_DATA_PIN;

	// Get the first bit(0) and write it on the port
	bit = (inst>>0)&1;
	HAL_GPIO_WritePin(LCD_DATA_PORT, pin, bit);

	// Loop on the remaining bits in the instruction and write it on the corresponding pins
	for(uint8_t i=1 ; i<8 ; i++)
	{
		bit = (inst>>i)&1;
		pin *= 2;
		HAL_GPIO_WritePin(LCD_DATA_PORT, pin, bit);
	}

	// Set RS to high
	HAL_GPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_PIN_RESET);

	// Clr RW to low
	HAL_GPIO_WritePin(LCD_RW_PORT, LCD_RW_PIN, GPIO_PIN_RESET);

	// Send enable pulse
	HAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_SET);

	HAL_Delay(10);

	HAL_GPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_PIN_RESET);
}

void LCD_SendStr(const uint8_t* str)
{
	// Loop till the null character and send the characters using SendData function
	while(*str != '\0')
	{
		LCD_SendData(*str++);
	}
}

void LCD_GoTo(uint8_t x, uint8_t y)
{
	// Go to specific position on the LCD
	uint8_t address = x + y*0x40;
	SET_BIT(address, 7);
	LCD_SendInst(address);
}

void LCD_SendNumber(uint16_t number)
{
	uint8_t num[10];
	uint16_t rem = number;
	uint8_t counter = 0;
	while(rem > 0)
	{
		num[counter] = rem%10;
		rem /= 10;
		counter++;
	}
	while(counter>0)
	{
		counter--;
		LCD_SendData(num[counter] + '0');
	}
}
