/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "i2c.h"
#include "spi.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "vl53l0x_api.h"
#include "vl53l0x_platform.h" // Ajout de l'en-tête vl53l0x_platform.h
#include <stdint.h>

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
VL53L0X_Dev_t tof_sensor; // ToF sensor device structure
VL53L0X_RangingMeasurementData_t RangingData; // Ranging data
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void setMotorSpeed(int speed1, int speed2);
void initToF(void);
void readToF(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
void setMotorSpeed(int speed1, int speed2) {
    // Configuration du sens du Moteur 1
    if (speed1 > 0) {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_RESET);
    } else {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, GPIO_PIN_SET);
    }
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, abs(speed1));

    // Configuration du sens du Moteur 2
    if (speed2 > 0) {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_SET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_RESET);
    } else {
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, GPIO_PIN_SET);
    }
    __HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, abs(speed2));
}

void initToF(void) {
    tof_sensor.i2cHandle = &hi2c1; // I2C handle
    tof_sensor.I2cDevAddr = 0x52; // I2C address of VL53L0X
    tof_sensor.comms_type = 1; // I2C communication
    tof_sensor.comms_speed_khz = 400; // I2C speed 400 kHz

    VL53L0X_Init(&tof_sensor);
    VL53L0X_StaticInit(&tof_sensor);
    VL53L0X_PerformRefCalibration(&tof_sensor, &VhvSettings, &PhaseCal);
    VL53L0X_PerformRefSpadManagement(&tof_sensor, &refSpadCount, &isApertureSpads);
    VL53L0X_SetDeviceMode(&tof_sensor, VL53L0X_DEVICEMODE_CONTINUOUS_RANGING);
    VL53L0X_StartMeasurement(&tof_sensor);
}

void readToF(void) {
    VL53L0X_GetRangingMeasurementData(&tof_sensor, &RangingData);
    VL53L0X_ClearInterruptMask(&tof_sensor, VL53L0X_INTERRUPT_MASK);
    printf("Distance: %d mm\n", RangingData.RangeMilliMeter);
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_I2C1_Init();
  MX_SPI2_Init();
  MX_SPI3_Init();
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  /* USER CODE BEGIN 2 */
  initToF(); //
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
    readToF(); //
    HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}
