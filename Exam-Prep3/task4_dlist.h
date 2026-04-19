#ifndef TASK4_DLIST_H
#define TASK4_DLIST_H

/*
 * Aufgabe 4: Doppelt verkettete Liste
 *
 * Implementiere die folgenden Funktionen in task4_dlist.c
 * Im Gegensatz zur einfach verketteten Liste hat jeder Knoten
 * zusaetzlich einen 'prev'-Zeiger.
 */

typedef struct DNode {
    int          data;
    struct DNode *next;
    struct DNode *prev;
} DNode;

typedef struct {
    DNode *head;
    DNode *tail;
    int    size;
} DList;

/*
 * Erstellt eine leere Liste. Gibt NULL bei Speicherfehler zurueck.
 */
DList *dlist_create(void);

/*
 * Gibt alle Knoten und die Listenstruktur frei.
 */
void dlist_destroy(DList *list);

/*
 * Fuegt einen Wert am Anfang ein. Gibt 0 bei Erfolg, -1 bei Fehler.
 */
int dlist_push_front(DList *list, int value);

/*
 * Fuegt einen Wert am Ende ein. Gibt 0 bei Erfolg, -1 bei Fehler.
 */
int dlist_push_back(DList *list, int value);

/*
 * Entfernt und gibt den letzten Wert zurueck.
 * Setzt *err = -1 bei leerer Liste, sonst *err = 0.
 */
int dlist_pop_back(DList *list, int *err);

/*
 * Gibt 1 zurueck wenn die Liste vorwaerts und rueckwaerts konsistent ist,
 * d.h. das Traversieren ueber next und ueber prev das gleiche Ergebnis
 * in umgekehrter Reihenfolge liefert und head->prev == NULL
 * sowie tail->next == NULL gilt.
 * Leere Liste -> 1.
 */
int dlist_is_consistent(const DList *list);

#endif /* TASK4_DLIST_H */
