#include "IntCtrl.h"
#include "Mcu.h"

extern const Mcu_Config_st McuConfig[];


int main(void)
{
	IntCtrl_Init();
	Mcu_Init(&McuConfig[0]);
	
	while(1)
	{
	
	}
	return 0;
}