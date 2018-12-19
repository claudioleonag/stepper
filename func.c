

#include <stdint.h>
#include <string.h>
#include "tm4c1294ncpdt.h"


void Motor_Meio_Horario(void)
{
		int i;
		for(i=0;i<256;i++)
		{
			PortN_Input(0x01);
			PortH_Output(0x07);
			SysTick_Wait1ms(2);
			PortH_Output(0x03);
			SysTick_Wait1ms(2);
			PortH_Output(0x0B);
			SysTick_Wait1ms(2);
			PortH_Output(0x09);
			SysTick_Wait1ms(2);
			PortH_Output(0x0D);
			SysTick_Wait1ms(2);
			PortH_Output(0x0C);
			SysTick_Wait1ms(2);
			PortH_Output(0x0E);
			SysTick_Wait1ms(2);
			PortH_Output(0x06);
			SysTick_Wait1ms(2);
			PortN_Input(0x00);
		}
		PortH_Output(0x0F);
}

void Motor_Antihorario(void)
{
		int i;
		for(i=0;i<256;i++)
		{
            PortN_Input(0x02);
			PortH_Output(0x0C);
			SysTick_Wait1ms(2);
			PortH_Output(0x04);
			SysTick_Wait1ms(2);
			PortH_Output(0x06);
			SysTick_Wait1ms(2);
			PortH_Output(0x02);
			SysTick_Wait1ms(2);
            PortH_Output(0x03);
            SysTick_Wait1ms(2);
            PortH_Output(0x01);
            SysTick_Wait1ms(2);
            PortH_Output(0x03);
            SysTick_Wait1ms(2);
            PortH_Output(0x09);
            SysTick_Wait1ms(2);
            PortH_Output(0x08);
            SysTick_Wait1ms(2);
            PortN_Input(0x02);
		}
		PortH_Output(0x0F);
}
