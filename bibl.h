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

/* Wypisuje wektor */
void wypisz_wektor(double v[], int n);

/* L1: Oblicza norme L1 wektora */
double L1(double v[], int n);

/* SumaWektorow: Oblicza sumę wektorów v1[] i v2[] o długości n, przyjmuje wskaźnik na wektor s w którym znajdą się zsumowane elementy */
void SumaWektorow(double *s, double v1[], double v2[], int n);

/* Normalizuj: Normalizuje funkcją double f(double) wektor, wczytywany wskaźnikiem v */
void Normalizuj(double (*f)(double), double *v, int n);

#endif

