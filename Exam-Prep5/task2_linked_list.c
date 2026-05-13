#include "task2_linked_list.h"
#include <stdlib.h>
#include <stdio.h>

SList *slist_create(void)
{
    /* TODO: Allokiere eine SList-Struktur.
     * Setze head = NULL, tail = NULL, size = 0.
     * Gib NULL bei Speicherfehler zurueck.
     */
    return NULL;
}

void slist_destroy(SList *list)
{
    /* TODO: Gib alle Knoten und dann die Listenstruktur frei.
     * NULL-sicher (frueher return falls list == NULL).
     * Wichtig: next-Zeiger vor free() sichern!
     */
}

int slist_push_front(SList *list, int value)
{
    /* TODO: Erstelle einen neuen Knoten und haenge ihn vorne ein.
     * new_node->next = list->head
     * list->head = new_node
     * Falls liste vorher leer war: list->tail = new_node
     * list->size++
     * Gibt 0 bei Erfolg, -1 bei Fehler.
     */
    return -1;
}

int slist_push_back(SList *list, int value)
{
    /* TODO: Erstelle einen neuen Knoten und haenge ihn hinten ein.
     * new_node->next = NULL
     * Falls leer: head = tail = new_node
     * Sonst:      list->tail->next = new_node; list->tail = new_node
     * list->size++
     * Gibt 0 bei Erfolg, -1 bei Fehler.
     */
    return -1;
}

int slist_pop_front(SList *list, int *err)
{
    /* TODO: Entferne den ersten Knoten und gib seinen Wert zurueck.
     * Bei leerer Liste: *err = -1, return 0.
     * Sonst:
     *   Wert sichern, head weitersetzen, size--, ggf. tail = NULL, free.
     *   *err = 0.
     */
    if (err) *err = -1;
    return 0;
}

int slist_remove_at(SList *list, int index)
{
    /* TODO: Entferne den Knoten an Position index.
     * Prueffe Gueltigkeit: list != NULL, index >= 0, index < list->size.
     * Sonderfall index == 0: head weitersetzen, ggf. tail = NULL.
     * Allgemeiner Fall: Laufe bis zum Vorgaenger (index-1), haenge um.
     *   Falls letztes Element: tail aktualisieren.
     * list->size--
     * Gibt 0 bei Erfolg, -1 bei Fehler.
     */
    return -1;
}

int *slist_to_array(const SList *list)
{
    /* TODO: Allokiere ein int-Array der Groesse list->size.
     * Kopiere alle Werte der Reihe nach hinein.
     * NULL oder leere Liste: NULL zurueckgeben.
     */
    return NULL;
}

void slist_reverse(SList *list)
{
    /* TODO: Kehre die Liste in-place um (Drei-Zeiger-Methode).
     * NULL oder size <= 1: keine Aktion.
     * Variablen: prev = NULL, current = list->head, next = NULL
     * Schleife: next sichern, current->next = prev, prev vorschieben, current vorschieben.
     * Am Ende: list->tail = list->head (alter Head wird neuer Tail)
     *          list->head = prev       (prev zeigt auf den neuen Head)
     */
}
