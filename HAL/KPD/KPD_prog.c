#include "STD_TYPES.h"
#include "ERRORTYPE.h"
#include "DIO_interface.h"

#include "KPD_interface.h"
#include "KPD_prv.h"
#include "KPD_cfg.h"

uint8 KPD_u8GetPressedKey(void)
{
	uint8 Local_u8ColIdx,Local_u8RowIdx,Local_u8PinState,Local_u8PressedKey=KPD_u8NO_PRESSED_KEY_VAL;
	uint8 Local_au8_ColArr[COL_NUM] = {KPD_u8COL0_PIN,KPD_u8COL1_PIN,KPD_u8COL2_PIN,KPD_u8COL3_PIN};
	uint8 Local_au8_RowArr[ROW_NUM] = {KPD_u8ROW0_PIN,KPD_u8ROW1_PIN,KPD_u8ROW2_PIN,KPD_u8ROW3_PIN};
	/*creating array having the sw values as we only put values of this array in cfg*/
	uint8 Local_au8KPDArr[ROW_NUM][COL_NUM] = KPD_au8_BUTTON_ARR ;

	/*Activate the column Pin*/
	for(Local_u8ColIdx=0u;  Local_u8ColIdx<COL_NUM ; Local_u8ColIdx++ )
	{
		/*Activate the current column*/
		DIO_u8SetPinValue(KPD_u8COL_PORT,Local_au8_ColArr[Local_u8ColIdx],DIO_u8PIN_LOW);

		/*Read ROW pins*/
		for(Local_u8RowIdx=0u;  Local_u8RowIdx<ROW_NUM ; Local_u8RowIdx++ )
			{
					/*read the current Row*/
				DIO_u8ReadPinValue(KPD_u8ROW_PORT,Local_au8_RowArr[Local_u8RowIdx], &Local_u8PinState);

				if(Local_u8PinState== DIO_u8PIN_LOW)
				{
					Local_u8PressedKey = Local_au8KPDArr[Local_u8RowIdx][Local_u8ColIdx];


					/*POLLING WITH BLOCKING(WAITING) Untu=il the key is released*/
					while(Local_u8PinState == DIO_u8PIN_LOW)
					{
						DIO_u8ReadPinValue(KPD_u8ROW_PORT,Local_au8_RowArr[Local_u8RowIdx], &Local_u8PinState);
					}

					return Local_u8PressedKey;
				}
			}
		/*deActivate the current column*/
		DIO_u8SetPinValue(KPD_u8COL_PORT,Local_au8_ColArr[Local_u8ColIdx],DIO_u8PIN_HIGH);
	}
	return Local_u8PressedKey;

}
