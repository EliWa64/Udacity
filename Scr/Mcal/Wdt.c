/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Wdt.c
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
#include "Hw_Regs.h"
#include "Mcu.h"
#include "Wdt_Cfg.h"
#include "Wdt.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

#define INTEN_OFFSET        0
#define RESEN_OFFSET        1
#define INTTYPE_OFFSET      2
#define WRC_OFFSET          31

#define WDT1_LOCK_KEY       0x1ACCE551
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
volatile Wdg_MaxTimeout_t maxTimeout;

void (*p_toFun)(void);
/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

void Wdg_Init(const Wdg_Config_st* p_config)
{
    uint8_t loc_notifiEnable, loc_interruptType, loc_hasReset;
    uint16_t loc_initialTimeout_ms, loc_maxTimeout_ms;

    loc_notifiEnable = p_config->notificationEnable;
    loc_interruptType = p_config->interruptType;
    loc_hasReset = p_config->hasReset;
    loc_initialTimeout_ms = p_config->intialTimeout_ms;
    loc_maxTimeout_ms = p_config->maxTimeout_ms;
    maxTimeout = loc_maxTimeout_ms;

	uint32_t x = (loc_initialTimeout_ms * Mcu_getSysClockFreq()) / 1000;
    /*Load Watch dog timer.*/
    WDTLOAD(WDT1_BASE_ADDRESS) = x;

    while(!(WDTCTL(WDT1_BASE_ADDRESS)>>WRC_OFFSET)); //Wait for the write complete.

    /*Configer Reset Enable bit if wanted or not.*/
    if(loc_hasReset == TRUE)
    {
        WDTCTL(WDT1_BASE_ADDRESS) |= 1<<RESEN_OFFSET;
    } //if
    else if(loc_hasReset == FALSE)
    {
        WDTCTL(WDT1_BASE_ADDRESS) &= ~(1<<RESEN_OFFSET);
    } //else if
    
    while(!(WDTCTL(WDT1_BASE_ADDRESS)>>WRC_OFFSET)); //Wait for the write complete.

    /*Init Interrupt Type.*/
    if(loc_interruptType == WDG_INT_STANDARD)
    {
        WDTCTL(WDT1_BASE_ADDRESS) &= ~(1<<INTTYPE_OFFSET);
    } //if
    else if (loc_interruptType == WDG_INT_NMI)
    {
        WDTCTL(WDT1_BASE_ADDRESS) |= 1<<INTTYPE_OFFSET;
    }

    if(loc_notifiEnable == WDG_NOTIFICATION_ENABLE)
    {
        p_toFun = p_CallBack_Fun;
    } //if
    else if (loc_notifiEnable == WDG_NOTIFICATION_DISABLE)
    {
        p_toFun = NULL_PTR;
    } //else if
    
    /*Enables the Interrupt and the WDT*/
    WDTCTL(WDT1_BASE_ADDRESS) |= 1<<INTEN_OFFSET;
    
    WDTLOCK(WDT1_BASE_ADDRESS) = 1; //Activate the lock for WDT1.

} /*Wdg_Init*/



void Wdg_SetTriggerCondition(uint16_t timeout_ms)
{
    if(timeout_ms <= maxTimeout)
    {
        WDTLOCK(WDT1_BASE_ADDRESS) = WDT1_LOCK_KEY; //Deactivate the lock for WDT1.
        while(WDTLOCK(WDT1_BASE_ADDRESS));
        /*Load Watch dog timer.*/
        WDTLOAD(WDT1_BASE_ADDRESS) = (timeout_ms * Mcu_getSysClockFreq()) / 1000;
        while(!(WDTCTL(WDT1_BASE_ADDRESS)>>WRC_OFFSET)); //Wait for the write complete.
        WDTLOCK(WDT1_BASE_ADDRESS) = 1; //Activate the lock for WDT1.
    } //if
    else
    {
        //Do Nothing.
    } //else
} /*Wdg_SetTriggerCondition*/


void WDT0_Handler(void)
{
    if(p_toFun != NULL_PTR)
    {
        p_toFun();
    } //if
		
    WDTICR(WDT1_BASE_ADDRESS) = 1;
} /*Wdg_Isr*/


/**********************************************************************************************************************
 *  END OF FILE: Wdt.c
 *********************************************************************************************************************/
