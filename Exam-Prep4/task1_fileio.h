#ifndef TASK1_FILEIO_H
#define TASK1_FILEIO_H

#include <stdio.h>

/*
 * Aufgabe 1: File I/O
 *
 * Implementiere die folgenden Funktionen in task1_fileio.c
 * Alle Funktionen muessen Dateien korrekt oeffnen und schliessen.
 * NULL-Zeiger und nicht existierende Dateien gelten als Fehler.
 */

/*
 * Zaehlt die Anzahl der Zeilen in einer Textdatei.
 * Eine Zeile endet mit '\n'. Eine nicht-leere letzte Zeile ohne '\n'
 * wird ebenfalls gezaehlt.
 * Gibt -1 zurueck wenn die Datei nicht geoeffnet werden kann.
 * Leere Datei -> 0.
 * Beispiel (Dateiinhalt "hallo\nwelt\n") -> 2
 */
int count_lines(const char *filename);

/*
 * Liest Integer-Werte aus einer Datei (einen pro Zeile) in das Array 'out'.
 * Liest hoechstens 'max_count' Werte.
 * Gibt die Anzahl der tatsaechlich gelesenen Werte zurueck.
 * Gibt -1 zurueck wenn die Datei nicht geoeffnet werden kann oder
 * out == NULL oder max_count <= 0.
 * Zeilen die keinen gueltigen Integer enthalten werden uebersprungen.
 * Beispiel (Datei: "10\n-3\n42\n"), max_count=10 -> liest {10,-3,42}, gibt 3 zurueck
 */
int read_ints_from_file(const char *filename, int *out, int max_count);

/*
 * Sucht den groessten Wert unter allen Integer-Werten in der Datei
 * (ein Integer pro Zeile) und schreibt ihn nach *out_max.
 * Gibt 0 bei Erfolg zurueck.
 * Gibt -1 zurueck wenn die Datei nicht geoeffnet werden kann,
 * leer ist oder out_max == NULL.
 */
int file_max(const char *filename, int *out_max);

/*
 * Schreibt die Quadratzahlen 1*1, 2*2, ..., n*n in die Datei,
 * je einen Wert pro Zeile.
 * Gibt 0 bei Erfolg, -1 bei Fehler (Datei nicht schreibbar, n <= 0).
 * Beispiel: n=3 -> Dateiinhalt "1\n4\n9\n"
 */
int write_squares(const char *filename, int n);

/*
 * Kopiert den Inhalt der Quelldatei 'src' Zeile fuer Zeile in die
 * Zieldatei 'dst', wobei jede Zeile mit einer Zeilennummer (1-indiziert)
 * und einem Doppelpunkt-Leerzeichen als Praefix versehen wird.
 * Gibt die Anzahl der kopierten Zeilen zurueck, -1 bei Fehler.
 * Beispiel: Quelle "hallo\nwelt\n" -> Ziel "1: hallo\n2: welt\n"
 */
int number_lines(const char *src, const char *dst);

#endif /* TASK1_FILEIO_H */
