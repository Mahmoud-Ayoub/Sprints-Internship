/*
 * X_O_game.c
 *      Author: Mahmoud Ayoub
 */
#include "stdio.h"
#define ROW 3
#define COL 3
char game_field [ROW][COL] ;
int winner_flag = 0 ;

void get_symbols (void) ;
void print_game_field (void) ;
void check_diagonal (void) ;
void check_rows (void) ;
void check_columns (void) ;
void check_winner (void) ;

int main () {
	printf ("welcome to the game \n") ;         // start game
	get_symbols () ;
	print_game_field () ;
	printf ("End of the Game \n") ;			  	//  end game
	return 0 ;
}
void get_symbols (void) {
	int i , row , col ;
	char entered_symbol ;
	for (i=0 ; i<9 ; i++) {
		printf ("Enter position row and col : \n") ;  // take position of the symbol
		fflush (stdin) ; 	fflush (stdout) ;
		scanf("%d %d" , &row , &col) ;

		printf ("Enter X or O : ") ;               	// take the symbol
		fflush (stdin) ; 	fflush (stdout) ;
		scanf ("%c" , &entered_symbol) ;

		game_field[row][col] = entered_symbol ;
		print_game_field() ;
		check_winner () ;
		if (winner_flag == 1)      					// end of the game
			break ;
	}
	if (winner_flag == 0) {
		printf ("No Winner .. Draw \n") ;
	}
}
void print_game_field (void) {
	int i , j ;
	for (i=0 ; i<ROW ; i++) {
		for (j=0 ; j<COL ; j++) {
			printf ("%c \t" , game_field[i][j]) ;
		}
		printf ("\n") ;
	}
}
void check_diagonal (void) {
	if ( (game_field[0][0] == game_field[1][1]) && (game_field[1][1] == game_field[2][2]) ) { // diagonal_1 completed
		if (game_field[0][0] == 'X') {
			printf ("X is the winner \n") ;
			winner_flag = 1 ;
		}
		else if (game_field[0][0] == 'O') {
			printf ("O is the winner \n") ;
			winner_flag = 1 ;
		}
	}
	if ( (game_field[2][0] == game_field[1][1]) && (game_field[1][1] == game_field[0][2]) ) { // diagonal_2 completed
		if (game_field[2][0] == 'X') {
			printf ("X is the winner \n") ;
			winner_flag = 1 ;
		}
		else if (game_field[2][0] == 'O') {
			printf ("O is the winner \n") ;
			winner_flag = 1 ;
		}
	}
}
void check_rows (void) {
	int i ;
	for (i=0 ; i<ROW ; i++) {
		if ( (game_field[i][0] == game_field[i][1]) && (game_field[i][1] == game_field[i][2]) ) {
			if (game_field[i][0] == 'X') {
				printf ("X is the winner \n") ;
				winner_flag = 1 ;
				break ;
			}

			else if (game_field[i][0] == 'O') {
				printf ("O is the winner \n") ;
				winner_flag = 1 ;
				break ;
			}
		}
	}
}
void check_columns (void) {
	int i ;
	for (i=0 ; i<COL ; i++) {
		if ( (game_field[0][i] == game_field[1][i]) && (game_field[1][i] == game_field[2][i]) ) {
			if (game_field[0][i] == 'X') {
				printf ("X is the winner \n") ;
				winner_flag = 1 ;
				break ;
			}

			else if (game_field[0][i] == 'O') {
				printf ("O is the winner \n") ;
				winner_flag = 1 ;
				break ;
			}
		}
	}
}
void check_winner (void) {
	check_diagonal () ;
	check_rows () ;
	check_columns () ;
}

/*
Test case 1 :
	X is winner
	X	O	X
	O	X	O
	X

Test case 2 :
	O is winner
	O 	O	O
	X 	X

Test case 3 :
	Draw
	X	O	X
	O	X	O
	O	X	O
 */
