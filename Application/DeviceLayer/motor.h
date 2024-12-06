#ifndef __MOTOR_H
#define __MOTOR_H

#include "stm32f1xx_hal.h"

#define MAX_REV_CCR		1000

typedef enum
{
	RF,		//右前轮
	LF,		//左前轮
	LB,		//左后轮
	RB,		//右后轮
	NUM_OF_WHEEL
	
}motor_signal_e;

typedef struct
{
	uint16_t rev_CCR;		//转速(实际上是CCR的值)
	
}motor_t;

void Motor_Init(void);

#endif
