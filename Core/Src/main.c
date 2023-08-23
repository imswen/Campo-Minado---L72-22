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
#include <stdlib.h>
#define NUM_ROWS 5
#define NUM_COLS 5

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
int matrix[4][4];
_Bool Fim = 0;
int b;
int c;
int d;
int e;
int f;
int g;
int h;
int *PC;
char Co[12];
int L;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */
void SortearBomba();
void TestaHardware();
int TestaBotao();
void LigaLed(int *);
void FimDeJogo();
char Coluna();
int Linha();
void Game(char *);
void testarL_C();
int VerificarJogada(int, char);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

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
  TestaHardware();
  TestaBotao();
  SortearBomba();
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
	  testarL_C();
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }


  // int ab=TestaBotao();
	 // LigaLed(ab);


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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
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

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12, GPIO_PIN_RESET);

  /*Configure GPIO pins : PA4 PA5 PA6 PA7 */
  GPIO_InitStruct.Pin = GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PB0 PB1 PB10 PB11 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_10|GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PB12 PB13 PB14 PB15 */
  GPIO_InitStruct.Pin = GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : PA8 PA9 PA10 PA11
                           PA12 */
  GPIO_InitStruct.Pin = GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11
                          |GPIO_PIN_12;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */
void TestaLed()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12,1);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12,0);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,1);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,0);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14,1);
	HAL_Delay(200);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14,0);
  	HAL_Delay(200);
  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15,1);
  	HAL_Delay(200);
  	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15,0);
  	HAL_Delay(200);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12,0);
  	HAL_Delay(1000);
  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12,1);
}

int TestaBotao()
{
	int X = 9;
	_Bool ver = 0;

	do {
		if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0) == 0 )
		{
			X = 1;
		}

		else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10)== 0)
		{
			X = 2;
		}

		else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_11)== 0)
		{
			X = 3;
		}

		else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)== 0)
		{
			X = 4;
		}

		else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7)== 0)
		{
			X = 5;
		}

		else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)== 0)
		{
			X = 6;
		}

		else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)== 0)
		{
			X = 7;
		}

		else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)== 0)
		{
			X = 8;
		}
	} while(ver);

	return X;
}

void LigaLed(int *a)
{
	//Letras
	if(*PC == 'A')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15,1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15,0);
	}

	else if(*PC == 'B')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14,1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14,0);
	}

	else if (*PC == 'C')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12,1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12,0);
	}

	else if(*PC == 'D')
	{
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,0);
	}

	//Numeros
	else if(*PC == '4')
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,0);
	}

	else if(*PC == '3')
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,0);
	}

	else if(*PC == '2')
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,0);
	}

	else if(*PC == '1')
	{
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,1);
		HAL_Delay(500);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,0);
	}
}

void SortearBomba()
{
	for(int i = 0;i < 4;i++)
	{
		for(int j = 0; j < 4; j++)
		{
			matrix[i][j] = 0;
		}
	}

	for(int i = 0; i<4; i++)
	{
		int BombaX = rand () % 4;
		int BombaY = rand () % 4;

		if(matrix[BombaX][BombaY] == 1)
		{
			i--;
		}

		else
		{
			matrix[BombaX][BombaY] = 1;
		}
	}
}

void FimDeJogo()
{
	_Bool Fim = 1;
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12,1);
	HAL_Delay(100);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_12,0);

	int a = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0);
	int b = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1);
	int c = HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10);
	int d =  HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_11);

	int e = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6);
	int f = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7);
	int h =  HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4);
	int g = HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5);

	while(Fim)
	{
		if(a == 0 && b == 0 && c == 0 && d ==0 && e == 0 && f == 0 && g == 0 && h == 0)
		{
			Fim = 0;
		}

		else
		{
			Fim = 1;
		}

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12,0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14,0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15,0);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,0);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,0);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,0);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,0);
		HAL_Delay(700);

		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12,1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13,1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14,1);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15,1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8,1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9,1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10,1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11,1);
		HAL_Delay(700);
	}
}

char Coluna()
{
	if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_0) ==0 )
	{
		return 'A';
	}

	else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_6)==0)
	{
		return 'B';

	}

	else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_4)==0)
	{
		return 'C';
	}

	else if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_5)==0)
	{
		return 'D';
	}

	else
	{
		return 0;
	}
}

int Linha()
{
	if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_7)==0)
	{
		return 1;
	}

	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_10)==0)
	{
		return 2;
	}

	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_1)==0)
	{
		return 3;
	}

	else if(HAL_GPIO_ReadPin(GPIOB,GPIO_PIN_11)==0)
	{
		return 4;
	}

	else
	{
		return 0;
	}
}

void Game(char C)
{
    for (int i = 0; i < 12; i++)
    {
        if (L == 0 || Co[i] == 0)
        {
            i--;
        }

        else
        {
            int resultado = VerificarJogada(L, Co[i]);

            if (resultado == 1)
            {
                FimDeJogo();
            }

            else if (resultado == 0)
            {
                LigaLed(&C);
                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
                HAL_Delay(2000);
                HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 0);

                break;
            }
        }
    }
}

void testarL_C()
{
    for(int i = 0 ; i < 12; i++)
    {
        Co[i] = Coluna();
        L = Linha();

        if (L == 0 || Co[i] == 0)
        {
            i--;
        }

        else
        {
            Game(Co[i], L);
        }
    }
}

int VerificarJogada(int linha, char coluna)
{
    int colunaIndex = coluna - 'A';

    if (linha > 0 && linha <= NUM_ROWS && colunaIndex >= 0 && colunaIndex < NUM_COLS)
    {
        if (matrix[colunaIndex][linha - 1] == 1)
        {
            return 1;
        }

        else
        {
            return 0;
        }
    }

    return -1;
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
