#ifndef __REMOTE_H
#define __REMOTE_H

#include "stm32f1xx_hal.h"
#include "spi.h"

/******************************Private Define**********************************************/

#define 		PSS_X_LEFT_LIMIT				0x03
#define 		PSS_X_RIGHT_LIMIT				0xFD
#define 		PSS_Y_UP_LIMIT					0x02
#define 		PSS_Y_DOWN_LIMIT				0xFC
#define 		PSS_X_MID	   						0X80
#define 		PSS_Y_MID     					0X7F						

/**@brief Mode switch of remote control.
  */
#define			RED_MODE								0x73
#define			GREEN_MODE							0x41

#define			CMD_START								0x01
#define			REQUEST_DATA						0x42
#define			SEND_START_FLAG					0x5A
#define			COMMUNI_CYCLE_LENGTH		0x09

/******************************Private Structure******************************************/

/**@brief Map every key on remote control.
  */
typedef struct
{
	uint8_t SELECT;
	uint8_t L3;			//press left joystick
	uint8_t R3;			//press right joystick
	uint8_t START;
	uint8_t UP;
	uint8_t RIGHT;
	uint8_t DOWN;
	uint8_t LEFT;
	uint8_t L2;
	uint8_t R2;
	uint8_t L1;
	uint8_t R1;
	uint8_t CYCLE;
	uint8_t FORK;
	uint8_t SQUARE;
	uint8_t TRIANGLE;
	uint8_t MODE;
	
}key_info_t;

/**@brief Map joystick value on remote control.
  */
typedef struct
{
	uint8_t PSS_RX;
	uint8_t PSS_RY;
	uint8_t PSS_LX;
	uint8_t PSS_LY;
	
}joystick_info_t;

/**@brief Set of all elements' info on remote control.
  */
typedef struct
{
	joystick_info_t* joystick_info;
	key_info_t* key_info;
	
}remote_info_t;

typedef struct
{
	remote_info_t* remote_info;
//	uint8_t cmd_start;					//micro sends 0x01 for starting a communication cycle
//	uint8_t receive_request;		//micro sends 0x42 requesting data
//	uint8_t send_flag;					//remote control sends 0x5A to micro for confirmation before sending next byte of data
	
}remote_t;

void RemoteKey_Info_Init(key_info_t* key_info);
void RemoteJoystick_Info_Init(joystick_info_t* joystick_info);
void Remote_Info_Init(remote_info_t* remote_info);
void Remote_Receive_Info_Init(void);		//MOSI
void Remote_Communi_Start(void);

#endif
