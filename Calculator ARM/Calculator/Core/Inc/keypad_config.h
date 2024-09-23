 /******************************************************************************
 *
 * Module: KEYPAD
 *
 * File Name: keypad_config.h
 *
 * Description: Header file for the KEYPAD driver
 *
 * Author: Misara Ahmed
 *
 * Date: 17/9/2024
 *
 *******************************************************************************/

#ifndef INC_KEYPAD_CONFIG_H_
#define INC_KEYPAD_CONFIG_H_

uint8_t KPAD_matrix[4][4] = {
	{'7','8','9','/'},
	{'4','5','6','x'},
	{'1','2','3','-'},
	{'C','0','=','+'},
};

#define KPAD_COL_PORT			GPIOA
#define KPAD_ROW_PORT			GPIOA

#define KPAD_ROW_PIN0			GPIO_PIN_0
#define KPAD_ROW_PIN1			GPIO_PIN_1
#define KPAD_ROW_PIN2			GPIO_PIN_2
#define KPAD_ROW_PIN3			GPIO_PIN_3

#define KPAD_COL_PIN0			GPIO_PIN_4
#define KPAD_COL_PIN1			GPIO_PIN_5
#define KPAD_COL_PIN2			GPIO_PIN_6
#define KPAD_COL_PIN3			GPIO_PIN_7


#endif /* INC_KEYPAD_CONFIG_H_ */
