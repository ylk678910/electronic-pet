#include "Function_Define.h"
#include "Pet_CH_Define.h"
#include "LCD_Define.h"

void BAR_Refresh(BAR_NUM ch)
{	
	unsigned char bar_temp;
	unsigned int CH_value = *CH_select[ch];
	int i, j, bit_select;
	
	PIC PIC_select = **PIC_data_select[ch];
	
	for(i=0; i<PIC_select.height;i++){
		for(j=1; j<PIC_select.width-1;j++){
			if(j<CH_value*PIC_select.width/100)
				PIC_select.data[j+i*PIC_select.width] = PIC_select.data[i*PIC_select.width];
			else{
				bar_temp = PIC_select.data[j+i*PIC_select.width];
				PIC_select.data[j+i*PIC_select.width] = 0;
				if(i==0){
					for(bit_select=0; bit_select<8; bit_select++){
						if((bar_temp>>bit_select&0x1) == 1){
							PIC_select.data[j+i*PIC_select.width] |= 0x1<<bit_select;
							break;
						}
					}
				}
				if(i == PIC_select.height-1){
					for(bit_select=7; bit_select>=0; bit_select--){
						if((bar_temp>>bit_select&0x1) == 1){
							PIC_select.data[j+i*PIC_select.width] |= 0x1<<bit_select;
							break;
						}
					}
				}
			}
		}
	}
}

void CAT_animation(void)
{
	unsigned static int cat_select=1;
	if(level>level_max)
		level = level_max;
	
	switch(level){
		case 0:
			CAT_PIC = PIC_CAT_LV0_select[cat_select%cat_lv0_num];
			break;
		case 1:
			CAT_PIC = PIC_CAT_LV1_select[cat_select%cat_lv1_num];
			break;
		default:
			CAT_PIC = PIC_CAT_LV0_select[cat_select%cat_lv0_num];
			level = 0;
			break;
	}
	cat_select++;
}

void BAR_tick_add(void)
{
	bar_tick++;
}

void Animation_delay(void)
{
	delay_flag=1;
}
