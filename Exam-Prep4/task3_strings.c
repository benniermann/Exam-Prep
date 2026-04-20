#ifndef TASK3_STRINGS_H
#define TASK3_STRINGS_H

/*
 * Aufgabe 3: Weitere String-Operationen
 *
 * Implementiere die folgenden Funktionen in task3_strings.c.
 * Alle Funktionen die neuen Speicher allokieren: Aufrufer ist verantwortlich
 * fuer free(). Bei Speicherfehler oder NULL-Eingabe: NULL zurueckgeben.
 */

/*
 * Gibt eine neu allokierte Kopie von 's' zurueck, bei der fuehrende und
 * abschliessende Leerzeichen (' ', '\t', '\n', '\r') entfernt wurden.
 * Bei NULL-Eingabe oder Speicherfehler: NULL zurueckgeben.
 * Beispiele:
 *   "  hallo  " -> "hallo"
 *   "\t test\n" -> "test"
 *   "ok"        -> "ok"
 *   "   "       -> ""   (nur Leerzeichen -> leerer String)
 */
char *str_trim(const char *s);

/*
 * Konvertiert den String in einen int und schreibt das Ergebnis nach *out.
 * Gibt 0 bei Erfolg zurueck, -1 bei Fehler.
 * Fehlerfall: s ist NULL, leer, enthaelt nicht-numerische Zeichen
 * (fuehrendes '-' fuer negative Zahlen ist erlaubt).
 * Leerzeichen am Anfang werden ignoriert (wie strtol).
 * Beispiele:
 *   "42"    -> *out=42,  gibt 0
 *   " -7"   -> *out=-7,  gibt 0
 *   "3abc"  -> gibt -1
 *   ""      -> gibt -1
 *   NULL    -> gibt -1
 */
int str_to_int(const char *s, int *out);

/*
 * Gibt 1 zurueck wenn 's' mit dem Praefix 'prefix' beginnt, sonst 0.
 * Gross-/Kleinschreibung wird BEACHTET.
 * NULL fuer s oder prefix -> 0.
 * Beispiele:
 *   str_starts_with("hallo welt", "hallo") -> 1
 *   str_starts_with("hallo", "hallo welt") -> 0
 *   str_starts_with("Test", "test")        -> 0
 *   str_starts_with("", "")               -> 1
 */
int str_starts_with(const char *s, const char *prefix);

/*
 * Zaehlt die Vokale (a, e, i, o, u) im String, Gross-/Kleinschreibung wird
 * ignoriert.
 * NULL -> 0.
 * Beispiele:
 *   "Hallo Welt"  -> 3  (a, o, e)
 *   "AEIOU"       -> 5
 *   "xyz"         -> 0
 *   ""            -> 0
 */
int str_count_vowels(const char *s);

/*
 * Gibt eine neu allokierte Kopie von 's' zurueck, bei der alle
 * Kleinbuchstaben in Grossbuchstaben umgewandelt wurden.
 * Andere Zeichen bleiben unveraendert.
 * NULL-Eingabe oder Speicherfehler -> NULL.
 * Beispiele:
 *   "hallo Welt!" -> "HALLO WELT!"
 *   "123abc"      -> "123ABC"
 *   ""            -> ""
 */
char *str_to_upper(const char *s);

/*
 * Gibt eine neu allokierten String zurueck, der 's' genau 'n' Mal
 * hintereinander enthaelt.
 * n == 0 -> gibt leeren String zurueck ("").
 * n < 0 oder NULL oder Speicherfehler -> NULL.
 * Beispiele:
 *   str_repeat("ab", 3) -> "ababab"
 *   str_repeat("x",  1) -> "x"
 *   str_repeat("hi", 0) -> ""
 */
char *str_repeat(const char *s, int n);

#endif /* TASK3_STRINGS_H */
