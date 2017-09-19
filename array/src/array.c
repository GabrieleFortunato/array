/*
 * array.c
 *
 *  Created on: 25 apr 2017
 *      Author: Gabriele Fortunato
 */

#include "array.h"

void srand_time(){
	srand(time(NULL));
}

int generate_length(){
	int length = rand()%MAX_LENGTH;
	length++;
	assert(length>ZERO);
	return length;
}

int* generate_array(int length){
	assert(length>ZERO);
	int* array = malloc(length*sizeof(int));
	for (int i=ZERO;i<length;i++){
		array[i] = generate_number();
	}
	return array;
}

void print_array(char* message, int* array, int length){
	printf(
			 DOUBLE_STRING
			,NEW_LINE
			,message
	);
	for (int i=ZERO;i<length;i++){
		printf(INT,array[i]);
		if (i<length-ONE){
			printf(SEPARATOR_LINE);
		}
	}
}

float mean(int* array, int length){
	assert(length>ZERO);
	int sum = ZERO;
	for (int i=ZERO;i<length;i++){
		sum += array[i];
	}
	return (double)sum/length;
}

void print_mean(int* array, int length){
	printf(
			"%sMedia degli elementi dell'array: %.2f"
			,NEW_LINE,mean(array,length)
	);
}

bool ordered_array(int* array, int length){
	assert(length>ZERO);
	bool result = true;
	for (int i=ZERO;i<length-ONE;i++){
		if (array[i]>array[i+ONE]){
			result = false;
			break;
		}
	}
	return result;
}

void bubble_sort(int* array, int length){
	assert(length>ZERO);
	for (int pass=ZERO;pass<length;pass++){
		for (int i=ZERO;i<length-ONE;i++){
			if (array[i]>array[i+ONE]){
				int hold = array[i];
				array[i] = array[i+ONE];
				array[i+ONE] = hold;
			}
		}
	}
	assert(ordered_array(array,length));
}

int median(int* array, int length){
	assert(length>ZERO);
	assert(ordered_array(array,length));
	return array[length/TWO];
}

void print_median(int* array, int length){
	printf(
			"%s"
			"Elemento mediano dell'array ordinato : %d"
			"%s"
			,NEW_LINE
			,median(array,length)
			,NEW_LINE
	);
}

int generate_number(){
	return rand()%MAX_ELEMENT;
}

void print_number(int number){
	printf(
			"Numero da cercare nell'array: %d"
			,number
	);
}

bool linear_search(int* array, int length, int number){
	assert(length>>ZERO);
	bool result = false;
	for (int i=ZERO;i<length;i++){
		if (array[i] == number){
			result = true;
		}
	}
	return result;
}

bool binary_search(int* array, int length, int number){
	assert(length>ZERO);
	assert(ordered_array(array,length));
	bool result = false;
	int min = ZERO;
	int max = length-ONE;
	while(min<=max||result==false){
		int ind = (min+max)/TWO;
		if (array[ind] == number){
			printf("TROVATO");
			result = true;
			break;
		} else if (array[ind] > number){
			printf("1");
			max = ind - ONE;
		} else {
			printf("2");
			max = ind + ONE;
		}
	}
	return result;
}




void print_search_result(int* array, int length, int number){
	if (linear_search(array,length,number)){
		printf(
				"%s"
				"Il numero %d e' presente nell'array."
				"%s"
				,NEW_LINE
				,number
				,NEW_LINE
		);
	} else {
		printf(
				"%s"
				"Il numero %d non e' presente nell'array."
				"%s"
				,NEW_LINE
				,number
				,NEW_LINE
		);
	}
}
