#ifndef TASK4_LIST_H
#define TASK4_LIST_H

/*
 * Aufgabe 4: Verkettete Liste -- Erweiterte Operationen
 *
 * Implementiere die folgenden Funktionen in task4_list.c.
 * Benutze die gegebene Node-Struktur.
 */

typedef struct Node {
    int         data;
    struct Node *next;
} Node;

/*
 * Haengt einen neuen Knoten ans Ende der Liste.
 * Aendert *head wenn die Liste leer war.
 */
void list_append(Node **head, int value);

/*
 * Gibt alle Knoten frei und setzt *head auf NULL.
 */
void list_free(Node **head);

/*
 * Gibt die Summe aller Knotenwerte zurueck.
 * Leere Liste / NULL -> 0.
 */
int list_sum(const Node *head);

/*
 * Entfernt alle Knoten mit doppelten Werten, sodass jeder Wert
 * nur noch einmal vorkommt. Das erste Vorkommen bleibt erhalten.
 * Beispiel: 1 -> 2 -> 2 -> 3 -> 2 -> NULL
 *        -> 1 -> 2 -> 3 -> NULL
 */
void list_remove_duplicates(Node **head);

/*
 * Gibt 1 zurueck wenn die Liste aufsteigend sortiert ist, sonst 0.
 * Leere Liste und einelementige Liste gelten als sortiert (-> 1).
 * NULL -> 1.
 */
int list_is_sorted(const Node *head);

/*
 * Fuegt einen Wert an der richtigen Stelle in eine bereits sortierte
 * Liste ein, sodass die Liste sortiert bleibt.
 * Beispiel: 1 -> 3 -> 5, insert 4
 *        -> 1 -> 3 -> 4 -> 5
 */
void list_insert_sorted(Node **head, int value);

#endif /* TASK4_LIST_H */