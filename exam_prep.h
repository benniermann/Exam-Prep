#ifndef KLAUSUR_PREP_H
#define KLAUSUR_PREP_H

#include <stddef.h>

/* =========================================
 * AUFGABE 1: STRINGS & POINTER
 * ========================================= */

/**
 * @brief Komprimiert einen String mittels Run-Length-Encoding.
 * * @param src Nullterminierter Quellstring (z.B. "AABBC")
 * @param dest Ziel-Buffer, in den das Ergebnis geschrieben wird (z.B. "A2B2C1").
 * Der Buffer ist garantiert groß genug.
 */
void compress_rle(const char* src, char* dest);


/* =========================================
 * AUFGABE 2: STRUCTS
 * ========================================= */

typedef struct {
    int id;
    char name[50];
    char category[20];
    float price;
    int quantity;
} Item;

/**
 * @brief Findet das Item mit dem geringsten Lagerbestand.
 * * @param items Array von Items.
 * @param length Anzahl der Elemente im Array.
 * @return Item* Pointer auf das Item mit der geringsten quantity. NULL bei length <= 0.
 */
Item* find_lowest_stock(Item* items, int length);

/**
 * @brief Reduziert den Preis aller Items einer Kategorie um den gegebenen Prozentsatz.
 * * @param items Array von Items.
 * @param length Anzahl der Elemente im Array.
 * @param target_category Die Kategorie, auf die der Rabatt angewendet wird.
 * @param discount_percent Prozentwert (z.B. 10.0 für 10% Rabatt).
 */
void apply_discount(Item* items, int length, const char* target_category, float discount_percent);


/* =========================================
 * AUFGABE 3: DYNAMIC MEMORY
 * ========================================= */

/**
 * @brief Alloziert eine 2D-Matrix dynamisch (Array von Pointern auf Arrays).
 * * @param rows Anzahl der Zeilen.
 * @param cols Anzahl der Spalten.
 * @return int** Pointer auf die allozierten Zeilen-Pointer. NULL bei Fehler.
 */
int** create_matrix(int rows, int cols);

/**
 * @brief Transponiert eine gegebene Matrix und gibt eine NEUE Matrix zurück.
 * * @param matrix Die Eingabematrix.
 * @param rows Zeilen der Eingabematrix.
 * @param cols Spalten der Eingabematrix.
 * @return int** Die neue (transponierte) Matrix der Größe cols x rows.
 */
int** transpose_matrix(int** matrix, int rows, int cols);

/**
 * @brief Gibt den Speicher einer 2D-Matrix komplett frei.
 * * @param matrix Die freizugebende Matrix.
 * @param rows Anzahl der Zeilen.
 */
void free_matrix(int** matrix, int rows);


/* =========================================
 * AUFGABE 4: LINKED LISTS
 * ========================================= */

typedef struct Node {
    int data;
    struct Node* next;
} Node;

/**
 * @brief Fügt einen neuen Knoten mit dem Wert 'value' am Ende der Liste ein.
 * * @param head_ref Doppelter Pointer auf den Head der Liste (Call-by-Reference für den Head).
 * @param value Der einzufügende Wert.
 */
void list_append(Node** head_ref, int value);

/**
 * @brief Löscht alle Knoten aus der Liste, die eine gerade Zahl enthalten.
 * Achtung: Der Head der Liste kann sich hierbei ändern!
 * * @param head_ref Doppelter Pointer auf den Head der Liste.
 */
void list_filter_even(Node** head_ref);

/**
 * @brief Gibt den gesamten Speicher der Liste frei und setzt den Head auf NULL.
 * * @param head_ref Doppelter Pointer auf den Head der Liste.
 */
void list_free(Node** head_ref);

#endif // KLAUSUR_PREP_H
