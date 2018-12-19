#include <stdint.h>
#include <string.h>
#include "tm4c1294ncpdt.h"
#include "func.h"

void PortH_Output(uint32_t valor);
void PLL_Init(void);
void SysTick_Init(void);
void SysTick_Wait1ms(uint32_t delay);
void GPIO_Init(void);

int main(void)
{
	PLL_Init();
	SysTick_Init();
	GPIO_Init();
	SysTick_Wait1ms(50);
	while(1)
	{
		uint32_t temp;
		temp = PortJ_Input();
		if (temp == 0x01)
		{
			Motor_Meio_Horario();
			
			SysTick_Wait1ms(50);			
		}
		//temp = 0x00;
	}
	//Motor_Antihorario();
	//SysTick_Wait1ms(50);
	
}
