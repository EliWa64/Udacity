/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Timer.c
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
#include "Mcu.h"
#include "Timer_Cfg.h"
#include "Timer.h"

/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/

#define PREDEF_TIMER					GPT_32_64_BIT_WIDE_TIMER4

#define MAX_NUMBER_OF_TIMERS            12

#define TAEN_OFFSET                     0
#define TAMR_OFFSET                     0
#define TATOIM_OFFSET                   0
#define TATOCINT_OFFSET									0
#define TACDIR_OFFSET                   4



static const uint32_t GptBaseAddress[] =
{
    GPT_16_32_BIT_TIMER0_BASE_ADDRESS,
    GPT_16_32_BIT_TIMER1_BASE_ADDRESS,
    GPT_16_32_BIT_TIMER2_BASE_ADDRESS,
    GPT_16_32_BIT_TIMER3_BASE_ADDRESS,
    GPT_16_32_BIT_TIMER4_BASE_ADDRESS,
    GPT_16_32_BIT_TIMER5_BASE_ADDRESS,
    GPT_32_64_BIT_WIDE_TIMER0_BASE_ADDRESS,
    GPT_32_64_BIT_WIDE_TIMER1_BASE_ADDRESS,
    GPT_32_64_BIT_WIDE_TIMER2_BASE_ADDRESS,
    GPT_32_64_BIT_WIDE_TIMER3_BASE_ADDRESS,
    GPT_32_64_BIT_WIDE_TIMER4_BASE_ADDRESS,
    GPT_32_64_BIT_WIDE_TIMER5_BASE_ADDRESS
};
/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

static volatile uint32_t gptPredefTimer_1USPrescale;
static volatile uint32_t gptPredefTimer_100USPrescale;

p_GptNotificationFun gp_gptNotification[MAX_NUMBER_OF_TIMERS];
static const Gpt_Config_st* gp_gptConfig;

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
void Gpt_Init(const Gpt_Config_st* p_config)
{
    Gpt_Channel_et loc_gptChannelId;
    Gpt_ChannelMode_et loc_channelMode;
    gp_gptConfig = p_config;

    uint32_t loc_gptBaseAddress, i;
    uint8_t loc_regNumber, loc_bitNumber;

    for(i= 0; i<NUMBER_OF_USED_TIMERS; i++)
    {
        loc_gptChannelId = p_config[i].gptChannelId;
        loc_channelMode = p_config[i].channelMode;
        gp_gptNotification[loc_gptChannelId] =p_config[i].p_gptNotification;

        loc_gptBaseAddress = GptBaseAddress[loc_gptChannelId];

        GPTMCTL(loc_gptBaseAddress) = 0; //Disable the timer.

        /*
         *For a 16/32-bit timer, this value selects the 16-bit timer configuration.
         *For a 32/64-bit wide timer, this value selects the 32-bit timer configuration.
         */
        GPTMCFG(loc_gptBaseAddress) = 0x04;

        GPTMTAMR(loc_gptBaseAddress) |= loc_channelMode << TAMR_OFFSET; //Set One-Shot or Periodic Mode.
        GPTMTAMR(loc_gptBaseAddress) |= 1 << TACDIR_OFFSET; //Count up.
    
	    GPTMIMR(loc_gptBaseAddress) = 0; //Disable Interrupts.
    } //for

    gptPredefTimer_1USPrescale = Mcu_getSysClockFreq()/1000000UL;
    for(i=2; ; i*=2)
	{
		if(gptPredefTimer_1USPrescale/i == 1)
		{
			if(gptPredefTimer_1USPrescale%i <= (i/2))
			{
				gptPredefTimer_1USPrescale = i;
			}
			else
			{
				gptPredefTimer_1USPrescale = i*2;
			}
			break;
		} //if
	} //for

    gptPredefTimer_100USPrescale = Mcu_getSysClockFreq()/10000;
    for(i=2; ; i*=2)
	{
		if(gptPredefTimer_100USPrescale/i == 1)
		{
			if(gptPredefTimer_100USPrescale%i <= (i/2))
			{
				gptPredefTimer_100USPrescale = i;
			}
			else
			{
				gptPredefTimer_100USPrescale = i*2;
			}
			break;
		}
	}

    /*Initializing the Predefined Timers*/
#if GPT_PREDEF_TIMER_1US_16BIT_STATE == ENABLE
    loc_gptBaseAddress = GptBaseAddress[PREDEF_TIMER];
    GPTMCTL(loc_gptBaseAddress) = 0; //Disable the timer.
    GPTMTAMR(loc_gptBaseAddress) |= GPT_CHANNEL_MODE_PERIODIC << TAMR_OFFSET; //Set Periodic Mode.
    GPTMTAMR(loc_gptBaseAddress) |= 1 << TACDIR_OFFSET; //Count up.
	GPTMIMR(loc_gptBaseAddress) = 0; //Disable Interrupts.
    GPTMTAILR(loc_gptBaseAddress) = 0xFFFF * gptPredefTimer_1USPrescale;
#endif
#if GPT_PREDEF_TIMER_1US_24BIT_STATE == ENABLE
    loc_gptBaseAddress = GptBaseAddress[PREDEF_TIMER];
    GPTMCTL(loc_gptBaseAddress) = 0; //Disable the timer.
    GPTMTAMR(loc_gptBaseAddress) |= GPT_CHANNEL_MODE_PERIODIC << TAMR_OFFSET; //Set Periodic Mode.
    GPTMTAMR(loc_gptBaseAddress) |= 1 << TACDIR_OFFSET; //Count up.
	GPTMIMR(loc_gptBaseAddress) = 0; //Disable Interrupts.
    GPTMTAILR(loc_gptBaseAddress) = 0xFFFFFF * gptPredefTimer_1USPrescale;
#endif
#if GPT_PREDEF_TIMER_1US_32BIT_STATE == ENABLE
    loc_gptBaseAddress = GptBaseAddress[PREDEF_TIMER];
    GPTMCTL(loc_gptBaseAddress) = 0; //Disable the timer.
    GPTMTAMR(loc_gptBaseAddress) |= GPT_CHANNEL_MODE_PERIODIC << TAMR_OFFSET; //Set Periodic Mode.
    GPTMTAMR(loc_gptBaseAddress) |= 1 << TACDIR_OFFSET; //Count up.
	GPTMIMR(loc_gptBaseAddress) = 0; //Disable Interrupts.
    GPTMTAILR(loc_gptBaseAddress) = 0xFFFFFFFF * gptPredefTimer_1USPrescale;
#endif
#if GPT_PREDEF_TIMER_100US_32BIT_STATE == ENABLE
    loc_gptBaseAddress = GptBaseAddress[PREDEF_TIMER];
    GPTMCTL(loc_gptBaseAddress) = 0; //Disable the timer.
    GPTMTAMR(loc_gptBaseAddress) |= GPT_CHANNEL_MODE_PERIODIC << TAMR_OFFSET; //Set Periodic Mode.
    GPTMTAMR(loc_gptBaseAddress) |= 1 << TACDIR_OFFSET; //Count up.
	GPTMIMR(loc_gptBaseAddress) = 0; //Disable Interrupts.
    GPTMTAILR(loc_gptBaseAddress) = 0xFFFFFFFF * gptPredefTimer_100USPrescale;
#endif

} /*Gpt_Init*/


void Gpt_DisableNotification(Gpt_Channel_et channel)
{
	uint32_t loc_gptBaseAddress;
	loc_gptBaseAddress = GptBaseAddress[channel];
	GPTMIMR(loc_gptBaseAddress) = 0;
} /*Gpt_DisableNotification*/


void Gpt_EnableNotification(Gpt_Channel_et channel)
{
	uint32_t loc_gptBaseAddress;
	loc_gptBaseAddress = GptBaseAddress[channel];
	GPTMIMR(loc_gptBaseAddress) |= 1 << TATOIM_OFFSET;
} /*Gpt_EnableNotification*/



Gpt_Value_t Gpt_getTimeElapsed(Gpt_Channel_et channel)
{
    Gpt_Value_t loc_value, loc_channelTickFreq, loc_maxChannelTickValue;
	uint32_t loc_prescale, loc_gptBaseAddress, i;
	
	loc_gptBaseAddress = GptBaseAddress[channel];

	for(i=0;i<MAX_NUMBER_OF_TIMERS;i++)
	{
		if (gp_gptConfig[i].gptChannelId == channel)
		{
			loc_channelTickFreq = gp_gptConfig[i].gptChannelTickFrequency;
			loc_maxChannelTickValue = gp_gptConfig[i].gptMaxChannelTickValue;
			break;
		}
	}
	
	loc_prescale = (Mcu_getSysClockFreq()/1000) / loc_channelTickFreq;
	
	for(i=2; ; i*=2)
	{
		if((loc_prescale/i) == 1)
		{
			if((loc_prescale%i) <= (i/2))
			{
				loc_prescale = i;
			}
			else
			{
				loc_prescale = i * 2;
			}
			break;
		} //if
	} //for
	loc_value = (GPTMTAV(loc_gptBaseAddress) / loc_prescale) & loc_maxChannelTickValue;
	
	return loc_value;
} /*Gpt_getTimeElapsed*/



Std_ErrorState_et Gpt_GetPredefTimerValue( Gpt_PredefTimer_et predefTimer, uint32_t* p_timeValue)
{
	Std_ErrorState_et loc_returnValue = NOK;
	uint32_t loc_gptBaseAddress;
	
	loc_gptBaseAddress = GptBaseAddress[PREDEF_TIMER];
	if (predefTimer == GPT_PREDEF_TIMER_1US_16BIT )
	{
		*p_timeValue = (GPTMTAV(loc_gptBaseAddress) / gptPredefTimer_1USPrescale) & 0xFFFF;
		loc_returnValue = OK;
	}
	else if (predefTimer == GPT_PREDEF_TIMER_1US_24BIT )
	{
		*p_timeValue = (GPTMTAV(loc_gptBaseAddress) / gptPredefTimer_1USPrescale) & 0xFFFFFF;
		loc_returnValue = OK;
	}
	else if (predefTimer == GPT_PREDEF_TIMER_1US_32BIT )
	{
		*p_timeValue = (GPTMTAV(loc_gptBaseAddress) / gptPredefTimer_1USPrescale) & 0xFFFFFFFF;
		loc_returnValue = OK;
	}
	else if (predefTimer == GPT_PREDEF_TIMER_100US_32BIT )
	{
		*p_timeValue = (GPTMTAV(loc_gptBaseAddress) / gptPredefTimer_100USPrescale) & 0xFFFFFFFF;
		loc_returnValue = OK;
	}
	else
	{
		loc_returnValue = NOK;
	}
	return loc_returnValue;
} /*Gpt_GetPredefTimerValue*/



Gpt_Value_t Gpt_getTimeRemaining(Gpt_Channel_et channel)
{

	Gpt_Value_t loc_channelTickFreq, loc_channelMaxValue, loc_value, loc_currentValue, loc_remainingValue;
	uint32_t loc_prescale, loc_gptBaseAddress, i;
	
	loc_gptBaseAddress = GptBaseAddress[channel];
	
	for(i=0;i<MAX_NUMBER_OF_TIMERS;i++)
	{
		if (gp_gptConfig[i].gptChannelId == channel)
		{
			loc_channelTickFreq = gp_gptConfig[i].gptChannelTickFrequency;
			loc_channelMaxValue = gp_gptConfig[i].gptMaxChannelTickValue;
			break;
		} //if
	} //for
	
	loc_prescale = (Mcu_getSysClockFreq()/1000) / loc_channelTickFreq;
	
	for(i=2; ; i*=2)
	{
		if((loc_prescale/i) == 1)
		{
			if((loc_prescale%i) <= (i/2))
			{
				loc_prescale = i;
			} //if
			else
			{
				loc_prescale = i * 2;
			} //else
			break;
		} //if
	} //for
	loc_currentValue = (GPTMTAV(loc_gptBaseAddress) / loc_prescale) & loc_channelMaxValue;
	loc_value = (GPTMTAILR(loc_gptBaseAddress) / loc_prescale) & loc_channelMaxValue;
	
	loc_remainingValue = loc_value - loc_currentValue;
	
	return loc_remainingValue;
} /*Gpt_getTimeRemaining*/


void Gpt_StartTimer( Gpt_Channel_et channel, Gpt_Value_t value )
{
	uint32_t loc_gptBaseAddress, loc_prescale, i;
	Gpt_Value_t loc_channelTickFreq;
	
	loc_gptBaseAddress = GptBaseAddress[channel];

	for(i=0; i<MAX_NUMBER_OF_TIMERS; i++)
	{
		if (gp_gptConfig[i].gptChannelId == channel)
		{
			loc_channelTickFreq = gp_gptConfig[i].gptChannelTickFrequency;			
			break;
		} //if
	} //for
	
	loc_prescale = (Mcu_getSysClockFreq()/1000) / loc_channelTickFreq;
	
	for(i=2; ; i*=2)
	{
		if((loc_prescale/i) == 1)
		{
			if((loc_prescale%i) <= (i/2))
			{
				loc_prescale = i;
			}
			else
			{
				loc_prescale = i * 2;
			}
			break;
		} //if
	} //for
	/* adding the value deppending on the freq required */
	GPTMTAILR(loc_gptBaseAddress) = value * loc_prescale;
	
	GPTMCTL(loc_gptBaseAddress) |= 1 << TAEN_OFFSET;
} /*Gpt_StartTimer*/


void Gpt_StopTimer( Gpt_Channel_et channel)
{
	uint32_t loc_gptBaseAddress;

	loc_gptBaseAddress = GptBaseAddress[channel];
	
	GPTMCTL(loc_gptBaseAddress) &= ~(1<<TAEN_OFFSET);
} /*Gpt_StopTimer*/

void TIMER0A_Handler(void)
{
	static p_GptNotificationFun gptNotificationFn_TIMER0A;
	if (gp_gptNotification[GPT_16_32_BIT_TIMER0] != NULL_PTR)
	{
		gptNotificationFn_TIMER0A = gp_gptNotification[GPT_16_32_BIT_TIMER0];
		gptNotificationFn_TIMER0A();
	}
	GPTMICR(GPT_16_32_BIT_TIMER0_BASE_ADDRESS) |= 1 << TATOCINT_OFFSET; //Clear Flag of Time-Out Raw Interrupt.
}

void TIMER1A_Handler(void)
{
	static p_GptNotificationFun gptNotificationFn_TIMER1A;
	if (gp_gptNotification[GPT_16_32_BIT_TIMER1] != NULL_PTR)
	{
		gptNotificationFn_TIMER1A = gp_gptNotification[GPT_16_32_BIT_TIMER1];
		gptNotificationFn_TIMER1A();
	}
	GPTMICR(GPT_16_32_BIT_TIMER1_BASE_ADDRESS) |= 1 << TATOCINT_OFFSET; //Clear Flag of Time-Out Raw Interrupt.
}

void TIMER2A_Handler(void)
{
	static p_GptNotificationFun gptNotificationFn_TIMER2A;
	if (gp_gptNotification[GPT_16_32_BIT_TIMER2] != NULL)
	{
		gptNotificationFn_TIMER2A = gp_gptNotification[GPT_16_32_BIT_TIMER2];
		gptNotificationFn_TIMER2A();
	}
	GPTMICR(GPT_16_32_BIT_TIMER2_BASE_ADDRESS) |= 1 << TATOCINT_OFFSET; //Clear Flag of Time-Out Raw Interrupt.
}

void TIMER3A_Handler(void)
{
	static p_GptNotificationFun gptNotificationFn_TIMER3A;
	if (gp_gptNotification[GPT_16_32_BIT_TIMER3] != NULL)
	{
		gptNotificationFn_TIMER3A = gp_gptNotification[GPT_16_32_BIT_TIMER3];
		gptNotificationFn_TIMER3A();
	}
	GPTMICR(GPT_16_32_BIT_TIMER3_BASE_ADDRESS) |= 1 << TATOCINT_OFFSET; //Clear Flag of Time-Out Raw Interrupt.
}

void TIMER4A_Handler(void)
{
	static p_GptNotificationFun gptNotificationFn_TIMER4A;
	if (gp_gptNotification[GPT_16_32_BIT_TIMER4] != NULL)
	{
		gptNotificationFn_TIMER4A = gp_gptNotification[GPT_16_32_BIT_TIMER4];
		gptNotificationFn_TIMER4A();
	} 
	GPTMICR(GPT_16_32_BIT_TIMER4_BASE_ADDRESS) |= 1 << TATOCINT_OFFSET; //Clear Flag of Time-Out Raw Interrupt.
}

void TIMER5A_Handler(void)
{
	static p_GptNotificationFun gptNotificationFn_TIMER5A;
	if (gp_gptNotification[GPT_16_32_BIT_TIMER5] != NULL)
	{
		gptNotificationFn_TIMER5A = gp_gptNotification[GPT_16_32_BIT_TIMER5];
		gptNotificationFn_TIMER5A();
	}
	GPTMICR(GPT_16_32_BIT_TIMER5_BASE_ADDRESS) |= 1 << TATOCINT_OFFSET; //Clear Flag of Time-Out Raw Interrupt.
}

void WTIMER0A_Handler(void)
{
	static p_GptNotificationFun gptNotificationFn_WTIMER0A;
	if (gp_gptNotification[GPT_32_64_BIT_WIDE_TIMER0] != NULL)
	{
		gptNotificationFn_WTIMER0A = gp_gptNotification[GPT_32_64_BIT_WIDE_TIMER0];
		gptNotificationFn_WTIMER0A();
	}
		GPTMICR(GPT_32_64_BIT_WIDE_TIMER0_BASE_ADDRESS) |= 1 << TATOCINT_OFFSET; //Clear Flag of Time-Out Raw Interrupt.
}

void WTIMER1A_Handler(void)
{
	static p_GptNotificationFun gptNotificationFn_WTIMER1A;
	if (gp_gptNotification[GPT_32_64_BIT_WIDE_TIMER1] != NULL)
	{
		gptNotificationFn_WTIMER1A = gp_gptNotification[GPT_32_64_BIT_WIDE_TIMER1];
		gptNotificationFn_WTIMER1A();
	}
	GPTMICR(GPT_32_64_BIT_WIDE_TIMER1_BASE_ADDRESS) |= 1 << TATOCINT_OFFSET; //Clear Flag of Time-Out Raw Interrupt.
}

void WTIMER2A_Handler(void)
{
	static p_GptNotificationFun gptNotificationFn_WTIMER2A;
	if (gp_gptNotification[GPT_32_64_BIT_WIDE_TIMER2] != NULL)
	{
		gptNotificationFn_WTIMER2A = gp_gptNotification[GPT_32_64_BIT_WIDE_TIMER2];
		gptNotificationFn_WTIMER2A();
	}
	GPTMICR(GPT_32_64_BIT_WIDE_TIMER2_BASE_ADDRESS) |= 1 << TATOCINT_OFFSET; //Clear Flag of Time-Out Raw Interrupt.
}

void WTIMER3A_Handler(void)
{
	static p_GptNotificationFun gptNotificationFn_WTIMER3A;
	if (gp_gptNotification[GPT_32_64_BIT_WIDE_TIMER3] != NULL)
	{
		gptNotificationFn_WTIMER3A = gp_gptNotification[GPT_32_64_BIT_WIDE_TIMER3];
		gptNotificationFn_WTIMER3A();
	}
	GPTMICR(GPT_32_64_BIT_WIDE_TIMER3_BASE_ADDRESS) |= 1 << TATOCINT_OFFSET; //Clear Flag of Time-Out Raw Interrupt.
}

void WTIMER4A_Handler(void)
{
	static p_GptNotificationFun gptNotificationFn_WTIMER4A;
	if (gp_gptNotification[GPT_32_64_BIT_WIDE_TIMER4] != NULL)
	{
		gptNotificationFn_WTIMER4A = gp_gptNotification[GPT_32_64_BIT_WIDE_TIMER4];
		gptNotificationFn_WTIMER4A();
	}
	GPTMICR(GPT_32_64_BIT_WIDE_TIMER4_BASE_ADDRESS) |= 1 << TATOCINT_OFFSET; //Clear Flag of Time-Out Raw Interrupt.
}

void WTIMER5A_Handler(void)
{
	static p_GptNotificationFun gptNotificationFn_WTIMER5A;
	if (gp_gptNotification[GPT_32_64_BIT_WIDE_TIMER5] != NULL)
	{
		gptNotificationFn_WTIMER5A = gp_gptNotification[GPT_32_64_BIT_WIDE_TIMER5];
		gptNotificationFn_WTIMER5A();
	}
	GPTMICR(GPT_32_64_BIT_WIDE_TIMER5_BASE_ADDRESS) |= 1 << TATOCINT_OFFSET; //Clear Flag of Time-Out Raw Interrupt.
}
/**********************************************************************************************************************
 *  END OF FILE: Timer.c
 *********************************************************************************************************************/
