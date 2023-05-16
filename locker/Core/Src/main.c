/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"

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

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
extern int key=0;
extern char Receive_nrf[2]={0};
extern char Receive_uart[2]={0};
int getinfo_nrf(char *Receive_nrf)
 {
    
    if(NRF24L01_RxPacket(Receive_nrf)==0)
      {
      u1_printf("NRF24L01:%s",Receive_nrf);
      if(Receive_nrf[0]=='1')
      {key = 1;;}
      else if(Receive_nrf[0] == '2')
      {key = 2;;}
      else
      key = 0;
      }
    
      return 0;
  
 }
 int getinfo_uart(char *Receive_uart)
 {
     HAL_UART_Receive_IT(&huart1,Receive_uart,1);

    if (Receive_uart[0] =='1' )
    {key = 1;return 1;}
    else if(Receive_uart[0]=='2')
    {key = 2; return 1;}
    else
    key = 0;
    return 1;
 }
 void clearbuffer()
 {
    Receive_uart[0]=0;
  Receive_nrf[0]=0;
  key = 0;
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
  MX_USART1_UART_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
 while(NRF24L01_Check())
	{
		u1_printf("worong wrpng\r\n"); 
 		HAL_Delay(1000);
	}
  NRF24L01_RX_Mode();
	u1_printf("NRF24L01  working\r\n");
  u1_printf("receiveing:\r\n");
  
  // if(HAL_GPIO_ReadPin(GPIOA,11)==1)
  //    {
  //      getinfo_uart(Receive_uart);
  //    }
  //   getinfo_nrf(Receive_nrf);
   
  //   switch (key)
  //   {
  //     case 0:
  //       break;
  //     case 1:
  //       loop(0,60);break;
  //     case 2:
  //       loop(1,60);break;
  //   }
  //   key = 0;
  //   HAL_Delay(500);
  int flag = 0;
  while (1)
  {
    /* USER CODE END WHILE */
    //getinfo_uart(Receive_uart);
    getinfo_nrf(Receive_nrf);
   
    switch (key)
    {
      case 0:
        if(flag == 0)u1_printf("connection will be cut!\n");flag = 1;break;
      case 1:
        flag = 0;u1_printf("open the door\n");HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,SET);loop(0,100);HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,RESET);break;
      case 2:
        flag = 0;u1_printf("close the door\n");HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,SET);loop(1,100);HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,RESET);break;
    }
    //
   // 
 
   //HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,SET);
    clearbuffer();
     HAL_Delay(500);
    //  HAL_Delay(1500);
      // HAL_GPIO_WritePin(GPIOB,GPIO_PIN_13,RESET);
    /* USER CODE BEGIN 3 */
    //clearbuffer(Receive_nrf,Receive_uart);
    
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
  /* Prevent unused argument(s) compilation warning */
  UNUSED(huart);
  /* NOTE: This function should not be modified, when the callback is needed,
           the HAL_UART_RxCpltCallback could be implemented in the user file
   */

 // while(HAL_UART_Receive_IT(&huart1, Receive_uart, 1) != HAL_OK); // Wait completly receive 1 byte data, and put data in rDataBuffer
}
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
