
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

#include "Std_Types.h"
#include "Mcu_Types.h"
#include "Mcu_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/



/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/* clockSource Options:
 * 1-MCU_MAIN_OSC,
 * 2-MCU_PRECISION_INTERNAL_OSC,
 * 3-MCU_PRECISION_INTERNAL_OSC_DIV4,
 * 4-MCU_INTERNAL_OSC,
 * 5-MCU_HIBERNATION_OSC
 */
 
 
/* pllOption Options:
 * 1-MCU_NO_PLL,
 * 2-MCU_PLL_WITH_DIVISOR,
 * 3-MCU_PLL_WITHOUT_DIVISOR
 */
 
 
/* sysDivisor Options:
 *
 * For MCU_NO_PLL:
 * ---------------
 * 1-From 1 to 64.
 *
 * For MCU_PLL_WITH_DIVISOR:
 * -------------------------
 * 1-From 3 to 64.
 *
 * For MCU_PLL_WITHOUT_DIVISOR:
 * ----------------------------
 * 1- 5
 * 2- 6
 * 3- From 8 to 128.
 */



const Mcu_Config_st McuConfig[MCU_CLOCK_SETTING_CONFIG_PROFILES_NUMBER] =
{
	/*clockSource									pllOption													isRunModeCGC				sysDivisor*/
	{MCU_PRECISION_INTERNAL_OSC	, MCU_NO_PLL											, TRUE							, 1},
};


/* Clock Gates Options:
 * 1-MCU_CLOCK_GATE_WDT_0
 * 2-MCU_CLOCK_GATE_WDT_1
 *
 * 3-MCU_CLOCK_GATE_16_32_GPT_0
 * 4-MCU_CLOCK_GATE_16_32_GPT_1
 * 5-MCU_CLOCK_GATE_16_32_GPT_2
 * 6-MCU_CLOCK_GATE_16_32_GPT_3
 * 7-MCU_CLOCK_GATE_16_32_GPT_4
 * 8-MCU_CLOCK_GATE_16_32_GPT_5
 *
 * 9-MCU_CLOCK_GATE_GPIO_A
 * 10-MCU_CLOCK_GATE_GPIO_B
 * 11-MCU_CLOCK_GATE_GPIO_C
 * 12-MCU_CLOCK_GATE_GPIO_D
 * 13-MCU_CLOCK_GATE_GPIO_E
 * 14-MCU_CLOCK_GATE_GPIO_F
 *
 * 15-MCU_CLOCK_GATE_UDMA
 * 16-MCU_CLOCK_GATE_HIBERNATION
 * 17-MCU_CLOCK_GATE_UART
 * 18-MCU_CLOCK_GATE_SSI
 *
 * 19-MCU_CLOCK_GATE_I2C_0
 * 20-MCU_CLOCK_GATE_I2C_1
 * 21-MCU_CLOCK_GATE_I2C_2
 * 22-MCU_CLOCK_GATE_I2C_3
 *
 * 23-MCU_CLOCK_GATE_USB
 *
 * 24-MCU_CLOCK_GATE_CAN_0
 * 25-MCU_CLOCK_GATE_CAN_1
 *
 * 26-MCU_CLOCK_GATE_ADC_0
 * 27-MCU_CLOCK_GATE_ADC_1
 *
 * 28-MCU_CLOCK_GATE_ANALOG_COMP
 *
 * 29-MCU_CLOCK_GATE_PWM_0
 * 30-MCU_CLOCK_GATE_PWM_1
 *
 * 31-MCU_CLOCK_GATE_QEI
 * 32-MCU_CLOCK_GATE_EEPROM
 *
 * 33-MCU_CLOCK_GATE_32_64_GPT_0
 * 34-MCU_CLOCK_GATE_32_64_GPT_1
 * 35-MCU_CLOCK_GATE_32_64_GPT_2
 * 36-MCU_CLOCK_GATE_32_64_GPT_3
 * 37-MCU_CLOCK_GATE_32_64_GPT_4
 * 38-MCU_CLOCK_GATE_32_64_GPT_5
 *
 *
 * For Sleep Mode TYPE for ex: 				MCU_S_CLOCK_GATE_WDT_0
 * For Deap Sleep Mode TYPE for ex: 	MCU_DS_CLOCK_GATE_WDT_0
 */

Mcu_ClockGate_et WantedClockGate[MCU_CLOCK_GATES_NUMBER] =
{
	MCU_CLOCK_GATE_GPIO_A,
};



