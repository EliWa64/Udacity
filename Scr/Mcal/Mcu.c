/**        \file  Mcu.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Hw_Regs.h"
#include "Mcu_Cfg.h"
#include "Mcu.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/


#ifndef F_MAINOSC
#error F_MAINOSC is NOT DEFINED.
#endif

#define F_PLL_WITHOUT_DIV							400000000UL
#define F_PLL_WITH_DIV								200000000UL
#define F_PIOSC										16000000UL
#define F_IOSC										30000U
#define F_HIOSC										32768U

#define APINT_VECTKEY           					0x05FA
#define SYSRESREQ_BIT_OFFSET						2

extern Mcu_ClockGate_et WantedClockGate[MCU_CLOCK_GATES_NUMBER];

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

volatile uint32_t clockSourceFreq;
volatile uint32_t RccForTest;

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

Std_ErrorState_et Mcu_Init(const Mcu_Config_st* p_configStdType)
{
	uint8_t loc_ErrorState = OK;
	uint8_t loc_clockSource, loc_pllOption, loc_sysDivisor;
	boolean loc_isRunModeCGC;

	loc_clockSource = p_configStdType->clockSource;
	loc_pllOption = p_configStdType->pllOption;
	loc_sysDivisor = p_configStdType->sysDivisor;

	/*Check the validation of input data*/
	if((loc_clockSource >= MCU_PRECISION_INTERNAL_OSC_DIV4) && (loc_pllOption != MCU_NO_PLL))
	{
		loc_ErrorState = NOK;
		return loc_ErrorState;
	}
		
	RCC->B.BYPASS = LOGIC_HIGH;	//Bypass PLL
		
	/*Initialize the clock source*/
	if((loc_clockSource == MCU_MAIN_OSC) || (loc_clockSource == MCU_PRECISION_INTERNAL_OSC))
	{
		RCC->B.OSCSRC = loc_clockSource; //Assign OSC source.
				
		if(loc_clockSource == MCU_MAIN_OSC)
		{
			RCC->B.MOSCDIS = LOGIC_LOW;	//Enable Main OSC.
			clockSourceFreq = F_MAINOSC / loc_sysDivisor;
		}
		else
		{
			clockSourceFreq = F_PIOSC / loc_sysDivisor;
			//How to enable Precision Internal OSC?!!!!!
		}
	}
	else if(loc_clockSource == MCU_PRECISION_INTERNAL_OSC_DIV4)
	{
		RCC->B.OSCSRC = loc_clockSource; //Assign OSC source.
		//How to enable Precision Internal OSC?!!!!!
		clockSourceFreq = (F_PIOSC/4) / loc_sysDivisor;
	}
	else if(loc_clockSource == MCU_INTERNAL_OSC)
	{
		RCC->B.OSCSRC = loc_clockSource; //Assign OSC source.
		clockSourceFreq = F_IOSC / loc_sysDivisor;
	}
	else if(loc_clockSource == MCU_HIBERNATION_OSC)
	{
		//TODO: init in RCC2.
		clockSourceFreq = F_HIOSC / loc_sysDivisor;
	}
		
	/*Init clock paths and system division*/
	if(loc_pllOption == MCU_NO_PLL)
	{
		RCC->B.XTAL = MCU_XTAL_VALUE_SEL;
		RCC->B.SYSDIV = loc_sysDivisor; //									RCC/RCC2
		RCC->B.USESYSDIV = LOGIC_HIGH;	//Use sys clock divider.
	} //if
	else if(loc_pllOption == MCU_PLL_WITH_DIVISOR)
	{
		RCC->B.USESYSDIV = LOGIC_LOW;	//Not use sys clock divider.
		RCC->B.XTAL = MCU_XTAL_VALUE_SEL;
		RCC->B.PWRDN = LOGIC_LOW;	//Power PLL up.							RCC/RCC2
		RCC->B.SYSDIV = loc_sysDivisor; //									RCC/RCC2
		RCC->B.USESYSDIV = LOGIC_HIGH;	//Use sys clock divider.
		//while(!GET_BIT(RIS,6)); //Wait for the PLL to lock.
		//RCC->B.BYPASS = LOGIC_LOW;	//Use PLL.

		clockSourceFreq = F_PLL_WITH_DIV / loc_sysDivisor;
	} //else if
	else if(loc_pllOption == MCU_PLL_WITHOUT_DIVISOR)
	{
		//TODO: init MCU_PLL_WITHOUT_DIVISOR 								RCC/RCC2
		clockSourceFreq = F_PLL_WITHOUT_DIV / loc_sysDivisor;
	} //else if
		
		
	/*Init Clock Gating Control*/
	RCC->B.ACG = ~loc_isRunModeCGC;
	uint8_t i;
	for(i=0; i<MCU_CLOCK_GATES_NUMBER; i++)
	{
		uint8_t loc_numberOfCGCReg = WantedClockGate[i] / 10;
		uint8_t loc_numberOfCGCBit = WantedClockGate[i] % 10;
			
		volatile uint32_t *p_wantedClockGateReg = ((uint32_t*)(RCGC_BASE_ADDRESS)) + loc_numberOfCGCReg;
		*p_wantedClockGateReg |= (1 << loc_numberOfCGCBit);
		uint32_t x = *p_wantedClockGateReg;
	} //for
	
	RccForTest = RCC->R;
	return loc_ErrorState;
} /*Mcu_Init*/



Mcu_PllStatus_et Mcu_GetPllStatus(void)
{
		return PLLSTAT;
} /*Mcu_GetPllStatus*/


Std_ErrorState_et Mcu_DistributePllClock(void)
{
	uint8_t loc_ErrorState = NOK;
		
	if(Mcu_GetPllStatus() != MCU_PLLSTATUS_UNPOWERED_OR_UNLOCKED)
	{
		RCC->B.BYPASS = LOGIC_LOW;	//Use PLL.
		loc_ErrorState = OK;
	} //if
	return loc_ErrorState;
} /*Mcu_DistributePllClock*/


void Mcu_PerformReset(void)
{
	RESC = 0; //Clear Reset Cause.
	APINT = (APINT_VECTKEY << 16) | (1 << SYSRESREQ_BIT_OFFSET);
} /*Mcu_PerformReset*/


Mcu_RawReset_et Mcu_GetResetRawValue(void)
{
	uint32_t loc_resetCause = RESC;
	RESC = 0;
	return loc_resetCause;
} /*Mcu_GetResetRawValue*/


uint32_t Mcu_getSysClockFreq()
{
	return clockSourceFreq;
} /*Mcu_getSysClockFreq*/