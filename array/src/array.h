/*
 * array.h
 *
 *  Created on: 25 apr 2017
 *      Author: Gabriele Fortunato
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <assert.h>

#define ZERO          		0
#define ONE           		1
#define TWO           		2
#define MAX_LENGTH   		20
#define MAX_ELEMENT 		15
#define NEW_LINE			"\n"
#define INT 				"%d"
#define PRINT_MEAN          "%sMedia degli elementi dell'array: %.2f"
#define SEPARATOR_LINE		"-"
#define DOUBLE_STRING       "%s%s"
#define GENERATED_ARRAY  	"Array generato: "
#define ORDERED_ARRAY  		"Array ordinato: "

/**
 * Assicura che ad ogni lancio
 * il programma generi in modo casuale
 * numeri sempre diversi
 */
void srand_time();

/**
 * Genera in modo casuale la dimensione dell'array
 * @post il numero generato deve essere maggiore di 0
 * @return
 */
int generate_length();

/**
 * Genera in modo casuale gli elementi dell'array
 * di dimensione stabilita dal parametro length
 * @pre il parametro length deve essere un numero intero maggiore di 0
 * @return
 */
int* generate_array(int length);

/**
 * Stampa a video gli elementi dell'array di dimensione
 * stabilita dal parametro length
 * @param message
 * @param array
 * @param length
 */
void print_array(char* message, int* array, int length);

/**
 * Restituisce la media degli elementi dell'array
 * di dimensione stabilita dal parametro length
 * @pre il parametro length deve essere un numero intero maggiore di 0
 * @param array
 * @param length
 * @return
 */
float mean(int* array, int length);

/**
 * Stampa a video la media degli elementi dell'array
 * @param array
 * @param length
 */
void print_mean(int* array, int length);

/**
 * Verifica che in un array di dimensione stabilita
 * dal parametro length gli elementi siano ordinati in maniera crescente
 * @pre il parametro dim deve essere un numero intero maggiore di 0
 * @param array
 * @param length
 * @return
 */
bool ordered_array(int* array, int length);

/**
 * Ordina in maniera crescente gli elementi dell'array
 * di dimensione stabilita dal parametro length
 * @pre il parametro length deve essere un numero intero maggiore di 0
 * @post gli elementi dell'array sono ordinati in maniera crescente
 * @param array
 * @param length
 */
void bubble_sort(int* array, int length);

/**
 * Restituisce l'elemento centrale dell'array ordinato di dimensione
 * stabilita dal parametro length
 * @pre il parametro length deve essere un numero intero maggiore di 0
 * @pre gli elementi dell'array devono essere ordinati in maniera crescente
 * @param array
 * @param length
 * @return
 */
int median(int* array, int length);

/**
 * Stampa a video l'elemento mediano dell'array ordinato
 * @param array
 * @param length
 */
void print_median(int* array, int length);

/**
 * Genera in modo casuale il numero da cercare nell'array
 * @return
 */
int generate_number();

/**
 * Stampa a video il numero da cercare nell'array
 * @param number
 */
void print_number(int number);

/**
 * Effettua la ricerca lineare del parametro number
 * nell'array di lunghezza stabilita dal parametro length
 * @pre il parametro length deve essere un numero intero maggiore di 0
 * @param array
 * @param length
 * @param number
 * @return
 */
bool linear_search(int* array, int length, int number);

/**
 * Stampa a video il risultato della ricerca
 * @param array
 * @param length
 * @param number
 */
void print_search_result(int* array, int length, int number);

#endif /* ARRAY_H_ */
