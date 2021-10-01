/*
 * Guessing_Game_V1.c
 *
 * Author : Mahmoud Ayoub
 */ 

#include "./HAL/LCD/LCD.h"
#include "./HAL/Push_Button/PB.h"
#include "./MCAL/Timer/TIMER.h"
#include <stdlib.h>
/*
Description : function to generate random number between lower value and upper value
inputs		: lower value , upper value
outputs		: random value generated
*/
char generate_random_value (uint8 lower , uint8 upper) {
	char number ; 
	number = (rand() % (upper - lower + 1)) + lower ; 
	return number ; 
}
/*
Description : function to start new game by printing message on LCD
inputs		: none
outputs		: none
*/
void start_game (void) {
	LCD_clear() ; 
	LCD_send_str("Guess Number: ") ;
	LCD_newline() ;
}
/*
Description : function to check that number of presses is between 1 and 15
inputs		: number of counts
outputs		: 1 >> error detected  || 0 >> no error
*/
char check_error (char press_count) {
	if ((press_count < 1) || (press_count > 15)) 
		return 1 ;
	else 
		return 0 ; 
}

int main(void)
{	
    LCD_init() ; 
	PB_init(portA , 0) ;										 // counter button
	char count = 0 ; 
	char count_str[3] ; 
	char random_number = generate_random_value(1,15) ;  
	
	start_game() ; 
	TIMER1_init() ;												// start timer
	while (1) {
		if (PB_read(portA , 0) == 1) {							// take number of counts
			count ++ ;
			itoa (count , count_str , 10) ;						// Display number of counts
			LCD_send_str (count_str) ;
			LCD_newline() ;
			while (PB_read(portA , 0) == 1) ;                   // handle long pressing
			TIMER1_reset() ;                                    // every press should reset the timer
		}
		if (TIMER1_end() == 1) {							   // timer ends without any press 
			LCD_clear() ; 
			LCD_send_str("Time OUT");
			_delay_ms(2000) ; 
			if (check_error(count) == 1) {                     // check number of presses is in between 1 , 15
				LCD_clear() ;
				LCD_send_str("Error ..") ; 
				_delay_ms(3000) ; 
				count = 0 ; 
				start_game() ; 
				TIMER1_reset() ;
			}
			else {                                            // check win or lose
				if (count == random_number) {
					LCD_clear() ;
					LCD_send_str("You Win") ;
					_delay_ms(3000) ;
					count = 0 ;
					start_game() ;
					TIMER1_reset() ;
				}
				else {
					LCD_clear() ;
					LCD_send_str("You Lose") ;
					_delay_ms(3000) ;
					count = 0 ;
					start_game() ;
					TIMER1_reset() ;
				}
			}
		}	
	}
}

