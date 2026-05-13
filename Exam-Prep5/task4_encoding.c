#include "task4_encoding.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

char *caesar_encode(const char *text, int shift)
{
    /* TODO: NULL -> NULL.
     * Allokiere Ergebnis-String (strlen(text) + 1).
     * Normalisiere shift: shift = shift % 26; if (shift < 0) shift += 26;
     * Fuer jedes Zeichen:
     *   Kleinbuchstabe: 'a' + (c - 'a' + shift) % 26
     *   Grossbuchstabe: 'A' + (c - 'A' + shift) % 26
     *   Sonstige: unveraendert uebernehmen
     * Nullterminator setzen, Ergebnis zurueckgeben.
     */
    return NULL;
}

char *caesar_decode(const char *text, int shift)
{
    /* TODO: NULL -> NULL.
     * Entschluesseln ist Verschluesseln mit inversem Shift.
     * s = shift % 26; if (s < 0) s += 26;
     * Inverser Shift: (26 - s) % 26
     * Rufe einfach caesar_encode mit dem inversen Shift auf.
     */
    return NULL;
}

int is_rotation(const char *a, const char *b)
{
    /* TODO: NULL -> 0.
     * Laengen unterschiedlich -> 0.
     * Beide leer -> 1.
     * Erstelle Hilfsstring concat = a + a (doppelt so lang).
     * Pruefe ob b ein Teilstring von concat ist (strstr).
     * Gib 1 wenn ja, 0 sonst. Speicher freigeben!
     */
    return 0;
}

char *rle_encode(const char *text)
{
    /* TODO: NULL -> NULL. Leerer String -> neu allokierter leerer String.
     * Allokiere grosszuegig Speicher (strlen(text) * 12 + 1 reicht immer).
     * Laufe durch den String:
     *   Zaehle aufeinanderfolgende gleiche Zeichen (count).
     *   Wenn das naechste Zeichen verschieden ist: schreibe "%d%c" in result.
     * Schreibe die letzte Gruppe.
     * Optional: realloc auf tatsaechliche Laenge.
     * Nullterminator setzen, Ergebnis zurueckgeben.
     */
    return NULL;
}

char *rle_decode(const char *encoded)
{
    /* TODO: NULL -> NULL. Leerer String -> neu allokierter leerer String.
     * Erster Durchlauf: Berechne die Gesamtlaenge des dekodierten Strings.
     *   Lese Zahl (isdigit-Schleife), dann ein Zeichen; addiere Zahl zur Gesamtlaenge.
     *   Ungueltig (kein Digit am Anfang) -> NULL.
     * Allokiere Ergebnis (Gesamtlaenge + 1).
     * Zweiter Durchlauf: Fuelle den Ergebnisstring.
     *   Lese Zahl, lese Zeichen, schreibe count-mal das Zeichen.
     * Nullterminator setzen, Ergebnis zurueckgeben.
     */
    return NULL;
}
