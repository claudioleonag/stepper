// gpio.c
// Desenvolvido para a placa EK-TM4C1294XL
// Inicializa as portas J e N
// Prof. Guilherme Peron


#include <stdint.h>

#include "tm4c1294ncpdt.h"

#define GPIO_PORTAS (0x5FB7) //bits 8 e 12 2_0101 1111 1011 0111 A B C E K L M N Q

void SysTick_Wait1ms(uint32_t delay);
// -------------------------------------------------------------------------------
// Função GPIO_Init
// Inicializa os ports J e N
// Parâmetro de entrada: Não tem
// Parâmetro de saída: Não tem
void GPIO_Init(void)
{
	int temp;
	//1a. Ativar o clock para a porta setando o bit correspondente no registrador RCGCGPIO
	SYSCTL_RCGCGPIO_R |= GPIO_PORTAS;
	//1b.   após isso verificar no PRGPIO se a porta está pronta para uso.
  while((SYSCTL_PRGPIO_R & (GPIO_PORTAS) ) != (GPIO_PORTAS) ){};
	
	// 2. Limpar o AMSEL para desabilitar a analógica
	temp = GPIO_PORTC_AHB_AMSEL_R;
	temp = temp & 0xF0;
	temp = temp | 0x00;
	GPIO_PORTC_AHB_AMSEL_R = temp;
	GPIO_PORTJ_AHB_AMSEL_R = 0x00;
	GPIO_PORTA_AHB_AMSEL_R = 0x00;
	GPIO_PORTB_AHB_AMSEL_R = 0x00;
	GPIO_PORTE_AHB_AMSEL_R = 0x00;
	GPIO_PORTF_AHB_AMSEL_R = 0x00;
	GPIO_PORTH_AHB_AMSEL_R = 0x00;
	GPIO_PORTK_AMSEL_R = 0x00;
	GPIO_PORTL_AMSEL_R = 0x00;
	GPIO_PORTM_AMSEL_R = 0x00;
	GPIO_PORTN_AMSEL_R = 0x00;
	GPIO_PORTQ_AMSEL_R = 0x00;
		
	// 3. Limpar PCTL para selecionar o GPIO
	temp = GPIO_PORTC_AHB_PCTL_R;
	temp = temp & 0x00001111;
	GPIO_PORTC_AHB_PCTL_R = temp;
	GPIO_PORTJ_AHB_PCTL_R = 0x00;
	GPIO_PORTA_AHB_PCTL_R = 0x00;
	GPIO_PORTB_AHB_PCTL_R = 0x00;
	GPIO_PORTE_AHB_PCTL_R = 0x00;
	GPIO_PORTF_AHB_PCTL_R = 0x00;
	GPIO_PORTH_AHB_PCTL_R = 0x00;
	GPIO_PORTK_PCTL_R = 0x00;
	GPIO_PORTL_PCTL_R = 0x00;
	GPIO_PORTM_PCTL_R = 0x00;
	GPIO_PORTN_PCTL_R = 0x00;
	GPIO_PORTQ_PCTL_R = 0x00;
		
	// 4. DIR para 0 se for entrada, 1 se for saída
	GPIO_PORTC_AHB_DIR_R = 0xF0;
	GPIO_PORTJ_AHB_DIR_R = 0x00;
	GPIO_PORTA_AHB_DIR_R = 0xF0; 			//2_11110000
	GPIO_PORTB_AHB_DIR_R = 0x30; 			//2_00110000
	GPIO_PORTE_AHB_DIR_R = 0x03;
	GPIO_PORTF_AHB_DIR_R = 0x0C;			//2_00001110
	GPIO_PORTH_AHB_DIR_R = 0x0F; 			//2_00001111
	GPIO_PORTK_DIR_R = 0xFF; 			//2_11111111
	GPIO_PORTL_DIR_R = 0x00; 			//2_00001111
	GPIO_PORTM_DIR_R = 0x47; 			//2_01000111
	GPIO_PORTN_DIR_R = 0x03; 			//2_00000011
	GPIO_PORTQ_DIR_R = 0x0F; 			//2_00001111
		
	// 5. Limpar os bits AFSEL para 0 para selecionar GPIO sem função alternativa	
	temp = GPIO_PORTC_AHB_AFSEL_R;
	temp = temp & 0x0F;
	temp = temp | 0x00;
	GPIO_PORTC_AHB_AFSEL_R = temp;
	GPIO_PORTJ_AHB_AFSEL_R = 0x00;
	GPIO_PORTA_AHB_AFSEL_R = 0x00;
	GPIO_PORTB_AHB_AFSEL_R = 0x00;
	GPIO_PORTE_AHB_AFSEL_R = 0x00;
	GPIO_PORTF_AHB_AFSEL_R = 0x00;
	GPIO_PORTH_AHB_AFSEL_R = 0x00;
	GPIO_PORTK_AFSEL_R = 0x00; 
	GPIO_PORTL_AFSEL_R = 0x00;
	GPIO_PORTM_AFSEL_R = 0x00;
	GPIO_PORTN_AFSEL_R = 0x00;
	GPIO_PORTQ_AFSEL_R = 0x00;
		
	// 6. Setar os bits de DEN para habilitar I/O digital	
	GPIO_PORTC_AHB_DEN_R = 0xF0;   	//2_11110000
	GPIO_PORTJ_AHB_DEN_R = 0x03;   	//2_00000011
	GPIO_PORTA_AHB_DEN_R = 0xF0; 		   	//2_11110000
	GPIO_PORTB_AHB_DEN_R = 0x30; 		   	//2_00110000
	GPIO_PORTE_AHB_DEN_R = 0x03;
	GPIO_PORTF_AHB_DEN_R = 0x0C;
	GPIO_PORTH_AHB_DEN_R = 0x0F; 		   	//2_00001111
	GPIO_PORTK_DEN_R = 0xFF; 		   	//2_11111111
	GPIO_PORTL_DEN_R = 0x0F; 		   	//2_00001111
	GPIO_PORTM_DEN_R = 0x47; 		   	//2_01000111
	GPIO_PORTN_DEN_R = 0x03; 		   	//2_00000011
	GPIO_PORTQ_DEN_R = 0x0F; 		   	//2_00001111
	
	// 7. Habilitar resistor de pull-up interno, setar PUR para 1
	GPIO_PORTL_PUR_R = 0x0F;		//2_00001111
	GPIO_PORTJ_AHB_PUR_R = 0x03;   	//Bit0 e bit1	

}	

// -------------------------------------------------------------------------------
// Função PortJ_Input
// Lê os valores de entrada do port J
// Parâmetro de entrada: Não tem
// Parâmetro de saída: o valor da leitura do port
uint32_t PortL_Input(void)
{
	return GPIO_PORTL_DATA_R;
}

uint32_t PortJ_Input(void)
{
	return GPIO_PORTJ_AHB_DATA_R;
}

// -------------------------------------------------------------------------------
// Função PortN_Output
// Escreve os valores no port N
// Parâmetro de entrada: Valor a ser escrito
// Parâmetro de saída: não tem

void PortA_Output(uint32_t valor)
{
    uint32_t temp;
    //para uma escrita amigável nos bits 0 e 1
    temp = GPIO_PORTA_AHB_DATA_R & 0x0F;	//2_00001111
    //agora vamos fazer o OR com o valor recebido na função
    temp = temp | valor;
    GPIO_PORTA_AHB_DATA_R = valor; 
}

void PortB_Output(uint32_t valor)
{
    uint32_t temp;
    //para uma escrita amigável nos bits 0 e 1
    temp = GPIO_PORTB_AHB_DATA_R & 0x0F;	//2_00001111
    //agora vamos fazer o OR com o valor recebido na função
    temp = temp | valor;
    GPIO_PORTB_AHB_DATA_R = valor; 
}

void PortC_Output(uint32_t valor)
{
    GPIO_PORTC_AHB_DATA_R = valor; 
}

void PortE_Output(uint32_t valor)
{
    GPIO_PORTE_AHB_DATA_R = valor; 
}

void PortF_Output(uint32_t valor)
{
    GPIO_PORTF_AHB_DATA_R = valor; 
}

void PortH_Output(uint32_t valor)
{
		uint32_t temp;
    //para uma escrita amigável nos bits 0 e 1
    temp = GPIO_PORTH_AHB_DATA_R & 0x0F;	//2_00001111
    //agora vamos fazer o OR com o valor recebido na função
    temp = temp | valor;
    GPIO_PORTH_AHB_DATA_R = valor;
}

void PortK_Output(uint32_t valor)
{
		uint32_t temp;
    //para uma escrita amigável nos bits 0 e 1
    temp = GPIO_PORTK_DATA_R & 0x00;	//2_00001111
    //agora vamos fazer o OR com o valor recebido na função
    temp = temp | valor;
    GPIO_PORTK_DATA_R = valor; 
}

void PortN_Output(uint32_t valor)
{
    uint32_t temp;
    //vamos zerar somente os bits menos significativos
    //para uma escrita amigável nos bits 0 e 1
    temp = GPIO_PORTN_DATA_R & 0xFC;
    //agora vamos fazer o OR com o valor recebido na função
    temp = temp | valor;
    GPIO_PORTN_DATA_R = valor; 
}

void PortQ_Output(uint32_t valor)
{
    uint32_t temp;
    //para uma escrita amigável nos bits 0 e 1
    temp = GPIO_PORTQ_DATA_R & 0xF0;	//2_11110000
    //agora vamos fazer o OR com o valor recebido na função
    temp = temp | valor;
    GPIO_PORTQ_DATA_R = valor; 
}

void Pulse_Enable()
{
		uint32_t temp;
    temp = GPIO_PORTM_DATA_R & 0x07; 	//2_0000 0111
    temp = temp | 0x04;	//2_0000 0100
    SysTick_Wait1ms(5);
	  GPIO_PORTM_DATA_R = temp; 
		SysTick_Wait1ms(5);
		temp = temp & 0x03;	//2_0000 0011
		GPIO_PORTM_DATA_R = temp; 
}

void Ativa_Rs()
{
		uint32_t temp;
    //vamos zerar somente os bits menos significativos
    //para uma escrita amigável nos bits 0 e 1
    temp = GPIO_PORTM_DATA_R & 0x07; 	//2_0000 0111
    //agora vamos fazer o OR com o valor recebido na função
    temp = temp | 0x01;	//2_0000 0001;
	  GPIO_PORTM_DATA_R = temp; ;
}

void Desativa_Rs()
{
		uint32_t temp;
    //vamos zerar somente os bits menos significativos
    //para uma escrita amigável nos bits 0 e 1
    temp = GPIO_PORTM_DATA_R & 0x07; 	//2_0000 0111
    //agora vamos fazer o OR com o valor recebido na função
    temp = temp & 0x06;	//2_0000 0110
	  GPIO_PORTM_DATA_R = temp; 
}

void ConfigJ_Interrupts(void)
{
		uint32_t temp=0x00;
	
		GPIO_PORTJ_AHB_IM_R = 0x0;
		
	
		temp = temp | GPIO_PORTJ_AHB_IS_R;
		GPIO_PORTJ_AHB_IS_R = temp;
		
	
		temp = 0x0;
		temp = temp | GPIO_PORTJ_AHB_IBE_R;
		GPIO_PORTJ_AHB_IBE_R = temp;
		
		
		temp = 0x00;
		temp = temp | GPIO_PORTJ_AHB_IEV_R;
		GPIO_PORTJ_AHB_IEV_R = temp;
		temp = 0x00;
		//temp = temp | GPIO_PORTL_IEV_R;
		//GPIO_PORTL_IEV_R = temp;
	
		GPIO_PORTJ_AHB_RIS_R = 0x1;
		
	
		GPIO_PORTJ_AHB_IM_R = 0x0;
		//GPIO_PORTL_IM_R = 0x0;
		
	
		temp = 0x1;
		temp = temp | GPIO_PORTJ_AHB_IM_R;
		GPIO_PORTJ_AHB_IM_R = temp;
		temp = 0x1;
		//temp = temp | GPIO_PORTL_IM_R;
		//GPIO_PORTL_IM_R = temp;
		
		NVIC_PRI12_R = 0x20000000;	//2_0010 0000 0000 0000 0000 0000 0000 0000
		
		NVIC_EN1_R 	 = 0x00080000; 	//2_0000 0000 0010 1000 0000 0000 0000 0000
		
		temp = 0x1;
		temp = temp | GPIO_PORTJ_AHB_ICR_R;
		GPIO_PORTJ_AHB_ICR_R = temp;
		
		
}

void ConfigL_Interrupts(void)
{
		uint32_t temp = 0x0;
	
		temp = GPIO_PORTL_IM_R;
		temp = temp & 0xF0;
		GPIO_PORTL_IM_R = temp;
		
		temp = GPIO_PORTL_IS_R;
		temp = temp & 0xF0;
		GPIO_PORTL_IS_R = temp;
	
		temp = GPIO_PORTL_IBE_R;
		temp = temp & 0xF0;
		GPIO_PORTL_IBE_R = temp;
		
		temp = 0x00;
		temp = temp | GPIO_PORTL_IEV_R;
		GPIO_PORTL_IEV_R = temp;
	
		temp = GPIO_PORTL_RIS_R;
		temp = temp & 0xF0;
		GPIO_PORTL_RIS_R = temp;
		
		temp = GPIO_PORTL_IM_R;
		temp = temp & 0x0F;
		GPIO_PORTL_IM_R = temp;
	
		NVIC_PRI13_R = 0x00002000;	//2_0000 0000 0000 0000 0010 0000 0000 0000
		NVIC_EN1_R 	 = 0x00280000; 	//2_0000 0000 0010 1000 0000 0000 0000 0000
		
		temp = GPIO_PORTL_ICR_R;
		temp = temp & 0x0F;
		GPIO_PORTL_ICR_R = temp;
}

