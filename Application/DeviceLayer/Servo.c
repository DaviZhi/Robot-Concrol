#include "Servo.h"

/**@brief Initialize all four servos to middle.
	*@param None
  *@retval None
  */
void Servo_Init(servo_t* servo)
{
	servo[FRONT].degr_CCR = FRONT_SERVO_MIDDLE_CCR;
	servo[LEFT].degr_CCR = LEFT_SERVO_MIDDLE_CCR;
	servo[RIGHT].degr_CCR = RIGHT_SERVO_MIDDLE_CCR;
	servo[BOTTOM].degr_CCR = BOTTOM_SERVO_MIDDLE_CCR;
}

void Servo_FRONT_Degr_Set(servo_t* servo, uint16_t degr_ccr)
{
	servo[FRONT].degr_CCR = degr_ccr;
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_1, servo[FRONT].degr_CCR);
}

void Servo_BOTTOM_Degr_Set(servo_t* servo, uint16_t degr_ccr)
{
	servo[BOTTOM].degr_CCR = degr_ccr;
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_4, servo[BOTTOM].degr_CCR);
}

void Servo_LEFT_Degr_Set(servo_t* servo, uint16_t degr_ccr)
{
	servo[LEFT].degr_CCR = degr_ccr;
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_2, servo[LEFT].degr_CCR);
}

void Servo_RIGHT_Degr_Set(servo_t* servo, uint16_t degr_ccr)
{
	servo[RIGHT].degr_CCR = degr_ccr;
	__HAL_TIM_SET_COMPARE(&htim3, TIM_CHANNEL_3, servo[RIGHT].degr_CCR);
}
