#ifndef TASK3_MATRIX_H
#define TASK3_MATRIX_H

/*
 * Aufgabe 3: Dynamische Matrizen
 *
 * Implementiere die folgenden Funktionen in task3_matrix.c
 * Alle Matrizen sind als int** (Array von Zeigern) dargestellt.
 */

/*
 * Allokiert eine rows x cols Matrix und initialisiert alle Werte auf 0.
 * Gibt NULL bei Speicherfehler zurueck.
 * Bei Fehler: kein Speicherleck (sauberes Cleanup).
 */
int **matrix_create(int rows, int cols);

/*
 * Gibt den gesamten Speicher der Matrix frei.
 * NULL-sicher.
 */
void matrix_free(int **m, int rows);

/*
 * Multipliziert jedes Element der Matrix mit 'factor' (in-place).
 */
void matrix_scale(int **m, int rows, int cols, int factor);

/*
 * Addiert zwei gleichgrosse Matrizen a und b und gibt das Ergebnis
 * als neu allokierte Matrix zurueck.
 * NULL bei Speicherfehler.
 */
int **matrix_add(int **a, int **b, int rows, int cols);

/*
 * Gibt 1 zurueck wenn die Matrix symmetrisch ist (m[i][j] == m[j][i]
 * fuer alle i, j), sonst 0. Nur fuer quadratische Matrizen.
 * NULL oder n <= 0 -> 0.
 */
int matrix_is_symmetric(int **m, int n);

/*
 * Berechnet die Summe der Haupt-Diagonale (m[0][0] + m[1][1] + ...).
 * Nur fuer quadratische Matrizen.
 * NULL oder n <= 0 -> 0.
 */
int matrix_trace(int **m, int n);

#endif /* TASK3_MATRIX_H */
