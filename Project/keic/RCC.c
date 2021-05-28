#include "RCC.h"

void RCC_conf (void){
	SystemInit();
//	DeInit_RCC();
	RCC->CR &= ~RCC_CR_PLLON;
	RCC->CR |= ((uint32_t)RCC_CR_HSEON);	 //HSE enable
	while(!(RCC->CR & RCC_CR_HSERDY));     //wait still HSE ready
	
	FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY; // Clock Flash memory
	RCC->CR &= ~RCC_CR_PLLON;
	while (!(RCC->CR|RCC_CR_PLLON))
	
	RCC->CFGR &= ~RCC_CFGR_PLLMULL16;
	RCC->CFGR |= RCC_CFGR_PLLMULL5; // PLL x5: clock = 8 MHz * 5 = 40 MHz
	
	RCC->CFGR |= RCC_CFGR_HPRE_DIV1; // AHB = SYSCLK
	RCC->CFGR |= RCC_CFGR_PPRE1_DIV2; //APB1 = AHB/2 = HCLK/2 = 72/2 = 36 MHz
	RCC->CFGR |= RCC_CFGR_PPRE2_DIV1; //APB2 = AHB = HCLK = 72 MHz
	RCC->CFGR |= RCC_CFGR_MCO_PLL; //System clock (SYSCLK) selected for Clock OUTPUT
	
	RCC->CFGR &= ~RCC_CFGR_PLLMULL;  //Clear PLLBIL bits
	RCC->CFGR &= ~RCC_CFGR_PLLSRC;   //Clear PLLSRC bit
	RCC->CFGR &= ~RCC_CFGR_PLLXTPRE; //Clear PLLXTPRE bit / HSE divider for PLL entry
	
	RCC->CFGR |= RCC_CFGR_PLLSRC; //HSE oscillator clock selected as PLL input clock
	clearBit(RCC->CFGR, 17); //HSE clock not divided
	
	//RCC->CFGR &= ~RCC_CFGR_PLLMULL16;
	
	
	RCC->CR |= RCC_CR_PLLON; //PLL on
	while((RCC->CR & RCC_CR_PLLRDY)==0); // wait till PLL ready
	
	RCC->CFGR &= ~RCC_CFGR_SW; //clear SW bits
	RCC->CFGR |= RCC_CFGR_SW_PLL; //PLL selected as system clock
	while((RCC->CFGR & RCC_CFGR_SWS) != RCC_CFGR_SWS_1) {};		// wait till PLL is used		
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN ;
//}

//void DeInit_RCC(void){
//	RCC->CR = 0x00008083;
//	
//	RCC->CFGR = 0x00;
//	
}
