/* 
 * Filename: main.c
 * ----------------
 *   It is the main.c file of the project.
 *   It calls functions from other .h files to read city.dat
 *     and parse it to an adjacency matrix, then it displays
 *     the city selection and interacts with the user.
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include "adjmatrix.h"
#include "parsecities.h"

#define PARIS 0
#define BERLIN 1
#define MILAN 2
#define ROME 3
#define COLOGNE 4
#define MUNICH 5
#define VIENNA 6
#define WARSAW 7
#define AMSTERDAM 8
#define BRUSSELS 9
#define FRANKFURT 10
#define PRAGUE 11


#define SUCCESS 0
#define ERROR 1

/*
 * Function: main
 * --------------
 *   The function that executes the main of the program
 *
 *   argc: the number of command line argument(s)
 *   argv: the string array of command line argument(s)
 *
 *   returns: if the program is correctly executed
 */

int main( int argc, char *argv[]){
	int** matrix = createMatrix(); /* create the matrix */
	if(matrix == NULL) {
		return ERROR;
	}	

	char fileName[] = "city.dat";
	int result = parseFile(fileName, matrix); /* parse content into matrix */
	if(result != SUCCESS) {
		return ERROR;
	}

	result = displayAndInteract(matrix); /* display and interact with the user */
	if(result != SUCCESS) {
		return ERROR;
	}

	result = freeMatrix(matrix); /* free matrix */
	if(result != SUCCESS) {
		return ERROR;
	}

	return SUCCESS;
}

