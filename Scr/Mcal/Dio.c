/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Dio.c
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
#include "Dio.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/
#define MAX_NUMBER_OF_CHANNELS_IN_PORT          8
#define MAX_NUMBER_OF_GPIO_PORTS                8
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/
static const uint32_t GpioApbBaseAddress[MAX_NUMBER_OF_GPIO_PORTS] = 
{
    GPIO_APB_BASE_ADDRESS_A,
    GPIO_APB_BASE_ADDRESS_B,
    GPIO_APB_BASE_ADDRESS_C,
    GPIO_APB_BASE_ADDRESS_D,
    GPIO_APB_BASE_ADDRESS_E,
    GPIO_APB_BASE_ADDRESS_F
};
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

void Dio_WriteChannel(Dio_Channel_et channelId, Dio_Level_et level)
{
    volatile uint32_t* p_wantedReg;
    uint8_t loc_maskRegAddr;
    uint8_t loc_regNumber, loc_bitNumber;

    loc_regNumber = channelId / MAX_NUMBER_OF_CHANNELS_IN_PORT;
    loc_bitNumber = channelId % MAX_NUMBER_OF_CHANNELS_IN_PORT;

    loc_maskRegAddr = (1<<loc_bitNumber) << 2;
    p_wantedReg = (uint32_t*)(GpioApbBaseAddress[loc_regNumber] + loc_maskRegAddr);
    *p_wantedReg = level << loc_bitNumber;
} /*Dio_WriteChannel*/


Dio_Level_et Dio_ReadChannel(Dio_Channel_et channelId)
{
    Dio_Level_et loc_channelLevel;
    volatile uint32_t* p_wantedReg;
    uint8_t loc_maskRegAddr;
    uint8_t loc_regNumber, loc_bitNumber;

    loc_regNumber = channelId / MAX_NUMBER_OF_CHANNELS_IN_PORT;
    loc_bitNumber = channelId % MAX_NUMBER_OF_CHANNELS_IN_PORT;

    loc_maskRegAddr = (1<<loc_bitNumber) << 2;
    p_wantedReg = (uint32_t*)(GpioApbBaseAddress[loc_regNumber] + loc_maskRegAddr);
    loc_channelLevel = *p_wantedReg >> loc_bitNumber;
    return loc_channelLevel;
} /*Dio_ReadChannel*/



Dio_Level_et Dio_FlipChannel(Dio_Channel_et channelId)
{
    Dio_Level_et loc_channelLevel;
    loc_channelLevel = ~Dio_ReadChannel(channelId);
    Dio_WriteChannel(channelId, loc_channelLevel);
    return loc_channelLevel;
} /*Dio_FlipChannel*/



void Dio_WritePort(Dio_Port_et portId, Dio_PortLevel_t level)
{
    volatile uint32_t* p_wantedReg;
    uint8_t loc_maskRegAddr;

    loc_maskRegAddr = 255;
    p_wantedReg = (uint32_t*)(GpioApbBaseAddress[portId] + loc_maskRegAddr);
    *p_wantedReg = level;
} /*Dio_WritePort*/



Dio_PortLevel_t Dio_ReadPort(Dio_Port_et portId)
{
    Dio_PortLevel_t loc_portLevel;
    volatile uint32_t* p_wantedReg;
    uint8_t loc_maskRegAddr;

    loc_maskRegAddr = 255;
    p_wantedReg = (uint32_t*)(GpioApbBaseAddress[portId] + loc_maskRegAddr);
    loc_portLevel = (uint8_t) *p_wantedReg;
    return loc_portLevel;
} /*Dio_ReadPort*/

/**********************************************************************************************************************
 *  END OF FILE: Dio.c
 *********************************************************************************************************************/
