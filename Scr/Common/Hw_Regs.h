#ifndef HW_Regs_H_
#define HW_Regs_H_

#include "Std_Types.h"



#define SYS_CONTROL_BASE_ADDRESS            0x400FE000
#define CORE_PERI_BASE_ADDRESS              0xE000E000

#define RCGC_BASE_ADDRESS								SYS_CONTROL_BASE_ADDRESS + 0x600 //Run Mode Clock Gating Control
#define Enable_BASE_ADDRESS             CORE_PERI_BASE_ADDRESS + 0x100
#define PRI_BASE_ADDRESS                CORE_PERI_BASE_ADDRESS + 0x400



#define RCC                             ((volatile RCC_Tag*)(SYS_CONTROL_BASE_ADDRESS + 0x060))
	

#define RESC														(*((volatile uint32_t*)(SYS_CONTROL_BASE_ADDRESS + 0x05C)))
#define PLLSTAT                         (*((volatile uint32_t*)(SYS_CONTROL_BASE_ADDRESS + 0x168)))

#define APINT                           (*((volatile uint32_t*)(CORE_PERI_BASE_ADDRESS + 0xD0C)))
#define SYSPRI1                         (*((volatile uint32_t*)(CORE_PERI_BASE_ADDRESS + 0xD18)))
#define SYSPRI2                         (*((volatile uint32_t*)(CORE_PERI_BASE_ADDRESS + 0xD1C)))
#define SYSPRI3                         (*((volatile uint32_t*)(CORE_PERI_BASE_ADDRESS + 0xD20)))



typedef struct
{
    uint32_t MOSCDIS          :1;
    uint32_t                  :3;
    uint32_t OSCSRC           :2;
    uint32_t XTAL             :5;
    uint32_t BYPASS           :1;
    uint32_t                  :1;
    uint32_t PWRDN            :1;
    uint32_t                  :3;
    uint32_t PWMDIV           :3;
    uint32_t USEPWMDIV        :1;
    uint32_t                  :1;
    uint32_t USESYSDIV        :1;
    uint32_t SYSDIV           :4;
    uint32_t ACG              :1;
    uint32_t                  :4;

}RCC_BF;

typedef union
{
    uint32_t R;
    RCC_BF B;
}RCC_Tag;
 
#endif  /* HW_Regs_H_ */