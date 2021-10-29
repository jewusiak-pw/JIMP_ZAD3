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
    int i;

    FILE *we = argc > 1 ? fopen(argv[1], "r") : stdin;    /* jesli argc > 1 to
                                                                         * program zostal
                                                                         * wywolany z argumentem
                                                                         * - probujemy otworzyc
                                                                         * taki plik do czytania */

    if (we == NULL) {       /* stdin != NULL, a wiec to mozliwe tylko,
                                 * gdy argv[1] zawiera cos, co nie jest nazwa
                                 * istniejacego pliku */
        fprintf(stderr, "Plik wejsciowy %s nie istnieje!\n", argv[1]);
        exit(1);
    }

//PRACA NA W_1

    n1 = read(we, w_1, 10);   /* czytamy z wejscia wektor i pakujemy go
                                 * do w_1 */

    if (n1 > 0) {
        printf("Wczytano %i-elementowy wektor:\n( ", n1);
        for (i = 0; i < n1; i++)
            printf("%f ", w_1[i]);
        printf(")\n");
    } else {
        fprintf(stderr, "Wystapil blad przy wczytywaniu wektora: kod bledu=%i\n", n1);
        return 1;
    }

    printf("Norma L2 wczytanego wektora = %f\n", L2(w_1, n1));

    printf("Norma L1 wczytanego wektora = %f\n", L1(w_1, n1));



//PRACA NA W_2

    n2 = read(we, w_2, 10);   /* czytamy z wejscia wektor i pakujemy go
                                 * do w_2 */

    if (n2 > 0) {
        printf("Wczytano %i-elementowy wektor:\n( ", n2);
        for (i = 0; i < n2; i++)
            printf("%f ", w_2[i]);
        printf(")\n");
    } else {
        fprintf(stderr, "Wystapil blad przy wczytywaniu wektora: kod bledu=%i\n", n2);
        return 1;
    }

    printf("Norma L2 wczytanego wektora = %f\n", L2(w_2, n2));

    printf("Norma L1 wczytanego wektora = %f\n", L1(w_2, n2));

//PRACA NA OBU

    if (n1 == n2) {
        printf("Iloczyn skalarny wczytanych wektorow = %f\n", dot_product(w_1, w_2, n1));
    } else {
        printf("Wczytane wektory maja rozna dlugosci i nie mozna ich pomnozyc przez siebie\n");
    }


    printf("Suma w_1 i w_2: \n");

    if (n1 == n2) {
        printf("Suma wczytanych wektorow:\n");
        double s[10];
        SumaWektorow(s ,w_1,w_2, n1);
        wypisz_wektor(s, n1);
    } else {
        printf("Wczytane wektory maja rozna dlugosci i nie mozna ich zsumować\n");
    }

    return 0;
}
