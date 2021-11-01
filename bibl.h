#ifndef _BIBL_H_                /* zabezpieczenie przed wielokrotnym
                                 * wlaczeniem tego pliku */
#define _BIBL_H_

#include <stdio.h>

/* Prototypy funkcji */

/*
 * read: czyta z pliku p wektor double v[], nie dluzszy niz max_l_e elementow
 * w v musi byc miejsce na co najmniej n elementow zwraca liczbe
 * przeczytanych elemento w razie sukcesu, -1 w razie bledu format wektora to
 * <liczba_elementow> [ <element> ... ] np. 3 [ 1.2 4.5, 7.8]
 */
int read(FILE *p, double v[], int max_l_e);


/*
 * L2: oblicza norme L2 (pierwiastek z sumy kwadratow) wektora double v[] o
 * dlugosci n
 */
double L2(double v[], int n);

/*
 * dot_product: oblicza iloczyn skalarny wektorow double v[] i u[] v i u maja
 * dlugosc n
 */
double dot_product(double v[], double u[], int n);



/* Funkcje z ZAD3 */

/* (podpunkt 1)
 * L1: Oblicza normę L1 wektora (podpunkt 1)
 */
double L1(double *v, int n);

/* (podpunkt 2)
 * SumaWektorow: Zwraca wektor sumy wektorów v1[n] i v2[n], a następnie zwraca wektor sumy
 */
double *SumaWektorow(double *v1, double *v2, int n);

/* (podpunkt 5)
 * Normalizuj: Zwraca wektor v[n] znonmalizowany funkcją f
 */
double *Normalizuj(double (*f)(double *, int), double *v, int n);

/* (podpunkt 8)
 * readCF: Zwraca liczbę odczytanych elementów typu double do wskaźnika v z wejścia p
 * o formacie dl <x, x, ...,x> gdzie dl - długość, x - kolejne wartości.
 * Zwraca -1 jeżeli:
 *      format wejścia jest zły lub
 *      dl > max_length lub
 *      wczytano <= 0 elementów
 */
int readCF(FILE *p, double *v, int max_length);

/* (podpunkt 9)
 * CzyOrtogonalne: Funkcja (z podpunktu 9) zwracająca:
 *      0 - dla nieortagonalnych v1[n] i v2[n]
 *      1 - dla ortagornalnych v1[n] i v2[n]
 */
int CzyOrtogonalne(double *v1, double *v2, int n1, int n2);



/* Funkcje pomocnicze */

/* Wypisuje wektor ( x x ...)*/
void wypisz_wektor(double *v, int n);

/* zerowa: Zwraca 0 - dla pokazania działania funkcji CzyOrtogonalne */
double zerowa(double *v, int n);


#endif

