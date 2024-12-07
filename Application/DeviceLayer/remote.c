#include "remote.h"

uint8_t Rx_Data[COMMUNI_CYCLE_LENGTH];

/**@brief Rewrite Rx Transfer completed callback function.
	*@param SPI_HandleTypeDef *hspi
  *@retval None
  */
void HAL_SPI_RxCpltCallback(SPI_HandleTypeDef *hspi)
{
	
//	HAL_SPI_Receive_DMA(&hspi1, Rx_Data, COMMUNI_CYCLE_LENGTH);		// need receive data from remote control continually
}

/**@brief Initialize key of remote control.
	*@param None
  *@retval None
  */
void RemoteKey_Init(key_info_t* key_info)		//将PS2上面所有的键值映射到遥控器按键结构体中
{
//	HAL_SPI_Receive_DMA(&hspi1, Rx_Data, COMMUNI_CYCLE_LENGTH);
	
	key_info->LEFT = (Rx_Data[3] >> 7) & 0x01;
	key_info->DOWN = (Rx_Data[3] >> 6) & 0x01;
	key_info->RIGHT = (Rx_Data[3] >> 5) & 0x01;
	key_info->UP = (Rx_Data[3] >> 4) & 0x01;
	key_info->START = (Rx_Data[3] >> 3) & 0x01;
	key_info->R3 = (Rx_Data[3] >> 2) & 0x01;
	key_info->L3 = (Rx_Data[3] >> 1) & 0x01;
	key_info->SELECT = Rx_Data[3] & 0x01;
	key_info->SQUARE = (Rx_Data[4] >> 7) & 0x01;
	key_info->FORK = (Rx_Data[4] >> 6) & 0x01;
	key_info->CYCLE = (Rx_Data[4] >> 5) & 0x01;
	key_info->TRIANGLE = (Rx_Data[4] >> 4) & 0x01;
	key_info->R1 = (Rx_Data[4] >> 3) & 0x01;
	key_info->L1 = (Rx_Data[4] >> 2) & 0x01;
	key_info->R2 = (Rx_Data[4] >> 1) & 0x01;
	key_info->L2 = Rx_Data[4] & 0x01;
}

void RemoteJoystick_Init(joystick_info_t* joystick_info)
{
	
}
