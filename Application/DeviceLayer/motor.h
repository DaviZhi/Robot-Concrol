#ifndef __MOTOR_H
#define __MOTOR_H

#include "stm32f1xx_hal.h"
#include "tim.h"

#define MAX_REV_CCR		1000

/*Position of each motor*/
typedef enum
{
	RF,		//right front
	LF,		//left front
	LB,		//left behind
	RB,		//right behind
	NUM_OF_WHEEL
	
}motor_signal_e;

typedef struct
{
	uint16_t rev_CCR;		//revolution speed(actual value of CCR)
	
}motor_t;

void Motor_Init(motor_t* motor);
void Motor_Rev_Forward_Set(motor_t* motor, uint16_t rev_ccr);
void Motor_Rev_Backward_Set(motor_t* motor, uint16_t rev_ccr);

#endif
