#include <stdio.h>
#include <stdlib.h>
#include "bibl.h"               /* dzieki temu kompilator moze sprawdzic, czy
                                 * dobrze wywolujemy funkcje z naszej
                                 * biblioteki */


int main(int argc, char *argv[]) {
    double w_1[10];
    double w_2[10];
    int n1;
    int n2;

    FILE *we = argc > 1 ? fopen(argv[1], "r") : stdin;

    if (we == NULL) {
        fprintf(stderr, "Plik wejsciowy %s nie istnieje!\n", argv[1]);
        exit(1);
    }



//PRACA NA W_1

   n1 = readCF(we, w_1, 10);   //czytamy wg formatu z podpunktu 8

    if (n1 > 0) {
        printf("\nWczytano %i-elementowy wektor w_1:\n", n1);
        wypisz_wektor(w_1, n1);
    } else {
        fprintf(stderr, "\nWystapil blad przy wczytywaniu wektora: kod bledu=%i\n", n1);
        return 1;
    }

    printf("Norma L1 wczytanego wektora = %f\n", L1(w_1, n1));

    printf("\n\n");



//PRACA NA W_2

    n2 = readCF(we, w_2, 10);    //czytamy wg formatu z podpunktu 8

    if (n2 > 0) {
        printf("Wczytano %i-elementowy wektor w_2:\n", n2);
        wypisz_wektor(w_2, n2);
    } else {
        fprintf(stderr, "Wystapil blad przy wczytywaniu wektora: kod bledu=%i\n", n2);
        return 1;
    }


    printf("Norma L1 wczytanego wektora = %f\n", L1(w_2, n2));

    printf("\n\n");

//PRACA NA OBU



    //Sumowanie wektorów

    if (n1 == n2) {
        printf("Suma w_1 i w_2: \n");
        wypisz_wektor(SumaWektorow(w_1,w_2, n1), n1);
    } else {
        printf("Wczytane wektory maja rozna dlugosci i nie mozna ich zsumować\n");
    }
    printf("\n\n");

    //Normalizacja L1

    printf("Wynik normalizacji po L1:\n");
    double *w_1_n_L1=Normalizuj(&L1, w_1, n1); //normalizacja po funkcji normy L1
    if(w_1_n_L1!=NULL){
        printf("Znormalizowany wektor w_1 po funkcji normy L1:\n");
        wypisz_wektor(w_1_n_L1, n1);
    } else {
        printf("Normalizacja nieudana - norma = 0 (nie można dzielić przez zero).\n");
    }


    printf("\nWynik normalizacji po funkcji zerowej:\n");
    double *w_1_n_zerowa=Normalizuj(&zerowa, w_1, n1); //romalizacja po funkcji "zerowa" zwracającej zawsze 0 jako normę
    if(w_1_n_zerowa!=NULL){
        printf("Znormalizowany wektor w_1 po funkcji \"zerowa\" zwracającej zawsze 0:\n");
        wypisz_wektor(w_1_n_zerowa, n1);
    } else {
        printf("Normalizacja nieudana - norma = 0 (nie można dzielić przez zero).\n");
    }


    printf("\n\n");

    printf("Wektory w_1 i w_2 są ");
    switch(CzyOrtogonalne(w_1, w_2, n1, n2)){
        case 0:
            printf("nieortogonalne.\n");
            break;
        case 1:
            printf("ortogonalne.\n");
            break;
        case -1:
            printf("nierównej długości, nie można stwierdzić ortogonalności.\n");
            break;
     }



    return 0;
}
