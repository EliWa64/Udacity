#include "Std_Types.h"
#include "Mcu_Types.h"
#include "Mcu_Cfg.h"



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
 
 
/* sysDivisor Options:-
 * For MCU_NO_PLL:
 * 1-From 1 to 64.
 *
 * For MCU_PLL_WITH_DIVISOR:
 * 1-From 3 to 64.
 *
 * For MCU_PLL_WITHOUT_DIVISOR:
 * 1- 5
 * 2- 6
 * 3- From 8 to 128.
 */



const Mcu_Config_st McuConfig[MCU_CLOCK_SETTING_CONFIGS_NUMBER] =
{
	/*clockSource								pllOption													isRunModeCGC				sysDivisor*/
	{MCU_MAIN_OSC							, MCU_NO_PLL											, FALSE							, 1},
};



