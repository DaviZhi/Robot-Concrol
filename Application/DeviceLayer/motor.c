#include "motor.h"

/**@brief Initialize all four motors' revolution value to zero.
  *@param None
  *@retval None
  */
void Motor_Init(motor_t* motor)
{
	for(uint8_t i = 0; i < NUM_OF_WHEEL; i++)
	{
		motor[i].rev_CCR = 0;
	}
}

/**@brief Set forward rev value of each motor.
  *@param Motor structure ptr
	*@param CCR
  *@retval None
  */
void Motor_Rev_Forward_Set(motor_t* motor, uint16_t rev_ccr)
{
	for(uint8_t i = 0; i < NUM_OF_WHEEL; i++)
	{
		motor[i].rev_CCR = rev_ccr;
	}
	
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_3, motor[RB].rev_CCR);		//
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_1, motor[LB].rev_CCR);		//
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_1, motor[RF].rev_CCR);		//
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_3, motor[LF].rev_CCR);		//
}

/**@brief Set backward rev value of each motor.
  *@param Motor structure ptr
	*@param CCR
  *@retval None
  */
void Motor_Rev_Backward_Set(motor_t* motor, uint16_t rev_ccr)
{
	for(uint8_t i = 0; i < NUM_OF_WHEEL; i++)
	{
		motor[i].rev_CCR = rev_ccr;
	}
	
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_4, motor[RB].rev_CCR);		//
	__HAL_TIM_SET_COMPARE(&htim2, TIM_CHANNEL_2, motor[LB].rev_CCR);		//
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_2, motor[RF].rev_CCR);		//
	__HAL_TIM_SET_COMPARE(&htim1, TIM_CHANNEL_4, motor[LF].rev_CCR);		//
}
