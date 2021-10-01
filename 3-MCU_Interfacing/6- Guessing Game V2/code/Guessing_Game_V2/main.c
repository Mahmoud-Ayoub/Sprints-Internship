/*
 * Guessing_Game_V2.c
 *
 * Author : Mahmoud Ayoub
 */ 

#include "./HAL/LCD/LCD.h"
#include "./HAL/Keypad/Keypad.h"
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
inputs		: pressed keys on keypad
outputs		: 1 >> error detected  || 0 >> no error
*/
char check_error (char* keys) {
	int guessed_number ; 
	guessed_number = atoi (keys) ; 
	if ((guessed_number < 1) || (guessed_number > 15)) 
		return 1 ;
	else 
		return 0 ; 
}

/*
Description : function to check if number is guessed correctly or not
inputs		: pressed keys on keypad , random number generated
outputs		: 1 >> guessed correctly (win state)  || 0 >> guessed uncorrectly (lose state)
*/
char check_state (char* keys , char random_num) {
	int guessed_number ;
	guessed_number = atoi (keys) ;
	if (guessed_number == random_num)
		return 1 ;
	else
		return 0 ;
}

/*
Description : function to add zeros in an array
inputs		: array name
outputs		: none
*/
void array_zeros (char* arr) {
	char no_of_elements  = 0 ; 
	char length = sizeof (arr) / sizeof (arr[0]) ; 
	for (no_of_elements = 0 ; no_of_elements < length ; no_of_elements ++ ) {
		arr[no_of_elements] = 0 ; 
	}
}

int main(void)
{	
    LCD_init() ;  
	char keys_pressed[3] ;
	char single_number ; 
	char no_of_keys = 0 ;  
	char random_number = generate_random_value(1,15) ;  
	
	start_game() ; 
													
	while (1) {
		single_number = KEYPAD_read() ; 
		KEYPAD_wait() ; 
		if (single_number != '=') {                          // user doesn't finish entering the number
			LCD_send_char(single_number) ; 
			keys_pressed[no_of_keys] = single_number ;  
			no_of_keys ++ ; 
		}
		else {												// user finished entering the number
			if (check_error(keys_pressed) == 1) {           // check number of presses is in between 1 , 15
				LCD_clear() ;
				LCD_send_str("Error ..") ;
				_delay_ms(3000) ;
				array_zeros(keys_pressed) ;				
				no_of_keys = 0 ; 
				start_game() ;
			}
			else {											// No error detected , check win or lose 
				if (check_state(keys_pressed , random_number) == 1) {                   // win
					LCD_clear() ;
					LCD_send_str("You Win") ;
					_delay_ms(3000) ;
					array_zeros(keys_pressed) ;
					no_of_keys = 0 ;
					start_game() ;
				}
				else {										// lose
					LCD_clear() ;
					LCD_send_str("You Lose") ;
					_delay_ms(3000) ;
					array_zeros(keys_pressed) ;
					no_of_keys = 0 ;
					start_game() ;
				}
			}
		}	
	}	
}
