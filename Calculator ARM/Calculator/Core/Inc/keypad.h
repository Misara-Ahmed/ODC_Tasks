 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad.h
 *
 * Description: Header file for the KEYPAD driver
 *
 * Author: Misara Ahmed
 *
 * Date: 17/9/2024
 *
 *******************************************************************************/

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

void KPAD_Init();
uint8_t KPAD_GetKeyPressed(void);

#endif /* INC_KEYPAD_H_ */
