#ifndef TEXT_UTILS_H
#define TEXT_UTILS_H

/*
 * Zählt wie oft ein Zeichen in einem String vorkommt.
 */
int char_frequency(const char *text, char c);

/*
 * Erstellt eine neue Zeichenkette ohne Ziffern.
 * Beispiel:
 * "a1b2c3" -> "abc"
 *
 * Der Rückgabewert muss dynamisch allokiert werden.
 */
char *remove_digits(const char *text);

/*
 * Prüft ob ein String ausschließlich Großbuchstaben enthält.
 * Leerstring soll 1 zurückgeben.
 */
int is_uppercase_string(const char *text);

/*
 * Dreht die Reihenfolge der Wörter um.
 * Beispiel:
 * "ich lerne c" -> "c lerne ich"
 *
 * Der Rückgabewert muss dynamisch allokiert werden.
 */
char *reverse_words(const char *text);

#endif