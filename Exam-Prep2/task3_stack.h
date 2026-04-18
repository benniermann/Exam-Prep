#ifndef TASK3_STACK_H
#define TASK3_STACK_H

/*
 * Aufgabe 3: Dynamischer Stack (LIFO)
 *
 * Implementiere einen dynamisch wachsenden Integer-Stack in task3_stack.c.
 * Der Stack verdoppelt seine Kapazitaet wenn er voll ist (wie ein Vector).
 */

typedef struct {
    int *data;       /* dynamisches Array */
    int  size;       /* aktuelle Anzahl Elemente */
    int  capacity;   /* aktuell allokierte Kapazitaet */
} Stack;

/*
 * Erstellt einen leeren Stack mit initialer Kapazitaet 4.
 * Gibt NULL bei Speicherfehler zurueck.
 */
Stack *stack_create(void);

/*
 * Gibt den gesamten Speicher des Stacks frei.
 * NULL-sicher.
 */
void stack_destroy(Stack *s);

/*
 * Legt einen Wert oben auf den Stack.
 * Verdoppelt die Kapazitaet wenn size == capacity.
 * Gibt 0 bei Erfolg, -1 bei Fehler zurueck.
 */
int stack_push(Stack *s, int value);

/*
 * Entfernt den obersten Wert und gibt ihn zurueck.
 * Setzt *err auf -1 wenn der Stack leer ist, sonst auf 0.
 * Bei leerem Stack: Rueckgabewert ist 0.
 */
int stack_pop(Stack *s, int *err);

/*
 * Gibt den obersten Wert zurueck OHNE ihn zu entfernen.
 * Setzt *err auf -1 wenn der Stack leer ist, sonst auf 0.
 */
int stack_peek(const Stack *s, int *err);

/*
 * Gibt 1 zurueck wenn der Stack leer ist, sonst 0.
 * NULL -> 1.
 */
int stack_is_empty(const Stack *s);

#endif /* TASK3_STACK_H */