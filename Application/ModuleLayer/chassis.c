#include "chassis.h"

//remote_t* remote;

void Chassis_Init(chassis_t* chassis)
{
	Servo_Init(&chassis->chassis_servo[BOTTOM], BOTTOM);
	Motor_Init(chassis->chassis_motor);
}

void Chassis_RedMode_Solution(chassis_t* chassis, remote_t* remote)
{
	RemoteJoystick_Info_Init(remote->remote_info->joystick_info);
	
	chassis->chassis_info->X_scale_factor = 
	MAX_DEGR_CCR / (PSS_X_RIGHT_LIMIT - PSS_X_LEFT_LIMIT);		//1
	
//	chassis->chassis_info->Y_scale_factor = 
//	MAX_REV_CCR / (PSS_Y_DOWN_LIMIT - PSS_Y_MID);		
			
	if(remote->remote_info->joystick_info->PSS_LY <= PSS_Y_MID)
	{
		//position limit
		if(remote->remote_info->joystick_info->PSS_LY < PSS_Y_UP_LIMIT)
		{
			remote->remote_info->joystick_info->PSS_LY = PSS_Y_UP_LIMIT;
		}
		
		chassis->chassis_info->Y_scale_factor = 
		MAX_REV_CCR / (PSS_Y_MID - PSS_Y_UP_LIMIT);		//8
		
		chassis->chassis_info->joystick_rev_CCR =	
		chassis->chassis_info->Y_scale_factor * (PSS_Y_MID - remote->remote_info->joystick_info->PSS_LY);
		
		Motor_Rev_Forward_Set(chassis->chassis_motor, chassis->chassis_info->joystick_rev_CCR);
	}
	else if(remote->remote_info->joystick_info->PSS_LY > PSS_Y_MID)
	{
		//position limit
		if(remote->remote_info->joystick_info->PSS_LY > PSS_Y_DOWN_LIMIT)
		{
			remote->remote_info->joystick_info->PSS_LY = PSS_Y_DOWN_LIMIT;
		}
		
		chassis->chassis_info->Y_scale_factor = 
		MAX_REV_CCR / (PSS_Y_DOWN_LIMIT - PSS_Y_MID);		//8
		
		chassis->chassis_info->joystick_rev_CCR = 
		chassis->chassis_info->Y_scale_factor * (remote->remote_info->joystick_info->PSS_LY - PSS_Y_MID);
		
		Motor_Rev_Backward_Set(chassis->chassis_motor, chassis->chassis_info->joystick_rev_CCR);
	}
	
	/**/
	if(remote->remote_info->joystick_info->PSS_RX < BOTTOM_SERVO_LEFT_LIMIT_CCR)
	{
		remote->remote_info->joystick_info->PSS_RX = BOTTOM_SERVO_LEFT_LIMIT_CCR;
	}
	if(remote->remote_info->joystick_info->PSS_RX > BOTTOM_SERVO_RIGHT_LIMIT_CCR)
	{
		remote->remote_info->joystick_info->PSS_RX = BOTTOM_SERVO_RIGHT_LIMIT_CCR;
	}
	chassis->chassis_servo->degr_CCR = remote->remote_info->joystick_info->PSS_RX;		//这段解算有问题，需检查
}

void Chassis_GreenMode_Solution(chassis_t* chassis, remote_t* remote)
{
	RemoteKey_Info_Init(remote->remote_info->key_info);

	chassis->chassis_info->key_rev_CCR = KEY_REV_CCR;			//绿灯模式固定转速

	if(remote->remote_info->key_info->UP == 0 && remote->remote_info->key_info->DOWN == 1)		//若前进键按下，则电机正转
	{
		Motor_Rev_Forward_Set(chassis->chassis_motor, chassis->chassis_info->key_rev_CCR);
	}
	else if(remote->remote_info->key_info->UP == 1 && remote->remote_info->key_info->DOWN == 0)		//若后退键按下，则电机反转
	{
		Motor_Rev_Backward_Set(chassis->chassis_motor, chassis->chassis_info->key_rev_CCR);
	}
	
	if(remote->remote_info->key_info->SQUARE == 0 && remote->remote_info->key_info->CYCLE == 1)
	{
		chassis->chassis_servo->degr_CCR = BOTTOM_SERVO_LEFT_LIMIT_CCR;
		Servo_BOTTOM_Degr_Set(&chassis->chassis_servo[BOTTOM], chassis->chassis_servo->degr_CCR);
	}
	else if(remote->remote_info->key_info->SQUARE == 1 && remote->remote_info->key_info->CYCLE == 0)
	{
		chassis->chassis_servo->degr_CCR = BOTTOM_SERVO_RIGHT_LIMIT_CCR;
		Servo_BOTTOM_Degr_Set(&chassis->chassis_servo[BOTTOM], chassis->chassis_servo->degr_CCR);
	}
}