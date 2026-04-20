#ifndef TASK2_QUEUE_H
#define TASK2_QUEUE_H

/*
 * Aufgabe 2: Dynamische FIFO-Queue
 *
 * Implementiere eine dynamisch wachsende Integer-Queue (First In, First Out)
 * in task2_queue.c.
 * Die Queue wird als Ring-Puffer (Circular Buffer) implementiert:
 * 'front' zeigt auf das erste Element, 'back' auf die Stelle hinter dem letzten.
 * Wenn die Queue voll ist (size == capacity), wird die Kapazitaet verdoppelt.
 *
 * Unterschied zum Stack: Das ERSTE eingefuegte Element wird auch als
 * ERSTES wieder entnommen (FIFO, nicht LIFO).
 */

typedef struct {
    int *data;       /* dynamisches Array                  */
    int  front;      /* Index des ersten Elements           */
    int  back;       /* Index hinter dem letzten Element    */
    int  size;       /* aktuelle Anzahl Elemente            */
    int  capacity;   /* aktuell allokierte Kapazitaet       */
} Queue;

/*
 * Erstellt eine leere Queue mit initialer Kapazitaet 4.
 * Gibt NULL bei Speicherfehler zurueck.
 */
Queue *queue_create(void);

/*
 * Gibt den gesamten Speicher der Queue frei.
 * NULL-sicher.
 */
void queue_destroy(Queue *q);

/*
 * Fuegt einen Wert am Ende der Queue ein.
 * Verdoppelt die Kapazitaet wenn size == capacity.
 * Gibt 0 bei Erfolg, -1 bei Fehler zurueck.
 */
int queue_enqueue(Queue *q, int value);

/*
 * Entfernt den vordersten Wert und gibt ihn zurueck (FIFO).
 * Setzt *err auf -1 wenn die Queue leer ist, sonst auf 0.
 * Bei leerer Queue: Rueckgabewert ist 0.
 */
int queue_dequeue(Queue *q, int *err);

/*
 * Gibt den vordersten Wert zurueck OHNE ihn zu entfernen.
 * Setzt *err auf -1 wenn die Queue leer ist, sonst auf 0.
 */
int queue_peek(const Queue *q, int *err);

/*
 * Gibt 1 zurueck wenn die Queue leer ist, sonst 0.
 * NULL -> 1.
 */
int queue_is_empty(const Queue *q);

/*
 * Gibt die aktuelle Anzahl der Elemente zurueck.
 * NULL -> 0.
 */
int queue_size(const Queue *q);

#endif /* TASK2_QUEUE_H */
