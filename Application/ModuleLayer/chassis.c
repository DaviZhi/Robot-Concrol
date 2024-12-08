#include "chassis.h"

remote_t* remote;

void Chassis_Init(chassis_t* chassis)
{
	Servo_Init(&chassis->chassis_servo[BOTTOM]);
	Motor_Init(chassis->chassis_motor);
}

void Chassis_Speed_Solution(chassis_t* chassis)
{
	chassis->chassis_info->X_scale_factor = MAX_REV_CCR / (PSS_X_RIGHT_LIMIT - PSS_X_LEFT_LIMIT);
	chassis->chassis_info->Y_scale_factor = MAX_REV_CCR / (PSS_Y_DOWN_LIMIT - PSS_Y_UP_LIMIT);
	
	switch(remote->remote_info->key_info->MODE)
	{
		case RED_MODE:
		{
			if(remote->remote_info->joystick_info->PSS_LY <= PSS_Y_MID)
			{
				//position limit
				if(remote->remote_info->joystick_info->PSS_LY < PSS_Y_UP_LIMIT)
				{
					remote->remote_info->joystick_info->PSS_LY = PSS_Y_UP_LIMIT;
				}
				
				chassis->chassis_info->joystick_rev_CCR =	
				PSS_Y_MID - remote->remote_info->joystick_info->PSS_LY;
				
				Motor_Rev_Forward_Set(chassis->chassis_motor, chassis->chassis_info->joystick_rev_CCR);
			}
			else if(remote->remote_info->joystick_info->PSS_LY > PSS_Y_MID)
			{
				//position limit
				if(remote->remote_info->joystick_info->PSS_LY > PSS_Y_DOWN_LIMIT)
				{
					remote->remote_info->joystick_info->PSS_LY = PSS_Y_DOWN_LIMIT;
				}
				
				chassis->chassis_info->joystick_rev_CCR = 
				remote->remote_info->joystick_info->PSS_LY - PSS_Y_MID;
				Motor_Rev_Backward_Set(chassis->chassis_motor, chassis->chassis_info->joystick_rev_CCR);
			}
			
			break;
		}
		case GREEN_MODE:
		{
			//...
			
			break;
		}
		default:
		{
			break;
		}
	}
	
}
