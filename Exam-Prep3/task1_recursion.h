#ifndef TASK1_RECURSION_H
#define TASK1_RECURSION_H

/*
 * Aufgabe 1: Rekursion
 *
 * Implementiere die folgenden Funktionen in task1_recursion.c
 * Keine Schleifen erlaubt -- nur Rekursion.
 */

/*
 * Gibt die n-te Fibonacci-Zahl zurueck (0-indiziert).
 *   fib(0) = 0, fib(1) = 1, fib(2) = 1, fib(3) = 2, ...
 * n < 0 -> -1
 */
long long fib(int n);

/*
 * Gibt die Summe aller Ziffern einer nicht-negativen Ganzzahl zurueck.
 *   digit_sum(1234) = 10
 *   digit_sum(0)    = 0
 */
int digit_sum(int n);

/*
 * Binaere Suche: Gibt den Index von 'target' im sortierten Array zurueck.
 * Gibt -1 zurueck wenn nicht gefunden.
 * Erster Aufruf: low=0, high=length-1
 */
int binary_search(const int *arr, int low, int high, int target);

/*
 * Gibt die Anzahl der Vorkommen von 'c' im String 's' zurueck.
 * NULL -> 0
 *   count_char("hello", 'l') = 2
 */
int count_char(const char *s, char c);

#endif /* TASK1_RECURSION_H */
