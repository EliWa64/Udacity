/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port_Lcfg.c
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
#include "Port.h"
#include "Port_Cfg.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

/* pinId Options:
 * -------------
 * 1-PORT_PIN_A0
 * 2-PORT_PIN_A1,
 * 3-PORT_PIN_A2,
 * 4-PORT_PIN_A3,
 * 5-PORT_PIN_A4,
 * 6-PORT_PIN_A5,
 * 7-PORT_PIN_A6,
 * 8-PORT_PIN_A7,
 *
 * 9-PORT_PIN_B0,
 * 10-PORT_PIN_B1,
 * 11-PORT_PIN_B2,
 * 12-PORT_PIN_B3,
 * 13-PORT_PIN_B4,
 * 14-PORT_PIN_B5,
 * 15-PORT_PIN_B6,
 * 16-PORT_PIN_B7,
 *
 * 17-PORT_PIN_C0,
 * 18-PORT_PIN_C1,
 * 19-PORT_PIN_C2,
 * 20-PORT_PIN_C3,
 * 21-PORT_PIN_C4,
 * 22-PORT_PIN_C5,
 * 23-PORT_PIN_C6,
 * 24-PORT_PIN_C7,
 *
 * 25-PORT_PIN_D0,
 * 26-PORT_PIN_D1,
 * 27-PORT_PIN_D2,
 * 28-PORT_PIN_D3,
 * 29-PORT_PIN_D4,
 * 30-PORT_PIN_D5,
 * 31-PORT_PIN_D6,
 * 32-PORT_PIN_D7,
 *
 * 33-PORT_PIN_E0,
 * 34-PORT_PIN_E1,
 * 35-PORT_PIN_E2,
 * 36-PORT_PIN_E3,
 * 37-PORT_PIN_E4,
 * 38-PORT_PIN_E5,
 *
 * 39-PORT_PIN_F0,
 * 40-PORT_PIN_F1,
 * 41-PORT_PIN_F2,
 * 42-PORT_PIN_F3,
 * 43-PORT_PIN_F4,
 */



/* PinMode Options:
 * ---------------
 * 1-PORT_PIN_MODE_X_ANALOG
 *
 * 2-PORT_PIN_MODE_X_DIO
 *
 * 3-PORT_PIN_MODE_PA0_U0RX
 * 4-PORT_PIN_MODE_PA1_U0TX
 * 5-PORT_PIN_MODE_PA0_CAN1RX
 * 6-PORT_PIN_MODE_PA1_CAN1TX
 * 7-PORT_PIN_MODE_PA2_SSI0ClK
 * 8-PORT_PIN_MODE_PA3_SSI0FSS
 * 9-PORT_PIN_MODE_PA4_SSI0R
 * 10-PORT_PIN_MODE_PA5_SSI0TX
 * 11-PORT_PIN_MODE_PA6_I2C1SCL
 * 12-PORT_PIN_MODE_PA7_I2C1SDA
 * 13-PORT_PIN_MODE_PA6_M1PWM2
 * 14-PORT_PIN_MODE_PA7_M1PWM3
 *
 * 15-PORT_PIN_MODE_PB0_U1RX	
 * 16-PORT_PIN_MODE_PB1_U1TX	
 * 17-PORT_PIN_MODE_PB2_I2C0SCL
 * 18-PORT_PIN_MODE_PB3_I2C0SDA
 * 19-PORT_PIN_MODE_PB4_SSI2Clk
 * 20-PORT_PIN_MODE_PB5_SSI2FSS
 * 21-PORT_PIN_MODE_PB6_SSI2RX
 * 22-PORT_PIN_MODE_PB7_SSI2TX
 * 23-PORT_PIN_MODE_PB4_M0PWM2
 * 24-PORT_PIN_MODE_PB5_M0PWM3
 * 25-PORT_PIN_MODE_PB6_M0PWM0
 * 26-PORT_PIN_MODE_PB7_M0PWM1
 * 27-PORT_PIN_MODE_PB4_CAN0RX
 * 28-PORT_PIN_MODE_PB5_CAN0TX
 * 29-PORT_PIN_MODE_PB0_T2CCP0
 * 30-PORT_PIN_MODE_PB1_T2CCP1
 * 31-PORT_PIN_MODE_PB2_T3CCP0
 * 32-PORT_PIN_MODE_PB3_T3CCP1
 * 33-PORT_PIN_MODE_PB4_T1CCP0
 * 34-PORT_PIN_MODE_PB5_T1CCP1
 * 35-PORT_PIN_MODE_PB6_T0CCP0
 * 36-PORT_PIN_MODE_PB7_T0CCP1
 *
 * 37-PORT_PIN_MODE_PC0_TCK_SWCLK
 * 38-PORT_PIN_MODE_PC1_TMS_SWDIO
 * 39-PORT_PIN_MODE_PC2_TDI
 * 40-PORT_PIN_MODE_PC3_TDO_SWO	
 * 41-PORT_PIN_MODE_PC4_U4RX
 * 42-PORT_PIN_MODE_PC5_U4TX
 * 43-PORT_PIN_MODE_PC6_U3RX
 * 44-PORT_PIN_MODE_PC7_U3TX
 * 45-PORT_PIN_MODE_PC4_M0PWM2
 * 46-PORT_PIN_MODE_PC5_M0PWM3
 * 47-PORT_PIN_MODE_PC6_M0PWM0
 * 48-PORT_PIN_MODE_PC7_M0PWM1
 * 49-PORT_PIN_MODE_PC4_IDX1
 * 50-PORT_PIN_MODE_PC5_PhA1
 * 51-PORT_PIN_MODE_PC6_PhB1
 * 52-PORT_PIN_MODE_PC4_U1RTS
 * 53-PORT_PIN_MODE_PC5_U1CTS
 * 54-PORT_PIN_MODE_PC6_USB0EPEN	
 * 55-PORT_PIN_MODE_PC7_USB0PFLT	
 * 56-PORT_PIN_MODE_PC0_T4CCP0
 * 57-PORT_PIN_MODE_PC1_T4CCP1
 * 58-PORT_PIN_MODE_PC2_T5CCP0
 * 59-PORT_PIN_MODE_PC3_T5CCP1  	
 * 60-PORT_PIN_MODE_PC4_WT0CCP0
 * 61-PORT_PIN_MODE_PC5_WT0CCP1
 * 62-PORT_PIN_MODE_PC6_WT1CCP0
 * 63-PORT_PIN_MODE_PC7_WT1CCP1
 *
 * 64-PORT_PIN_MODE_PD0_SSI3Clk
 * 65-PORT_PIN_MODE_PD1_SSI3FSS
 * 66-PORT_PIN_MODE_PD2_SSI3RX
 * 67-PORT_PIN_MODE_PD3_SSI3TX
 * 68-PORT_PIN_MODE_PD4_U6RX
 * 69-PORT_PIN_MODE_PD5_U6TX
 * 70-PORT_PIN_MODE_PD6_U2RX
 * 71-PORT_PIN_MODE_PD7_U2TX
 * 72-PORT_PIN_MODE_PD0_SSI1Clk
 * 73-PORT_PIN_MODE_PD1_SSI1FSS
 * 74-PORT_PIN_MODE_PD2_SSI1RX
 * 75-PORT_PIN_MODE_PD3_SSI1TX
 * 76-PORT_PIN_MODE_PD0_I2C3SCL
 * 77-PORT_PIN_MODE_PD1_I2C3SDA
 * 78-PORT_PIN_MODE_PD0_M0PWM6
 * 79-PORT_PIN_MODE_PD1_M0PWM7
 * 80-PORT_PIN_MODE_PD2_M0FAULT0
 * 81-PORT_PIN_MODE_PD0_M1PWM0
 * 82-PORT_PIN_MODE_PD1_M1PWM1
 * 83-PORT_PIN_MODE_PD2_USB0EPEN	
 * 84-PORT_PIN_MODE_PD3_USB0PFLT	
 * 85-PORT_PIN_MODE_PD3_IDX0
 * 86-PORT_PIN_MODE_PD6_PhA0
 * 87-PORT_PIN_MODE_PD7_PhB0
 * 88-PORT_PIN_MODE_PD7_NMI
 * 89-PORT_PIN_MODE_PD0_WT2CCP0
 * 90-PORT_PIN_MODE_PD1_WT2CCP1
 * 91-PORT_PIN_MODE_PD2_WT3CCP0
 * 92-PORT_PIN_MODE_PD3_WT3CCP1
 * 93-PORT_PIN_MODE_PD4_WT4CCP0
 * 94-PORT_PIN_MODE_PD5_WT4CCP1
 * 95-PORT_PIN_MODE_PD6_WT5CCP0
 * 96-PORT_PIN_MODE_PD7_WT5CCP1
 *
 * 97-PORT_PIN_MODE_PE0_U7RX
 * 98-PORT_PIN_MODE_PE1_U7TX
 * 99-PORT_PIN_MODE_PE4_U5RX
 * 100-PORT_PIN_MODE_PE5_U5TX
 * 101-PORT_PIN_MODE_PE4_I2C2SCL
 * 102-PORT_PIN_MODE_PE5_I2C2SDA
 * 103-PORT_PIN_MODE_PE4_M0PWM4
 * 104-PORT_PIN_MODE_PE5_M0PWM5
 * 105-PORT_PIN_MODE_PE4_M1PWM2
 * 106-PORT_PIN_MODE_PE5_M1PWM3
 * 107-PORT_PIN_MODE_PE4_CAN0RX
 * 108-PORT_PIN_MODE_PE5_CAN0TX
 *
 * 109-PORT_PIN_MODE_PF0_U1RTS	
 * 110-PORT_PIN_MODE_PF1_U1CTS	
 * 111-PORT_PIN_MODE_PF0_SSI1RX
 * 112-PORT_PIN_MODE_PF1_SSI1TX
 * 113-PORT_PIN_MODE_PF2_SSI1Clk
 * 114-PORT_PIN_MODE_PF3_SSI1FSS
 * 115-PORT_PIN_MODE_PF0_CAN0RX
 * 116-PORT_PIN_MODE_PF3_CAN0TX
 * 117-PORT_PIN_MODE_PF2_M0FAULT0
 * 118-PORT_PIN_MODE_PF0_M1PWM4
 * 119-PORT_PIN_MODE_PF1_M1PWM5
 * 120-PORT_PIN_MODE_PF2_M1PWM6
 * 121-PORT_PIN_MODE_PF3_M1PWM7
 * 122-PORT_PIN_MODE_PF4_M1FAULT0
 * 123-PORT_PIN_MODE_PF0_PhA0
 * 124-PORT_PIN_MODE_PF1_PhB0
 * 125-PORT_PIN_MODE_PF4_IDX0
 * 126-PORT_PIN_MODE_PF0_T0CCP0
 * 127-PORT_PIN_MODE_PF1_T0CCP1
 * 128-PORT_PIN_MODE_PF2_T1CCP0
 * 129-PORT_PIN_MODE_PF3_T1CCP1
 * 130-PORT_PIN_MODE_PF4_T2CCP0
 * 131-PORT_PIN_MODE_PF0_NMI
 * 132-PORT_PIN_MODE_PF4_USB0EPEN
 * 133-PORT_PIN_MODE_PF0_C0O
 * 134-PORT_PIN_MODE_PF1_C1O
 * 135-PORT_PIN_MODE_PF1_TRD1
 * 136-PORT_PIN_MODE_PF2_TRD0
 * 137-PORT_PIN_MODE_PF3_TRCLK
 */

/* pinDir Options:
 * 1-PORT_PIN_IN
 * 2-PORT_PIN_OUT
 */

/* pinLevel Options:
 * 1-PORT_PIN_LOW
 * 2-PORT_PIN_HIGH
 */

/* pinInternalAttach Options:
 * 1-PORT_ATTACH_DEFAULT
 * 2-PORT_ATTACH_OPEN_DRAIN
 * 3-PORT_ATTACH_INTERNAL_PULL_UP
 * 4-PORT_ATTACH_INTERNAL_PULL_DOWN
 */

/* pinOutputCurrent Options:
 * 1-PORT_CURRENT_2_MILLIAMPERE
 * 2-PORT_CURRENT_4_MILLIAMPERE
 * 3-PORT_CURRENT_8_MILLIAMPERE
 */

/* pinExtInt Options:
 * 1-PORT_EXT_INT_DISABLE
 * 2-PORT_EXT_INT_RISING_EDGE
 * 3-PORT_EXT_INT_FALLING_EDGE
 * 4-PORT_EXT_INT_BOTH_EDGES
 * 5-PORT_EXT_INT_LOW_EVENT
 * 6-PORT_EXT_INT_HIGH_EVENT
 */
const Port_Config_st PortConfig[MAX_NUMBER_OF_CONFIGS] = 
{
    /*pinId,        PinMode                 pinDir,         pinLevel,       pinInternalAttach,                  pinOutputCurrent,               pinExtInt*/
    /*-----         -------                 ------          ---------       ------------------                  ----------------                ---------*/

    {PORT_PIN_F1,   PORT_PIN_MODE_X_DIO,    PORT_PIN_OUT,   PORT_PIN_LOW,  PORT_ATTACH_DEFAULT,     PORT_CURRENT_2_MILLIAMPERE,     PORT_EXT_INT_DISABLE},
    {PORT_PIN_F3,   PORT_PIN_MODE_X_DIO,    PORT_PIN_OUT,   PORT_PIN_LOW,  	PORT_ATTACH_DEFAULT,     PORT_CURRENT_2_MILLIAMPERE,     PORT_EXT_INT_DISABLE}
};
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

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






/**********************************************************************************************************************
 *  END OF FILE: Port_Lcfg.c
 *********************************************************************************************************************/
