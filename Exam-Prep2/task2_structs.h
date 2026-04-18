#ifndef TASK2_STRUCTS_H
#define TASK2_STRUCTS_H

#define MAX_NAME_LEN  64
#define MAX_GRADES    10

/*
 * Aufgabe 2: Structs & Arrays of Structs
 *
 * Implementiere die folgenden Funktionen in task2_structs.c
 */

typedef struct {
    int    id;
    char   name[MAX_NAME_LEN];
    double grades[MAX_GRADES];  /* Noten 1.0 - 5.0 */
    int    grade_count;
} Student;

/*
 * Berechnet den Notendurchschnitt eines Studenten.
 * Gibt 0.0 zurueck wenn grade_count == 0 oder s == NULL.
 */
double student_average(const Student *s);

/*
 * Gibt einen Zeiger auf den Studenten mit dem besten (niedrigsten)
 * Notendurchschnitt zurueck.
 * Bei mehreren Gleichstaenden: den mit dem niedrigsten Index.
 * Bei n <= 0 oder NULL: NULL zurueckgeben.
 */
Student *find_best_student(Student *students, int n);

/*
 * Sortiert das Array aufsteigend nach Notendurchschnitt (bester zuerst).
 * Bei gleichem Durchschnitt bleibt die urspruengliche Reihenfolge erhalten
 * (stabiler Sort).
 */
void sort_students_by_average(Student *students, int n);

/*
 * Gibt 1 zurueck wenn der Student alle Pruefungen bestanden hat
 * (alle Noten <= 4.0), sonst 0.
 * NULL oder grade_count == 0 -> 0.
 */
int student_passed_all(const Student *s);

#endif /* TASK2_STRUCTS_H */