/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_H_
#define INTCTRL_H_

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "../../Common/Std_Types.h"

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
    GPIO_PORT_A = 0,
    GPIO_PORT_B,
    GPIO_PORT_C,
    GPIO_PORT_D,
    GPIO_PORT_E,
    UART0,
    UART1,
    SSI0,
    I2C0,
    PWM0_FAULT,
    PWM0_GENERATOR_0,
    PWM0_GENERATOR_1,
    PWM0_GENERATOR_2,
    QEI0,
    ADC0_SEQUENCE_0,
    ADC0_SEQUENCE_1,
    ADC0_SEQUENCE_2,
    ADC0_SEQUENCE_3,
    WDT_0_AND_1,
    _16_32_TIMER_0A,
    _16_32_TIMER_0B,
    _16_32_TIMER_1A,
    _16_32_TIMER_1B,
    _16_32_TIMER_2A,
    _16_32_TIMER_2B,
    ANALOG_COMPARATOR_0,
    ANALOG_COMPARATOR_1,

    /*Interrupt number 27 is Reserved*/

    SYSTEM_CONTROL = 28,
    FLASH_MEMORY_CONTROL_AND_EEPROM_CONTROL,
    GPIO_PORT_F,

    /*Interrupt number 31-32 are Reserved*/

    UART2 = 33,
    SSI1,
    _16_32_BIT_TIMER_3A,
    _16_32_BIT_TIMER_3B,
    I2C1,
    QEI1,
    CAN0,
    CAN1,

    /*Interrupt number 41-42 are Reserved*/

    HIBERNATION_MODULE = 43,
    USB,
    PWM_GENERATOR_3,
    UDMA_SOFTWARE,
    UDMA_ERROR,
    ADC1_SEQUENCE_0,
    ADC1_SEQUENCE_1,
    ADC1_SEQUENCE_2,
    ADC1_SEQUENCE_3,

    /*Interrupt number 52-56 are Reserved*/

    SSI2 = 57,
    SSI3,
    UART3,
    UART4,
    UART5,
    UART6,
    UART7,

    /*Interrupt number 64-67 are Reserved*/
    
    I2C2 = 68,
    I2C3,
    _16_32_BIT_TIMER_4A,
    _16_32_BIT_TIMER_4B,

    /*Interrupt number 72-91 are Reserved*/
    
    _16_32_BIT_TIMER_5A = 92,
    _16_32_BIT_TIMER_5B,
    _32_64_BIT_TIMER_0A,
    _32_64_BIT_TIMER_0B,
    _32_64_BIT_TIMER_1A,
    _32_64_BIT_TIMER_1B,
    _32_64_BIT_TIMER_2A,
    _32_64_BIT_TIMER_2B,
    _32_64_BIT_TIMER_3A,
    _32_64_BIT_TIMER_3B,
    _32_64_BIT_TIMER_4A,
    _32_64_BIT_TIMER_4B,
    _32_64_BIT_TIMER_5A,
    _32_64_BIT_TIMER_5B,
    SYSTEM_EXCEPTION,

    /*Interrupt number 107-133 are Reserved*/
    
    PWM1_GENERATOR_0 = 134,
    PWM1_GENERATOR_1,
    PWM1_GENERATOR_2,
    PWM1_GENERATOR_3,
    PWM1_FAULT
}IntCtrl_Interrupt_et;


typedef struct
{
    IntCtrl_Interrupt_et   interruptNumber;
    uint8_t groupPriority;
    uint8_t subPriority;
    uint8_t isEnabled;
}IntCtrl_Interrupt_st;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

 
#endif  /* INTCTRL_H_ */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
