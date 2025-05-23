/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stm32h747i_discovery_qspi.h"
#include "stm32h747i_discovery_sdram.h"
#include "stm32h747i_discovery_bus.h"
#include "stm32h747i_discovery_errno.h"
#include "../Components/otm8009a/otm8009a.h"
#include <stdbool.h>
//#include <TouchGFXGeneratedHAL.hpp>
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
extern int32_t DSI_IO_Write(uint16_t ChannelNbr, uint16_t Reg, uint8_t *pData, uint16_t Size);
extern int32_t DSI_IO_Read(uint16_t ChannelNbr, uint16_t Reg, uint8_t *pData, uint16_t Size);
/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define JOY_RIGHT_Pin GPIO_PIN_5
#define JOY_RIGHT_GPIO_Port GPIOK
#define JOY_LEFT_Pin GPIO_PIN_4
#define JOY_LEFT_GPIO_Port GPIOK
#define JOY_UP_Pin GPIO_PIN_6
#define JOY_UP_GPIO_Port GPIOK
#define JOY_DOWN_Pin GPIO_PIN_3
#define JOY_DOWN_GPIO_Port GPIOK
#define LCD_BL_Pin GPIO_PIN_12
#define LCD_BL_GPIO_Port GPIOJ
#define button_Pin GPIO_PIN_13
#define button_GPIO_Port GPIOC
#define led_1_Pin GPIO_PIN_12
#define led_1_GPIO_Port GPIOI
#define led_2_Pin GPIO_PIN_13
#define led_2_GPIO_Port GPIOI
#define led_3_Pin GPIO_PIN_14
#define led_3_GPIO_Port GPIOI
#define LCD_RESET_Pin GPIO_PIN_3
#define LCD_RESET_GPIO_Port GPIOG
#define N_state_Pin GPIO_PIN_2
#define N_state_GPIO_Port GPIOK
#define GEAR_UP_Pin GPIO_PIN_1
#define GEAR_UP_GPIO_Port GPIOK
#define MCU_ACTIVE_Pin GPIO_PIN_8
#define MCU_ACTIVE_GPIO_Port GPIOF
#define FRAME_RATE_Pin GPIO_PIN_9
#define FRAME_RATE_GPIO_Port GPIOJ
#define RENDER_TIME_Pin GPIO_PIN_8
#define RENDER_TIME_GPIO_Port GPIOJ
#define CLUTCH_DETECT_Pin GPIO_PIN_7
#define CLUTCH_DETECT_GPIO_Port GPIOJ
#define VSYNC_FREQ_Pin GPIO_PIN_3
#define VSYNC_FREQ_GPIO_Port GPIOJ

/* USER CODE BEGIN Private defines */
extern bool sdCardInserted;
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
