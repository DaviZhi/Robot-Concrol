#ifndef __MOTOR_H
#define __MOTOR_H

#include "stm32f1xx_hal.h"

#define MAX_REV_CCR		1000

typedef enum
{
	RF,		//��ǰ��
	LF,		//��ǰ��
	LB,		//�����
	RB,		//�Һ���
	NUM_OF_WHEEL
	
}motor_signal_e;

typedef struct
{
	uint16_t rev_CCR;		//ת��(ʵ������CCR��ֵ)
	
}motor_t;

void Motor_Init(void);

#endif
