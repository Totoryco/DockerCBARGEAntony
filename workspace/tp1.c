#include <stdio.h>

double prix_du_billet = 0;

double calculPrixBillet(double prix_plein_tarif, int age_enfant) {
    if (age_enfant < 2) {
        prix_du_billet = prix_plein_tarif/10;
    }
    else {
        if(age_enfant < 12) {
            prix_du_billet = prix_plein_tarif/2;
        }
        else {
            prix_du_billet = prix_plein_tarif;
        }
    }
    return prix_du_billet;
}

void avecQuelsDes(int N){
    /* N est entre 3 et 18*/
    if(N<=18 && N>=3){
        for(int D1=1; D1<=6; D1 ++){
            for(int D2=1; D2<=6; D2 ++){
                int D3 = N-D1-D2;
                if ((D3 <= 6) && (D3 >= 1)) {
                    printf("%d", D1); 
                    printf("%d", D2); 
                    printf("%d", D3); 
                    printf("\n");
                }
            }
        }
    }
}

int estParfait(int D){
    /* D est positif */
    int sum = 0;
    if(D>=0){
        for(int div=1; div<=D/2; div++){
            if (D%div == 0) {
                sum += div;
            }
        }
        if(sum == D){
            return 1;
        }
    }
    return 0;
}

void afficheNombresParfaits(int N){
    /* N est positif */
    for(int n=1; n<=N; n ++){
        if (estParfait(n) == 1) {
            printf("%d", n);
            printf("\n");
        }
    }
}

typedef short TypeEntier;
TypeEntier factorielle(TypeEntier N){
    if (N == 0) {
        return 1;
    }
    return factorielle(N-1)*N;
}


int main(void){
    // printf("%lf", calculPrixBillet(48.0,8));
    // printf("\n");
    // printf("%lf", calculPrixBillet(48.0,1));
    // printf("\n");
    // printf("%lf", calculPrixBillet(48.0,15));
    // printf("\n");
    // avecQuelsDes(4);
    // printf("\n");
    // avecQuelsDes(3);
    // printf("\n");
    // avecQuelsDes(12);
    // printf("\n");
    // avecQuelsDes(8);
    // printf("\n");
    // afficheNombresParfaits(32);
    // printf("\n");
    // afficheNombresParfaits(45);
    // printf("\n");
    // afficheNombresParfaits(1378);
    // printf("\n");
    printf("%d", factorielle(9));
    printf("\n");
    return 0;
}
