/*
 * Filename: parsecities.h
 * -----------------------
 *   It is the file that contains functions that parses the city infomation.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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

#define UNKNOWN_CITY -1
#define CITIES 12
#define NO_ROUTE -1


#define SUCCESS 0
#define ERROR 1

/* Function: getIntCity
 * --------------------
 *   It convert string city name, like "paris", to its int number,
 *     which is pre-defined as PARIS(0). If the city is not 
 *     in the pre-defined list, then it returns UNKNOWN_CITY,
 *     showing that it is an invalid city name.
 *
 *   strCity: a string city
 *
 *   returns: the int number of the city
 */

int getIntCity(char* strCity) {
    if(!strcmp(strCity, "paris")) {
        return PARIS;
    } else if (!strcmp(strCity, "berlin")) {
        return BERLIN;
    } else if (!strcmp(strCity, "milan")) {
        return MILAN;
    } else if (!strcmp(strCity, "rome")) {
        return ROME;
    } else if (!strcmp(strCity, "cologne")) {
        return COLOGNE;
    } else if (!strcmp(strCity, "munich")) {
        return MUNICH;
    } else if (!strcmp(strCity, "vienna")) {
        return VIENNA;
    } else if (!strcmp(strCity, "warsaw")) {
        return WARSAW;
    } else if (!strcmp(strCity, "amsterdam")) {
        return AMSTERDAM;
    } else if (!strcmp(strCity, "brussels")) {
        return BRUSSELS;
    } else if (!strcmp(strCity, "frankfurt")) {
        return FRANKFURT;
    } else if (!strcmp(strCity, "prague")) {
        return PRAGUE;
    } else {
        return UNKNOWN_CITY;
    }
}

/* 
 * Function: getStrCity
 * --------------------
 *   It converts an int city number to its string city name.
 *   If the int city number is not pre-defined, it returns "UNKNOWN CITY".
 *
 *   intCity: the int city number
 *
 *   returns: the string name of the city
 */

char* getStrCity(int intCity){
	switch(intCity) {
		case PARIS:
			return "Paris";
		case BERLIN:
			return "Berlin";
		case MILAN:
            return "Milan";
        case ROME:
            return "Rome";
        case COLOGNE:
            return "Cologne";
        case MUNICH:
            return "Munich";
        case VIENNA:
            return "Vienna";
        case WARSAW:
            return "Warsaw";
        case AMSTERDAM:
            return "Amsterdam";
        case BRUSSELS:
            return "Brussels";
        case FRANKFURT:
            return "Frankfurt";
        case PRAGUE:
            return "Prague";
        default:
            return "Unknown City";
    }
}

/*
 * Function: parseFile
 * -------------------
 *   It reads data from fileName and parse it into matrix.
 *
 *   fileName: the filename of the data file
 *   matrix: the adjacency matrix that store the graph info
 *
 *   returns: the result of the process
 */

int parseFile(char* fileName, int** matrix) {
	char line[64]; 
	char delimiter[] = " ";
	int oriCity, destCity, distance;
	if (matrix == NULL) {
		return 1;
	}

	FILE* file = fopen(fileName,"r");
	if (file == NULL) {
		return 1;
	}

	while(fgets(line, 64, file)){ /* read file line by line */
		char* strOriCity = strtok(line, delimiter); /* split the line and get strOriCity */
		char* strDestCity = strtok(NULL, delimiter); /* split the line and get strDestCity */
		char* dist = strtok(NULL, delimiter); /* split the line and the distance */
		
		oriCity = getIntCity(strOriCity);
		destCity = getIntCity(strDestCity);
		distance = atoi(dist);
		
		matrix[oriCity][destCity] = distance;
	} 	

	fclose(file);
	return 0;
}

/*
 * Function: displayCitySelection
 * ------------------------------
 *   It displays the cities from which to select.
 *
 *   citiList: the city list
 *
 *   returns: the result of the process
 */

int displayCitySelection(bool cityList[]) {
	int i;
    printf("\n\nPlease select a city.\n");
    printf("Enter a number associated with one of the cities below:\n\n");
    for(i=0; i<CITIES; i++){
        if(cityList[i] == false) {
            char* city = getStrCity(i);
            printf("%s\t---\t%d\n", city, i);
        }
    }
    printf("\nTO QUIT ENTER\t--\t%d\n", CITIES);

	return SUCCESS;	
}

/*
 * Function: getUserInput
 * ----------------------
 *   It gets input from user
 *
 *   cityList: the city list
 */

int getUserInput(bool cityList[]) {
	int city;
	scanf("%d", &city);
	if(city>=0 && city <CITIES) {
		cityList[city] = true;;
		return city;
	} else if (city == CITIES) {
		printf("Bye bye.\n");
		return city;
	} else {
		// city < 0 or city > CITIES, which is an invalid input
		printf("Invalid City Number.\n");
		exit(1);
	}
}

/*
 * Fucntion: showEdgeMessage
 * -------------------------
 *   It shows the edge message.
 *
 *   ori: origin city
 *   dest: dest city
 *   matrix: the adjacency matrix
 * */

void showEdgeMessage(int ori, int dest, int** matrix) {
	// show if there is an edge between the ori city and the dest city
	if (matrix == NULL) {
		exit(1);
	}
	int distance = matrix[ori][dest];
	if(distance == NO_ROUTE) {
		printf("\n\nThere is no edge between the selected two cities.\n\n");
	} else {
		printf("\n\nThe distance between the selected two cities is %dkm.\n\n", distance);
	}
}

/* Function: displayAndInteract
 * ----------------------------
 *  It displays and interacts with the user
 *
 *  matrix: the adjacency matrix
 */

int displayAndInteract(int** matrix) {
	while(true) {
		// create a list of cities
		bool cityList[CITIES] = {false, false, false, false, false, false, false, false, false, false, false};

	    // display the cities from which to select
		displayCitySelection(cityList);
		printf("Enter the origin city: ");
	    int ori = getUserInput(cityList);
		if(ori==CITIES){
			break;
		}
	
	    displayCitySelection(cityList);
	    printf("Enter the destination city: ");
	    int dest = getUserInput(cityList);
		if(dest==CITIES){
			break;
		}

	    showEdgeMessage(ori, dest, matrix);
	}
	return SUCCESS;
}
