/*
 * Lcd.c
 *
 *  Created on: Sep 5, 2024
 *      Author: Misara
 */
#include <stdint.h>
#define F_CPU		16000000ul
#include <util/delay.h>
#include "bit_math.h"
#include "Dio.h"
#include "Lcd.h"
#include "Lcd_config.h"

void LCD_Init(void)
{
	// Set direction of LCD pins
	DIO_SetPortDirection(LCD_DATA_PORT, 0xff);
	DIO_SetPinDirection(LCD_RS_PORT, LCD_RS_PIN, OUTPUT);
	DIO_SetPinDirection(LCD_RW_PORT, LCD_RW_PIN, OUTPUT);
	DIO_SetPinDirection(LCD_EN_PORT, LCD_EN_PIN, OUTPUT);

	// Wait more than 30ms
	_delay_ms(40);

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
	DIO_SetPortValue(LCD_DATA_PORT, data);

	// Set RS to high
	DIO_SetPinValue(LCD_RS_PORT, LCD_RS_PIN, HIGH);

	// Clr RW to low
	DIO_SetPinValue(LCD_RW_PORT, LCD_RW_PIN, LOW);

	// Send enable pulse
	DIO_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(10);
	DIO_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);

}

void LCD_SendInst(uint8_t inst)
{
	// Send instruction on data port
	DIO_SetPortValue(LCD_DATA_PORT, inst);

	// Set RS to high
	DIO_SetPinValue(LCD_RS_PORT, LCD_RS_PIN, LOW);

	// Clr RW to low
	DIO_SetPinValue(LCD_RW_PORT, LCD_RW_PIN, LOW);

	// Send enable pulse
	DIO_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, HIGH);
	_delay_ms(10);
	DIO_SetPinValue(LCD_EN_PORT, LCD_EN_PIN, LOW);
}

void LCD_SendStr(const uint8_t* str)
{
	while(*str != '\0')
	{
		LCD_SendData(*str++);
	}
}

void LCD_GoTo(uint8_t x, uint8_t y)
{
	uint8_t address = x + y*0x40;
	SET_BIT(address, 7);
	LCD_SendInst(address);
}

void LCD_SendNumber(uint16_t number)
{
//	uint16_t num = number;
//	uint8_t flag = 1;
//	while ( (num != (num%10)) || flag)
//	{
//		flag = 1;
//		switch (num%10)
//		{
//		case 0: LCD_SendData('0'); break;
//		case 1: LCD_SendData('1'); break;
//		case 2: LCD_SendData('2'); break;
//		case 3: LCD_SendData('3'); break;
//		case 4: LCD_SendData('4'); break;
//		case 5: LCD_SendData('5'); break;
//		case 6: LCD_SendData('6'); break;
//		case 7: LCD_SendData('7'); break;
//		case 8: LCD_SendData('8'); break;
//		case 9: LCD_SendData('9'); break;
//		}
//		num = num/10;
//	}

	switch (number)
	{
	case 0: LCD_SendData('0'); break;
	case 1: LCD_SendData('1'); break;
	case 2: LCD_SendData('2'); break;
	case 3: LCD_SendData('3'); break;
	case 4: LCD_SendData('4'); break;
	case 5: LCD_SendData('5'); break;
	case 6: LCD_SendData('6'); break;
	case 7: LCD_SendData('7'); break;
	case 8: LCD_SendData('8'); break;
	case 9: LCD_SendData('9'); break;
	}
}
