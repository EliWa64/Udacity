#ifndef MCU_H_
#define MCU_H_

#include "Mcu_Types.h"

typedef enum
{
	MCU_PLLSTATUS_UNPOWERED_OR_UNLOCKED,
	MCU_PLLSTATUS_LOCKED
}Mcu_PllStatus_et;

typedef enum
{
	MCU_EXTERNAL_RESET,
	MCU_POWER_ON_RESET,
	MCU_BROWN_OUT_RESET,
	MCU_WD_TMR0_RESET,
	MCU_SOFTWARE_RESET,
	MCU_WD_TMR1_RESET,
	MCU_MOSC_FAILURE_RESET = 16
}Mcu_RawReset_et;

Std_ErrorState_et Mcu_Init(const Mcu_Config_st* p_configStdType);
Std_ErrorState_et Mcu_DistributePllClock(void);
Mcu_RawReset_et Mcu_GetResetRawValue(void);
Mcu_PllStatus_et Mcu_GetPllStatus(void);

void Mcu_PerformReset(void);

#endif  /* MCU_H_ */