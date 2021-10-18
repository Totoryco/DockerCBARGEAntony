#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


struct StructMatrice{
    int nbLignes;
    int nbColonnes;
    int* matrice;
};

typedef struct StructMatrice Matrix;

Matrix readMatrix(){
    Matrix matrice;
    int nombreLignes, nombreColonnes;
	scanf("%i %i \n", &nombreLignes, &nombreColonnes);
    matrice.nbLignes = nombreLignes;
    matrice.nbColonnes = nombreColonnes;
    //matrice.matrice = malloc(nombreLignes * nombreColonnes * sizeof(int));
    for(int ligne = 0; ligne < nombreLignes -1 ; ligne++){
        for(int colonne = 0; colonne < nombreColonnes -1 ; colonne++){
            scanf("%i" , matrice.matrice[ligne*nombreColonnes + colonne]);
            printf("%ls" , matrice.matrice[ligne*nombreColonnes + colonne]);
        }
        scanf("%i \n" , matrice.matrice[ligne*(nombreColonnes -1) + nombreColonnes -1]);
        printf("%ls \n" , matrice.matrice[ligne*(nombreColonnes -1) + nombreColonnes -1]);
    }
    scanf("%i \n" , matrice.matrice[(nombreLignes -1)*(nombreColonnes-1)]);
    printf("%ls \n" , matrice.matrice[(nombreLignes -1)*(nombreColonnes-1)]);
	return matrice;
}

// Matrix* readMatrixArray(){
//     int nbMatrice;
//     scanf("%i\n",&nbMatrice);
// 	Matrix *MatrixArray;
//     MatrixArray = calloc(nbMatrice, sizeof(Matrix));
//     for(int numMatrice=0; numMatrice < nbMatrice; numMatrice++){
//         MatrixArray[numMatrice] = readMatrix();
// 	}
//     return MatrixArray;
// }

// void printMatrix(Matrix* matrice){
// 	for(int ligne=0; ligne< matrice->nbLignes; ligne++){
//         for(int colonne=0; colonne< matrice->nbColonnes; colonne++){
// 		    printf("%d \n", matrice->matrice[ligne*(matrice->nbColonnes-1) + colonne]);
//         }
// 	}
// }

// void printMatrixArray(Matrix* matriceArray){
//     for(int numMatrice=0; numMatrice < matriceArray->nbMatrice; numMatrice++){
//         printMatrix(matriceArray[numMatrice]);
// 	}
// }

int main(void)
{
    readMatrix();
    // Matrix *matriceArray = readMatrixArray();
	// printMatrixArray(matriceArray);
    // free(matriceArray);
	return EXIT_SUCCESS;
}