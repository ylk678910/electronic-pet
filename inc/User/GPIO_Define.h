//*****************************************************************************
//
// GPIO_Define.h by Allen Hsu.
// First version on Aug. 24. 2014
//
//*****************************************************************************
#ifndef __GPIO_DEFINE_H__
#define __GPIO_DEFINE_H__

#include "GPIO.h"

#define SEGMENT_LED_GROUP E_GPIOE
#define SEGMENT_CS_GROUP E_GPIOC

#define SA	PIN_3
#define SB	PIN_4
#define SC  PIN_0
#define SD	PIN_5
#define SE	PIN_6
#define SF	PIN_2
#define SG	PIN_7
#define DOT	PIN_1

#define SEG_PIN_MASK 		( SA | SB | SC | SD | SE | SF | SG | DOT )

#define SEGMENT_1	PIN_4
#define SEGMENT_2	PIN_5
#define SEGMENT_3	PIN_6
#define SEGMENT_4	PIN_7

#define SEG_CS_MASK 		( SEGMENT_1 | SEGMENT_2 | SEGMENT_3 | SEGMENT_4 )
#define SEG_0		~( SA | SB | SC | SD | SE | SF )
#define SEG_1		~( SB | SC )
#define SEG_2		~( SA | SB | SD | SE | SG )
#define SEG_3		~( SA | SB | SC | SD | SG )
#define SEG_4		~( SB | SC | SF | SG )
#define SEG_5		~( SA | SC | SD | SF | SG )
#define SEG_6		~( SA | SC | SD | SE | SF | SG )
#define SEG_7		~( SA | SB | SC | SF )
#define SEG_8		~( SA | SB | SC | SD | SE | SF | SG )
#define SEG_9		~( SA | SB | SC | SD | SF | SG )

#define LED_MASK 		( PIN_12 | PIN_13 | PIN_14 | PIN_15 )

#define PIN_0		(1UL << 0)
#define PIN_1		(1UL << 1)
#define PIN_2		(1UL << 2)
#define PIN_3		(1UL << 3)
#define PIN_4		(1UL << 4)
#define PIN_5		(1UL << 5)
#define PIN_6		(1UL << 6)
#define PIN_7		(1UL << 7)
#define PIN_8		(1UL << 8)
#define PIN_9		(1UL << 9)
#define PIN_10	(1UL << 10)
#define PIN_11	(1UL << 11)
#define PIN_12	(1UL << 12)
#define PIN_13	(1UL << 13)
#define PIN_14	(1UL << 14)
#define PIN_15	(1UL << 15)

#endif

