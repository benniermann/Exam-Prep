#include "task3_matrix.h"
#include <stdlib.h>
#include <stdio.h>

int **matrix_create(int rows, int cols)
{
    /* TODO: Allokiere das Zeigerarray (int**) fuer 'rows' Zeiger.
     * Allokiere dann fuer jede Zeile ein int-Array mit calloc (cols Elemente).
     * Bei Fehler in Zeile i: gib alle Zeilen 0..i-1 frei, dann das Zeigerarray.
     * Gib NULL bei Speicherfehler zurueck.
     */
    return NULL;
}

void matrix_free(int **m, int rows)
{
    /* TODO: NULL-sicher.
     * Gib jede Zeile m[i] frei (Schleife von 0 bis rows-1).
     * Gib dann das Zeigerarray m frei.
     */
}

void matrix_scale(int **m, int rows, int cols, int factor)
{
    /* TODO: Multipliziere jeden Eintrag m[i][j] mit factor.
     * Doppelte Schleife ueber alle Zeilen und Spalten.
     */
}

int **matrix_add(int **a, int **b, int rows, int cols)
{
    /* TODO: Erstelle eine neue rows x cols Matrix mit matrix_create.
     * Setze result[i][j] = a[i][j] + b[i][j].
     * Gib die neue Matrix zurueck (NULL bei Fehler).
     */
    return NULL;
}

int matrix_is_symmetric(int **m, int n)
{
    /* TODO: Prueffe ob m[i][j] == m[j][i] fuer alle i < j.
     * NULL oder n <= 0 -> 0.
     * Nur die obere Dreieckshaelfte muss verglichen werden:
     *   aeussere Schleife i von 0 bis n-1
     *   innere Schleife j von i+1 bis n-1
     * Gib 1 wenn symmetrisch, 0 sonst.
     */
    return 0;
}

int matrix_trace(int **m, int n)
{
    /* TODO: NULL oder n <= 0 -> 0.
     * Summiere m[i][i] fuer i von 0 bis n-1 und gib die Summe zurueck.
     */
    return 0;
}

int **transpose_matrix(int **matrix, int rows, int cols)
{
    /* TODO: Erstelle eine neue cols x rows Matrix mit matrix_create.
     * Setze result[j][i] = matrix[i][j].
     * Gib die transponierte Matrix zurueck (NULL bei Fehler).
     */
    return NULL;
}
