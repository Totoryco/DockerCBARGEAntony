/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars until the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

struct NobelWinner{
    int year;
    char* name;
    char* description;
};

typedef struct NobelWinner Winner;


int* readWinners(){
	int nbGagnants = scanLineAsInt();
	Winner *tab;
	tab = calloc(nbGagnants, sizeof(Winner));
	
    for(int i=0; i<nbGagnants; i++){
        tab[i].year = scanLineAsInt();
        tab[i].name = scanLine();
        tab[i].description = scanLine();
	}
	return tab;
}

void printWinners(Winner *tab){
	for(int i=0; i<50; i++){
		printf("%d \n", tab[i].year);
		printf("%s \n", tab[i].name);
		printf("%s \n", tab[i].description);
	}
}

void infosAnnee(int year){
	int nbGagnants = scanLineAsInt();
	Winner *tab;
	tab = calloc(nbGagnants, sizeof(Winner));
	
    for(int i=0; i<nbGagnants; i++){
        tab[i].year = scanLineAsInt();
		tab[i].name = scanLine();
        tab[i].description = scanLine();

		if(tab[i].year == year){
			printf("L'annee %d, le(s) gagnant(s) ont été : %s \n", year, tab[i].name);
			printf("Nature des travaux : %s \n", tab[i].description);
		}
	}
}


int main(void)
{
	Winner *tab = readWinners();
	printWinners(tab);
	//infosAnnee(2003);
	//free(tab);

	return EXIT_SUCCESS;
}
