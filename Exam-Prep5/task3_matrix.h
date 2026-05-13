#ifndef TASK3_MATRIX_H
#define TASK3_MATRIX_H

/*
 * Aufgabe 3: Matrix-Operationen
 *
 * Implementiere die folgenden Funktionen in task3_matrix.c.
 * Matrizen werden als int** (Array von Zeigern auf int-Arrays) dargestellt.
 * Alle Funktionen muessen NULL-Zeiger korrekt behandeln.
 */

/*
 * Allokiert eine rows x cols Matrix und initialisiert alle Eintraege mit 0.
 * Gibt NULL bei Speicherfehler zurueck.
 * Hinweis: Allokiere zuerst das Zeigerarray (int**), dann fuer jede Zeile
 *          ein int-Array mit calloc. Bei Fehler bereits allokierte Zeilen freigeben!
 * Beispiel: matrix_create(2, 3) -> 2x3 Nullmatrix
 */
int **matrix_create(int rows, int cols);

/*
 * Gibt eine mit matrix_create allokierte Matrix frei.
 * Erst alle Zeilen (m[0] .. m[rows-1]) freigeben, dann das Zeigerarray.
 * NULL-sicher.
 * Parameter: m = die Matrix, rows = Anzahl der Zeilen
 */
void matrix_free(int **m, int rows);

/*
 * Multipliziert jeden Eintrag der Matrix in-place mit 'factor'.
 * Beispiel: [[1,2],[3,4]], factor=3 -> [[3,6],[9,12]]
 */
void matrix_scale(int **m, int rows, int cols, int factor);

/*
 * Addiert zwei gleichgrosse Matrizen a und b elementweise und gibt
 * das Ergebnis als neu allokierte Matrix zurueck.
 * Die Eingabematrizen bleiben unveraendert.
 * Gibt NULL bei Speicherfehler zurueck.
 * Beispiel: [[1,2],[3,4]] + [[9,8],[7,6]] -> [[10,10],[10,10]]
 */
int **matrix_add(int **a, int **b, int rows, int cols);

/*
 * Prueft ob eine quadratische n x n Matrix symmetrisch ist.
 * Symmetrisch bedeutet: m[i][j] == m[j][i] fuer alle i, j.
 * Gibt 1 zurueck wenn symmetrisch, 0 sonst.
 * NULL oder n <= 0 -> 0.
 * Tipp: Es genuegt, nur die obere Dreieckshaelfte zu pruefen.
 * Beispiel: [[1,2,3],[2,5,6],[3,6,9]] -> symmetrisch -> 1
 */
int matrix_is_symmetric(int **m, int n);

/*
 * Berechnet die Spur (Trace) einer quadratischen n x n Matrix:
 * Summe aller Hauptdiagonalelemente (m[0][0] + m[1][1] + ... + m[n-1][n-1]).
 * NULL oder n <= 0 -> 0.
 * Beispiel: [[1,9,9],[9,2,9],[9,9,3]] -> Spur = 1+2+3 = 6
 */
int matrix_trace(int **m, int n);

/*
 * Transponiert eine rows x cols Matrix und gibt die transponierte
 * cols x rows Matrix als neu allokierte Matrix zurueck.
 * Element [i][j] des Originals wird zu Element [j][i] des Ergebnisses.
 * Gibt NULL bei Speicherfehler zurueck.
 * Beispiel: [[1,2,3],[4,5,6]] (2x3) -> [[1,4],[2,5],[3,6]] (3x2)
 */
int **transpose_matrix(int **matrix, int rows, int cols);

#endif /* TASK3_MATRIX_H */
