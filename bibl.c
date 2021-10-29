#include "bibl.h"

#include <math.h>               /* dzieki temu kompilator sprawdzi, czy
                                 * dobrze uzywamy funkcji sqrt */

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


/* Wypisuje wektor */
void wypisz_wektor(double v[], int n){
    printf("( ", n);
    for (int i = 0; i < n; i++)
        printf("%f ", v[i]);
    printf(")\n");

}


/* L1: Oblicza norme L1 wektora */
double L1(double v[], int n) {
    double sum = 0;

    while (n--)
        sum += v[n] < 0 ? v[n] * (-1.) : v[n];
    return sum;
}


/* SumaWektorow: Oblicza sumę wektorów v1[] i v2[] o długości n, przyjmuje wskaźnik na wektor s w którym znajdą się zsumowane elementy */
void SumaWektorow(double *s, double v1[], double v2[], int n) {
    for(int i=0; i<n; i++)
        *s++ = v1[i] + v2[i];
}

/* Normalizuj: Normalizuje funkcją double f(double) wektor, wczytywany wskaźnikiem v */
void Normalizuj(double (*f)(double), double *v, int n){
    while(n--)
        *v++ = f(*v);
}

