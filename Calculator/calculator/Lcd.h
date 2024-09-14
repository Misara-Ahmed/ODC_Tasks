/*
 * LCD.h
 *
 *  Created on: Sep 5, 2024
 *      Author: Misara
 */

#ifndef LCD_H_
#define LCD_H_

void LCD_Init(void);
void LCD_SendData(uint8_t data);
void LCD_SendInst(uint8_t inst);
void LCD_SendStr(const uint8_t* str);

void LCD_SendNumber(uint16_t number);
void LCD_GoTo(uint8_t x, uint8_t y);
// Move Cursor Function

#endif /* LCD_H_ */
