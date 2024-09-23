 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: lcd_config.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Misara Ahmed
 *
 * Date: 17/9/2024
 *
 *******************************************************************************/
#ifndef INC_LCD_CONFIG_H_
#define INC_LCD_CONFIG_H_

#define LCD_DATA_PORT			GPIOA
#define LCD_DATA_PIN			GPIO_PIN_8

#define LCD_RS_PORT				GPIOB
#define LCD_RS_PIN				GPIO_PIN_13

#define LCD_RW_PORT				GPIOB
#define LCD_RW_PIN				GPIO_PIN_14

#define LCD_EN_PORT				GPIOB
#define LCD_EN_PIN				GPIO_PIN_15

#endif /* INC_LCD_CONFIG_H_ */
