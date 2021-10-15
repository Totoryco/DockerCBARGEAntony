#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>

void echangeContenu(int *a,int *b){
    int c = (*a);
    (*a) = (*b);
    (*b) = c;
};

bool estConvexe(bool tab[], int length){
    for (int i = 0; i < length ; i++){
        if (tab[i]) {
            if (i == 0){
                if ((tab[length-1] != tab[i]) && (tab[i+1] != tab[i])) {
                    return false;
                }
            }
            else{
                if (i == length-1){
                    if ((tab[0] != tab[i]) && (tab[i-1] != tab[i])) {
                        return false;
                    }
                }
                else{
                    if ((tab[i-1] != tab[i]) && (tab[i+1] != tab[i])) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
};

void affiche_matrice(int64_t matrice[5][5]){
    for (int16_t colonne = 0; colonne < 5; colonne ++){
        for (int16_t ligne = 0; ligne < 5; ligne ++){
            printf("%5li", matrice[ligne][colonne]);
        }
        printf("%s", "\n");
    }
};

void mult_matrice(int64_t matriceRes[5][5],int64_t matrice1[5][5],int64_t matrice2[5][5]){
    for (int16_t colonne = 0; colonne < 5; colonne ++){
        for (int16_t ligne = 0; ligne < 5; ligne ++){
            matriceRes[ligne][colonne] = 0;
            for (int16_t k = 0; k < 5; k ++){
                matriceRes[ligne][colonne] += matrice1[ligne][k]*matrice2[k][colonne];
            }
        }
    }
};

enum MesMois {
    janvier = 1,
    fevrier,
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre
};

typedef enum MesMois Mois;

struct DateSimple{
    int jourNum;
    Mois mois;
    int annee;
};

typedef struct DateSimple Date;

void initialiseDate(Date *date){
    printf("Entrer le numero du jour: ");
    scanf("%i", &date->jourNum);
    printf("Entrer le mois: ");
    scanf("%i", (int *)&date->mois);
    printf("Entrer l'annee: ");
    scanf("%i", &date->annee);
};

Date creerDateParCopie(){
    Date date;
    printf("Entrer le numero du jour: ");
    scanf("%i", date.jourNum);
    printf("Entrer le mois: ");
    scanf("%i", (int *)date.mois);
    printf("Entrer l'annee: ");
    scanf("%i", date.annee);
    return date;
}

Date* newDate(){
    Date* pDate = (Date*)malloc(sizeof(Date));
    if (pDate){
        initialiseDate(pDate);
    }
    return pDate;
}

void afficheDate(Date *date){
    printf("%i", &date->jourNum);
    printf("%s", " ");
    printf("%i", (int *)&date->mois);
    printf("%s", " ");
    printf("%i", &date->annee);
};

int main(void){
    // int a = 10,b = 20;
    // echangeContenu(&a,&b);
    // printf("%s", "a = ");
    // printf("%d", a);
    // printf("%s", "\nb = ");
    // printf("%d", b);
    // printf("%s", "\n");
    // bool T1[5] = {false, true, true, false, false};
    // bool T2[5] = {true, true, false, false, false};
    // bool T3[5] = {true, true, false, true, false};
    // printf("%s\n", estConvexe(T1,5) ? "true" : "false");
    // printf("%s\n", estConvexe(T2,5) ? "true" : "false");
    // printf("%s\n", estConvexe(T3,5) ? "true" : "false");
    // int64_t matrice1[5][5]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
    // int64_t matrice2[5][5]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
    // int64_t matriceRes[5][5];
    // affiche_matrice(matrice2);
    // mult_matrice(matriceRes,matrice1,matrice2);
    // affiche_matrice(matriceRes);
    Date d;
    initialiseDate(&d);
    afficheDate(&d);
    d = creerDateParCopie();
    afficheDate(&d);
    return 0;
}