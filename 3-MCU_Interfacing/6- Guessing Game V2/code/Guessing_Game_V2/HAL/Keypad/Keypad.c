/*
 * Keypad.c
 *
 *  Author: Mahmoud Ayoub
 */ 
/*
Keypad 4*4
1	2	3	+
4	5	6	-
7	8	9	*
#	0	=	/
*/

#include "Keypad.h"

/*
Description : function to initialize the port which keypad is connected (low nibble rows as OUTPUTs) , (high nibble cols as INPUTS)
inputs		:	 none
outputs		:    none  
*/
void KEYPAD_init (void) {
	  DDRD_REG = 0x0F ;             // initialization for ports (LSB is output row) and (MSB is input columns)

}

/*
Description : function to read value from keypad 
inputs		:	 none
outputs		:    value of pressed button on keypad 
*/
char KEYPAD_read (void) {
	DDRD_REG = 0x0F ;
	char row_data ;
	while (1){
		for (row_data=1 ; row_data<=8 ; row_data = row_data << 1 ){         // loop for sending ones for rows
			OUTPUT_ROW = row_data ;
			_delay_ms(1) ;
			if (row_data == 1 ){
				switch(INPUT_COL){
					case 1  : return '1' ; break;
					case 2  : return '2' ; break;
					case 4  : return '3' ; break;
					case 8  : return '+' ; break;
				}
				
			}
			else if (row_data == 2 ){
				switch(INPUT_COL){
					case 1  : return '4' ; break;
					case 2  : return '5' ; break;
					case 4  : return '6' ; break;
					case 8  : return '-' ; break;
				}
				
			}
			else if (row_data == 4 ){
				switch(INPUT_COL){
					case 1  : return '7' ; break;
					case 2  : return '8' ; break;
					case 4  : return '9' ; break;
					case 8  : return '*' ; break;
				}
				
			}
			else if (row_data == 8 ){
				switch(INPUT_COL){
					case 1  : return '#' ; break;
					case 2  : return '0' ; break;
					case 4  : return '=' ; break;
					case 8  : return '/' ; break;
				}	
			}			
		}
	}
}

/*
Description : function to handle pressing on keypad buttons
inputs		:	 none
outputs		:    none
*/
void KEYPAD_wait (void) {
	while(INPUT_COL) ;
}