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
#include "dac.h"
#include "i2s.h"
#include "opamp.h"
#include "ucpd.h"
#include "usart.h"
#include "usb_device.h"
#include "gpio.h"
#include <stdint.h>

void SystemClock_Config(void);

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_DAC1_Init();
  MX_DAC3_Init();
  MX_I2S3_Init();
  MX_OPAMP1_Init();
  MX_OPAMP3_Init();
  MX_UCPD1_Init();
  MX_USART3_Init();
  MX_USB_Device_Init();

  adc_t channel_1_freq = {
    .config = {
      .Channel = ADC_CHANNEL_3,
      .Rank = ADC_REGULAR_RANK_1,
      .SamplingTime = ADC_SAMPLETIME_6CYCLES_5,
      .SingleDiff = ADC_SINGLE_ENDED,
      .OffsetNumber = ADC_OFFSET_NONE,
      .Offset = 0
    },
    .hadc = &hadc2
  };
  adc_t channel_2_freq = {
    .config = {
      .Channel = ADC_CHANNEL_2,
      .Rank = ADC_REGULAR_RANK_1,
      .SamplingTime = ADC_SAMPLETIME_6CYCLES_5,
      .SingleDiff = ADC_SINGLE_ENDED,
      .OffsetNumber = ADC_OFFSET_NONE,
      .Offset = 0
    },
    .hadc = &hadc1
  };
  adc_t channel_3_freq = {
    .config = {
      .Channel = ADC_CHANNEL_1,
      .Rank = ADC_REGULAR_RANK_1,
      .SamplingTime = ADC_SAMPLETIME_6CYCLES_5,
      .SingleDiff = ADC_SINGLE_ENDED,
      .OffsetNumber = ADC_OFFSET_NONE,
      .Offset = 0
    },
    .hadc = &hadc1
  };
  adc_t channel_4_freq = {
    .config = {
      .Channel = ADC_CHANNEL_4,
      .Rank = ADC_REGULAR_RANK_1,
      .SamplingTime = ADC_SAMPLETIME_6CYCLES_5,
      .SingleDiff = ADC_SINGLE_ENDED,
      .OffsetNumber = ADC_OFFSET_NONE,
      .Offset = 0
    },
    .hadc = &hadc2
  };
  adc_t channel_1_waveform = {
    .config = {
      .Channel = ADC_CHANNEL_15,
      .Rank = ADC_REGULAR_RANK_1,
      .SamplingTime = ADC_SAMPLETIME_6CYCLES_5,
      .SingleDiff = ADC_SINGLE_ENDED,
      .OffsetNumber = ADC_OFFSET_NONE,
      .Offset = 0
    },
    .hadc = &hadc1
  };
  adc_t channel_2_waveform = {
    .config = {
      .Channel = ADC_CHANNEL_12,
      .Rank = ADC_REGULAR_RANK_1,
      .SamplingTime = ADC_SAMPLETIME_6CYCLES_5,
      .SingleDiff = ADC_SINGLE_ENDED,
      .OffsetNumber = ADC_OFFSET_NONE,
      .Offset = 0
    },
    .hadc = &hadc2
  };
  adc_t channel_3_waveform = {
    .config = {
      .Channel = ADC_CHANNEL_15,
      .Rank = ADC_REGULAR_RANK_1,
      .SamplingTime = ADC_SAMPLETIME_6CYCLES_5,
      .SingleDiff = ADC_SINGLE_ENDED,
      .OffsetNumber = ADC_OFFSET_NONE,
      .Offset = 0
    },
    .hadc = &hadc2
  };
  adc_t channel_4_waveform = {
    .config = {
      .Channel = ADC_CHANNEL_5,
      .Rank = ADC_REGULAR_RANK_1,
      .SamplingTime = ADC_SAMPLETIME_6CYCLES_5,
      .SingleDiff = ADC_SINGLE_ENDED,
      .OffsetNumber = ADC_OFFSET_NONE,
      .Offset = 0
    },
    .hadc = &hadc1
  };

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    // Get ADC value
    ADC_Get_val(&channel_1_freq);
    ADC_Get_val(&channel_2_freq);
    ADC_Get_val(&channel_3_freq);
    ADC_Get_val(&channel_4_freq);
    ADC_Get_val(&channel_1_waveform);
    ADC_Get_val(&channel_2_waveform);
    ADC_Get_val(&channel_3_waveform);
    ADC_Get_val(&channel_4_waveform);
    USB_Print(
      "1_freq : %.4d | 2_freq : %.4d | 3_freq : %.4d | 4_freq : %.4d || 1_wave : %.4d | 2_wave : %.4d | 3_wave : %.4d | 4_wave : %.4d\n\r", 
      channel_1_freq.last_value,
      channel_2_freq.last_value,
      channel_3_freq.last_value,
      channel_4_freq.last_value,
      channel_1_waveform.last_value,
      channel_2_waveform.last_value,
      channel_3_waveform.last_value,
      channel_4_waveform.last_value
      );

    HAL_Delay(100);
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}




/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV1;
  RCC_OscInitStruct.PLL.PLLN = 12;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV4;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
