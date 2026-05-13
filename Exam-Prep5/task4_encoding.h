#ifndef TASK4_ENCODING_H
#define TASK4_ENCODING_H

/*
 * Aufgabe 4: Encoding / Verschluesselung
 *
 * Implementiere die folgenden Funktionen in task4_encoding.c.
 * Alle Funktionen die Speicher allokieren: Aufrufer ist verantwortlich fuer free().
 * Bei NULL-Eingabe oder Speicherfehler: NULL zurueckgeben.
 */

/*
 * Verschluesselt einen String mit der Caesar-Chiffre (Verschiebung um 'shift' Positionen).
 * Nur Buchstaben (a-z, A-Z) werden verschluesselt; Gross-/Kleinschreibung bleibt erhalten.
 * Alle anderen Zeichen (Zahlen, Leerzeichen, Satzzeichen) werden unveraendert uebernommen.
 * shift kann negativ sein oder groesser als 25; verwende Modulo-Arithmetik.
 * Gibt einen neu allokierten String zurueck.
 * Beispiele:
 *   caesar_encode("hallo", 3)       -> "kdoor"
 *   caesar_encode("xyz", 3)         -> "abc"    (Wrap-around!)
 *   caesar_encode("Hello World!", 1) -> "Ifmmp Xpsme!"
 *   caesar_encode("abc", 26)        -> "abc"    (voller Umlauf = keine Aenderung)
 *   caesar_encode(NULL, 3)          -> NULL
 */
char *caesar_encode(const char *text, int shift);

/*
 * Entschluesselt einen mit caesar_encode verschluesselten String.
 * Tipp: Entschluesseln ist dasselbe wie Verschluesseln mit dem inversen Shift.
 *       Inverser Shift von s: (26 - (s % 26)) % 26
 * Gibt einen neu allokierten String zurueck.
 * Beispiele:
 *   caesar_decode("kdoor", 3) -> "hallo"
 *   caesar_decode("abc", 3)   -> "xyz"
 *   caesar_decode(NULL, 3)    -> NULL
 */
char *caesar_decode(const char *text, int shift);

/*
 * Prueft ob String b eine Rotation von String a ist.
 * Zwei Strings sind Rotationen voneinander, wenn b als Teilstring in
 * der Verkettung aa vorkommt.
 * Unterschiedliche Laengen -> 0. Beide leer -> 1. NULL -> 0.
 * Gibt 1 zurueck wenn b eine Rotation von a ist, sonst 0.
 * Beispiele:
 *   is_rotation("abcd", "cdab") -> 1
 *   is_rotation("abcd", "dabc") -> 1
 *   is_rotation("abcd", "abcd") -> 1  (Rotation um 0)
 *   is_rotation("abcd", "abce") -> 0
 *   is_rotation("abc",  "abcd") -> 0  (unterschiedliche Laenge)
 *   is_rotation("", "")         -> 1
 */
int is_rotation(const char *a, const char *b);

/*
 * Kodiert einen String mit Run-Length Encoding (RLE).
 * Format: Anzahl gefolgt vom Zeichen. Beispiel: "aaa" -> "3a"
 * Gibt einen neu allokierten String zurueck.
 * Leerer String -> leerer String (""). NULL -> NULL.
 * Beispiele:
 *   rle_encode("aaabbc")  -> "3a2b1c"
 *   rle_encode("a")       -> "1a"
 *   rle_encode("aabbcc")  -> "2a2b2c"
 *   rle_encode("")        -> ""
 *   rle_encode(NULL)      -> NULL
 */
char *rle_encode(const char *text);

/*
 * Dekodiert einen RLE-kodierten String (Format: Zahl gefolgt vom Zeichen).
 * Gibt einen neu allokierten String zurueck.
 * Leerer String -> leerer String (""). NULL -> NULL.
 * Ungueltige Eingabe (z.B. Buchstabe vor Zahl) -> NULL.
 * Beispiele:
 *   rle_decode("3a2b1c") -> "aaabbc"
 *   rle_decode("1a")     -> "a"
 *   rle_decode("2x2y")   -> "xxyy"
 *   rle_decode("")       -> ""
 *   rle_decode(NULL)     -> NULL
 */
char *rle_decode(const char *encoded);

#endif /* TASK4_ENCODING_H */
