#include "LCD_Define.h"	
	
	unsigned char* LCD_output(unsigned int pic_print){
		unsigned static char LCD_output_temp[8*128];
		int i, x, y, now_data=0;
		
		for(i=0; i<128*8; i++)
			LCD_output_temp[i] = 0;//clear
	
		for(i=0; i<data_num; i++){//no blanking
			now_data = 0;
			if((pic_print&LCD_OUTPUT_CONST[i])!=0 && i!=CAT_EAT_NUM && i!=CAT_PLAY_NUM){//select normal
				PIC PIC_select = **PIC_data_select[i];
				if(i!=CAT_EAT_NUM & i!=CAT_PLAY_NUM)
					for(y=PIC_select.loca_y-1; y< PIC_select.loca_y-1+PIC_select.height; y++){
							for(x = PIC_select.loca_x-1; x<PIC_select.loca_x-1+PIC_select.width; x++){
								if(x<128 && x>=0 && y<8 && y>=0)
									LCD_output_temp[x+y*128] |= PIC_select.data[now_data];//setbit
								now_data++;
							}
					}
			}
		}
		for(i=0; i<data_num; i++){//blanking
			now_data = 0;
			if((pic_print&LCD_OUTPUT_CONST[i])==CAT_EAT || (pic_print&LCD_OUTPUT_CONST[i])==CAT_PLAY){//select playing or eating
				PIC PIC_select = **PIC_data_select[i];
					for(y=PIC_select.loca_y-1; y< PIC_select.loca_y-1+PIC_select.height; y++){
							for(x = PIC_select.loca_x-1; x<PIC_select.loca_x-1+PIC_select.width; x++){
								if(x<128 && x>=0 && y<8 && y>=0){
									if(PIC_select.height != 1){
										int bit_select,j;
										if(y-PIC_select.loca_y+1==0){//pic.y=first
											for(bit_select=0; bit_select<8; bit_select++){
												if((PIC_select.data[now_data]>>bit_select&0x1) == 1){
													for(j=7; j>bit_select; j--)
														LCD_output_temp[x+y*128] &= ~(0x1<<j);//clearbit
										//LCD_output_temp[x+y*128] |= PIC_select.data[now_data];//setbit
													break;
												}
											}			
										}													
										if(y-PIC_select.loca_y+1>0 && y-PIC_select.loca_y+1 < PIC_select.height-1){//pic.y!=first && pic.y!=last
											LCD_output_temp[x+y*128] &= PIC_select.data[now_data];//clearbit
										//LCD_output_temp[x+y*128] |= PIC_select.data[now_data];//setbit
										}
										if(y-PIC_select.loca_y+1 == PIC_select.height-1){//pic.y=last
											for(bit_select=7; bit_select>=0; bit_select--){
												if((PIC_select.data[now_data]>>bit_select&0x1) == 1){
													for(j=0; j<bit_select; j++)
														LCD_output_temp[x+y*128] &= ~(0x1<<j);//clearbit
										//LCD_output_temp[x+y*128] |= PIC_select.data[now_data];//setbit
													break;
												}
											}
										}
										
										LCD_output_temp[x+y*128] |= PIC_select.data[now_data];//setbit
										
									}
									else{
									
									}
								now_data++;
							}
						}
					}
			}
		}
		return LCD_output_temp;
		
	}

	