#include "motor.h"
	volatile uint8 Motor_reverse_flag = 1 ;


void PWM_Timer0_Init(unsigned char set_duty_cycle)
{

	TCNT0 = 0; //Set Timer Initial value

	OCR0  = set_duty_cycle; // Set Compare Value

	DDRB  |=  (1<<PB3); //set PB3/OC0 as output pin --> pin where the PWM signal is generated from MC.

	/* Configure timer control register
	 * 1. Fast PWM mode FOC0=0
	 * 2. Fast PWM Mode WGM01=1 & WGM00=1
	 * 3. Clear OC0 when match occurs (non inverted mode) COM00=0 & COM01=1
	 * 4. clock = F_CPU/8 CS00=0 CS01=1 CS02=0
	 */
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS01);
}
void MOTOR_setSpeed(uint8  speed){
	OCR0 = speed;
}
void MOTOR_configure(void){
	/* configure pin interrupt pin*/
	//SET_BIT (DDRD,PD3);
	/* Motor is stop at the beginning */
		PORTB &= 0xFC;
		/* configure pin PB0 and PB1 as output pins */
		DDRB |= 0x03;
		PORTB &= (~(1<<PB0));
		PORTB |= (1<<PB1);

}
void Motor_reverse(){
	if(Motor_reverse_flag){
		// Rotate the motor --> anti-clock wise
					PORTB |= (1<<PB0);
					PORTB &= (~(1<<PB1));
					Motor_reverse_flag = 0;
			}
	else{
		// Rotate the motor --> clock wise
					PORTB &= (~(1<<PB0));
					PORTB |= (1<<PB1);
					Motor_reverse_flag = 1;

	}
}
void int1_init(void){
	DDRD &= ~(1<<3);
	PORTD |= (1<<3);
	//rising Edge
	MCUCR |=(1<<ISC11) |(1<<ISC10);
	//MCUCR &= ~(1<<ISC10);

	//Module Enable
	GICR |= (1<<INT1);
}


