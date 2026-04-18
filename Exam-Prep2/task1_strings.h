#ifndef TASK1_STRINGS_H
#define TASK1_STRINGS_H

/*
 * Aufgabe 1: String-Operationen
 *
 * Implementiere die folgenden Funktionen in task1_strings.c
 */

/*
 * Gibt 1 zurueck wenn der String ein Palindrom ist, sonst 0.
 * Gross-/Kleinschreibung wird ignoriert. Leerzeichen zaehlen mit.
 * Beispiele:
 *   "racecar" -> 1
 *   "Racecar" -> 1
 *   "hello"   -> 0
 *   ""        -> 1  (leerer String gilt als Palindrom)
 */
int is_palindrome(const char *s);

/*
 * Zaehlt die Anzahl der Woerter in einem String.
 * Woerter sind durch beliebig viele Leerzeichen getrennt.
 * Fuehrende und abschliessende Leerzeichen werden ignoriert.
 * Beispiele:
 *   "hello world"    -> 2
 *   "  foo  bar  "   -> 2
 *   ""               -> 0
 *   "one"            -> 1
 */
int count_words(const char *s);

/*
 * Gibt eine neu allokierte, umgekehrte Kopie des Strings zurueck.
 * Der Aufrufer ist verantwortlich fuer free().
 * Bei NULL-Eingabe oder Speicherfehler: NULL zurueckgeben.
 * Beispiele:
 *   "hello" -> "olleh"
 *   ""      -> ""
 */
char *str_reverse(const char *s);

/*
 * Ersetzt in-place alle Vorkommen von 'old_char' durch 'new_char'.
 * Gibt die Anzahl der vorgenommenen Ersetzungen zurueck.
 * Bei NULL-Eingabe: -1 zurueckgeben.
 * Beispiel:
 *   "hello world", 'l', 'r'  -> "herro worrd", gibt 3 zurueck
 */
int str_replace_char(char *s, char old_char, char new_char);

#endif /* TASK1_STRINGS_H */