/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Timer.h
 *       Module:  -
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef TIMER_H_
#define TIMER_H_

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
typedef uint32_t Gpt_Value_t;
typedef void (*p_GptNotificationFun)(void);

typedef enum
{
    GPT_16_32_BIT_TIMER0,
    GPT_16_32_BIT_TIMER1,
    GPT_16_32_BIT_TIMER2,
    GPT_16_32_BIT_TIMER3,
    GPT_16_32_BIT_TIMER4,
    GPT_16_32_BIT_TIMER5,
    GPT_32_64_BIT_WIDE_TIMER0,
    GPT_32_64_BIT_WIDE_TIMER1,
    GPT_32_64_BIT_WIDE_TIMER2,
    GPT_32_64_BIT_WIDE_TIMER3,
    GPT_32_64_BIT_WIDE_TIMER4,
    GPT_32_64_BIT_WIDE_TIMER5,
}Gpt_Channel_et;

typedef enum
{
    GPT_MODE_NORMAL,
    GPT_MODE_SLEEP
}Gpt_Mode_et;

typedef enum
{
    GPT_PREDEF_TIMER_1US_16BIT,
    GPT_PREDEF_TIMER_1US_24BIT,
    GPT_PREDEF_TIMER_1US_32BIT,
    GPT_PREDEF_TIMER_100US_32BIT
}Gpt_PredefTimer_et;

typedef enum
{
    GPT_CHANNEL_MODE_ONESHOT = 1,
    GPT_CHANNEL_MODE_PERIODIC,
}Gpt_ChannelMode_et;

typedef struct
{
    Gpt_Channel_et          gptChannelId;
    Gpt_Value_t             gptChannelTickFrequency;
    Gpt_Value_t             gptMaxChannelTickValue;
    Gpt_ChannelMode_et      channelMode;
    p_GptNotificationFun    p_gptNotification;
}Gpt_Config_st;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Gpt_Init(const Gpt_Config_st* p_config);
void Gpt_DisableNotification(Gpt_Channel_et channel);
void Gpt_EnableNotification(Gpt_Channel_et channel);
Gpt_Value_t Gpt_getTimeElapsed(Gpt_Channel_et channel);
Std_ErrorState_et Gpt_GetPredefTimerValue( Gpt_PredefTimer_et predefTimer, uint32_t* p_timeValue);
Gpt_Value_t Gpt_getTimeRemaining(Gpt_Channel_et channel);
void Gpt_StartTimer( Gpt_Channel_et channel, Gpt_Value_t value );
void Gpt_StopTimer( Gpt_Channel_et channel);
 
#endif  /* TIMER_H_ */

/**********************************************************************************************************************
 *  END OF FILE: Timer.h
 *********************************************************************************************************************/
