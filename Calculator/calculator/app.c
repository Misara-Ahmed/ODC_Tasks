/*
 * app.c
 *
 *  Created on: Sep 8, 2024
 *      Author: Misara
 */

#include <util/delay.h>
//#include <stdint.h>
#include "Dio.h"
#include "Kpad.h"
#include "Lcd.h"
#include <stdint.h>

uint8_t op1 = 0xff;
uint8_t op2 = 0xff;
uint8_t op;
uint8_t ans;

//void handle_input(uint8_t input)
//{
//	if(input == '=')
//	{
//		answer = First+Second;
//		LCD_SendData(First);
//		LCD_SendNumber(Second);
//		LCD_SendStr("Hi");
////		switch (operator)
////		{
////		case '+':
////			answer = First+Second;
////			break;
////
////		case '-':
////			answer = First-Second;
////			break;
////
////		case '*':
////			answer = First*Second;
////			break;
////
////		case '/':
////			answer = First/Second;
////			break;
////
////		default: LCD_SendStr("ERROR"); break;
////		}
//	}
//	else if(input > 47 && input < 58)
//	{
//		if(operator == 0)
//		{
//			if(First == 0xff)
//			{
//				First = input-48;
//			}
//			else
//			{
//				First = First*10 + input;
//
//			}
//		}
//		else
//		{
//			if(Second == 0xff)
//			{
//				Second = input-48;
//			}
//			else
//			{
//				Second = Second*10 + input;
//
//			}
//		}
//	}
//	else
//	{
//		operator = input;
//	}
//}
int main()
{
	LCD_Init();
	KPAD_Init();
	while(1)
	{
		uint8_t pressed_key = KPAD_GetKeyPressed();
		_delay_ms(10);
		if(pressed_key != 0xff)
		{
			if(pressed_key == '=')
			{
				LCD_SendData('=');
				switch(op)
				{
				case '+': LCD_SendData( (op1 + op2) + '0'); break;
				case '-': LCD_SendData( (op1 - op2) + '0'); break;
				case 'x': LCD_SendData( (op1 * op2) + '0'); break;
				case '/': LCD_SendData( (op1 / op2) + '0'); break;
				}
			}
			else if(pressed_key >= '0' && pressed_key <= '9')
			{
				LCD_SendData(pressed_key);
				if(op1 == 0xff)
				{
					op1 = pressed_key - '0';
				}
				else
				{
					op2 = pressed_key - '0';
				}
			}
			else if(pressed_key == 'C')
			{
				LCD_SendInst(1);
				op1 = 0xff;
				op2 = 0xff;
				op = 0xff;
			}
			else
			{
				LCD_SendData(pressed_key);
				op = pressed_key;
			}

		}

	}
}


//
//
//int main()
//{
//	KPAD_Init();
//	LCD_Init();
////	//LCD_SendNumber(5);
////	//LCD_SendNumber(1);
////	//DIO_EnablePullup(PORT_A, PIN_0);
////	//uint8_t btn;
////
////	// 0 -> 48
////	// 9 -> 57
////	while(1)
////	{
////		uint8_t Pressed_key = KPAD_GetKeyPressed();
////		//_delay_ms(10);
////		if(Pressed_key != 0xff)
////		{
////			if(Pressed_key == '=')
////			{
////				handle_input(Pressed_key);
////				LCD_SendNumber(answer);
////			}
////			else
////			{
////				LCD_SendData(Pressed_key);
////			}
////		}
////	}
//////////////////////////////////
//	while(1)
//	{
//		uint8_t Pressed_key = KPAD_GetKeyPressed();
//		if(Pressed_key != 0xff)
//		{
//			LCD_SendData(Pressed_key);
//		}
//	}
//}
