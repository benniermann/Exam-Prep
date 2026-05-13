#ifndef TASK1_REKURSION_H
#define TASK1_REKURSION_H

/*
 * Aufgabe 1: Rekursion
 *
 * Implementiere die folgenden Funktionen in task1_rekursion.c.
 * Alle Funktionen muessen rekursiv implementiert werden.
 */

/*
 * Berechnet x hoch n durch schnelles Potenzieren (Exponentiation by Squaring).
 * Teilt das Problem bei jedem Schritt durch 2 statt um 1 zu reduzieren.
 * Komplexitaet: O(log n) statt O(n).
 * n >= 0 wird vorausgesetzt.
 * Beispiele:
 *   fast_power(2, 0)  -> 1
 *   fast_power(2, 10) -> 1024
 *   fast_power(3, 4)  -> 81
 *   fast_power(5, 3)  -> 125
 */
long long fast_power(long long x, int n);

/*
 * Berechnet den groessten gemeinsamen Teiler (ggT) von a und b
 * mit dem euklidischen Algorithmus (rekursiv).
 * Formel: gcd(a, 0) = a,  gcd(a, b) = gcd(b, a % b)
 * Beispiele:
 *   gcd(12, 8)   -> 4
 *   gcd(7, 3)    -> 1
 *   gcd(100, 75) -> 25
 *   gcd(0, 5)    -> 5
 */
int gcd(int a, int b);

/*
 * Berechnet die Quersumme einer nicht-negativen ganzen Zahl rekursiv.
 * digit_sum(n) = (n % 10) + digit_sum(n / 10)
 * Basisfall: n <= 0 -> 0
 * Beispiele:
 *   digit_sum(0)   -> 0
 *   digit_sum(5)   -> 5
 *   digit_sum(123) -> 6   (1+2+3)
 *   digit_sum(999) -> 27
 *   digit_sum(100) -> 1
 */
int digit_sum(int n);

/*
 * Rekursive Binaersuche in einem sortierten Integer-Array.
 * Gibt den Index des Zielwerts zurueck, -1 wenn nicht gefunden.
 * Parameter: arr = Array, low/high = aktueller Suchbereich (inklusiv), target = gesuchter Wert
 * Beispiele (arr = {1,3,5,7,9,11,13}):
 *   binary_search(arr, 0, 6, 1)  -> 0
 *   binary_search(arr, 0, 6, 7)  -> 3
 *   binary_search(arr, 0, 6, 13) -> 6
 *   binary_search(arr, 0, 6, 6)  -> -1
 */
int binary_search(const int *arr, int low, int high, int target);

/*
 * Zaehlt rekursiv die Anzahl der Vorkommen von Zeichen c im String s.
 * NULL oder leerer String -> 0.
 * Beispiele:
 *   count_char("hallo", 'l')  -> 2
 *   count_char("banana", 'a') -> 3
 *   count_char("hallo", 'z')  -> 0
 *   count_char("", 'a')       -> 0
 *   count_char(NULL, 'a')     -> 0
 */
int count_char(const char *s, char c);

#endif /* TASK1_REKURSION_H */
