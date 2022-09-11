#include "IntCtrl.h"
#include "Mcu.h"
#include "Dio.h"
#include "Port.h"
#include "Timer.h"

extern const Mcu_Config_st McuConfig[];
extern const Port_Config_st PortConfig[];
extern const Gpt_Config_st Gpt_Config[];

void App_SetLedConfig(uint8_t onTime, uint8_t offTime);
void App_WTimer0_IsrHandler(void);

uint32_t g_led_onTicksNumber;
uint32_t g_led_offTicksNumber;
	
int main(void)
{
	Mcu_Init(&McuConfig[0]);
	IntCtrl_Init();
	Port_Init(&PortConfig[0]);
	Gpt_Init(&Gpt_Config[0]);
	Gpt_EnableNotification(GPT_32_64_BIT_WIDE_TIMER0);
	Gpt_StartTimer(GPT_32_64_BIT_WIDE_TIMER0, 1000);
	App_SetLedConfig(1, 1);
	while(1)
	{
	}
	return 0;
}



void App_SetLedConfig(uint8_t onTime, uint8_t offTime)
{
	g_led_onTicksNumber = onTime;
	g_led_offTicksNumber = offTime;
} /*App_SetLedConfig*/


void App_WTimer0_IsrHandler(void)
{
	static i = 0;
	static count = 0;
	if((i == 0) && ((count/500) < g_led_offTicksNumber))
	{
		Dio_WriteChannel(CHANNEL_F3, ~Dio_ReadChannel(CHANNEL_F3));
	}
	else if((i == 0) && ((count/500) == g_led_offTicksNumber))
	{
		Dio_WriteChannel(CHANNEL_F3, HIGH);
		count = 0;
		i++;
	}
	else if((i == 1) && ((count/500) == g_led_onTicksNumber))
	{
		Dio_WriteChannel(CHANNEL_F3, LOW);
		count = 0;
		i = 0;
	}
	count++;
}