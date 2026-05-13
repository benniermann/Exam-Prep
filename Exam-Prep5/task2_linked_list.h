#ifndef TASK2_LINKED_LIST_H
#define TASK2_LINKED_LIST_H

/*
 * Aufgabe 2: Einfach verkettete Liste (Singly Linked List)
 *
 * Implementiere eine einfach verkettete Integer-Liste in task2_linked_list.c.
 * Die Liste verwaltet einen head- und tail-Zeiger sowie die Groesse (size).
 */

/* Knoten der Liste */
typedef struct SNode
{
    int          value;
    struct SNode *next;
} SNode;

/* Listen-Struktur */
typedef struct
{
    SNode *head;   /* Zeiger auf das erste Element   */
    SNode *tail;   /* Zeiger auf das letzte Element  */
    int    size;   /* Anzahl der Elemente            */
} SList;

/*
 * Erstellt eine leere Liste (head = NULL, tail = NULL, size = 0).
 * Gibt NULL bei Speicherfehler zurueck.
 */
SList *slist_create(void);

/*
 * Gibt alle Knoten und die Listen-Struktur frei.
 * NULL-sicher.
 */
void slist_destroy(SList *list);

/*
 * Fuegt einen Wert am ANFANG der Liste ein.
 * Gibt 0 bei Erfolg, -1 bei Fehler (NULL-Liste oder Speicherfehler).
 * Hinweis: Bei leerer Liste muss auch tail gesetzt werden.
 * Beispiel: [] -> push_front(10) -> [10]
 *           [10] -> push_front(20) -> [20, 10]
 */
int slist_push_front(SList *list, int value);

/*
 * Fuegt einen Wert am ENDE der Liste ein.
 * Gibt 0 bei Erfolg, -1 bei Fehler.
 * Hinweis: tail-Zeiger ermoeglicht O(1)-Einfuegen.
 * Beispiel: [10] -> push_back(30) -> [10, 30]
 */
int slist_push_back(SList *list, int value);

/*
 * Entfernt den ersten Knoten und gibt seinen Wert zurueck (FIFO-Stil).
 * Setzt *err auf -1 wenn die Liste leer oder NULL ist, sonst auf 0.
 * Hinweis: Bei einem Element muss auch tail auf NULL gesetzt werden.
 * Beispiel: [1, 2, 3] -> pop_front() -> gibt 1, Liste wird [2, 3]
 */
int slist_pop_front(SList *list, int *err);

/*
 * Entfernt den Knoten an Position 'index' (0-indiziert).
 * Gibt 0 bei Erfolg, -1 bei ungueltigem Index oder NULL-Liste.
 * Hinweis: Sonderfall index == 0 (kein Vorgaenger); tail aktualisieren
 *          wenn das letzte Element entfernt wird.
 * Beispiel: [10, 20, 30, 40], remove_at(1) -> [10, 30, 40]
 */
int slist_remove_at(SList *list, int index);

/*
 * Kopiert alle Werte der Liste in ein neu allokiertes int-Array.
 * Gibt NULL bei leerer Liste, NULL-Eingabe oder Speicherfehler zurueck.
 * Der Aufrufer ist verantwortlich fuer free().
 * Beispiel: [5, 10, 15] -> {5, 10, 15}
 */
int *slist_to_array(const SList *list);

/*
 * Kehrt die Reihenfolge der Elemente in der Liste um (in-place).
 * Kein neuer Speicher wird allokiert.
 * NULL oder Liste mit <= 1 Element: keine Aktion.
 * Hinweis: Drei-Zeiger-Methode (prev, current, next).
 *          Vergiss nicht, head und tail zu tauschen!
 * Beispiel: [1, 2, 3] -> reverse -> [3, 2, 1]
 */
void slist_reverse(SList *list);

#endif /* TASK2_LINKED_LIST_H */
