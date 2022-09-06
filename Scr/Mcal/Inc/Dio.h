/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef DIO_H_
#define DIO_H_

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
    CHANNEL_A0 = 0,
    CHANNEL_A1,
    CHANNEL_A2,
    CHANNEL_A3,
    CHANNEL_A4,
    CHANNEL_A5,
    CHANNEL_A6,
    CHANNEL_A7,

    CHANNEL_B0,
    CHANNEL_B1,
    CHANNEL_B2,
    CHANNEL_B3,
    CHANNEL_B4,
    CHANNEL_B5,
    CHANNEL_B6,
    CHANNEL_B7,

    CHANNEL_C0,
    CHANNEL_C1,
    CHANNEL_C2,
    CHANNEL_C3,
    CHANNEL_C4,
    CHANNEL_C5,
    CHANNEL_C6,
    CHANNEL_C7,

    CHANNEL_D0,
    CHANNEL_D1,
    CHANNEL_D2,
    CHANNEL_D3,
    CHANNEL_D4,
    CHANNEL_D5,
    CHANNEL_D6,
    CHANNEL_D7,

    CHANNEL_E0,
    CHANNEL_E1,
    CHANNEL_E2,
    CHANNEL_E3,
    CHANNEL_E4,
    CHANNEL_E5,
    CHANNEL_E6_NONE,
    CHANNEL_E7_NONE,

    CHANNEL_F0,
    CHANNEL_F1,
    CHANNEL_F2,
    CHANNEL_F3,
    CHANNEL_F4,
    CHANNEL_F5_NONE,
    CHANNEL_F6_NONE,
    CHANNEL_F7_NONE,
}Dio_Channel_et;


typedef enum
{
    PORT_A = 0,
    PORT_B,
    PORT_C,
    PORT_D,
    PORT_E,
    PORT_F
}Dio_Port_et;


typedef enum
{
    LOW = 0,
    HIGH
}Dio_Level_et;


typedef uint8_t Dio_PortLevel_t;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
Dio_Level_et Dio_ReadChannel(Dio_Channel_et channelId);
Dio_Level_et Dio_FlipChannel(Dio_Channel_et channelId);
Dio_PortLevel_t Dio_ReadPort(Dio_Port_et portId);
void Dio_WriteChannel(Dio_Channel_et channelId, Dio_Level_et level);
void Dio_WritePort(Dio_Port_et portId, Dio_PortLevel_t level);
 
#endif  /*DIO_H_*/

/**********************************************************************************************************************
 *  END OF FILE: Dio.h
 *********************************************************************************************************************/
