/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "IntCtrl_Types.h"
#include "IntCtrl_Cfg.h"




/* Interrupts Options:
 * 1-GPIO_PORT_A
 * 2-GPIO_PORT_B
 * 3-GPIO_PORT_C
 * 4-GPIO_PORT_D
 * 5-GPIO_PORT_E
 * 6-UART0
 * 7-UART1
 * 8-SSI0
 * 9-I2C0
 * 10-PWM0_FAULT
 * 11-PWM0_GENERATOR_0
 * 12-PWM0_GENERATOR_1
 * 13-PWM0_GENERATOR_2
 * 14-QEI0
 * 15-ADC0_SEQUENCE_0
 * 16-ADC0_SEQUENCE_1
 * 17-ADC0_SEQUENCE_2
 * 18-ADC0_SEQUENCE_3
 * 19-WDT_0_AND_1
 * 20-_16_32_TIMER_0A
 * 21-_16_32_TIMER_0B
 * 22-_16_32_TIMER_1A
 * 23-_16_32_TIMER_1B
 * 24-_16_32_TIMER_2A
 * 25-_16_32_TIMER_2B
 * 26-ANALOG_COMPARATOR_0
 * 27-ANALOG_COMPARATOR_1
 * 28-SYSTEM_CONTROL
 * 29-FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL
 * 30-GPIO_PORT_F
 * 31-UART2
 * 32-SSI1
 * 33-_16_32_BIT_TIMER_3A
 * 34-_16_32_BIT_TIMER_3B
 * 35-I2C1
 * 36-QEI1
 * 37-CAN0
 * 38-CAN1
 * 39-HIBERNATION_MODULE
 * 40-USB
 * 41-PWM_GENERATOR_3
 * 42-UDMA_SOFTWARE
 * 43-UDMA_ERROR
 * 44-ADC1_SEQUENCE_0
 * 45-ADC1_SEQUENCE_1
 * 46-ADC1_SEQUENCE_2
 * 47-ADC1_SEQUENCE_3
 * 48-SSI2 = 57
 * 49-SSI3
 * 50-UART3
 * 51-UART4
 * 52-UART5
 * 53-UART6
 * 54-UART7
 * 55-I2C2
 * 56-I2C3
 * 57-_16_32_BIT_TIMER_4A
 * 58-_16_32_BIT_TIMER_4B
 * 59-_16_32_BIT_TIMER_5A
 * 60-_16_32_BIT_TIMER_5B
 * 61-_32_64_BIT_TIMER_0A
 * 62-_32_64_BIT_TIMER_0B
 * 63-_32_64_BIT_TIMER_1A
 * 64-_32_64_BIT_TIMER_1B
 * 65-_32_64_BIT_TIMER_2A
 * 66-_32_64_BIT_TIMER_2B
 * 67-_32_64_BIT_TIMER_3A
 * 68-_32_64_BIT_TIMER_3B
 * 69-_32_64_BIT_TIMER_4A
 * 70-_32_64_BIT_TIMER_4B
 * 71-_32_64_BIT_TIMER_5A
 * 72-_32_64_BIT_TIMER_5B
 * 73-SYSTEM_EXCEPTION
 * 74-PWM1_GENERATOR_0
 * 75-PWM1_GENERATOR_1
 * 76-PWM1_GENERATOR_2
 * 77-PWM1_GENERATOR_3
 * 78-PWM1_FAULT
 */


const IntCtrl_Interrupt_st interrupts[NUMBER_OF_USED_INTERRUPTS] =
{
  /*Interrupt             Group Priority           Subgroup Priority              Is Enabled*/
	{GPIO_PORT_A,                      0,                       1,                      TRUE},
  {UART0,                      			 2,                       1,                      FALSE},
};


/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
