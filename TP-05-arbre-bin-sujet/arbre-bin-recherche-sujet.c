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
		if (e < arbreTempo->val){
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
	return 1 + nombreDeNoeud(a->filsGauche) + nombreDeNoeud(a->filsDroit);
}

// retourne la profondeur du noeud ayant la valeur e dans a
// retourne -1 si a est vide ou si e n'est pas dans a 
int profondeur(ArbreBinaire a, Element e){
	ArbreBinaire arbreTempo;
	int prof;
	if (!estVide(a)){
		arbreTempo = a;
		prof = 1;
		while (!(estVide(arbreTempo))){
			if(arbreTempo->val == e)
				return prof;

			if (e < arbreTempo->val){
				if(!estVide(arbreTempo->filsGauche)){
					prof++;
					arbreTempo = arbreTempo->filsGauche;
				}
				else
					return -1;
			}
			else{
				if(!estVide(arbreTempo->filsDroit)){
					prof++;
					arbreTempo = arbreTempo->filsDroit;
				}
				else
					return -1;
			}
		}
	}
	return -1;
}

int maxOf(int a, int b){
	if (a>b)
		return a;
	return b;
}

// retourne la hauteur de l'arbre a
int hauteur(ArbreBinaire a){
	if(estVide(a))
		return 0;
	return 1 + maxOf(nombreDeNoeud(a->filsGauche),nombreDeNoeud(a->filsDroit));
}

// retourne le pere de e dans l'arbre a ou NULL s'il n'existe pas
ArbreBinaire pere(ArbreBinaire a, Element e){
	ArbreBinaire arbreTempo, arbrePrecedent;
	if (!estVide(a)){
		arbreTempo = a;
		arbrePrecedent = NULL;
		while (!estVide(arbreTempo)){
			if(arbreTempo->val == e)
				return arbrePrecedent;

			arbrePrecedent = arbreTempo;
			if (e < arbreTempo->val){
				arbreTempo = arbreTempo->filsGauche;
			}
			else{
				arbreTempo = arbreTempo->filsDroit;
			}
		}
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
	ArbreBinaire arbreTempo;
	if(estVide(a))
		return NULL;
	arbreTempo = a;
	while(!estVide(arbreTempo->filsGauche)){
		arbreTempo = arbreTempo->filsGauche;
	}
	return arbreTempo;
}

// retourne le noeud dont la valeur est maximum dans l'arbre
// Suppose que a est un arbre binaire de recherche sans doublons
ArbreBinaire max(ArbreBinaire a){
	ArbreBinaire arbreTempo;
	if(estVide(a))
		return NULL;
	arbreTempo = a;
	while(!estVide(arbreTempo->filsDroit)){
		arbreTempo = arbreTempo->filsDroit;
	}
	return arbreTempo;
}


// retourne l'arbre dont la valeur de la racine est e et NULL si e n'est pas dans a 
// version récursive
ArbreBinaire recherche_r(ArbreBinaire a, Element e){
	if (estVide(a))
		return NULL;
	if(a->val == e)
		return a;
	else {
		if (e < a->val){
			return recherche_r(a->filsGauche, e);
		}
		else{
			return recherche_r(a->filsDroit, e);
		}
	}
}


// supprime x de a
ArbreBinaire supprimer_r(ArbreBinaire a,Element x){
	if(estVide(a))
		return NULL;
	if(a->val == x){
		if (!estVide(a->filsDroit)){
			a->filsDroit->filsGauche = a->filsGauche;
			a = a->filsDroit;
			return a;
		}
		else{
			a = a->filsGauche;
			return a;
		}
	}
	else {
		if (x < a->val){
			a->filsGauche = supprimer_r(a->filsGauche, x);
		}
		else{
			a->filsDroit = supprimer_r(a->filsDroit, x);
		}
	}
	return a;
}

void detruire_r(ArbreBinaire a){
	if(!estVide(a)){
		detruire_r(a->filsGauche);
		detruire_r(a->filsDroit);
		a = supprimer_r(a, a->val);
		free(a);
	}
}

