/*
 * motor.h
 *
 *  Created on: Feb 20, 2021
 *      Author: Mohamed Essam
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include <avr/io.h>
#include "std_types.h"
#include "common_macros.h"
#include "micro_config.h"

void PWM_Timer0_Init(unsigned char set_duty_cycle);
void MOTOR_setSpeed(uint8  speed);
void MOTOR_configure(void);
void Motor_reverse();
void int1_init(void);

#endif /* MOTOR_H_ */
