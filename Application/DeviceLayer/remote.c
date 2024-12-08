#include "remote.h"

uint8_t Rx_Data[COMMUNI_CYCLE_LENGTH] = {0x00};
uint8_t Tx_Data[COMMUNI_CYCLE_LENGTH];

/**@brief Rewrite Rx Transfer completed callback function.
	*@param SPI_HandleTypeDef *hspi
  *@retval None
  */
void HAL_SPI_TxRxCpltCallback(SPI_HandleTypeDef *hspi)
{
	Remote_Communi_Start();
}

/**@brief Initialize key info of remote control.
	*@param Key info structure ptr
  *@retval None
  */
void RemoteKey_Info_Init(key_info_t* key_info)		//Map every key value on the remote control to the structure
{
//	HAL_SPI_Receive_DMA(&hspi1, Rx_Data, COMMUNI_CYCLE_LENGTH);
	
	key_info->MODE = Rx_Data[1];
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

/**@brief Initialize joystick info of remote control.
	*@param Joystick info structure ptr
  *@retval None
  */
void RemoteJoystick_Info_Init(joystick_info_t* joystick_info)
{
	joystick_info->PSS_RX = Rx_Data[5];
	joystick_info->PSS_RY = Rx_Data[6];
	joystick_info->PSS_LX = Rx_Data[7];
	joystick_info->PSS_LY = Rx_Data[8];
}

/**@brief Initialize remote control info.
	*@param remote control info structure ptr
  *@retval None
  */
void Remote_Info_Init(remote_info_t* remote_info)
{
	RemoteKey_Info_Init(remote_info->key_info);
	RemoteJoystick_Info_Init(remote_info->joystick_info);
}

/**@brief Initialize Tx_Data from micro.
	*@param None
  *@retval None
  */
void Remote_Receive_Info_Init(void)		//MOSI
{
	Tx_Data[0] = CMD_START;
	Tx_Data[1] = REQUEST_DATA;
	
	for(uint8_t i = 2; i < COMMUNI_CYCLE_LENGTH; i++)
	{
		Tx_Data[i] = 0x00;
	}
}

/**@brief Start communication between micro and remote control.
	*@param None
  *@retval None
  */
void Remote_Communi_Start(void)
{
	Remote_Receive_Info_Init();
	HAL_SPI_TransmitReceive_DMA(&hspi1, Tx_Data, Rx_Data, COMMUNI_CYCLE_LENGTH);
}
