

#include "stm32f3xx.h"                  // Device header



int main(void)
void TIM2_IRQHandler();
int counter;
 DACValue;
	

{
	// Enable clock on GPIO port E
	RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
	
	// Enable timer
	RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->CR1 |= TIM_CR1_CEN; //enable timer
	TIM2->PSC = 79; //prescalor set
	TIM2->ARR = 9999; //Auto reset tegister set
	
	//DAC setup
	RCC->APB1ENR |= RCC_APB1ENR_DAC1EN; //enable APB1 clock connection
	GPIOA->MODER |=	0x00000300; //analogue mode pin PA.4 set
	DAC1->CR |= DAC_CR_BOFF1; //buffer disabled
	DAC1->CR |= DAC_CR_EN1; //enable DAC peripheral
	
	
	// GPIOE is a structure defined in stm32f303xc.h file
	// Define settings for each output pin using GPIOE structure
	GPIOE->MODER |= 0x55550000; // 
	GPIOE->OTYPER &= ~(0x00000100); // 
	GPIOE->PUPDR &= ~(0x00030000); // 
	
	
	
	while (1)
  {
	/*	DACValue = GPIOE->BSRRL = (counter << 8); //shifts bits left by 8 spots, auto converts from decimal to hex
		DAC1->DHR12R1 = DACVALUE ; */

}

void TIM2_IRQHandler()
{
DACValue = GPIOE->BSRRL = (counter << 8); //shifts bits left by 8 spots, auto converts from decimal to hex
DAC1->DHR12R1 = DACVALUE ;
	
	if ((TIM2->SR & TIM_SR_UIF) !=0) // Check interrupt source is from the �Update� interrupt flag
	{	
	GPIOE->BSRRH = (counter << 8);
	
	counter++;
	}
	TIM2->SR &= ~TIM_SR_UIF; // Reset �Update� interrupt flag in the SR register
{