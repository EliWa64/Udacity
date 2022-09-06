#ifndef HW_Regs_H_
#define HW_Regs_H_

#include "Std_Types.h"




#define GPIO_DIR_OFFSET                     0x400
#define GPIO_IS_OFFSET                      0x404
#define GPIO_IBE_OFFSET                     0x408
#define GPIO_IEV_OFFSET                     0x40C
#define GPIO_IM_OFFSET                      0x410
#define GPIO_ICR_OFFSET                     0x41C
#define GPIO_AFSEL_OFFSET                   0x420
#define GPIO_DR2R_OFFSET                    0x500
#define GPIO_DR4R_OFFSET                    0x504
#define GPIO_DR8R_OFFSET                    0x508
#define GPIO_ODR_OFFSET                     0x50C
#define GPIO_PUR_OFFSET                     0x510
#define GPIO_PDR_OFFSET                     0x514
#define GPIO_DEN_OFFSET                     0x51C
#define GPIO_LOCK_OFFSET                    0x520
#define GPIO_CR_OFFSET                      0x524
#define GPIO_AMSEL_OFFSET                   0x528
#define GPIO_PCTRL_OFFSET                   0x52C


#define GPIO_APB_BASE_ADDRESS_A             0x40004000
#define GPIO_APB_BASE_ADDRESS_B             0x40005000
#define GPIO_APB_BASE_ADDRESS_C             0x40006000
#define GPIO_APB_BASE_ADDRESS_D             0x40007000
#define GPIO_APB_BASE_ADDRESS_E             0x40024000
#define GPIO_APB_BASE_ADDRESS_F             0x40025000

#define SYS_CONTROL_BASE_ADDRESS            0x400FE000
#define CORE_PERI_BASE_ADDRESS              0xE000E000

#define RCGC_BASE_ADDRESS				    SYS_CONTROL_BASE_ADDRESS + 0x600 //Run Mode Clock Gating Control
#define Enable_BASE_ADDRESS                 CORE_PERI_BASE_ADDRESS + 0x100
#define PRI_BASE_ADDRESS                    CORE_PERI_BASE_ADDRESS + 0x400


#define RCC                                 ((volatile RCC_Tag*)(SYS_CONTROL_BASE_ADDRESS + 0x060))
	
#define GPIOPDIR(BASE_ADDRESS)              (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_DIR_OFFSET)))
#define GPIOIS(BASE_ADDRESS)                (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_IS_OFFSET)))
#define GPIOIBE(BASE_ADDRESS)               (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_IBE_OFFSET)))
#define GPIOIEV(BASE_ADDRESS)                (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_IEV_OFFSET)))
#define GPIOIM(BASE_ADDRESS)                (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_IM_OFFSET)))
#define GPIOICR(BASE_ADDRESS)                (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_ICR_OFFSET)))
#define GPIOAFSEL(BASE_ADDRESS)             (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_AFSEL_OFFSET)))
#define GPIODR2R(BASE_ADDRESS)              (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_DR2R_OFFSET)))
#define GPIODR4R(BASE_ADDRESS)              (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_DR4R_OFFSET)))
#define GPIODR8R(BASE_ADDRESS)              (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_DR8R_OFFSET)))
#define GPIOODR(BASE_ADDRESS)               (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_ODR_OFFSET)))
#define GPIOPUR(BASE_ADDRESS)               (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_PUR_OFFSET)))
#define GPIOPDR(BASE_ADDRESS)               (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_PDR_OFFSET)))
#define GPIODEN(BASE_ADDRESS)               (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_DEN_OFFSET)))
#define GPIOLOCK(BASE_ADDRESS)              (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_LOCK_OFFSET)))
#define GPIOCR(BASE_ADDRESS)                (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_CR_OFFSET)))
#define GPIOAMSEL(BASE_ADDRESS)             (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_AMSEL_OFFSET)))
#define GPIOPCTRL(BASE_ADDRESS)             (*((volatile uint32_t*)(BASE_ADDRESS + GPIO_PCTRL_OFFSET)))


#define GPIOLOCK_APB_PORT_A                 (*((volatile uint32_t*)(GPIO_APB_BASE_ADDRESS_A + 0x520)))
#define GPIOLOCK_APB_PORT_B                 (*((volatile uint32_t*)(GPIO_APB_BASE_ADDRESS_B + 0x520)))
#define GPIOLOCK_APB_PORT_C                 (*((volatile uint32_t*)(GPIO_APB_BASE_ADDRESS_C + 0x520)))
#define GPIOLOCK_APB_PORT_D                 (*((volatile uint32_t*)(GPIO_APB_BASE_ADDRESS_D + 0x520)))
#define GPIOLOCK_APB_PORT_E                 (*((volatile uint32_t*)(GPIO_APB_BASE_ADDRESS_E + 0x520)))
#define GPIOLOCK_APB_PORT_F                 (*((volatile uint32_t*)(GPIO_APB_BASE_ADDRESS_F + 0x520)))
#define RESC							    (*((volatile uint32_t*)(SYS_CONTROL_BASE_ADDRESS + 0x05C)))
#define PLLSTAT                             (*((volatile uint32_t*)(SYS_CONTROL_BASE_ADDRESS + 0x168)))

#define APINT                               (*((volatile uint32_t*)(CORE_PERI_BASE_ADDRESS + 0xD0C)))
#define SYSPRI1                             (*((volatile uint32_t*)(CORE_PERI_BASE_ADDRESS + 0xD18)))
#define SYSPRI2                             (*((volatile uint32_t*)(CORE_PERI_BASE_ADDRESS + 0xD1C)))
#define SYSPRI3                             (*((volatile uint32_t*)(CORE_PERI_BASE_ADDRESS + 0xD20)))



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