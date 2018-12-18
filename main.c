#include <stdint.h>
#include "tm4c1294ncpdt.h"

void PortL_Output(uint32_t valor);
void PLL_Init(void);
void SysTick_Init(void);
void SysTick_Wait1ms(uint32_t delay);
void GPIO_Init(void);

void Motor_Antihorario(void)
{
		int i;
		for(i=0;i<256;i++)
		{
			PortL_Output(0x0E);
			SysTick_Wait1ms(2);
			PortL_Output(0x0D);
			SysTick_Wait1ms(2);
			PortL_Output(0x0B);
			SysTick_Wait1ms(2);
			PortL_Output(0x07);
			SysTick_Wait1ms(2);
		}
		PortL_Output(0x0F);
}

int main(void)
{
	PLL_Init();
	SysTick_Init();
	GPIO_Init();
	SysTick_Wait1ms(50);
	Motor_Antihorario();
}