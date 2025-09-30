#include "stm32f10x.h"

typedef enum {
	GPIO_MODE_INPUT=0,
	GPIO_MODE_OUTPUT_10MHZ,
	GPIO_MODE_OUTPUT_2MHZ,
	GPIO_MODE_OUTPUT_50MHZ
} GPIO_MODE;
typedef enum{
	GPIO_CNF_ANALOG=0,
	GPIO_CNF_FLOATING=1,
	GPIO_CNF_PULL=2,
	GPIO_CNF_GP_PP=0,
	GPIO_CNF_GP_OD=1,
	GPIO_CNF_AF_PP=2,
	GPIO_CNF_AF_OD=3
}GPIO_Cnf;
 typedef enum{
	Bit_Reset=0,
	Bit_Set
 }BitAction;
 
void GPIOconfig(GPIO_TypeDef *GPIOx,uint16_t PINmask,GPIO_MODE mode,GPIO_Cnf cnf);
void GPIO_Write_Pin (GPIO_TypeDef *GPIOx,uint16_t PINmask,BitAction State_Set_Reset);
void GPIO_Toggle (GPIO_TypeDef *GPIOx,uint16_t PINmask);
 
