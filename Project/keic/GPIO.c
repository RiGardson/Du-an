#include "GPIO.h"

void GPIO (void){
	
	//gpioc 13 out put

	
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	GPIOC->BSRR &= ~GPIO_BSRR_BS13 ;
	GPIOC->CRH &= ~GPIO_CRH_CNF13;//general purpose output push-pull
	GPIOC->CRH |= GPIO_CRH_MODE13;
	GPIOC->ODR &= ~GPIO_ODR_ODR13;
	
	// GPIO PA8 out put dung PWM : TIM1_CH1
	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
	RCC->APB2ENR &= ~RCC_APB2ENR_AFIOEN;
	RCC->APB2ENR |= RCC_APB2ENR_AFIOEN;
	// MODE 10: Alternate function output Push-pull
//	RCC->APB2ENR |= RCC_APB2ENR_IOPAEN;
//	GPIOA->CRH &= ~GPIO_CRH_CNF8;
	GPIOA->CRH |= GPIO_CRH_CNF8_1;// Alternate function output Push-pull
	GPIOA->CRH &= ~GPIO_CRH_CNF8_0;
//	GPIOA->CRH |= GPIO_CRH_MODE8;//output-50Hz
//	
	
	
	//GPIOA->BSRR &= ~GPIO_BSRR_BS8 ;
	//GPIOA->CRH &= ~GPIO_CRH_CNF8;//general purpose output push-pull
	GPIOA->CRH |= GPIO_CRH_MODE8;
	//GPIOA->ODR &= ~GPIO_ODR_ODR8;
	
}
