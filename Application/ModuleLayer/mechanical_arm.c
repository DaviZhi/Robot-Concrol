#include "mechanical_arm.h"

//remote_t* remote;

void Arm_Init(arm_t* arm)
{
	Servo_Init(&arm->arm_servo[FRONT], FRONT);
	Servo_Init(&arm->arm_servo[LEFT], LEFT);
	Servo_Init(&arm->arm_servo[RIGHT], RIGHT);
}
