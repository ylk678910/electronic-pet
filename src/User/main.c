#include "NUC1xx.h"
#include "DrvSYS.h"
#include "DrvGPIO.h"
#include "Function_Define.h"
#include "DrvTIMER.h"
#include "Pet_CH_Define.h"
#include "LCD_Define.h"

volatile unsigned int *reg_ptr;

int main(void)
{
	UNLOCKREG();
	DrvSYS_Open(50000000);// Set System Clock to run at 50MHz.
	SYSCLK->CLKSEL0.STCLK_S = 0x3; // System tick's clock.
	LOCKREG();
	
	DrvTIMER_Init();//Timer enable
	
	//LCD initial
	Initial_panel();
	clr_all_panel();//Clear LCD
	
	//Keypad initial
	OpenKeyPad();//Key Pad open
	
	//Cat animation timer initial(TIMER0)
	DrvTIMER_Open(E_TMR0, 0x2/*The larger the value, the higher the frequency.*/, E_PERIODIC_MODE);
	DrvTIMER_EnableInt(E_TMR0);
	DrvTIMER_SetTimerEvent(E_TMR0,1/*How many interrupt times needs to do a function.*/,(TIMER_CALLBACK)CAT_animation,0);
	DrvTIMER_Start(E_TMR0);
	//Bar animation timer initial(TIMER1)
	DrvTIMER_Open(E_TMR1, 10/*The larger the value, the higher the frequency.*/, E_PERIODIC_MODE);
	DrvTIMER_EnableInt(E_TMR1);
	DrvTIMER_SetTimerEvent(E_TMR1,1/*How many interrupt times needs to do a function.*/,(TIMER_CALLBACK)BAR_tick_add,0);
	DrvTIMER_Start(E_TMR1);
	//Delay timer initial(TIMER2)
	DrvTIMER_Open(E_TMR2, 0x5/*The larger the value, the higher the frequency.*/, E_PERIODIC_MODE);
	DrvTIMER_SetTimerEvent(E_TMR2,2/*How many interrupt times needs to do a function.*/,(TIMER_CALLBACK)Animation_delay,0);
	DrvTIMER_Start(E_TMR2);
	
	int action_flag = 0,i;
	enum {
  	NOTHING=0,
  	EATING,
		PLAYING
	};
	while(1){
		switch(action_flag){
			case NOTHING:
				//Bar Change Animation
				if(happiness>100){//happiness is unsigned, so if it's value below 0, it will be counted from 0xffffffffffff
					happiness=0;
				}else if(bar_tick%2 == 1 && happiness!=0){
					happiness--;
					BAR_Refresh(BAR_HAPPINESS_NUM);
				}
				if(hunger>100){//hunger is unsigned, so if it's value below 0, it will be counted from 0xffffffffffff
					hunger=0;
				}else if(bar_tick%3 == 1 && hunger!=0){
					hunger--;
					BAR_Refresh(BAR_HUNGER_NUM);
				}				
				if(growth>100){//growth is unsigned, so if it's value below 0, it will be counted from 0xffffffffffff
					growth=0;
					if(level<level_max) level++;
				}else if(bar_tick%7 == 1 && hunger>0 && happiness>0){
					growth++;
				}
				draw_LCD(LCD_output(CAT | HAPPINESS | HUNGER | HAPPINESS_BAR | HUNGER_BAR));
				break;
				
			case EATING:
				hunger += 50;
				if(hunger>100){//hunger is unsigned, so if it's value below 0, it will be counted from 0xffffffffffff
					hunger=100;
				}
				DrvTIMER_DisableInt(E_TMR1);
				//Eating Animation
				for(i=0; i<cat_eat_num; i++){
					CAT_EAT_PIC = PIC_CAT_EAT_select[i];
					DrvTIMER_EnableInt(E_TMR2);
					while(!delay_flag)
						draw_LCD(LCD_output(CAT | HAPPINESS | HUNGER | HAPPINESS_BAR | HUNGER_BAR | CAT_EAT));
					DrvTIMER_DisableInt(E_TMR2);
					delay_flag = 0;
				}
				DrvTIMER_EnableInt(E_TMR1);
				action_flag = NOTHING;
				break;
			
			case PLAYING:
				happiness += 50;
				if(happiness>100){//hunger is unsigned, so if it's value below 0, it will be counted from 0xffffffffffff
					happiness=100;
				}
				DrvTIMER_DisableInt(E_TMR1);
				//Eating Animation
				for(i=0; i<cat_play_num*2; i++){
					CAT_PLAY_PIC = PIC_CAT_PLAY_select[i%2];
					DrvTIMER_EnableInt(E_TMR2);
					while(!delay_flag)
						draw_LCD(LCD_output(CAT | HAPPINESS | HUNGER | HAPPINESS_BAR | HUNGER_BAR | CAT_PLAY));
					DrvTIMER_DisableInt(E_TMR2);
					delay_flag = 0;
				}
				DrvTIMER_EnableInt(E_TMR1);
				action_flag = NOTHING;
				break;
			default:
				action_flag = NOTHING;
		}

		uint8_t key = Scankey();
		switch(key){
			case 1:
				action_flag = PLAYING;
				break;
			case 2:
				action_flag = EATING;
				break;
			default:
				action_flag = NOTHING;
				break;
		}
	}

}

