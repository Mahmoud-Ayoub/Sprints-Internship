/*
Author : Mahmoud Ayoub
 */
#include "types.h"

#define max 100
int Stack [max] ;
int top = -1 ;          // NOTE : top is an index not pointer

int Stack_is_empty (void) ;
int Stack_is_full (void) ;
void Stack_push (uint8_t value) ;
uint8_t Stack_pop (void) ;
void Stack_display (void) ;
uint8_t* balanced_Parentheses (uint8_t* expression) ;

int main()
{
	printf ("\n %s \n" , balanced_Parentheses("(2*3+(5/2+(4*3)))")) ;
	printf ("\n %s \n" , balanced_Parentheses("{({2+10}}*11}")) ;
	return 0;
}
int Stack_is_empty (void) {
	if (top == -1)
		return 1 ;
	else
		return 0 ;
}
int Stack_is_full (void) {
	if (top == max-1)
		return 1 ;
	else
		return 0 ;
}
void Stack_push (uint8_t value) {
	if (Stack_is_full() == 1) {        // before push a value in stack, we must check if stack is full or not
		printf("Stack overflow \n") ;
		return ;
	}
	else {
		top ++ ;
		Stack[top] = value ;
	}
}
uint8_t Stack_pop (void) {
	if (Stack_is_empty() == 1) {    // before pop a value from stack, we must check if stack is empty or not
		//printf("Empty Stack \n") ;
		return ;
	}
	else {
		int data = Stack[top] ;
		top -- ;
		return data ;
	}
}
void Stack_display (void) {
	if (Stack_is_empty() == 1)    // before display a value from stack, we must check if stack is empty or not
		return ;
	else {
		int i = 0 ;
		for (i=top ; i >=0 ; i--) {           // NOTE : greater than or equal to zero to display the element in index [0]
			printf("values in stack = %d \n" , Stack[i]) ;
		}
	}
}
// function balanced parentheses
// input : string
// output : string (balanced or Not balanced)
uint8_t* balanced_Parentheses (uint8_t* expression) {
	// loop on the string if it is '{' , '(' , '[' then push it to stack
	// if current char is '}' , ')' , ']' then pop from stack
	// if popped char is matching the start >> it is balanced
	// if not : Not balanced
	int i = 0 ;
	int flag = 0 ;
	uint8_t popped_char ;
	while (expression[i]) {
		if ((expression[i]=='{') || (expression[i]=='(') || (expression[i]=='[') ) {
			printf ("expression [%d] = %c \n" , i , expression[i]) ;
			printf ("pushed char = %c " , expression[i]);
			Stack_push(expression[i]) ;
			printf ("\n") ;
		}
		if ((expression[i]=='}') || (expression[i]==')') || (expression[i]==']') ) {
			popped_char = Stack_pop() ;
			if (popped_char == '{' && expression[i] == '}') {
				flag = 1 ;
			}
			else if (popped_char == '(' && expression[i] == ')') {
				flag = 1 ;
			}
			else if (popped_char == '[' && expression[i] == ']') {
				flag = 1 ;
			}
			else if (Stack_is_empty()==1) {
				flag = 0 ;
			}
			else {
				flag = 0 ;
				return "Not Balanced" ;
			}

		}
		i++ ;
	}
	if (flag == 1) {
		flag = 0  ;
		return "Balanced \n" ;
	}
}
