#include "arbre-bin-recherche.h"
#include <stdlib.h>
#include <stdbool.h>

// retourne TRUE si a est l'arbre vide et FALSE sinon
bool estVide(ArbreBinaire a) {
	return a == NULL;
}

// initialise l'arbre a à l'arbre vide
void initialiser(ArbreBinaire* a) {
	*a = NULL;
}

// créer un arbre contenant un seul noeud ayant la valeur e
ArbreBinaire creer(Element e) {
	ArbreBinaire a = malloc(sizeof(Noeud));
	a->val = e;
	a->filsGauche = NULL;
	a->filsDroit = NULL;
	return a;
}

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version itérative
ArbreBinaire insere_i(ArbreBinaire a, Element e) {
	ArbreBinaire nouvelArbre, arbreTempo, arbrePrecedent;
	nouvelArbre = creer(e);
	bool estAGauche; 
	if (estVide(a)){
		return nouvelArbre;
	}
	arbreTempo = a;
	while (!estVide(arbreTempo)){
		if(arbreTempo->val == e)
			return a;

		arbrePrecedent = arbreTempo;
		if (e < a->val){
			arbreTempo = arbreTempo->filsGauche;
			estAGauche = true;
		}
		else{
			arbreTempo = arbreTempo->filsDroit;
			estAGauche = false;
		}
	}
	if (estAGauche)
		arbrePrecedent->filsGauche = nouvelArbre;
	else
		arbrePrecedent->filsDroit = nouvelArbre;
	return a;
}	

// insere e dans a sachant que a est un arbre binaire de recherche
// si a contient déjà un element e, ce dernier n'est pas insérer afin d'éviter les doublons
// version récursive
ArbreBinaire insere_r(ArbreBinaire a, Element e) {
	ArbreBinaire nouvelArbre = creer(e);
	if (estVide(a)){
		return nouvelArbre;
	}

	if (a->val == e)
		return a;

	if (e < a->val)
		a->filsGauche = insere_r(a->filsGauche, e);
	else
		a->filsDroit = insere_r(a->filsDroit, e);
	return a;
}

// retourne le nombre de noeud contenus dans l'arbre a
int nombreDeNoeud(ArbreBinaire a){
	if(estVide(a))
		return 0;
	if(!estVide(a->filsDroit))
		return (nombreDeNoeud(a->filsDroit)+1);
	if(!estVide(a->filsGauche))
		return (nombreDeNoeud(a->filsGauche)+1);
	return 1;
}


// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a
int profondeur(ArbreBinaire a, Element e){
	int prof = -1;
	if(estVide(a))
		return prof;
	if(e != a->val)
		prof = profondeur(a->filsGauche, e)+1;
		prof--;
	    prof = profondeur(a->filsDroit, e)+1;
	return 0;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if(estVide(a))
		return 0;
	return 0;
}

// retourne le pere de elem dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element elem){
	ArbreBinaire arbreTempo, arbrePrecedent;
	if (estVide(a)){
		return NULL;
	}
	arbreTempo = a;
	while (!estVide(arbreTempo)){
		if(arbreTempo->val == e)
			return arbrePrecedent;

		arbrePrecedent = arbreTempo;
		pere(arbreTempo->)
	}
	return NULL;
}


void afficheRGD_r(ArbreBinaire a){
	if(!estVide(a)){
		printf("(");
		printf("%d",a->val);
		afficheGRD_r(a->filsGauche);
		afficheGRD_r(a->filsDroit);
		printf(")");
	}
}

void afficheGRD_r(ArbreBinaire a){
	if(!estVide(a)){
		printf("(");
		afficheGRD_r(a->filsGauche);
		printf("%d",a->val);
		afficheGRD_r(a->filsDroit);
		printf(")");
	}
}

void afficheGDR_r(ArbreBinaire a){
	if(!estVide(a)){
		printf("(");
		afficheGRD_r(a->filsGauche);
		afficheGRD_r(a->filsDroit);
		printf("%d",a->val);
		printf(")");
	}
}

// retourne le noeud dont la valeur est minimum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire min(ArbreBinaire a){
	return NULL;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	return NULL;
}


// retourne l'arbre dont la valeur de la racine est elem et NULL si elem n'existe dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element elem){

	return NULL;
}


// suppime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x)
{

	return NULL;
}

void detruire_r(ArbreBinaire a){

}

