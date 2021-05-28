#include "TIM.h"
int h=0;
void Tim_Init (void){
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN ;//enable TIM2; AHB=1;APB1=1
	TIM1->CR1 |= TIM_CR1_ARPE; 					//	TIMx_ARR register is buffered(chay xong mooi nhan UEV)
	TIM1->SMCR |= (TIM_SMCR_SMS_1|TIM_SMCR_SMS_2);
	TIM1->PSC = 35999;
	TIM1->ARR = 4;
	
	TIM1->CCMR1 &= ~TIM_CCMR1_CC1S; //CC1 channel is configured as output
	//TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1;// 110 -> PWM mode 1
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_1 | TIM_CCMR1_OC1M_0 ;// Toggle - OC1REF toggles when TIMx_CNT=TIMx_CCR1.
	TIM1->CCER &= ~TIM_CCER_CC1P;//OC1 active high
	TIM1->CCMR1 |= TIM_CCMR1_OC1PE;  //TIMx_CCR1 preload value is loaded in the active register at each update event.
	TIM1->CR1 &= ~TIM_CR1_UDIS;			//Update disable -Counter overflow/underflow
	TIM1->CR1 &= ~ TIM_CR1_CMS ;// Edge-aligned mode. The counter counts up or down depending on the direction bit(DIR).
	TIM1->CR1 &= ~TIM_CR1_DIR;//UPCOUNTING MODE

}



void Delay ( uint32_t DLus  ){//unit 0,05us=>t=0,05 * DLus
	//trc khi ghi arr can disable UEV bit UDIS
       	
	
//	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN ;//enable TIM1; AHB=1;APB1=1
//	TIM1->CR1 |= TIM_CR1_ARPE; // TIMx_ARR register is buffered
//	//TIM1->DIER &= ~TIM_DIER_UIE;
//	
//	TIM1->PSC = 1;
//	TIM1->ARR = DLus;//45=1us=>delay 1/45 us
//	TIM1->CR1 &= ~ TIM_CR1_CMS ;// Edge-aligned mode. The counter counts up or down depending on the direction bit(DIR).
//	TIM1->CR1 &= ~TIM_CR1_DIR;//UPCOUNTING MODE
//	TIM1->CR1 &= ~TIM_CR1_UDIS;
//	TIM1->SR &= ~TIM_CR1_URS;
//	TIM1->SR &= ~TIM_SR_UIF;//clear update flag
//	TIM1->DIER |= TIM_DIER_UIE;//UEV-update event enable
//	//TIM1->DIER |= TIM_DIER_TIE;//.Trigger interrupt enable
//	TIM1->CR1 |= TIM_CR1_CEN;//COUNTER ENABLE
//	
//	while ((TIM1->SR & TIM_SR_UIF) != TIM_SR_UIF);
//	TIM1->SR &= ~TIM_SR_UIF;
	
	TIM1->PSC = 0; //arr=90=> t= 1us
	TIM1->ARR =DLus;

	TIM1->EGR = TIM_EGR_UG;
	TIM1->CR1 |=  TIM_CR1_OPM | TIM_CR1_CEN ;//one pulse mode
	TIM1->DIER |= TIM_DIER_TIE;
	while((TIM1->CR1 & TIM_CR1_CEN) != 0);
	
	while ((TIM1->SR & TIM_SR_UIF) != TIM_SR_UIF);
	TIM1->SR &= ~TIM_SR_UIF;

}
void PWM_config (void){
	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN ;//enable TIM1; AHB=1;APB1=1
	TIM1->CR1 |= TIM_CR1_ARPE; // TIMx_ARR register is buffered
	
	TIM1->PSC = 35999;
	TIM1->ARR = 1000;//1,25 us
	TIM1->CR1 &= ~ TIM_CR1_CMS ;// Edge-aligned mode. The counter counts up or down depending on the direction bit(DIR).
	TIM1->CR1 &= ~TIM_CR1_DIR;//UPCOUNTING MODE
	
	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 ;// 110 -> PWM mode 1
	TIM1->CCER |= TIM_CCER_CC1E; // ENABLE COMPARE 1 OUTPUT ENABLE
	TIM1->CCER &= ~TIM_CCER_CC1P; //OC1 active high
	TIM1->CCMR1 &= ~TIM_CCMR1_CC1S; //CC1 channel is configured as output
	TIM1->CCMR1 |= TIM_CCMR1_OC1PE;  //Output Compare 1 preload enable
	TIM1->CCMR1 |= TIM_CCMR1_OC1FE;//Output Compare 1 fast enable
	
//	TIM2->CR1 &= ~TIM_CR1_UDIS;// UPDATE ENABLE
	TIM1->EGR |= TIM_EGR_UG;// UPDATE ENABLE ( DEM TU O -> VALUE ARR)
	TIM1->BDTR |= TIM_BDTR_MOE;//Main output enable
	TIM1->BDTR |= TIM_BDTR_AOE;//Automatic output enable
//	// TIM_CR1_URS =O (RESET) KHONG CAN CAI 
	
//	TIM2->SR &= ~TIM_CR1_URS;
  
	
//	TIM2->DIER |= TIM_DIER_TIE;//Trigger interrupt enable
//	TIM2->DIER |= TIM_DIER_UIE;//Update interrupt enable
//	NVIC_EnableIRQ(TIM2_IRQn);// Enable interrup TIM2

 // NVIC_EnableIRQ(TIM1_CC_IRQn);//Interrupt compare enable
	//TIM1->CR1 |= TIM_CR1_CEN;//COUNTER ENABLE
	
}
void res (void){
//	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN ;//enable TIM1; AHB=1;APB1=1
//	TIM1->CR1 |= TIM_CR1_ARPE; // TIMx_ARR register is buffered
//	
//	TIM1->PSC = 0;
//	TIM1->ARR = 3600;//86,4=>  1.2 us; 93.6=>1.3us
//	TIM1->CR1 &= ~ TIM_CR1_CMS ;// Edge-aligned mode. The counter counts up or down depending on the direction bit(DIR).
//	TIM1->CR1 &= ~TIM_CR1_DIR;//UPCOUNTING MODE
//	
//	TIM1->CCMR1 |= TIM_CCMR1_OC1M_2 | TIM_CCMR1_OC1M_1 ;// 110 -> PWM mode 1
//	TIM1->CCER |= TIM_CCER_CC1E; // ENABLE COMPARE 1 OUTPUT ENABLE
//	TIM1->CCER &= ~TIM_CCER_CC1P; //OC1 active high
//	TIM1->CCMR1 &= ~TIM_CCMR1_CC1S; //CC1 channel is configured as output
//	TIM1->CCMR1 |= TIM_CCMR1_OC1PE;  //Output Compare 1 preload enable
//	TIM1->CCMR1 |= TIM_CCMR1_OC1FE;//Output Compare 1 fast enable
//	
////	TIM2->CR1 &= ~TIM_CR1_UDIS;// UPDATE ENABLE
//	TIM1->EGR |= TIM_EGR_UG;// UPDATE ENABLE ( DEM TU O -> VALUE ARR)
//	TIM1->BDTR |= TIM_BDTR_MOE;//Main output enable
//	TIM1->BDTR |= TIM_BDTR_AOE;//Automatic output enable
////	// TIM_CR1_URS =O (RESET) KHONG CAN CAI 
////	TIM2->SR &= ~TIM_CR1_URS;
//  
//	
////	TIM2->DIER |= TIM_DIER_TIE;//Trigger interrupt enable
////	TIM2->DIER |= TIM_DIER_UIE;//Update interrupt enable
////	NVIC_EnableIRQ(TIM2_IRQn);// Enable interrup TIM2

// // NVIC_EnableIRQ(TIM1_CC_IRQn);//Interrupt compare enable
//	TIM1->CR1 |= TIM_CR1_CEN;//COUNTER ENABLE
//	TIM1->CCR1 = 0;
//	while ((TIM1->SR & TIM_SR_UIF) != TIM_SR_UIF);
//	
//	TIM1->SR &= ~TIM_SR_UIF;
	clearBit(GPIOC->ODR, 13);
	Delay(5500);
	
}
void set (void){
//  GPIOC->ODR |= GPIO_ODR_ODR13; 
//	//setBit(GPIOC->ODR, 13);
//	Delay(100);
//	GPIOC->ODR &= ~GPIO_ODR_ODR13;
//	//clearBit(GPIOC->ODR, 13);
//	Delay(300);
//	
	
	
}
void reset (void){         
	setBit(GPIOC->ODR, 13);
	Delay(36);
	clearBit(GPIOC->ODR, 13);
	Delay(76);
}

