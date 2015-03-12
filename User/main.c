/**
  ******************************************************************************
  * @file    IAP/src/main.c 
  * @author  MCD Application Team
  * @version V3.3.0
  * @date    10/15/2010
  * @brief   Main program body
  ******************************************************************************
  * @copy
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2010 STMicroelectronics</center></h2>
  */ 

/** 
 * @file     main.c
 * @brief    STM32F10x-IAP-UART
 * @details  STM32F10x in-application programming using the USART (AN2557)
 * @author   华兄
 * @email    591881218@qq.com
 * @date     2015
 * @version  vX.XX
 * @par Copyright (c):  
 *           华兄电子
 * @par History:          
 *   version: author, date, desc\n 
 */ 

/** @addtogroup IAP
  * @{
  */

/* Includes ------------------------------------------------------------------*/
#include "common.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int  main(void)
{
  /* Flash unlock */
  FLASH_Unlock();

  /* Initialize Key Button mounted on STM3210X-EVAL board */       
  STM_EVAL_PBInit(BUTTON_KEY, BUTTON_MODE_GPIO);   

  /* Test if Key push-button on STM3210X-EVAL Board is pressed */
  if (RESET == STM_EVAL_PBGetState(BUTTON_KEY))
  { 
    /* If Key is pressed */
    /* Initialize Leds mounted on STM3210X-EVAL board */
    STM_EVAL_LEDInit(LED_PWR);
    STM_EVAL_LEDInit(LED_UART);

    /* Turn on PWR's LED */
    STM_EVAL_LEDOn(LED_PWR);
    
    /* Turn off UART's LED */
    STM_EVAL_LEDOff(LED_UART); 

    /* Execute the IAP driver in order to re-program the Flash */
    IAP_Init(UART_BAUD_RATE); /* Default BaudRate: 115200bps */
    Main_Menu();
  }
  /* Keep the user application running */
  else
  {
    IAP_JumpToApplication();
  }

  while (1)
  {}
}

#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */

/******************* (C) COPYRIGHT 2010 STMicroelectronics *****END OF FILE****/
