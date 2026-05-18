#ifndef RECURSION_H
#define RECURSION_H

/*
 * Berechnet rekursiv die Summe aller Zahlen von 1 bis n.
 * Beispiel:
 * n = 5 -> 15
 */
int recursive_sum(int n);

/*
 * Berechnet rekursiv die Anzahl gerader Zahlen im Array.
 */
int recursive_count_even(const int *arr, int size);

/*
 * Prüft rekursiv ob ein String nur aus Ziffern besteht.
 */
int recursive_is_number(const char *text);

/*
 * Berechnet rekursiv x hoch n.
 */
long long recursive_power(int x, int n);

#endif