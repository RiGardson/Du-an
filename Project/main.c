#include "main.h"
int i=0;
uint8_t j=0;
int k=21;//so bong den
int A[8];
//int val_test=0;
//volatile uint8_t g = 0; 
//uint32_t t1=0,t2=0,detalt;
//uint32_t ms=0;
uint8_t a=0,b=0,c=255;
int main (void){
	//__disable_irq();

	RCC_conf();
	GPIO();
	//PWM_config();
	__enable_irq();
	
	while(1){	

//for (i=0;i<21;i++){
//if ((a&0x80)>0)set_test();else reset_test();
//if ((a&0x40)>0)set_test();else reset_test();
//if ((a&0x20)>0)set_test();else reset_test();
//if ((a&0x10)>0)set_test();else reset_test();
//if ((a&0x08)>0)set_test();else reset_test();
//if ((a&0x04)>0)set_test();else reset_test();
//if ((a&0x02)>0)set_test();else reset_test();
//if ((a&0x01)>0)set_test();else reset_test();
//	
//if ((b&0x80)>0)set_test();else reset_test();
//if ((b&0x40)>0)set_test();else reset_test();	
//if ((b&0x20)>0)set_test();else reset_test();
//if ((b&0x10)>0)set_test();else reset_test();
//if ((b&0x08)>0)set_test();else reset_test();
//if ((b&0x04)>0)set_test();else reset_test();
//if ((b&0x02)>0)set_test();else reset_test();
//if ((b&0x01)>0)set_test();else reset_test();
//	
//if ((c&0x80)>0)set_test();else reset_test();
//if ((c&0x40)>0)set_test();else reset_test();	
//if ((c&0x20)>0)set_test();else reset_test();
//if ((c&0x10)>0)set_test();else reset_test();
//if ((c&0x08)>0)set_test();else reset_test();
//if ((c&0x04)>0)set_test();else reset_test();
//if ((c&0x02)>0)set_test();else reset_test();
//last_bit();
//}

//Delay (3500);
//reb=>green=>blu=>do====>b=255=>a=255=>c=255=>a=255
a=0;b=255;c=0;
for (j=0;j<255;j++){
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);	
	a++;
	b--;
		}

for (j=0;j<255;j++){
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
	c++;
	a--;
	}
	
for (j=0;j<254;j++){
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
loop(k,a,b,c);
	b++;
	c--;
		}
	}
}



//void TIM1_UP_IRQHandler (void){
//	TIM1->SR &= ~TIM_SR_UIF;
//	ToogleBit(GPIOC->ODR, 13);
//}
//void SysTick_Handler(void)
//{
//	SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Pos;
//	ms++;
//	//ToogleBit(GPIOC->ODR, 13);
//}
void bit_color (uint8_t l){
	if ((l&0x80)>0)GPIOC->ODR |= GPIO_ODR_ODR13;else GPIOC->ODR &= ~GPIO_ODR_ODR13;
	GPIOC->ODR |= GPIO_ODR_ODR12 ;

	if ((l&0x40)>0)GPIOC->ODR |= GPIO_ODR_ODR13;else GPIOC->ODR &= ~GPIO_ODR_ODR13;
	GPIOC->ODR |= GPIO_ODR_ODR12 ;

	if ((l&0x20)>0)GPIOC->ODR |= GPIO_ODR_ODR13;else GPIOC->ODR &= ~GPIO_ODR_ODR13;
	GPIOC->ODR |= GPIO_ODR_ODR12 ;

	if ((l&0x10)>0)GPIOC->ODR |= GPIO_ODR_ODR13;else GPIOC->ODR &= ~GPIO_ODR_ODR13;
	GPIOC->ODR |= GPIO_ODR_ODR12 ;

	if ((l&0x8)>0)GPIOC->ODR |= GPIO_ODR_ODR13;else GPIOC->ODR &= ~GPIO_ODR_ODR13;
	GPIOC->ODR |= GPIO_ODR_ODR12 ;

	if ((l&0x4)>0)GPIOC->ODR |= GPIO_ODR_ODR13;else GPIOC->ODR &= ~GPIO_ODR_ODR13;
	GPIOC->ODR |= GPIO_ODR_ODR12 ;

	if ((l&0x2)>0)GPIOC->ODR |= GPIO_ODR_ODR13;else GPIOC->ODR &= ~GPIO_ODR_ODR13;
	GPIOC->ODR |= GPIO_ODR_ODR12 ;
	
	if ((l&0x1)>0)GPIOC->ODR |= GPIO_ODR_ODR13;else GPIOC->ODR &= ~GPIO_ODR_ODR13;
	GPIOC->ODR |= GPIO_ODR_ODR12 ;


}

void loop (uint8_t N, uint8_t x,uint8_t y, uint8_t z){

	for (i=0;i<21;i++){
if ((a&0x80)>0)set_test();else reset_test();
if ((a&0x40)>0)set_test();else reset_test();
if ((a&0x20)>0)set_test();else reset_test();
if ((a&0x10)>0)set_test();else reset_test();
if ((a&0x08)>0)set_test();else reset_test();
if ((a&0x04)>0)set_test();else reset_test();
if ((a&0x02)>0)set_test();else reset_test();
if ((a&0x01)>0)set_test();else reset_test();
	
if ((b&0x80)>0)set_test();else reset_test();
if ((b&0x40)>0)set_test();else reset_test();	
if ((b&0x20)>0)set_test();else reset_test();
if ((b&0x10)>0)set_test();else reset_test();
if ((b&0x08)>0)set_test();else reset_test();
if ((b&0x04)>0)set_test();else reset_test();
if ((b&0x02)>0)set_test();else reset_test();
if ((b&0x01)>0)set_test();else reset_test();
	
if ((c&0x80)>0)set_test();else reset_test();
if ((c&0x40)>0)set_test();else reset_test();	
if ((c&0x20)>0)set_test();else reset_test();
if ((c&0x10)>0)set_test();else reset_test();
if ((c&0x08)>0)set_test();else reset_test();
if ((c&0x04)>0)set_test();else reset_test();
if ((c&0x02)>0)set_test();else reset_test();
last_bit();
}

Delay (4500);

	}

void set_test(void){
GPIOC->ODR |= GPIO_ODR_ODR13;
GPIOC->ODR |= GPIO_ODR_ODR12;
GPIOC->ODR |= GPIO_ODR_ODR12;
GPIOC->ODR |= GPIO_ODR_ODR12;
GPIOC->ODR |= GPIO_ODR_ODR12;
GPIOC->ODR |= GPIO_ODR_ODR12;
//GPIOC->ODR |= GPIO_ODR_ODR12;

GPIOC->ODR &= ~GPIO_ODR_ODR13;

}


void reset_test(void){
GPIOC->ODR |= GPIO_ODR_ODR13;
GPIOC->ODR |= GPIO_ODR_ODR12;
GPIOC->ODR |= GPIO_ODR_ODR12;
//GPIOC->ODR |= GPIO_ODR_ODR12;
GPIOC->ODR &= ~GPIO_ODR_ODR13;
GPIOC->ODR |= GPIO_ODR_ODR12;
GPIOC->ODR |= GPIO_ODR_ODR12;
GPIOC->ODR |= GPIO_ODR_ODR12;
}

void last_bit (void){
GPIOC->ODR |= GPIO_ODR_ODR13;
GPIOC->ODR |= GPIO_ODR_ODR12;
GPIOC->ODR |= GPIO_ODR_ODR12;
//GPIOC->ODR |= GPIO_ODR_ODR12;

GPIOC->ODR &= ~GPIO_ODR_ODR13;
GPIOC->ODR |= GPIO_ODR_ODR12;

}
