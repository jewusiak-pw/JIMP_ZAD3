#include "bibl.h"

#include <math.h>               /* dzieki temu kompilator sprawdzi, czy
                                 * dobrze uzywamy funkcji sqrt */
#include <malloc.h>

/* Definicje funkcji */

/*
 * read: czyta z pliku p wektor double v[], nie dluzszy niz max_l_e elementow
 * w v musi byc miejsce na co najmniej n elementow zwraca liczbe             
 * przeczytanych elemento w razie sukcesu, -1 w razie bledu                  
 *                                                                           
 * Format wektora w pliku - np.:  5 [ 0.1 1.2 2.3 3.4 4.5 ]                  
 */
int read(FILE *p, double v[], int max_l_e) {
    int n, i;   /* zmienne robocze */

    if (fscanf(p, "%i", &n) != 1 || n <= 0 || n > max_l_e) {        /* probujemy przeczytac
                                                                         * liczbe elementow */
        /*
         * nie udalo sie (fscanf zwrocila wartosc inna niz 1 lub
         * wczytana wartosc jest niedodatnia albo zbyt duza )
         */
        return -1;
    }
    while ((i = fgetc(p)) == ' ')   /* pomijamy spacje po liczbie
                                         * elementow */
        ;

    /* mamy znak rozny od spacji - powinien to byc znak '[' */
    if (i != '[')
        return -1;      /* nie jest - bledny format pliku */

    /* teraz czytamy n liczb */
    for (i = 0; i < n; i++)
        if (fscanf(p, "%lf", &(v[i])) != 1)      /* fscanf powinno zawsze
                                                         * zwracac 1 - jesli
                                                         * zwroci cos innego */
            return -1;      /* to znaczy, ze format pliku jest
                                         * zly */

    /* mamy liczby, teraz szukamy zamykajacego nawiasu: */
    while ((i = fgetc(p)) == ' ')   /* pomijamy spacje */
        ;

    /* mamy znak rozny od spacji - powinien to byc znak ']' */
    if (i != ']')
        return -1;      /* nie jest - bledny format pliku */

    /*
     * jesli doszlismy juz tu, to wszystko jest ok, mamy w wektorze n
     * liczb
     */
    return n;
}

/*
 * L2: oblicza norme L2 (pierwiastek z sumy kwadratow) wektora double v[] o
 * dlugosci n
 */
double L2(double v[], int n) {
    int i;
    int l2 = 0; /* wazne jest, aby nadac l2 wartosc
                                 * poczatkowa */
    for (i = 0; i < n; i++)
        l2 += v[i] * v[i];
    return sqrt(l2);
}

/*
 * dot_product: oblicza iloczyn skalarny wektorow double v[] i u[] v i u maja
 * dlugosc n
 */
double dot_product(double v[], double u[], int n) {
    int i;
    double dp = 0; /* wazne jest, aby nadac dp wartosc
                                 * poczatkowa */
    for (i = 0; i < n; i++)
        dp += v[i] * u[i];
    return dp;
}


/* Funkcje z ZAD3 */

/* (podpunkt 1)
 * L1: Oblicza normę L1 wektora (podpunkt 1)
 */
double L1(double *v, int n) {
    double sum = 0;

    while (n--)
        sum += v[n] < 0 ? v[n] * (-1.) : v[n];
    return sum;
}


/* (podpunkt 2)
 * SumaWektorow: Zwraca wektor sumy wektorów v1[n] i v2[n], a następnie zwraca wektor sumy
 */
double *SumaWektorow(double *v1, double *v2, int n) {

    double *s = (double *) malloc(n * sizeof(double));

    for (int i = 0; i < n; i++)
        s[i] = v1[i] + v2[i];

    return s;
}


/* (podpunkt 5)
 * Normalizuj: Zwraca wektor v[n] znormalizowany funkcją f, bądź NULL jeżeli norma = 0 (nie można dzielić przez 0)
 */
double *Normalizuj(double (*f)(double *, int), double *v, int n) {
    double *s = (double *) calloc(n, sizeof(double));
    double norm = f(v, n);
    if (norm == 0)
        return NULL;


    for (int i = 0; i < n; i++)
        s[i] = v[i] / norm;
    return s;
}


/* (podpunkt 8)
 * readCF: Zwraca liczbę odczytanych elementów typu double do wskaźnika v z wejścia p
 * o formacie dl <x, x, ...,x> gdzie dl - długość, x - kolejne wartości.
 * Zwraca -1 jeżeli:
 *      format wejścia jest zły lub
 *      dl > max_length lub
 *      wczytano <= 0 elementów
 */
int readCF(FILE *ind, double *v, int max_length) {
    int n, a, c;

    if (fscanf(ind, "%i", &n) != 1 || n <= 0 || n > max_length) //czy plik ok
        return -1;


    while ((c = fgetc(ind)) == ' ') {} //pomiń spcje

    if (c != '<')
        return -1;

    for (int i = 0; i < n; i++) {
        if (fscanf(ind, "%lf", &v[i]) != 1)
            return -1;
        while ((c = fgetc(ind)) == ',') {}
    }

    if (c == ' ')
        while ((c = fgetc(ind)) == ' ') {} //pomiń spcje

    if (c != '>')
        return -1;

    return n;
}


/* (podpunkt 9)
 * CzyOrtogonalne: Funkcja (z podpunktu 9) zwracająca:
 *     -1 - dla n1 != n2
 *      0 - dla nieortagonalnych v1[n1] i v2[n2]
 *      1 - dla ortagornalnych v1[n1] i v2[n2]
 */
int CzyOrtogonalne(double *v1, double *v2, int n1, int n2) {

    return n1 == n2 ? (dot_product(v1, v2, n1) == 0 ? 1 : 0) : -1;

}



/* Funkcje pomocnicze */

/* Wypisuje wektor ( x x ...)*/
void wypisz_wektor(double *v, int n) {
    printf("( ");
    while(n--)
        printf("%f ", *v++);

    printf(")\n");

}

/* zerowa: Zwraca 0 - dla pokazania działania funkcji CzyOrtogonalne */
double zerowa(double *v, int n) {
    return 0;
}
