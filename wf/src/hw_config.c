/* Includes ------------------------------------------------------------------*/
#include "header.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Extern variables ----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/*******************************************************************************
* Function Name  : Set_System
* Description    : Configures Main system clocks & power
* Input          : None.
* Return         : None.
*******************************************************************************/
void Set_System(void)
{
  //Запускаємо тактові клоки на периверію
 
  //AHB3

  //AHB1
  RCC_AHB1PeriphClockCmd(
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
                         RCC_AHB1Periph_GPIO_CANAL1_MO          |
                         RCC_AHB1Periph_GPIO_CANAL2_MO          |
                         RCC_AHB1Periph_GPIO_CANAL1_MO_Out1     |
#endif                           
                         RCC_AHB1Periph_DMA1                    |
                         RCC_AHB1Periph_DMA2                    |
                         RCC_AHB1Periph_GPIO_LCD_RW             |
                         RCC_AHB1Periph_GPIO_LCD_RS             |
                         RCC_AHB1Periph_GPIO_LCD_BL             |
                         RCC_AHB1Periph_GPIO_CON_L              |
                         RCC_AHB1Periph_GPIO_KEYBOARD           |
                         RCC_AHB1Periph_GPIO_KEYBOARD_SW_A      |
                         RCC_AHB1Periph_GPIO_KEYBOARD_SW_B      |
                         RCC_AHB1Periph_GPIO_KEYBOARD_SW_C      |
                         RCC_AHB1Periph_GPIO_KEYBOARD_SW_D      |
                         RCC_AHB1Periph_GPIO_SELECT_ADC         |
                         RCC_AHB1Periph_GPIO_SPI_ADC            |
                         RCC_AHB1Periph_GPIO_I2C                |
                         RCC_AHB1Periph_GPIO_SPI_EDF            |
                         RCC_AHB1Periph_GPIO_SPI_EDF_A0         |
                         RCC_AHB1Periph_GPIO_SPI_EDF_A1         |
                         RCC_AHB1Periph_GPIO_CON_OUTPUTS        |
                         RCC_AHB1Periph_GPIO_USART_RS485        |
                         RCC_AHB1Periph_GPIO_485DE              |
                         RCC_AHB1Periph_GPIO_EXTERNAL_WATCHDOG  |
                         RCC_AHB1Periph_GPIO_POWER_CTRL         |
                         RCC_AHB1Periph_GPIO_REPROGRAM          |
                         RCC_AHB1Periph_GPIO_STAFF              |
                         RCC_AHB1Periph_GPIO_STAFF_REPROGRAM/*    |
                         RCC_AHB1Periph_GPIO_TEST_OUTPUT*/,
                         
                         ENABLE);

  //APB2
  RCC_APB2PeriphClockCmd(
#if (((MODYFIKACIA_VERSII_PZ / 10) & 0x1) != 0)
                         RCC_CANAL1_MO          |
                         RCC_CANAL2_MO          |
#endif
                         RCC_APB2Periph_SYSCFG  |
                         RCC_APB2Periph_SPI_EDF,
                         
                         ENABLE);
  
  //APB1
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2C     |
                         RCC_APB1Periph_TIM2    |
                         RCC_APB1Periph_TIM5    |
                         RCC_APB1Periph_TIM4    |
                         RCC_APB1Periph_SPI_ADC |
                         RCC_USARTRS_485,
                         
                         ENABLE);

}

/*******************************************************************************
* Function Name  : Interrupts_Config
* Description    : Configures the USB interrupts
* Input          : None.
* Return         : None.
*******************************************************************************/
void Interrupts_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
  
//#ifdef  VECT_TAB_RAM
//  /* Set the Vector Table base location at 0x20000000 */
//  NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x0);
//#else  /* VECT_TAB_FLASH */
//  /* Set the Vector Table base location at 0x08000000 */
//  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x0);
//#endif

  /*******************************/
  //Настройки контролера переривань
  /*
  Пріоритет груп
  4-біт на Pre-emption поле: 4 рівні [0-3] Pre-emption пріоритету. 0 - найвищий Pre-emption пріоритет
  
  Пріоритет всередині групи
  4-біт на Subpriority поле: 4 рівні [0-3] Subpriority пріоритету. 0 - найвищий Subpriority пріоритет
  */
  /*******************************/
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_3);
  /*******************************/

  /*******************************/
  /* Enable the I2C global events Interrupt */
  /*
  //За рекомендацією ST має бути найвищий приорітет
  Pre-emption пріоритет = 0 
  Subpriority пріоритет = 0 
  */
  /*******************************/
  NVIC_InitStructure.NVIC_IRQChannel = I2C_EV_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /*******************************/

  /*******************************/
  /* Enable the I2C global errors Interrupt */
  /*
  Pre-emption пріоритет = 0 
  Subpriority пріоритет = 0 
  */
  /*******************************/
  NVIC_InitStructure.NVIC_IRQChannel = I2C_ER_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /*******************************/

  /*******************************/
  /* Переривання від TIM5, який запускається кожні 0,625мс для початку зняття даних з АЦП*/
  /*
  Pre-emption пріоритет = 1 
  Subpriority пріоритет = 0 
  */
  /*******************************/
  NVIC_InitStructure.NVIC_IRQChannel = TIM5_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /*******************************/

  /*******************************/
  /* Дозволяємо переривання від SPI вимірювальної системи */
  /*
  Pre-emption пріоритет = 1 
  Subpriority пріоритет = 1
  */
  /*******************************/
  NVIC_InitStructure.NVIC_IRQChannel = SPI_ADC_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /*******************************/
  
  /*******************************/
  /* Переривання від TIM2, який запускається кожні 1мс для роботи модулів захистів*/
  /*
  Pre-emption пріоритет = 2 
  Subpriority пріоритет = 0
  */
  /*******************************/
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /*******************************/

  /*******************************/
  /* Дозволяємо переривання від SPI_EDF - читання Dataflash */
  /*
  Pre-emption пріоритет = 3 
  Subpriority пріоритет = 0
  */
  /*******************************/
  NVIC_InitStructure.NVIC_IRQChannel = SPI_EDF_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /*******************************/

  /*******************************/
  /* Дозволяємо переривання від DMA_SPI_EDF запису - читання Dataflash */
  /*
  Pre-emption пріоритет = 3 
  Subpriority пріоритет = 1
  */
  /*******************************/
  NVIC_InitStructure.NVIC_IRQChannel = DMA_StreamSPI_EDF_Rx_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 3;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /*******************************/

  /*******************************/
  /* Переривання від USART2 для RS-485*/
  /*
  Pre-emption пріоритет = 4 
  Subpriority пріоритет = 0
  */
  /*******************************/
  NVIC_InitStructure.NVIC_IRQChannel = USARTRS485_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /*******************************/
  
  /*******************************/
  /* Переривання від DMA1_ChannelRS485_TX*/
  /*
  Pre-emption пріоритет = 4 
  Subpriority пріоритет = 1
  */
  /*******************************/
  NVIC_InitStructure.NVIC_IRQChannel = DMA_StreamRS485_Tx_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 4;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /*******************************/

  /*******************************/
  /* Дозволяємо переривання від DMA_StreamI2C_Tx передача даних через I2C */
  /*
  Pre-emption пріоритет = 6
  Subpriority пріоритет = 1 
  */
  /*******************************/
  NVIC_InitStructure.NVIC_IRQChannel = DMA_StreamI2C_Tx_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 6;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /*******************************/
  
  /*******************************/
  /* Дозволяємо переривання від DMA_ChannelI2C_Rx прийом даних з I2C */
  /*
  Pre-emption пріоритет = 6
  Subpriority пріоритет = 1 
  */
  /*******************************/
  NVIC_InitStructure.NVIC_IRQChannel = DMA_StreamI2C_Rx_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 6;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /*******************************/

  /*******************************/
  /* Дозволяємо переривання від фронтів сигналу появдення/пропадання живлення на вході джерела живлення */
  /*
  Pre-emption пріоритет = 7 
  Subpriority пріоритет = 0
  */
  /*******************************/
  NVIC_InitStructure.NVIC_IRQChannel = EXITI_POWER_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 7;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /*******************************/
  
  /*******************************/
  /* Переривання від TIM4, обробка клавіатури і інші низькопріоритетні задачі*/
  /*
  Pre-emption пріоритет = 7
  Subpriority пріоритет = 0 
  */
  /*******************************/
  NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 7;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
  /*******************************/
}

