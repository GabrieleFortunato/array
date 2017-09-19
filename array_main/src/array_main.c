/*
 ============================================================================
 Name        : array_main.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "array.h"

int main(void) {
	srand_time();
	int length = generate_length();
	int* array = generate_array(length);
	int number = generate_number();
	print_array(GENERATED_ARRAY,array,length);
	if (!ordered_array(array,length)){
		bubble_sort(array,length);
	}
	print_array(ORDERED_ARRAY,array,length);
	print_mean(array,length);
	print_median(array,length);
	print_number(number);
	print_search_result(array,length,number);
	return EXIT_SUCCESS;
}
