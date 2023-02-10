/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright (c) Nuvoton Technology Corp. All rights reserved.                                             */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/*

	AMIC A7125 Driver

 */

#ifndef _DRVRF_AMIC_A7125_H_
#define _DRVRF_AMIC_A7125_H_

//#include "Platform.h"
#include "System/SysInfra.h"

#define RF_DEFAULT_ID		0x51688888			// Fix to 4 bytes and define as you wish.

#define RF_DEFAULT_CHANNEL	94					// Define the default channel.
												// f = 2400MHz + 0.5MHz * n

#define RF_MAX_FIFO_SIZE	64					// Maximum FIFO size.
#define RF_MAX_PACKET_SIZE	RF_MAX_FIFO_SIZE

//#define RF_ENABLE_EXT_PA						// Enable control of external PA
#define RF_4dB_MODULE                           // Enable the setting for 4dB module

							// PA switch control, only valid if enable external PA.
							// Both switches can't be turn on at the same time.
							// TX_SW => GPIOA4, RX_SW => GPIOA5
//#define RF_TXSW_ON()		outp32(GPIOA_DOUT, inp32(GPIOA_DOUT) & (~(1 << 4)) |   (1 << 5))
//#define RF_RXSW_ON()		outp32(GPIOA_DOUT, inp32(GPIOA_DOUT) &   (1 << 4)  | (~(1 << 5)))
//#define RF_TRXSW_OFF()		outp32(GPIOA_DOUT, inp32(GPIOA_DOUT) |  ((1 << 4)  |   (1 << 5)))

/*** End of Control Definitions ***/
										
/* Error codes */
#define ERR_AMIC_INIT_FAIL			-1
#define ERR_AMIC_MASTER_TIMEOUT		-2
#define ERR_AMIC_CALIBRATION_FAIL	-3

/* AMIC A7125 Register Definitions */

#define RF_AMIC_REG_MODE			0x00
#define RF_AMIC_REG_MODE_CONTROL	0x01
#define RF_AMIC_REG_CALIRATION		0x02
#define RF_AMIC_REG_FIFO1			0x03
#define RF_AMIC_REG_FIFO2			0x04
#define RF_AMIC_REG_FIFO_DATA		0x05
#define RF_AMIC_REG_ID_DATA			0x06
#define RF_AMIC_REG_RC_OSC1			0x07
#define RF_AMIC_REG_RC_OSC2			0x08
#define RF_AMIC_REG_RC_OSC3			0x09
#define RF_AMIC_REG_CKO_CONTROL		0x0A
#define RF_AMIC_REG_GPIO1			0x0B
#define RF_AMIC_REG_GPIO2			0x0C
#define RF_AMIC_REG_DATA_RATE_CLOCK	0x0D

#define RF_AMIC_REG_PLL1			0x0E
#define RF_AMIC_REG_PLL2			0x0F
#define RF_AMIC_REG_PLL3			0x10
#define RF_AMIC_REG_PLL4			0x11
#define RF_AMIC_REG_PLL5			0x12

#define RF_AMIC_REG_CHANNEL_GROUP1	0x13
#define RF_AMIC_REG_CHANNEL_GROUP2	0x14
#define RF_AMIC_REG_TX1				0x15
#define RF_AMIC_REG_TX2				0x16
#define RF_AMIC_REG_DELAY1			0x17
#define RF_AMIC_REG_DELAY2			0x18

#define RF_AMIC_REG_RX				0x19
#define RF_AMIC_REG_RX_GAIN1		0x1A
#define RF_AMIC_REG_RX_GAIN2		0x1B
#define RF_AMIC_REG_RX_GAIN3		0x1C
#define RF_AMIC_REG_RX_GAIN4		0x1D

#define RF_AMIC_REG_RSSI			0x1E
#define RF_AMIC_REG_ADC_CONTROL		0x1F

#define RF_AMIC_REG_CODE1			0x20
#define RF_AMIC_REG_CODE2			0x21
#define RF_AMIC_REG_CODE3			0x22

#define RF_AMIC_REG_IF_CALIBRATION1	0x23
#define RF_AMIC_REG_IF_CALIBRATION2	0x24
#define RF_AMIC_REG_VCO_CURR_CALI	0x25
#define RF_AMIC_REG_VCO_BANK_CALI1	0x26
#define RF_AMIC_REG_VCO_BANK_CALI2	0x27
#define RF_AMIC_REG_VCO_DEVI_CALI1	0x28
#define RF_AMIC_REG_VCO_DEVI_CALI2	0x29
#define RF_AMIC_REG_VCO_DEVI_CALI3	0x2A

#define RF_AMIC_REG_VCO_MOD_DELAY	0x2B
#define RF_AMIC_REG_BATTERY_DETECT	0x2C
#define RF_AMIC_REG_TX_TEST			0x2D
#define RF_AMIC_REG_RX_DEM_TEST1	0x2E
#define RF_AMIC_REG_RX_DEM_TEST2	0x2F

#define RF_AMIC_REG_CHARGE_PUMP1	0x30
#define RF_AMIC_REG_CHARGE_PUMP2	0x31

#define RF_AMIC_REG_CRYSTAL			0x32
#define RF_AMIC_REG_PLL_TEST		0x33
#define RF_AMIC_REG_VCO_TEST		0x34
#define RF_AMIC_REG_ANALOG_TEST		0x35
#define RF_AMIC_REG_IFAT			0x36
#define RF_AMIC_REG_CHANNEL_SELECT	0x37
#define RF_AMIC_REG_VRB				0x38

/* AMIC A7125 Strobe Commands to control module state */

#define RF_AMIC_CMD_SLEEP			0x80
#define RF_AMIC_CMD_IDLE			0x90
#define RF_AMIC_CMD_STANDBY			0xA0
#define RF_AMIC_CMD_PLL				0xB0
#define RF_AMIC_CMD_RX				0xC0
#define RF_AMIC_CMD_TX				0xD0
#define RF_AMIC_CMD_TX_FIFO_RESET	0xE0
#define RF_AMIC_CMD_RX_FIFO_RESET	0xF0

#ifdef __cplusplus
extern "C"
{
#endif

/* Operation Modes */
typedef enum {
	RF_CMD_SLEEP = RF_AMIC_CMD_SLEEP,
	RF_CMD_IDLE = RF_AMIC_CMD_IDLE,
	RF_CMD_STANDBY = RF_AMIC_CMD_STANDBY,
	RF_CMD_PLL = RF_AMIC_CMD_PLL,
	RF_CMD_RX = RF_AMIC_CMD_RX,
	RF_CMD_TX = RF_AMIC_CMD_TX
} E_RF_OP_CMD;

/* Internal global variables */ 
typedef struct {
	uint8_t			u8Channel;			// current channel number
	uint8_t			u8PacketSize;		// current packet size
	uint8_t			R20;				// backup of Register Code 1 (0x20)
	uint8_t			bIsPacketErr;		// record the status of the last received packet
    uint8_t            bEnableRssi;        // Enable RSSI evaluation at Rx
} S_RF_DRV_DATA;


/* AMIC A7125 Driver API */

void AMIC_A7125_WriteReg(uint8_t u8Addr, uint8_t n8Val);
uint8_t AMIC_A7125_ReadReg(uint8_t u8Addr);

void AMIC_A7125_WriteFifo(uint8_t * pBuffer, uint8_t nLen);
void AMIC_A7125_ReadFifo(uint8_t * pBuffer, uint8_t nLen);

int32_t AMIC_A7125_Init(void);						// Initialize RF module
void AMIC_A7125_Reset(void);						// Reset RF module
void AMIC_A7125_ResetTxFifo(void);					// Reset Tx FIFO
void AMIC_A7125_ResetRxFifo(void);					// Reset Rx FIFO

void AMIC_A7125_SetPayloadSize(uint16_t u16Size);		// Set payload (packet) size
uint16_t AMIC_A7125_GetPayloadSize(void);				// Get current payload (packet) size

void AMIC_A7125_SetId(uint32_t u32Id);				// Set RF Id
uint32_t AMIC_A7125_GetId(void);						// Get RF Id

void AMIC_A7125_OpCmd(E_RF_OP_CMD eMode);			// Set operation command to RF.

void AMIC_A7125_SetChannel(uint8_t u8Channel);		// Set channel #. f = 2400MHz + 0.5MHz * u8Channel
uint8_t AMIC_A7125_GetChannel(void);					// Get current channel #.

void AMIC_A7125_EnableCrc(void);					// Enable/Disable CRC
void AMIC_A7125_DisableCrc(void);
void AMIC_A7125_EnableFec(void);					// Enable/Disable FEC
void AMIC_A7125_DisableFec(void);
void AMIC_A7125_EnableEncryption(void);				// Enable/Disable Whitening
void AMIC_A7125_DisableEncryption(void);
void AMIC_A7125_SetEncryptionKey(uint32_t u32Key);	// Only the least significant 7 bits are valid.
void AMIC_A7125_EnableRssi(void);
void AMIC_A7125_DisableRssi(void);
uint8_t AMIC_A7125_GetRssi(void);


#ifdef __cplusplus
}
#endif

#endif	// _AMIC_A7125_RF_H_
