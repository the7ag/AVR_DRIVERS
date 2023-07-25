/*
 * TWI.c
 *
 * Created: 26/06/2023 06:35:24 م
 *  Author: The7ag
 */ 
#include "TWI.h"

void TWI_voidMasterInit(void)
{
	/* Set Prescaler Value */
	ClearBit(TWSR_Reg,1);
	ClearBit(TWSR_Reg,0);
	
	/* Set TWBR Value 200KHZ */
	TWBR_Reg = 12;
	
	/* Enable ACKnowledgemnet */
	SetBit(TWCR_Reg,6);
	
	/* Enable TWI */
	SetBit(TWCR_Reg,2);
}

void   TWI_u8SlaveInit(uint8_t Copy_u8SlaveAddress)
{
	//u8 Local_u8ErrorState = STD_TYPES_OK;
	/* Set Slave Adress IN TWAR REG */
	TWAR_Reg = Copy_u8SlaveAddress << 1;
	
	/* Enable ACKnowledgemnet */
	SetBit(TWCR_Reg,6);
	
	/* Enable TWI */
	SetBit(TWCR_Reg,2);
}

TWI_ErrorState   TWI_enuSendStartCondition(void)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Send Start Condition */
	SetBit(TWCR_Reg,5);
	/* Clear Flag */
	SetBit(TWCR_Reg,7);
	/* Wait for the Flag */
	while(!(ReadBit(TWCR_Reg,7)));
	/* Check ACKnowledgemnt => START CONDITION */
	if((TWSR_Reg & 0xF8) != 0x08 )
	{
		Local_enuErrorState = TWI_SC_ERROR;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuSendRepeatedStartCondition(void)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Send Start Condition */
	SetBit(TWCR_Reg,5);
	/* Clear Flag */
	SetBit(TWCR_Reg,7);
	/* Wait for the Flag */
	while(!(ReadBit(TWCR_Reg,7)));
	/* Check ACKnowledgemnt => START CONDITION */
	if((TWSR_Reg & 0xF8) != 0x10 )
	{
		Local_enuErrorState = TWI_RSC_ERROR;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuSendSlaveWithWrite(uint8_t Copy_u8SlaveAddress)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Set TWDR = SL Address + Write*/
	TWDR_Reg = Copy_u8SlaveAddress << 1;
	ClearBit(TWDR_Reg,0);
	/* Clear Start Condition */
	ClearBit(TWCR_Reg,5);
	/* Clear Flag */
	SetBit(TWCR_Reg,7);
	/* Wait for the Flag */
	while(!(ReadBit(TWCR_Reg,7)));
	/* Check ACKnowledgemnt => Slave Address + W */
	if((TWSR_Reg & 0xF8) != 0x18 )
	{
		Local_enuErrorState = TWI_SLA_W_ERROR;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuSendSlaveWithRead(uint8_t Copy_u8SlaveAddress)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Set TWDR = SL Address + Write*/
	TWDR_Reg = Copy_u8SlaveAddress << 1;
	SetBit(TWDR_Reg,0);
	/* Clear Start Condition */
	ClearBit(TWCR_Reg,5);
	/* Clear Flag */
	SetBit(TWCR_Reg,7);
	/* Wait for the Flag */
	while(!(ReadBit(TWCR_Reg,7)));
	/* Check ACKnowledgemnt => Slave Address + W */
	if((TWSR_Reg & 0xF8) != 0x40 )
	{
		Local_enuErrorState = TWI_SLA_R_ERROR;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuSendDataByte(uint8_t Copy_u8Data)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;
	/* Set TWDR = Data + Read*/
	TWDR_Reg = Copy_u8Data;
	/* Clear Flag */
	SetBit(TWCR_Reg,7);
	/* Wait for the Flag */
	while(!(ReadBit(TWCR_Reg,7)));
	/* Check ACKnowledgemnt => Slave Address + W */
	if((TWSR_Reg & 0xF8) != 0x28 )
	{
		Local_enuErrorState = TWI_DATA_W_ERROR;
	}
	return Local_enuErrorState;
}

TWI_ErrorState   TWI_enuReceiveDataByte(uint8_t * Copy_pu8ReceivedData)
{
	TWI_ErrorState Local_enuErrorState = TWI_OK;

	/* Check pointer */
	if(Copy_pu8ReceivedData != NULL)
	{

		/* Clear Flag */
		SetBit(TWCR_Reg,7);
		/* Wait for the Flag */
		while(!(ReadBit(TWCR_Reg,7)));
		/* Check ACKnowledgemnt => Slave Address + W */
		if((TWSR_Reg & 0xF8) != 0x50 )
		{
			Local_enuErrorState = TWI_DATA_R_ERROR;
		}
		else
		{
			/* Read Data */
			*Copy_pu8ReceivedData = TWDR_Reg;
		}
	}
	else
	{
		Local_enuErrorState = TWI_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}

void TWI_voidSendStopCondition(void)
{
	/* Send Stop Condition */
	SetBit(TWCR_Reg,4);
	
	/* Clear Flag */
	SetBit(TWCR_Reg,7);
}
/*uint8_t TWI_SlaveAddr = 0;
static volatile uint8_t TWI_Tx_Buffer[TWI_TX_BUFFER_SIZE_Byte] = {0};
static volatile uint8_t TWI_Tx_Buffer_Index = 0;
static volatile uint8_t TWI_Tx_Buffer_Size = 0;
static volatile uint8_t TWI_Rx_Buffer[TWI_RX_BUFFER_SIZE_Byte] = {0};
static uint8_t TWI_Rx_Buffer_Index = 0;
static uint8_t TWI_Rx_Buffer_Size = 0;
void TWI_Initialize(void)
{
	TWBR_Reg |= TWI_BITRATE_TWBR_VAL ;
	#if (TWI_PRESCALER_SELECT == TWI_PRESCALER_1)
	ClearBit(TWSR_Reg ,0 );
	ClearBit(TWSR_Reg ,1 );
	#elif(TWI_PRESCALER_SELECT == TWI_PRESCALER_4 )
	SetBit(TWSR_Reg ,0 );
	ClearBit(TWSR_Reg ,1 );
	#elif(TWI_PRESCALER_SELECT == TWI_PRESCALER_16 )
	ClearBit(TWSR_Reg ,0 );
	SetBit(TWSR_Reg ,1 );
	#elif(TWI_PRESCALER_SELECT == TWI_PRESCALER_64 )
	SetBit(TWSR_Reg ,0 );
	SetBit(TWSR_Reg ,1 );
	#endif
	TWI_AckEnable();
	//enable the TWI
	SetBit(TWCR_Reg,2);
}
void TWI_InterruptEnable(void)
{
	TWCR_Reg |= TWI__Interrupt_Enable ;
}
/* Disable TWI interrupt 
void TWI_InterruptDisable(void)
{
	ClearBit( TWCR_Reg , 0 );
}
/* Enable Acknowledgment 
void TWI_AckEnable(void)
{
	TWCR_Reg|=TWI_Enable_Acknowledge;
}
/* Disable Acknowledgment 
void TWI_AckDisable(void)
{
	ClearBit(TWCR_Reg , 6 );
}
/* Generate a start condition 
void TWI_GenerateStartCondition(void)
{
	TWCR_Reg|=TWI_START_Condition;
}
/* Clear start condition 
void TWI_ClearStartCondition(void)
{
	ClearBit(TWCR_Reg , 5 );
}
/* Generate a stop condition 
void TWI_GenerateStopCondition(void)
{
	TWCR_Reg|= TWI_STOP_Condition;
}
void TWI_SendData(uint8_t Data)
{
	TWDR_Reg=Data;
	SetBit(TWCR_Reg,7);
	while(!ReadBit(TWCR_Reg,7));
	if ((TWSR_Reg&0xf8)!=MasterRx_SlaveAddrReadbitTx_AckRx)
	{
		//error
	}
}
void TWI_ReadData(uint8_t* Data)
{
	SetBit(TWCR_Reg,7);
	while(!ReadBit(TWCR_Reg,7));
	if ((TWSR_Reg&0xf8)!=MasterRx_DataRx_AckTx)
	{
		//error
	}
	else
	{
		*Data=TWDR_Reg;
	}
}
/* Send a message 
uint8_t TWI_SendMsg(uint8_t SlaveAddress, uint8_t TxMsg[], uint8_t TxMsgSize){
	uint8_t i;
	uint8_t result;
	if(TWI_Tx_Buffer_Size == 0)
	{
		/* Copy slave address 
		TWI_SlaveAddr = (SlaveAddress << 1); // 0b01010101 --> 0b1010101(0)
		ClearBit(TWI_SlaveAddr,0); // 0b1010101(0) For Write
		for(i=0; i<TxMsgSize; i++)
		{
			TWI_Tx_Buffer[i] = TxMsg[i];
		}
		TWI_Tx_Buffer_Size = TxMsgSize;
		TWI_InterruptEnable();
		TWI_AckEnable();
		TWI_GenerateStartCondition();
		result = 1;
	}
	else
	{
		/* Driver busy send another data 
		result = 0;
	}
	return result;
}
/* Start reading operation 
void TWI_StartReading(uint8_t SlaveAddress, uint8_t RxMsgSize)
{
	if (RxMsgSize < TWI_RX_BUFFER_SIZE_Byte)
	{
		TWI_SlaveAddr = (SlaveAddress <<1);
		SetBit(TWI_SlaveAddr, 0); // 0b1010101(1) //for read opration
		TWI_Rx_Buffer_Size = RxMsgSize;
		TWI_InterruptEnable();
		TWI_AckEnable();
		TWI_GenerateStartCondition();
	}
}
/* Get last received message 
uint8_t TWI_GetLastRxMsg(uint8_t RxMsg[], uint8_t* RxMsgSize)
{
	uint8_t Index;
	/* Provide the length of the received message 
	*RxMsgSize = TWI_Rx_Buffer_Size;
	for(Index=0; Index<TWI_Rx_Buffer_Size; Index++)
	{
		/* Copy message from local Rx buffer back to user 
		RxMsg[Index]= TWI_Rx_Buffer[Index];
	}
	return 1;
}
void __vector_19(void) __attribute__((signal,used));
void __vector_19(void)
{
	TWI_Status_T CurrentStatus = (TWSR_Reg & 0b11111000);
	/* Interrupt sources handling 
	switch(CurrentStatus)
	{
		case Master_Start_Condition:
		case Master_RepeatedStart_Condition:
		TWDR_Reg = TWI_SlaveAddr;
		ClearBit(TWCR_Reg , 5);
		break;
		case MasterTx_SlaveAddrWritebitTx_AckRx:
		case MasterTx_SlaveAddrWritebitTx_NotAckRx:
		TWDR_Reg = TWI_Tx_Buffer[TWI_Tx_Buffer_Index];
		TWI_Tx_Buffer_Index++;
		break;
		case MasterTx_DataTx_AckRx:
		case MasterTx_DataTx_NotAckRx:
		if (TWI_Tx_Buffer_Index < TWI_Tx_Buffer_Size)
		{
			TWDR_Reg = TWI_Tx_Buffer[TWI_Tx_Buffer_Index];
			TWI_Tx_Buffer_Index++;
		}
		else
		{
			TWI_Tx_Buffer_Index = 0;
			TWI_Tx_Buffer_Size = 0;
			TWI_GenerateStopCondition();
		}
		break;
		case MasterRx_SlaveAddrReadbitTx_AckRx:
		case MasterRx_SlaveAddrReadbitTx_NotAckRx:
		break;
		case MasterRx_DataRx_AckTx:
		if(TWI_Rx_Buffer_Index < TWI_Rx_Buffer_Size)
		{
			TWI_Rx_Buffer[TWI_Rx_Buffer_Index] =TWDR_Reg;
			TWI_Rx_Buffer_Index++;
		}
		else
		{
			TWI_AckDisable();
		}
		break;
		case MasterRx_DataRx_NotAckTx:
		TWI_GenerateStopCondition();
		break;
		default:
		break;
	}
	/* Manually clear interrupt flag by writing 1 to it 
	SetBit(TWCR_Reg, 7);
}*/