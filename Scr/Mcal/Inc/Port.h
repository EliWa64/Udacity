/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Port.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef PORT_H_
#define PORT_H_

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
    PORT_PIN_A0 = 0,
    PORT_PIN_A1,
    PORT_PIN_A2,
    PORT_PIN_A3,
    PORT_PIN_A4,
    PORT_PIN_A5,
    PORT_PIN_A6,
    PORT_PIN_A7,

    PORT_PIN_B0,
    PORT_PIN_B1,
    PORT_PIN_B2,
    PORT_PIN_B3,
    PORT_PIN_B4,
    PORT_PIN_B5,
    PORT_PIN_B6,
    PORT_PIN_B7,

    PORT_PIN_C0,
    PORT_PIN_C1,
    PORT_PIN_C2,
    PORT_PIN_C3,
    PORT_PIN_C4,
    PORT_PIN_C5,
    PORT_PIN_C6,
    PORT_PIN_C7,

    PORT_PIN_D0,
    PORT_PIN_D1,
    PORT_PIN_D2,
    PORT_PIN_D3,
    PORT_PIN_D4,
    PORT_PIN_D5,
    PORT_PIN_D6,
    PORT_PIN_D7,

    PORT_PIN_E0,
    PORT_PIN_E1,
    PORT_PIN_E2,
    PORT_PIN_E3,
    PORT_PIN_E4,
    PORT_PIN_E5,
    PORT_PIN_E6_NONE,
    PORT_PIN_E7_NONE,

    PORT_PIN_F0,
    PORT_PIN_F1,
    PORT_PIN_F2,
    PORT_PIN_F3,
    PORT_PIN_F4,
    PORT_PIN_F5_NONE,
    PORT_PIN_F6_NONE,
    PORT_PIN_F7_NONE,
}Port_Pin_et;

typedef uint8_t Port_PinMode_t;
#define PORT_PIN_MODE_X_ANALOG				10

#define PORT_PIN_MODE_X_DIO					0

#define PORT_PIN_MODE_PA0_U0RX			    1
#define PORT_PIN_MODE_PA1_U0TX			    1
#define PORT_PIN_MODE_PA0_CAN1RX			8
#define PORT_PIN_MODE_PA1_CAN1TX			8
#define PORT_PIN_MODE_PA2_SSI0ClK		    2
#define PORT_PIN_MODE_PA3_SSI0FSS		    2
#define PORT_PIN_MODE_PA4_SSI0RX			2
#define PORT_PIN_MODE_PA5_SSI0TX			2
#define PORT_PIN_MODE_PA6_I2C1SCL		    3
#define PORT_PIN_MODE_PA7_I2C1SDA		    3
#define PORT_PIN_MODE_PA6_M1PWM2			5
#define PORT_PIN_MODE_PA7_M1PWM3			5

#define PORT_PIN_MODE_PB0_U1RX			    1
#define PORT_PIN_MODE_PB1_U1TX			    1
#define PORT_PIN_MODE_PB2_I2C0SCL		    3
#define PORT_PIN_MODE_PB3_I2C0SDA		    3
#define PORT_PIN_MODE_PB4_SSI2Clk		    2
#define PORT_PIN_MODE_PB5_SSI2FSS		    2
#define PORT_PIN_MODE_PB6_SSI2RX		    2
#define PORT_PIN_MODE_PB7_SSI2TX		    2
#define PORT_PIN_MODE_PB4_M0PWM2		    4
#define PORT_PIN_MODE_PB5_M0PWM3		    4
#define PORT_PIN_MODE_PB6_M0PWM0		    4
#define PORT_PIN_MODE_PB7_M0PWM1	        4
#define PORT_PIN_MODE_PB4_CAN0RX			8
#define PORT_PIN_MODE_PB5_CAN0TX			8
#define PORT_PIN_MODE_PB0_T2CCP0			7
#define PORT_PIN_MODE_PB1_T2CCP1			7
#define PORT_PIN_MODE_PB2_T3CCP0			7
#define PORT_PIN_MODE_PB3_T3CCP1			7
#define PORT_PIN_MODE_PB4_T1CCP0			7
#define PORT_PIN_MODE_PB5_T1CCP1			7
#define PORT_PIN_MODE_PB6_T0CCP0			7
#define PORT_PIN_MODE_PB7_T0CCP1			7

#define PORT_PIN_MODE_PC0_TCK_SWCLK	        1
#define PORT_PIN_MODE_PC1_TMS_SWDIO	        1
#define PORT_PIN_MODE_PC2_TDI				1
#define PORT_PIN_MODE_PC3_TDO_SWO		    1	
#define PORT_PIN_MODE_PC4_U4RX				1
#define PORT_PIN_MODE_PC5_U4TX				1
#define PORT_PIN_MODE_PC6_U3RX				1
#define PORT_PIN_MODE_PC7_U3TX				1
#define PORT_PIN_MODE_PC4_M0PWM2			4
#define PORT_PIN_MODE_PC5_M0PWM3			4
#define PORT_PIN_MODE_PC6_M0PWM0			4
#define PORT_PIN_MODE_PC7_M0PWM1			4
#define PORT_PIN_MODE_PC4_IDX1				6
#define PORT_PIN_MODE_PC5_PhA1				6
#define PORT_PIN_MODE_PC6_PhB1				6
#define PORT_PIN_MODE_PC4_U1RTS			    8
#define PORT_PIN_MODE_PC5_U1CTS			    8
#define PORT_PIN_MODE_PC6_USB0EPEN		    8
#define PORT_PIN_MODE_PC7_USB0PFLT		    8
#define PORT_PIN_MODE_PC0_T4CCP0			7
#define PORT_PIN_MODE_PC1_T4CCP1			7
#define PORT_PIN_MODE_PC2_T5CCP0			7
#define PORT_PIN_MODE_PC3_T5CCP1		    7   	
#define PORT_PIN_MODE_PC4_WT0CCP0		    7
#define PORT_PIN_MODE_PC5_WT0CCP1		    7
#define PORT_PIN_MODE_PC6_WT1CCP0		    7
#define PORT_PIN_MODE_PC7_WT1CCP1		    7

#define PORT_PIN_MODE_PD0_SSI3Clk		    1
#define PORT_PIN_MODE_PD1_SSI3FSS		    1
#define PORT_PIN_MODE_PD2_SSI3RX			1
#define PORT_PIN_MODE_PD3_SSI3TX			1
#define PORT_PIN_MODE_PD4_U6RX				1
#define PORT_PIN_MODE_PD5_U6TX				1
#define PORT_PIN_MODE_PD6_U2RX				1
#define PORT_PIN_MODE_PD7_U2TX				1
#define PORT_PIN_MODE_PD0_SSI1Clk		    2
#define PORT_PIN_MODE_PD1_SSI1FSS		    2
#define PORT_PIN_MODE_PD2_SSI1RX			2
#define PORT_PIN_MODE_PD3_SSI1TX			2
#define PORT_PIN_MODE_PD0_I2C3SCL		    3
#define PORT_PIN_MODE_PD1_I2C3SDA		    3
#define PORT_PIN_MODE_PD0_M0PWM6			4
#define PORT_PIN_MODE_PD1_M0PWM7			4
#define PORT_PIN_MODE_PD2_M0FAULT0		    4
#define PORT_PIN_MODE_PD0_M1PWM0			5
#define PORT_PIN_MODE_PD1_M1PWM1			5
#define PORT_PIN_MODE_PD2_USB0EPEN		    8
#define PORT_PIN_MODE_PD3_USB0PFLT		    8
#define PORT_PIN_MODE_PD3_IDX0				6
#define PORT_PIN_MODE_PD6_PhA0 			    6
#define PORT_PIN_MODE_PD7_PhB0				6
#define PORT_PIN_MODE_PD7_NMI 				8
#define PORT_PIN_MODE_PD0_WT2CCP0		    7
#define PORT_PIN_MODE_PD1_WT2CCP1		    7
#define PORT_PIN_MODE_PD2_WT3CCP0		    7
#define PORT_PIN_MODE_PD3_WT3CCP1		    7
#define PORT_PIN_MODE_PD4_WT4CCP0		    7
#define PORT_PIN_MODE_PD5_WT4CCP1		    7
#define PORT_PIN_MODE_PD6_WT5CCP0		    7
#define PORT_PIN_MODE_PD7_WT5CCP1		    7

#define PORT_PIN_MODE_PE0_U7RX				1
#define PORT_PIN_MODE_PE1_U7TX				1
#define PORT_PIN_MODE_PE4_U5RX				1
#define PORT_PIN_MODE_PE5_U5TX				1
#define PORT_PIN_MODE_PE4_I2C2SCL		    3
#define PORT_PIN_MODE_PE5_I2C2SDA		    3
#define PORT_PIN_MODE_PE4_M0PWM4			4
#define PORT_PIN_MODE_PE5_M0PWM5			4
#define PORT_PIN_MODE_PE4_M1PWM2			5
#define PORT_PIN_MODE_PE5_M1PWM3			5
#define PORT_PIN_MODE_PE4_CAN0RX			8
#define PORT_PIN_MODE_PE5_CAN0TX			8

#define PORT_PIN_MODE_PF0_U1RTS		        1
#define PORT_PIN_MODE_PF1_U1CTS		        1
#define PORT_PIN_MODE_PF0_SSI1RX		    2
#define PORT_PIN_MODE_PF1_SSI1TX		    2
#define PORT_PIN_MODE_PF2_SSI1Clk	        2
#define PORT_PIN_MODE_PF3_SSI1FSS	        2
#define PORT_PIN_MODE_PF0_CAN0RX		    3
#define PORT_PIN_MODE_PF3_CAN0TX		    3
#define PORT_PIN_MODE_PF2_M0FAULT0	        4
#define PORT_PIN_MODE_PF0_M1PWM4		    5
#define PORT_PIN_MODE_PF1_M1PWM5		    5
#define PORT_PIN_MODE_PF2_M1PWM6		    5
#define PORT_PIN_MODE_PF3_M1PWM7		    5
#define PORT_PIN_MODE_PF4_M1FAULT0	        5
#define PORT_PIN_MODE_PF0_PhA0			    6
#define PORT_PIN_MODE_PF1_PhB0			    6
#define PORT_PIN_MODE_PF4_IDX0			    6
#define PORT_PIN_MODE_PF0_T0CCP0		    7
#define PORT_PIN_MODE_PF1_T0CCP1		    7
#define PORT_PIN_MODE_PF2_T1CCP0		    7
#define PORT_PIN_MODE_PF3_T1CCP1		    7
#define PORT_PIN_MODE_PF4_T2CCP0		    7
#define PORT_PIN_MODE_PF0_NMI			    8
#define PORT_PIN_MODE_PF4_USB0EPEN	        8
#define PORT_PIN_MODE_PF0_C0O			    9
#define PORT_PIN_MODE_PF1_C1O			    9
#define PORT_PIN_MODE_PF1_TRD1			    14
#define PORT_PIN_MODE_PF2_TRD0			    14
#define PORT_PIN_MODE_PF3_TRCLK		        14

typedef enum
{
    PORT_PIN_LOW = 0,
    PORT_PIN_HIGH
}Port_PinLevel_et;

typedef enum
{
    PORT_PIN_IN = 0,
    PORT_PIN_OUT
}Port_PinDir_et;

typedef enum
{
    PORT_ATTACH_DEFAULT = 0,
    PORT_ATTACH_OPEN_DRAIN,
    PORT_ATTACH_INTERNAL_PULL_UP,
    PORT_ATTACH_INTERNAL_PULL_DOWN
}Port_PinInternalAttach_et;

typedef enum
{
    PORT_CURRENT_2_MILLIAMPERE = 0,
    PORT_CURRENT_4_MILLIAMPERE,
    PORT_CURRENT_8_MILLIAMPERE
}Port_PinOutputCurrent_et;

typedef enum
{
    PORT_EXT_INT_DISABLE = 0,
    PORT_EXT_INT_RISING_EDGE,
    PORT_EXT_INT_FALLING_EDGE,
    PORT_EXT_INT_BOTH_EDGES,
    PORT_EXT_INT_LOW_EVENT,
    PORT_EXT_INT_HIGH_EVENT
}Port_PinExtInt_et;

typedef struct
{
    Port_Pin_et pinId;
    Port_PinMode_t PinMode;
    Port_PinDir_et pinDir;
    Port_PinLevel_et pinLevel;
    Port_PinInternalAttach_et pinInternalAttach;
    Port_PinOutputCurrent_et pinOutputCurrent;
    Port_PinExtInt_et pinExtInt;
}Port_Config_st;
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

void Port_Init(const Port_Config_st* p_config);
 
#endif  /* PORT_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Port.h
 *********************************************************************************************************************/
