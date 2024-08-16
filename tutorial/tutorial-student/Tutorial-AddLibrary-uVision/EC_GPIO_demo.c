/*----------------------------------------------------------------\
@ Embedded Controller by Young-Keun Kim - Handong Global University
Author           : SSS LAB
Created          : 05-03-2021
Modified         : 10-10-2023
Language/ver     : C++ in Keil uVision

Description      : Distributed to Students for TU_Adding_Library_in_uVision
/----------------------------------------------------------------*/


#include "ecGPIO_simpleTU.h"

#define LED_PIN 	5
#define BUTTON_PIN 13

void setup(void);

int main(void) {
	// Initialiization
	setup();

	// Inifinite Loop 
	while (1) {
		if (GPIO_read(GPIOC, BUTTON_PIN) == 0)		GPIO_write(GPIOA, LED_PIN, HIGH);
		else 										GPIO_write(GPIOA, LED_PIN, LOW);
	}
}


// Initialiization 
void setup(void)
{
	RCC_HSI_init();
	GPIO_init(GPIOC, BUTTON_PIN, INPUT);  // calls RCC_GPIOC_enable()
	GPIO_init(GPIOA, LED_PIN, OUTPUT);    // calls RCC_GPIOA_enable()
}