/*
 * main.c
 *      Author: Mahmoud Ayoub
 */
#include "types.h"
uint8_t check_sorted (uint32_t* arr , uint8_t size) ;
void bubble_sort (uint32_t* arr , uint8_t size) ;
int8_t binarySearch (uint32_t* arr , uint8_t size , uint32_t number) ;

int main () {
	uint32_t sample_array [5] = {20 , 10 , 200 , 100 , 15} ;
	uint8_t i = 0;
	int8_t found_number_index ;
	uint8_t sort_flag = 0 ;
	uint8_t sample_array_size = sizeof(sample_array) / sizeof (sample_array[0]) ;

	printf ("original array \n") ;
	for (i=0 ; i<sample_array_size ; i++) {
		printf ("%d  " , sample_array[i]) ;
	}
	printf ("\n") ;
	found_number_index = binarySearch (sample_array , sample_array_size , 127) ;
	if (found_number_index == -1) {
		printf ("Number entered is Not found \n") ;
	}
	else {
		printf ("Number entered is found in %d index \n" , found_number_index) ;
	}

	return 0 ;
}
// function : check if a given array is sorted or not
// inputs : array , its size
// outputs : (if sorted >> 1) , (if Not sorted >> 0)
uint8_t check_sorted (uint32_t* arr , uint8_t size) {
	uint8_t i = 0 ;
	for (i=0 ; i<size ; i++) {
		if (arr[i] > arr[i+1])
			return 0 ;             // array is Not sorted
	}
	return 1 ;                    // array is sorted
}

// function : bubble sort
// inputs : array , its size
// outputs : nothing
void bubble_sort (uint32_t* arr , uint8_t size) {
	uint8_t i = 0 ;
	uint32_t temp ;
	for (i=0 ; i<size ; i++) {
		if (arr[i] > arr[i+1]) {
			// swap
			temp = arr[i] ;
			arr[i] = arr[i+1] ;
			arr[i+1] = temp ;
			bubble_sort(arr , size) ;
		}
	}
}
// function : binary search
// inputs : array , its size , number to be searched for
// outputs : (if found >> index of the number) ,  (if Not found >> -1 )
int8_t binarySearch (uint32_t* arr , uint8_t size , uint32_t number) {
	uint8_t start = 0 ;
	uint8_t end = size-1 ;
	uint8_t middle ;
	uint8_t i = 0 ;
	if (check_sorted(arr , size) == 0)  {    // array is NOT sorted
		printf ("Array is Not sorted \n") ;
		bubble_sort(arr , size) ;
		printf (".................\n") ;
		printf ("Now array is sorted \n") ;
		for (i=0 ; i<size ; i++) {
			printf ("%d  " , arr[i]) ;
		}
		printf ("\n") ;
	}
	while (start <= end) {                   // search after confirmation that array is sorted
		middle = (start+end) / 2 ;
		if (arr[middle] == number)           // number found in the middle
			return middle ;
		else if (arr[middle] < number) {     // number in RHS of middle
			start = middle + 1 ;
		}
		else if (arr[middle] > number) {     // number in LHS of middle
			end = middle - 1 ;
		}
	}
	return -1 ;
}
