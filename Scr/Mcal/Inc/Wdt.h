/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Wdt.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef WDT_H_
#define WDT_H_

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
typedef uint32_t Wdg_InitialTimeout_t;
typedef uint32_t Wdg_MaxTimeout_t ;


typedef enum{
	WDG_NOTIFICATION_DISABLE,
	WDG_NOTIFICATION_ENABLE
}Wdg_NotificationEnable_et;

typedef enum{
	WDG_INT_STANDARD,
	WDG_INT_NMI
}Wdg_InterruptType_et;


typedef struct{
	Wdg_NotificationEnable_et   notificationEnable;
	Wdg_InterruptType_et        interruptType;
	uint8_t 					hasReset;
	Wdg_InitialTimeout_t        intialTimeout_ms;
	Wdg_MaxTimeout_t            maxTimeout_ms;
}Wdg_Config_st;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Wdg_Init(const Wdg_Config_st* p_config);
void Wdg_SetTriggerCondition(uint16_t timeout_ms);
 
#endif  /* WDT_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Wdt.h
 *********************************************************************************************************************/