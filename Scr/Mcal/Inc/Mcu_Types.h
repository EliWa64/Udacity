/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef MCU_TYPES_H_
#define MCU_TYPES_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/

typedef enum
{
	MCU_CLOCK_GATE_WDT_0 = 0,
	MCU_CLOCK_GATE_WDT_1,
	
	MCU_CLOCK_GATE_16_32_GPT_0 = 10,
	MCU_CLOCK_GATE_16_32_GPT_1,
	MCU_CLOCK_GATE_16_32_GPT_2,
	MCU_CLOCK_GATE_16_32_GPT_3,
	MCU_CLOCK_GATE_16_32_GPT_4,
	MCU_CLOCK_GATE_16_32_GPT_5,
	
	MCU_CLOCK_GATE_GPIO_A = 20,
	MCU_CLOCK_GATE_GPIO_B,
	MCU_CLOCK_GATE_GPIO_C,
	MCU_CLOCK_GATE_GPIO_D,
	MCU_CLOCK_GATE_GPIO_E,
	MCU_CLOCK_GATE_GPIO_F,
	
	MCU_CLOCK_GATE_UDMA = 30,
	
	MCU_CLOCK_GATE_HIBERNATION = 50,
	
	MCU_CLOCK_GATE_UART = 60,
	
	MCU_CLOCK_GATE_SSI = 70,
	
	MCU_CLOCK_GATE_I2C_0 = 80,
	MCU_CLOCK_GATE_I2C_1,
	MCU_CLOCK_GATE_I2C_2,
	MCU_CLOCK_GATE_I2C_3,
	
	MCU_CLOCK_GATE_USB = 100,
	
	MCU_CLOCK_GATE_CAN_0 = 130,
	MCU_CLOCK_GATE_CAN_1,
	
	MCU_CLOCK_GATE_ADC_0 = 140,
	MCU_CLOCK_GATE_ADC_1,
	
	MCU_CLOCK_GATE_ANALOG_COMP = 150,
	
	MCU_CLOCK_GATE_PWM_0 = 160,
	MCU_CLOCK_GATE_PWM_1,
	
	MCU_CLOCK_GATE_QEI = 170,
	
	MCU_CLOCK_GATE_EEPROM = 220,
	
	MCU_CLOCK_GATE_32_64_GPT_0 = 230,
	MCU_CLOCK_GATE_32_64_GPT_1,
	MCU_CLOCK_GATE_32_64_GPT_2,
	MCU_CLOCK_GATE_32_64_GPT_3,
	MCU_CLOCK_GATE_32_64_GPT_4,
	MCU_CLOCK_GATE_32_64_GPT_5,
	
	
	
	MCU_S_MODE_CLOCK_GATE_WDT_0 = 640,
	MCU_S_MODE_CLOCK_GATE_WDT_1,
	
	MCU_S_MODE_CLOCK_GATE_16_32_GPT_0 = 650,
	MCU_S_MODE_CLOCK_GATE_16_32_GPT_1,
	MCU_S_MODE_CLOCK_GATE_16_32_GPT_2,
	MCU_S_MODE_CLOCK_GATE_16_32_GPT_3,
	MCU_S_MODE_CLOCK_GATE_16_32_GPT_4,
	MCU_S_MODE_CLOCK_GATE_16_32_GPT_5,
	
	MCU_S_MODE_CLOCK_GATE_GPIO_A = 660,
	MCU_S_MODE_CLOCK_GATE_GPIO_B,
	MCU_S_MODE_CLOCK_GATE_GPIO_C,
	MCU_S_MODE_CLOCK_GATE_GPIO_D,
	MCU_S_MODE_CLOCK_GATE_GPIO_E,
	MCU_S_MODE_CLOCK_GATE_GPIO_F,
	
	MCU_S_MODE_CLOCK_GATE_UDMA = 670,
	
	MCU_S_MODE_CLOCK_GATE_HIBERNATION = 690,
	
	MCU_S_MODE_CLOCK_GATE_UART = 700,
	
	MCU_S_MODE_CLOCK_GATE_SSI = 710,
	
	MCU_S_MODE_CLOCK_GATE_I2C_0 = 720,
	MCU_S_MODE_CLOCK_GATE_I2C_1,
	MCU_S_MODE_CLOCK_GATE_I2C_2,
	MCU_S_MODE_CLOCK_GATE_I2C_3,
	
	MCU_S_MODE_CLOCK_GATE_USB = 740,
	
	MCU_S_MODE_CLOCK_GATE_CAN_0 = 770,
	MCU_S_MODE_CLOCK_GATE_CAN_1,
	
	MCU_S_MODE_CLOCK_GATE_ADC_0 = 780,
	MCU_S_MODE_CLOCK_GATE_ADC_1,
	
	MCU_S_MODE_CLOCK_GATE_ANALOG_COMP = 790,
	
	MCU_S_MODE_CLOCK_GATE_PWM_0 = 800,
	MCU_S_MODE_CLOCK_GATE_PWM_1,
	
	MCU_S_MODE_CLOCK_GATE_QEI = 810,
	
	MCU_S_MODE_CLOCK_GATE_EEPROM = 860,
	
	MCU_S_MODE_CLOCK_GATE_32_64_GPT_0 = 870,
	MCU_S_MODE_CLOCK_GATE_32_64_GPT_1,
	MCU_S_MODE_CLOCK_GATE_32_64_GPT_2,
	MCU_S_MODE_CLOCK_GATE_32_64_GPT_3,
	MCU_S_MODE_CLOCK_GATE_32_64_GPT_4,
	MCU_S_MODE_CLOCK_GATE_32_64_GPT_5,
	
	
	
	MCU_DS_MODE_CLOCK_GATE_WDT_0 = 1280,
	MCU_DS_MODE_CLOCK_GATE_WDT_1,
	
	MCU_DS_MODE_CLOCK_GATE_16_32_GPT_0 = 1290,
	MCU_DS_MODE_CLOCK_GATE_16_32_GPT_1,
	MCU_DS_MODE_CLOCK_GATE_16_32_GPT_2,
	MCU_DS_MODE_CLOCK_GATE_16_32_GPT_3,
	MCU_DS_MODE_CLOCK_GATE_16_32_GPT_4,
	MCU_DS_MODE_CLOCK_GATE_16_32_GPT_5,
	
	MCU_DS_MODE_CLOCK_GATE_GPIO_A = 1300,
	MCU_DS_MODE_CLOCK_GATE_GPIO_B,
	MCU_DS_MODE_CLOCK_GATE_GPIO_C,
	MCU_DS_MODE_CLOCK_GATE_GPIO_D,
	MCU_DS_MODE_CLOCK_GATE_GPIO_E,
	MCU_DS_MODE_CLOCK_GATE_GPIO_F,
	
	MCU_DS_MODE_CLOCK_GATE_UDMA = 1310,
	
	MCU_DS_MODE_CLOCK_GATE_HIBERNATION = 1330,
	
	MCU_DS_MODE_CLOCK_GATE_UART = 1340,
	
	MCU_DS_MODE_CLOCK_GATE_SSI = 1350,
	
	MCU_DS_MODE_CLOCK_GATE_I2C_0 = 1360,
	MCU_DS_MODE_CLOCK_GATE_I2C_1,
	MCU_DS_MODE_CLOCK_GATE_I2C_2,
	MCU_DS_MODE_CLOCK_GATE_I2C_3,
	
	MCU_DS_MODE_CLOCK_GATE_USB = 1380,
	
	MCU_DS_MODE_CLOCK_GATE_CAN_0 = 1410,
	MCU_DS_MODE_CLOCK_GATE_CAN_1,
	
	MCU_DS_MODE_CLOCK_GATE_ADC_0 = 1420,
	MCU_DS_MODE_CLOCK_GATE_ADC_1,
	
	MCU_DS_MODE_CLOCK_GATE_ANALOG_COMP = 1430,
	
	MCU_DS_MODE_CLOCK_GATE_PWM_0 = 1440,
	MCU_DS_MODE_CLOCK_GATE_PWM_1,
	
	MCU_DS_MODE_CLOCK_GATE_QEI = 1450,
	
	MCU_DS_MODE_CLOCK_GATE_EEPROM = 1500,
	
	MCU_DS_MODE_CLOCK_GATE_32_64_GPT_0 = 1510,
	MCU_DS_MODE_CLOCK_GATE_32_64_GPT_1,
	MCU_DS_MODE_CLOCK_GATE_32_64_GPT_2,
	MCU_DS_MODE_CLOCK_GATE_32_64_GPT_3,
	MCU_DS_MODE_CLOCK_GATE_32_64_GPT_4,
	MCU_DS_MODE_CLOCK_GATE_32_64_GPT_5,
}Mcu_ClockGate_et;



typedef enum
{
	MCU_MAIN_OSC,
	MCU_PRECISION_INTERNAL_OSC,
	MCU_PRECISION_INTERNAL_OSC_DIV4,
	MCU_INTERNAL_OSC,
	MCU_HIBERNATION_OSC = 7
}Mcu_ClockSource_et;

typedef enum
{
	MCU_NO_PLL,
	MCU_PLL_WITH_DIVISOR,
	MCU_PLL_WITHOUT_DIVISOR
}Mcu_PllOption_et;



typedef struct
{
	Mcu_ClockSource_et clockSource;
	Mcu_PllOption_et pllOption;
	boolean isRunModeCGC; //Clock Gating Control (CGC).
	uint8_t sysDivisor; //Valuse 3-64 for (MCU_PLL_WITH_DIVISOR), and 5-128 except 7 for (MCU_PLL_WITHOUT_DIVISOR)
}Mcu_Config_st;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* MCU_TYPES_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Types.h
 *********************************************************************************************************************/
