extern unsigned int bar_tick;
extern unsigned int happiness;
extern unsigned int hunger;
extern unsigned int growth;

extern unsigned int level;
extern unsigned int level_max;

extern unsigned int *CH_select[];

typedef enum {
  	BAR_HAPPINESS_NUM=0,
  	BAR_HUNGER_NUM
}BAR_NUM;

void BAR_Refresh(BAR_NUM ch);
