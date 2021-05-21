#include "Mini_Project_2.h"


int main(void)
{	SREG |= (1<<7);

	uint16 MAIN_resultSpeed;

	PWM_Timer0_Init(125); //generate duty cycle 50% to get half motor speed
	int1_init();
	MOTOR_configure();
	LCD_init();
	ADC_init(); /* initialize ADC driver */
	LCD_clearScreen(); /* clear LCD at the beginning */
	LCD_displayString("ADC Value = ");


    while(1)
    {
    	LCD_goToRowColumn(0,12);
    	MAIN_resultSpeed = ADC_readChannel(0); /* read channel zero where the potentiometer is connect */
    	LCD_intgerToString(MAIN_resultSpeed); /* display the ADC value on LCD screen */
    	MOTOR_setSpeed(MAIN_resultSpeed);

    }
}
ISR(INT1_vect){
	Motor_reverse();

	// he clears the flag automatically this is a useless line but for other modules
	//GIFR |= (1<<INTF0);
}
