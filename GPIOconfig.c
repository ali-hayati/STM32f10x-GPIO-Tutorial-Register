#include "GPIOconfig.h"

void GPIOconfig(GPIO_TypeDef *GPIOx,uint16_t PINmask,GPIO_MODE mode,GPIO_Cnf cnf)
{
	uint8_t pin;
	for (pin=0; pin<16; pin++)
	{
		if(PINmask &(1<<pin))
		{
			volatile uint32_t *cr;
			uint32_t pos=(pin%8)*4;
			uint32_t val=((uint32_t) cnf<<2)| ((uint32_t)mode &0x3);
			
			if(pin<8)
			{
				cr = &GPIOx->CRL;
			}else
			{
				cr = &GPIOx->CRH;
			}
			
			*cr &= ~(0xf<<pos);
			*cr|= (val<<pos);
		}
	}
	
}

void GPIO_Write_Pin(GPIO_TypeDef *GPIOx,uint16_t PINmask,BitAction State_Set_Reset)
{
	uint8_t pin;
	for(pin=0;pin<16;pin++)
	{
		if (PINmask &(1<<pin))
		{
			if (State_Set_Reset== Bit_Set)
			{
				GPIOx->BSRR= (1<<pin);
			}else{
				GPIOx->BSRR=(1<<(pin+16));
			}
		}
	}
}

void GPIO_Toggle (GPIO_TypeDef *GPIOx,uint16_t PINmask)
{
	uint8_t pin;
	for(pin=0;pin<16;pin++)
	{
		if (PINmask & (1<<pin))
		{
			if (GPIOx->ODR &(1<<pin))
			{
				GPIOx->BSRR= (1<<(pin+16));
			}else{
				GPIOx->BSRR= (1<<pin);
			}
		}
	}
}
