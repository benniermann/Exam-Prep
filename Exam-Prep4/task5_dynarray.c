#ifndef TASK5_DYNARRAY_H
#define TASK5_DYNARRAY_H

/*
 * Aufgabe 5: Dynamisches double-Array
 *
 * Implementiere ein dynamisch wachsendes Array fuer double-Werte in
 * task5_dynarray.c. Die Kapazitaet verdoppelt sich bei Bedarf.
 * Aehnlich wie ein std::vector in C++.
 */

typedef struct {
    double *data;     /* dynamisches Array                */
    int     size;     /* aktuelle Anzahl Elemente         */
    int     capacity; /* aktuell allokierte Kapazitaet    */
} DynArray;

/*
 * Erstellt ein leeres DynArray mit initialer Kapazitaet 4.
 * Gibt NULL bei Speicherfehler zurueck.
 */
DynArray *da_create(void);

/*
 * Gibt den gesamten Speicher frei.
 * NULL-sicher.
 */
void da_destroy(DynArray *a);

/*
 * Fuegt einen Wert am Ende hinzu.
 * Verdoppelt die Kapazitaet wenn size == capacity.
 * Gibt 0 bei Erfolg, -1 bei Fehler.
 */
int da_push(DynArray *a, double value);

/*
 * Gibt den Wert am Index zurueck.
 * Setzt *err auf -1 bei ungueltigem Index oder NULL-Eingabe, sonst 0.
 * Ungueltiger Index: index < 0 oder index >= size.
 */
double da_get(const DynArray *a, int index, int *err);

/*
 * Entfernt das Element am gegebenen Index (verschiebt nachfolgende Elemente).
 * Gibt 0 bei Erfolg, -1 bei ungueltigem Index oder NULL.
 * Beispiel: [1.0, 2.0, 3.0, 4.0], remove_at(1) -> [1.0, 3.0, 4.0]
 */
int da_remove_at(DynArray *a, int index);

/*
 * Gibt den kleinsten Wert im Array zurueck.
 * Setzt *err auf -1 bei leerem Array oder NULL, sonst 0.
 */
double da_min(const DynArray *a, int *err);

/*
 * Gibt den groessten Wert im Array zurueck.
 * Setzt *err auf -1 bei leerem Array oder NULL, sonst 0.
 */
double da_max(const DynArray *a, int *err);

/*
 * Berechnet und gibt den arithmetischen Mittelwert aller Elemente zurueck.
 * Setzt *err auf -1 bei leerem Array oder NULL, sonst 0.
 * Beispiel: [1.0, 2.0, 3.0] -> 2.0
 */
double da_mean(const DynArray *a, int *err);

/*
 * Sortiert das Array aufsteigend (in-place).
 * NULL oder leeres Array: keine Aktion.
 * Beispiel: [3.0, 1.5, 2.0] -> [1.5, 2.0, 3.0]
 */
void da_sort(DynArray *a);

#endif /* TASK5_DYNARRAY_H */
