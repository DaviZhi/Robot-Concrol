#ifndef __SERVO_H
#define __SERVO_H

#include "stm32f1xx_hal.h"
#include "tim.h"

#define BOTTOM_SERVO_MIDDLE_CCR							142
#define BOTTOM_SERVO_LEFT_LIMIT_CCR					112
#define BOTTOM_SERVO_RIGHT_LIMIT_CCR				172

#define FRONT_SERVO_MIDDLE_CCR							150
#define FRONT_SERVO_MAX_LIMIT_CCR						200
#define FRONT_SERVO_MIN_LIMIT_CCR						118

#define LEFT_SERVO_MIDDLE_CCR								150
#define LEFT_SERVO_RISE_LIMIT_CCR						215
#define LEFT_SERVO_DESCEND_LIMIT_CCR				75

#define RIGHT_SERVO_MIDDLE_CCR							170
#define RIGHT_SERVO_EXTEND_LIMIT_CCR				230
#define RIGHT_SERVO_DRAWBACK_LIMIT_CCR			140

typedef enum
{
	FRONT,
	LEFT,
	RIGHT,
	BOTTOM,
	NUM_OF_SERVO
}servo_signal_e;

typedef struct
{
	uint16_t degr_CCR;
	
}servo_t;

void Servo_Init(servo_t* servo);
void Servo_FRONT_Degr_Set(servo_t* servo, uint16_t degr_ccr);
void Servo_BOTTOM_Degr_Set(servo_t* servo, uint16_t degr_ccr);
void Servo_LEFT_Degr_Set(servo_t* servo, uint16_t degr_ccr);
void Servo_RIGHT_Degr_Set(servo_t* servo, uint16_t degr_ccr);
	
#endif
