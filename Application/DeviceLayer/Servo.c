#include "Servo.h"

servo_t* servo;

/**@brief Initialize all four servos to middle.
	*@param None
  *@retval None
  */
void Servo_Init(void)
{
	servo[FRONT].degr_CCR = FRONT_SERVO_MIDDLE_CCR;
	servo[LEFT].degr_CCR = LEFT_SERVO_MIDDLE_CCR;
	servo[RIGHT].degr_CCR = RIGHT_SERVO_MIDDLE_CCR;
	servo[BOTTOM].degr_CCR = BOTTOM_SERVO_MIDDLE_CCR;
}
