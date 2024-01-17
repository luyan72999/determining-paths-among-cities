/*
 * Filename: adjmatrix.h
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

#define CITIES 12
#define NO_ROUTE -1

/*
 * Function: createMatrix
 * ----------------------
 *   It creates a adjacency matrix
 *
 *   returns: adjacency matrix
 */

int** createMatrix() {
	/* allocate memory for matrix */
	int** matrix = (int**)malloc(CITIES * sizeof(int*));
	if (matrix == NULL) {
		return NULL;
	}

	int i, j;	
	for(i=0; i<CITIES; i++){
		matrix[i] = (int*)malloc(CITIES * sizeof(int));
		if (matrix[i] == NULL) {
			return NULL;
		}
	}

	/* initialize the adjacency matrix, set all edges to NO_ROUTE, 
	 * which means initially we suppose there are no routes between those cities
     */
	for(i=0; i<CITIES; i++){
		for(j=0; j<CITIES; j++){
			matrix[i][j] = NO_ROUTE;
		}
    }
	/* after that we can set those routes with city.dat */
	
	return matrix;
}


/*
 * Function: freeMatrix
 * --------------------
 *   It frees the allocated memory of matrix
 *
 *   matrix: the adjacency matrix
 */

int freeMatrix(int** matrix) {
	if (matrix == NULL) {
		return 1;
	}
	int i;
	for(i=0; i<CITIES; i++){
		if (matrix[i] == NULL) {
			exit(1);
		}
		free(matrix[i]);
	}
	free(matrix);

	return 1;
}

