#if 1
void draw_LCD(unsigned char *buffer);
void clr_all_panel(void);
void Initial_panel(void);

typedef struct pic_Detail {
	unsigned char *data;
	unsigned char height;
	unsigned char width;
	unsigned char loca_x;//1~128
	unsigned char loca_y;//1~8
}PIC;	

/*---------------------------------------------------------------------------------------------------------*/
/* picture name define					   		                                                                     */
/*---------------------------------------------------------------------------------------------------------*/
	typedef enum {
			HAPPINESS_BAR_NUM = 0,
			HUNGER_BAR_NUM,
    	CAT_NUM,
    	HAPPINESS_NUM,
			HUNGER_NUM,
    	CAT_EAT_NUM,
			CAT_PLAY_NUM
	}PIC_NAME;

/*---------------------------------------------------------------------------------------------------------*/
/* picture select define							                                                                     */
/*---------------------------------------------------------------------------------------------------------*/
	#define HAPPINESS 1<<HAPPINESS_NUM	
	#define HUNGER 1<<HUNGER_NUM
	#define HAPPINESS_BAR 1<<HAPPINESS_BAR_NUM	
	#define HUNGER_BAR 1<<HUNGER_BAR_NUM
	#define CAT 1<<CAT_NUM
	#define CAT_EAT 1<<CAT_EAT_NUM
	#define CAT_PLAY 1<<CAT_PLAY_NUM
	extern int LCD_OUTPUT_CONST[];
	
	extern unsigned char CAT_data[];
	extern unsigned char CAT1_LV0_data[];
	extern unsigned char CAT2_LV0_data[];
	extern unsigned char CAT1_LV1_data[];
	extern unsigned char CAT2_LV1_data[];
	extern unsigned char CAT_EAT1_data[];
	extern unsigned char CAT_EAT2_data[];
	extern unsigned char CAT_PLAY1_data[];
	extern unsigned char CAT_PLAY2_data[];
  extern unsigned char HAPPINESS_data[];
	extern unsigned char HUNGER_data[];
  extern unsigned char HAPPINESS_BAR_data[];
	extern unsigned char HUNGER_BAR_data[];
	extern PIC *CAT_PIC;
	extern PIC *CAT_EAT_PIC;
	extern PIC *CAT_PLAY_PIC;
	extern PIC CAT1_LV0_PIC;
	extern PIC CAT2_LV0_PIC;
	extern PIC CAT1_LV1_PIC;
	extern PIC CAT2_LV1_PIC;
	extern PIC CAT_EAT1_PIC;
	extern PIC CAT_EAT2_PIC;
	extern PIC CAT_PLAY1_PIC;
	extern PIC CAT_PLAY2_PIC;
	extern PIC HAPPINESS_PIC;
	extern PIC HUNGER_PIC;
	extern PIC HAPPINESS_BAR_PIC;
	extern PIC HUNGER_BAR_PIC;
	
extern int data_num;
extern int cat_lv0_num;
extern int cat_lv1_num;
extern int cat_eat_num;
extern int cat_play_num;
extern PIC **PIC_data_select[];	
extern PIC *PIC_CAT_LV0_select[];
extern PIC *PIC_CAT_LV1_select[];
extern PIC *PIC_CAT_EAT_select[];
extern PIC *PIC_CAT_PLAY_select[];
extern PIC *PIC_HAPPINESS_select[];
extern PIC *PIC_HUNGER_select[];
extern PIC *PIC_HAPPINESS_BAR_select[];
extern PIC *PIC_HUNGER_BAR_select[];

extern unsigned char delay_flag;
#else	
#endif
