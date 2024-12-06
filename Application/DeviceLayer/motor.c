#include "motor.h"

motor_t* motor;

/**@brief Initialize all four motors.
  *@param None
  *@retval None
  */
void Motor_Init(void)
{
	for(uint8_t i = 0; i < NUM_OF_WHEEL; i++)
	{
		motor[i].rev_CCR = 0;
	}
}
