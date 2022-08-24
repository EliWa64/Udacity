/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

/*****************************************************INCLUDES********************************************************/
#include "Std_Types.h"
#include "IntCtrl_Cfg.h"
#include "Hw_Regs.h"
#include "IntCtrl_Types.h"
#include "IntCtrl.h"

/******************************************LOCAL MACROS CONSTANT\FUNCTION*********************************************/
#define APINT_VECTKEY           0x05FA

extern IntCtrl_Interrupt_st interrupts[NUMBER_OF_USED_INTERRUPTS];

/*
 * Syntax          : void IntCtrl_Init(void)        
 * Description     : Describe this service                                    
 *                                                                             
 * Sync\Async      : Synchronous                                               
 * Reentrancy      : Non Reentrant                                             
 * Parameters (in) : None                    
 * Parameters (out): None                                                      
 * Return value:   : None                                 
 */
void IntCtrl_Init(void)
{
	uint8_t interruptNumber, numberOfPriReg, numberOfPriBitsOffset, i, numberOfEnReg, numberOfEnBit;
	uint32_t priReg, enReg;
	volatile uint32_t *p_wantedPriRegAddress, *p_wantedEnRegAddress;

	/*TODO: Configure Grouping/Subgrouping system in APINT register in SCB.*/
  APINT = (APINT_VECTKEY << 16) | (INTCTRL_INTERRUPT_PRIORITY_LEVEL_SEL << 8);

	/*TODO: Assign Group/Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers.*/
	for(i=0; i<NUMBER_OF_USED_INTERRUPTS; i++)
	{
		interruptNumber = interrupts[i].interruptNumber;
		numberOfPriReg = interruptNumber / 4;
		numberOfPriBitsOffset = ((interruptNumber%4) * 8) + 5;

		p_wantedPriRegAddress = ((uint32_t*)(PRI_BASE_ADDRESS)) + numberOfPriReg;
		priReg = *p_wantedPriRegAddress;
        
#if INTCTRL_INTERRUPT_PRIORITY_LEVEL_SEL == 0x4
		priReg |= (uint32_t)(interrupts[i].groupPriority << numberOfPriBitsOffset);
#elif INTCTRL_INTERRUPT_PRIORITY_LEVEL_SEL == 0x5
		priReg |= (uint32_t)(((interrupts[i].groupPriority)<<1 | interrupts[i].subPriority) << numberOfPriBitsOffset);
#elif INTCTRL_INTERRUPT_PRIORITY_LEVEL_SEL == 0x6
		priReg |= (uint32_t)(((interrupts[i].groupPriority<<2) | interrupts[i].subPriority) << numberOfPriBitsOffset);
#elif INTCTRL_INTERRUPT_PRIORITY_LEVEL_SEL == 0x7
		priReg |= (uint32_t)(interrupts[i].subPriority << numberOfPriBitsOffset);
#else
#error Interrupt Priority Level is not VALID.
#endif
		*p_wantedPriRegAddress = priReg;
	} //for
	
	SYSPRI1 = (USAGE_FAULT_PRIORITY<<21) | (BUS_FAULT_PRIORITY<<13) | (MEMORY_MANAGEMENT_FAULT_PRIORITY<<5);
	SYSPRI2 = SVCALL_PRIORITY<<29;
	SYSPRI3 = (SYSTICK_EXCEPTION_PRIORITY<<29) | (PENDSV_PRIORITY<<21) | (DEBUG_PRIORITY<<5);

	/*TODO: Enable/Disable based on user configuration in NVIC_ENx and SCB_SYS Registers.*/
	for(i=0; i<NUMBER_OF_USED_INTERRUPTS; i++)
	{
		if(interrupts[i].isEnabled == TRUE)
		{
			interruptNumber = interrupts[i].interruptNumber;
			numberOfEnReg = interruptNumber / 32;
			numberOfEnBit = interruptNumber - (numberOfEnReg * 32);

			p_wantedEnRegAddress = ((uint32_t*)(Enable_BASE_ADDRESS)) + numberOfEnReg;
			enReg = *p_wantedEnRegAddress; //Read.
			enReg |= (1<<numberOfEnBit); //Modify
			*p_wantedEnRegAddress = enReg; //Write
		} //if
	} //for
} //IntCtrl_Init

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
