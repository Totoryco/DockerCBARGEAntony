// gcc -W -Wall linkedListOfMusic.c mySpitofy.c -o mySpitofy

#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// ============
// Definition des fonctions externes :
// ============
void afficheElement(Element e){ 
	if (e == NULL)
		printf("Element vide\n");
	else {
		Music *m = (Music *) e; 
		printf("%s,%s,%s,%s,%d,%d,%d\n", 
		(char*) m->name,
		(char*) m->artist,
		(char*) m->album,
		(char*) m->genre,
		m->discNumber,
		m->trackNumber,
		m->year);
	}

}

void detruireElement(Element e){
}

bool equalsElement(Element e1, Element e2){
	Music *m1 = (Music *) e1;
	Music *m2 = (Music *) e2;
	return (
		strcmp((char*)m1->name, (char*)m2->name) 
		&& strcmp((char*)m1->artist, (char*)m2->artist) 
		&& strcmp((char*)m1->album, (char*)m2->album)
		&& strcmp((char*)m1->genre, (char*)m2->genre)
		&& m1->discNumber == m2->discNumber
		&& m1->trackNumber == m2->trackNumber
		&& m1->year == m2->year
	);
}

// Definition des fonctions de tests:
void verifAffichageMusique(){
	Music maMusique;
	maMusique.name = "Take it Back";
	maMusique.album = "Closure";
	maMusique.artist = "Nevoaii";
	maMusique.genre = "EDM";
	maMusique.discNumber = 10;
	maMusique.trackNumber = 29;
	maMusique.year = 2017;
	afficheElement(&maMusique);
}

void listeVide(){
	Liste maListeDeMusiques;
	maListeDeMusiques = NULL;
	printf("estVide(maListeDeMusiques) = %s\n",estVide(maListeDeMusiques)?"TRUE":"FALSE");
}

// ============
// Main
// ============
int main(void){

	listeVide();
	verifAffichageMusique();

	Liste maListeDeMusiques = lireCSV();
	afficheListe_i(maListeDeMusiques);
	// trierParAnnee(maListeDeMusiques);
	// afficheListe_r(maListeDeMusiques);

	// detruire_r(maListeDeMusiques);
	return EXIT_SUCCESS;
}