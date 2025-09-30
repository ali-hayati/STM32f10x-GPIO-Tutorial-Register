#include "RCCconfig.h"
#include "stm32f10x.h"

void PLLConfig (void)
{
	// 1. ENABLE HSE and wait for the HSE to become Ready
	RCC->CR |= RCC_CR_HSEON;
	while (!(RCC->CR & RCC_CR_HSERDY));
	
	RCC->APB1ENR |= RCC_APB1ENR_PWREN;
	PWR->CR = PWR_CR_PLS_2V9 | PWR_CR_PVDE; // VDD threshold = 2.9V, Power Voltage Detector enabled
	while (PWR->CSR & PWR_CSR_PVDO); // Wait while VDD is below 2.9V (PVDO = 1)
	
	FLASH->ACR=FLASH_ACR_LATENCY_2 | FLASH_ACR_PRFTBE; //Configure Flash: 2 wait states, enable prefetch for 72 MHz
	while (!(FLASH->ACR & FLASH_ACR_PRFTBS)); // Wait until prefetch buffer is enabled
	
	RCC->CR |= RCC_CR_PLLON;                 // Enable the PLL
	while (!(RCC->CR & RCC_CR_PLLRDY));      // Wait until the PLL is ready/stable

	// Configure system clocks and prescalers:
	// - PLL source = HSE
	// - PLL multiplier = 9 (8MHz HSE × 9 = 72MHz)
	// - APB1 prescaler = 2 (max 36MHz)
	// - APB2 prescaler = 1 (max 72MHz)
	// - AHB prescaler = 1 (HCLK = 72MHz)
	
	RCC->CFGR = RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL9 |
							RCC_CFGR_PPRE1_DIV2 | RCC_CFGR_PPRE2_DIV1 |
							RCC_CFGR_HPRE_DIV1;
	RCC->AHBENR |= RCC_AHBENR_FLITFEN | RCC_AHBENR_SRAMEN;
	
	// - Select PLL as system clock
	RCC->CFGR |= RCC_CFGR_SW_PLL;
	while (!(RCC->CFGR & RCC_CFGR_SWS_PLL)); // Wait until PLL is used as system clock
	
}
