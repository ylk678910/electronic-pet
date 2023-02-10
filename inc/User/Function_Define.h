#include <stdint.h>
#include <DrvTIMER.h>

#if 1
//DrvSYS.c
	void DrvSYS_Delay(uint32_t);
//ScanKey.c
	void OpenKeyPad(void);
	uint8_t Scankey(void);
//DrvTIMER.c
	void DrvTIMER_Init(void);
	void TMR0_IRQHandler(void);
	int32_t DrvTIMER_Open(E_TIMER_CHANNEL ch, uint32_t uTicksPerSecond, E_TIMER_OPMODE op_mode);
	int32_t DrvTIMER_DisableInt(E_TIMER_CHANNEL ch);
	int32_t DrvTIMER_SetTimerEvent(E_TIMER_CHANNEL ch, uint32_t uInterruptTicks, TIMER_CALLBACK pTimerCallback, uint32_t parameter);
	int32_t DrvTIMER_EnableInt(E_TIMER_CHANNEL ch);
	int32_t DrvTIMER_Start(E_TIMER_CHANNEL ch);
//Animation.c
	void CAT_animation(void);
	void BAR_tick_add(void);
	void Animation_delay(void);
//LCD_Function.c
	unsigned char* LCD_output(unsigned int pic_print);
#else
#endif

