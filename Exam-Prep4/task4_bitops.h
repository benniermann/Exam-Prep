#ifndef TASK4_BITOPS_H
#define TASK4_BITOPS_H

/*
 * Aufgabe 4: Bit-Manipulation
 *
 * Implementiere die folgenden Funktionen in task4_bitops.c.
 * Alle Positionen sind 0-indiziert (Bit 0 = LSB, Bit 31 = MSB).
 * Ungueltige Positionen (pos < 0 oder pos > 31) sollen den Wert
 * unveraendert zurueckgeben bzw. 0 liefern.
 */

/*
 * Setzt Bit an Position 'pos' auf 1 und gibt das Ergebnis zurueck.
 * Beispiele:
 *   bit_set(0b0000, 0) -> 0b0001  (= 1)
 *   bit_set(0b0101, 1) -> 0b0111  (= 7)
 *   bit_set(0b1111, 2) -> 0b1111  (= 15, schon gesetzt)
 */
unsigned int bit_set(unsigned int n, int pos);

/*
 * Loescht Bit an Position 'pos' (setzt auf 0) und gibt das Ergebnis zurueck.
 * Beispiele:
 *   bit_clear(0b1111, 0) -> 0b1110  (= 14)
 *   bit_clear(0b0101, 2) -> 0b0001  (= 1)
 *   bit_clear(0b0000, 1) -> 0b0000  (= 0, war schon 0)
 */
unsigned int bit_clear(unsigned int n, int pos);

/*
 * Flippt Bit an Position 'pos' (0 -> 1, 1 -> 0) und gibt das Ergebnis zurueck.
 * Beispiele:
 *   bit_toggle(0b0000, 3) -> 0b1000  (= 8)
 *   bit_toggle(0b1010, 1) -> 0b1000  (= 8)
 *   bit_toggle(0b1010, 3) -> 0b0010  (= 2)
 */
unsigned int bit_toggle(unsigned int n, int pos);

/*
 * Gibt den Wert (0 oder 1) des Bits an Position 'pos' zurueck.
 * Ungueltige Position -> 0.
 * Beispiele:
 *   bit_get(0b1010, 1) -> 1
 *   bit_get(0b1010, 0) -> 0
 *   bit_get(0b1010, 3) -> 1
 */
int bit_get(unsigned int n, int pos);

/*
 * Zaehlt die Anzahl der gesetzten Bits (1-Bits) in n (Popcount).
 * Beispiele:
 *   count_ones(0)          -> 0
 *   count_ones(0b1111)     -> 4
 *   count_ones(0b10110100) -> 4
 *   count_ones(0xFFFFFFFF) -> 32
 */
int count_ones(unsigned int n);

/*
 * Gibt 1 zurueck wenn n eine Potenz von 2 ist (n > 0), sonst 0.
 * Potenzen von 2: 1, 2, 4, 8, 16, 32, ...
 * Tipp: Eine Potenz von 2 hat genau ein gesetztes Bit.
 * Beispiele:
 *   is_power_of_two(0)  -> 0
 *   is_power_of_two(1)  -> 1
 *   is_power_of_two(4)  -> 1
 *   is_power_of_two(6)  -> 0
 *   is_power_of_two(32) -> 1
 */
int is_power_of_two(unsigned int n);

/*
 * Gibt das Byte-Muster von n mit umgekehrter Bit-Reihenfolge zurueck.
 * Nur die unteren 8 Bit (ein Byte) werden betrachtet, der Rest wird 0.
 * Bit 7 von n wird zu Bit 0 des Ergebnisses, Bit 0 zu Bit 7, etc.
 * Beispiele:
 *   reverse_byte(0b10110001) -> 0b10001101  (= 0x8D)
 *   reverse_byte(0b00000001) -> 0b10000000  (= 128)
 *   reverse_byte(0b11111111) -> 0b11111111  (= 255)
 *   reverse_byte(0x1FF)      -> behandle nur untere 8 Bit: 0xFF -> 0xFF
 */
unsigned int reverse_byte(unsigned int n);

#endif /* TASK4_BITOPS_H */
