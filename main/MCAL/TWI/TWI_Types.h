/*
 * TWI_Types.h
 *
 * Created: 26/06/2023 06:35:01 م
 *  Author: The7ag
 */ 


#ifndef TWI_TYPES_H_
#define TWI_TYPES_H_

typedef enum
{
	TWI_OK = 1,
	TWI_SC_ERROR,
	TWI_RSC_ERROR,
	TWI_SLA_W_ERROR,
	TWI_SLA_R_ERROR,
	TWI_DATA_W_ERROR,
	TWI_NULL_POINTER,
	TWI_DATA_R_ERROR
}TWI_ErrorState;
/*
/*	*************	TWCR	*********************************
#define TWI_CLEAR_FLAG  			0b10000000 //  bit 7
#define TWI_Enable_Acknowledge		0b01000000 //  bit 6
#define TWI_START_Condition			0b00100000 //  bit 5
#define TWI_STOP_Condition			0b00010000 //  bit 4
//#define TWI_
//#define TWI_Enable_TWI				0b00000100 // bit 2
#define TWI__Interrupt_Enable		0b00000001 // bit 0
/*-------------------------------------------------------------------------
/*	*************	TWAR	*********************************
#define TWI_General_Call_ENABLE      0b00000001 // bit 0
#define TWI_General_Call_DISABLE     0b00000000 // bit 0
/*	*************	TWSR	*********************************
typedef enum
{
	BusError=0,
	Master_Start_Condition = 0x08,
	Master_RepeatedStart_Condition = 0x10,
	MasterTx_SlaveAddrWritebitTx_AckRx = 0x18,
	MasterTx_SlaveAddrWritebitTx_NotAckRx =0x20,
	MasterTx_DataTx_AckRx=0x28,
	MasterTx_DataTx_NotAckRx=0x30,
	Master_ArbitrationLost=0x38,
	MasterRx_SlaveAddrReadbitTx_AckRx = 0x40,
	MasterRx_SlaveAddrReadbitTx_NotAckRx =0x48,
	MasterRx_DataRx_AckTx=0x50,
	MasterRx_DataRx_NotAckTx=0x58,
	SlaveRx_SlaveAddrReadbitRx_AckTx = 0x60,
	SlaveRx_ArbitrationLost_SlaveAddrWritebitRx_AckTx = 0x68,
	SlaveRx_BroadcastAddrRx_AckTx = 0x70,
	SlaveRx_ArbitrationLost_BroadcastAddrRx_AckTx = 0x78,
	SlaveRx_PrevSlaveAddrWritebitRx_AckTx = 0x80,
	SlaveRx_PrevArbitrationLost_SlaveAddrWritebitRxx_AckTx = 0x88,
	SlaveRx_PrevBroadcastAddrRx_AckTx = 0x90,
	SlaveRx_PrevArbitrationLost_BroadcastAddrRx_AckTx = 0x98,
	SlaveRx_StopCondition_Or_RepeatedStartCondition = 0xA0,
	SlaveTx_SlaveAddrReadbitRx_AckTx = 0xA8,
	SlaveTx_ArbitrationLost_SlaveAddrReadbitRx_AckTx = 0xB0,
	SlaveTx_DataTx_AckRx = 0xB8,
	SlaveTx_DataTx_NotAckRx = 0xC0,
	SlaveTx_LastDataTx_AckRx = 0xC8,
	NoRelevantState = 0xF8
}TWI_Status_T;
 #define  TWI_PRESCALER_1 0
 #define  TWI_PRESCALER_4 1
 #define  TWI_PRESCALER_16 2
 #define  TWI_PRESCALER_64 3
 */
#endif /* TWI_TYPES_H_ */