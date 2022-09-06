#include "IntCtrl.h"
#include "Mcu.h"
#include "Dio.h"
#include "Port.h"

extern const Mcu_Config_st McuConfig[];
extern const Port_Config_st PortConfig[];

int main(void)
{
	IntCtrl_Init();
	Mcu_Init(&McuConfig[0]);
	Port_Init(&PortConfig[0]);
	while(1)
	{
		
	}
	return 0;
}