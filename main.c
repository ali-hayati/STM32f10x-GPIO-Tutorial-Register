#include "stm32f10x.h"
#include "RCCconfig.h"
#include "GPIOconfig.h"
void delay (uint32_t time)
{
	while (time--);
}
int main()
{
	PLLConfig();
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	GPIOconfig(GPIOA,0xFFFF,GPIO_MODE_OUTPUT_10MHZ,GPIO_CNF_GP_PP);
	GPIOconfig(GPIOB,0xffff,GPIO_MODE_OUTPUT_10MHZ,GPIO_CNF_GP_PP);
	
	while(1)
	{
		//GPIO_Write_Pin(GPIOA,0xFFFF,Bit_Set);
		GPIO_Toggle(GPIOA,(1<<0)|(1<<5));
		GPIO_Toggle(GPIOB,0xffff);
		delay (200000); 
		//GPIO_Write_Pin(GPIOA,0xFFFF,Bit_Reset);
		//delay (200000);
	}
}
