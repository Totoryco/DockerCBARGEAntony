// gcc -W -Wall -Wextra -std=c99 arbre-bin-recherche-sujet.c arbre-bin-recherche-main.c

// gcc -W -Wall -Wextra -std=c99 arbre-bin-recherche-correction.c arbre-bin-recherche-main.c

// valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./a.out

#include "arbre-bin-recherche.h"

int main(void){
	ArbreBinaire a,p;

	initialiser(&a);
	// a = NULL;
	printf("estVide(a)= %s\n",estVide(a)?"TRUE":"FALSE");
	printf("nombreDeNoeud(a)= %i\n",nombreDeNoeud(a));

	a = insere_r(a,5);
	afficheGRD_r(a);printf("\n");
	a = insere_r(a,3);
	afficheGRD_r(a);printf("\n");
	a = insere_r(a,2);
	afficheGRD_r(a);printf("\n");
	a = insere_r(a,3);
	afficheGRD_r(a);printf("\n");
	a = insere_r(a,1);
	afficheGRD_r(a);printf("\n");

	printf("nombreDeNoeud(a)= %i\n",nombreDeNoeud(a));
	printf("hauteur(a)= %i\n",hauteur(a));

	a = insere_i(a,7);
	afficheGRD_r(a);printf("\n");
	a = insere_i(a,8);
	afficheGRD_r(a);printf("\n");
	a = insere_i(a,6);
	afficheGRD_r(a);printf("\n");
	a = insere_i(a,3);
	afficheGRD_r(a);printf("\n");
	printf("nombreDeNoeud(a)= %i\n",nombreDeNoeud(a));
	printf("hauteur(a)= %i\n",hauteur(a));



	a = supprimer_r(a,6);
	afficheGRD_r(a);printf("\n");
	printf("nombreDeNoeud(a)= %i\n",nombreDeNoeud(a));

	a = supprimer_r(a,5);
	afficheGRD_r(a);printf("\n");
	printf("nombreDeNoeud(a)= %i\n",nombreDeNoeud(a));

	printf("profondeur 5 = %i\n",profondeur(a,5));
	printf("profondeur 2 = %i\n",profondeur(a,2));
	printf("profondeur 3 = %i\n",profondeur(a,3));
	printf("profondeur 1 = %i\n",profondeur(a,1));
	printf("profondeur 6 = %i\n",profondeur(a,6));
	printf("profondeur 7 = %i\n",profondeur(a,7));
	printf("profondeur NULL = %i\n",profondeur(NULL,5));
	printf("profondeur 18 = %i\n",profondeur(a,18));
	
	
	p=pere(NULL,5);
	printf("pere(NULL,5) = %i\n",p==NULL?-1:p->val);
	p=pere(a,18);
	printf("pere(18) = %i\n",p==NULL?-1:p->val);
	p=pere(a,5);
	printf("pere(5) = %i\n",p==NULL?-1:p->val);
	p=pere(a,8);
	printf("pere(8) = %i\n",p==NULL?-1:p->val);
	p=pere(a,3);
	printf("pere(3) = %i\n",p==NULL?-1:p->val);
	
	p=min(a);
	printf("minimum de a = %i\n",p==NULL?-1:p->val);
	p=max(a);
	printf("maximum de a = %i\n",p==NULL?-1:p->val);


	p=recherche_r(a, 18);
	printf("recherche(18) = %i\n",p==NULL?-1:p->val);
	p=recherche_r(NULL, 3);
	printf("recherche(NULL) = %i\n",p==NULL?-1:p->val);
	p=recherche_r(a, 3);
	printf("recherche(3) = %i\n",p==NULL?-1:p->val);
	p=recherche_r(a, 8);
	printf("recherche(8) = %i\n",p==NULL?-1:p->val);
	
	a = supprimer_r(a,18);
	printf("nombreDeNoeud(a)= %i\n",nombreDeNoeud(a));
	printf("suppression(18) : \n");afficheGRD_r(a);printf("\n");
	printf("nombreDeNoeud(a)= %i\n",nombreDeNoeud(a));
	a = supprimer_r(a,8);
	printf("suppression(8) : \n");afficheGRD_r(a);printf("\n");
	printf("nombreDeNoeud(a)= %i\n",nombreDeNoeud(a));
	a = supprimer_r(a,5);
	printf("suppression(5) : \n");afficheGDR_r(a);printf("\n");
	printf("nombreDeNoeud(a)= %i\n",nombreDeNoeud(a));

	detruire_r(a);
	// Il y a des fuites m??moires puisqu'au moment de la suppression,
	// je d??place simplement la branche pour la r??ordonner.
	// Je perds ainsi le pointeur vers le noeud et je ne sais pas comment
	// le r??cup??rer pour le free.

	return EXIT_SUCCESS;
}