#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedListOfMusic.h"

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste listeCreee = malloc(sizeof(Cellule));
	listeCreee->suiv = NULL;
	listeCreee->val = v;
	return listeCreee;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste nouvelleListe = creer(v);
	nouvelleListe->suiv = l;
	return nouvelleListe;
}


// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Liste p = l;

	while(!estVide(p)) {
		afficheElement(p->val);
		p=p->suiv;
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	afficheElement(l->val);
	if (! estVide(l->suiv))
		afficheListe_r(l->suiv);
	else
		printf("\n");
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste temp;
	while(! estVide(l)){
		temp = l;
		l = l->suiv;
		detruireElement(temp->val);
		free(temp);
	};
}

// version récursive
void detruire_r(Liste l) {
	if (! estVide(l->suiv)){
		detruire_r(l->suiv);
		detruireElement(l->val);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste temp = l;
	if (estVide(temp))
		return creer(v);
	while(! estVide(temp->suiv))
		temp = temp->suiv;
	temp->suiv = creer(v);
	return l;
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if (estVide(l))
		return creer(v);
	else
		l->suiv = ajoutFin_r(v,l->suiv);
	return l;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	while(!estVide(l) && !equalsElement(l->val, v)){
		l = l->suiv;
	};
	return l;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if (estVide(l))
		return l;
	if (equalsElement(l->val, v))
		return l;
	return cherche_r(v, l->suiv);
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste precedent, temp;
	if (estVide(l))
		return l;
	if(equalsElement(l->val,v)){
		temp = l->suiv;
		l->suiv = NULL;
		detruire_r(l);
		return temp;
	}
	precedent = l;
	temp = l->suiv;
	while(!estVide(temp) && !equalsElement(temp->val,v)){
		precedent = temp;
		temp = temp->suiv;
	}
	if (!estVide(temp)){
		precedent->suiv = temp->suiv;
		temp->suiv = NULL;
		detruire_r(temp);
	}
	return l;
}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if (estVide(l))
		return l;
	if(equalsElement(l->val,v)){
		Liste temp = l->suiv;
		l->suiv = NULL;
		detruire_r(l);
		return temp;
	}
	l->suiv = retirePremier_r(v,l->suiv);
	return l;
}


// void afficheEnvers_r(Liste l) {
// 	TODO;
// }


/* This function scans a line of text (until \n) and returns an element that contains the music of the line (255 max char) excluding \n.
It also ensures the \0 and , terminations.
**WARNING**: The result of this function has been allocated (calloc) by the function */
Element scanLine(FILE* fichier)
{
	Music* musique = (Music *) malloc(sizeof(Music));
	int maxLineSize = 255;
	char* first = calloc(maxLineSize+1,sizeof(char));
	if ( (first = fgets(first,maxLineSize,fichier)) != NULL){
		char* ligne = strdup(first);
		musique->name = strsep(&ligne, ",");
		musique->artist = strsep(&ligne, ",");
		musique->album = strsep(&ligne, ",");
		musique->genre = strsep(&ligne, ",");
		musique->discNumber = atoi(strsep(&ligne, ","));
		musique->trackNumber = atoi(strsep(&ligne, ","));
		musique->year = atoi(ligne);
		free(first);
		return musique;
	}
	free(first);
	return NULL;
	
}

// Renvoie une liste de musiques construite à partir du fichier CSV des musiques
MusicList lireCSV() {
	FILE* fileCSV = fopen("music.csv", "r");
	printf("Ouverture du fichier\n");
	Element temp = scanLine(fileCSV);
	MusicList mesMusiques = (Cellule *) malloc(sizeof(Cellule));
	mesMusiques->suiv = NULL;
	mesMusiques->val = (Music *) malloc(sizeof(Music));
	if (fileCSV != NULL)
    {
		while ( (temp = scanLine(fileCSV)) != NULL) {
			ajoutFin_r(temp, mesMusiques);
		}
        fclose(fileCSV);
    }
	return mesMusiques;
}

bool estPlusRecent(Element e1, Element e2){
	Music *m1 = (Music *) e1;
	Music *m2 = (Music *) e2;
	return (m1->year < m2->year);
}

void echangeValeur(Element a,Element b){
    Element c = a;
    a = b;
    b = c;
};

// Change la liste en la triant par ordre d'année croissant
void trierParAnnee(MusicList l){
	if (!estVide(l)){
		Liste temp;
		temp = l->suiv;
		if(!estVide(temp)){
			if(!estPlusRecent(l->val,temp->val)){
				echangeValeur(l->val,temp->val);
			}
			trierParAnnee(l->suiv);
		}
	}
}



