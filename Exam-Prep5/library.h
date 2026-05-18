#ifndef LIBRARY_H
#define LIBRARY_H

#define MAX_TITLE_LEN 64

typedef struct
{
    int id;
    char title[MAX_TITLE_LEN];
    int pages;
    float rating;
} Book;

/*
 * Berechnet die durchschnittliche Bewertung aller Bücher.
 * Gibt 0.0 zurück falls count <= 0 oder books == NULL.
 */
float average_rating(const Book *books, int count);

/*
 * Findet das Buch mit den meisten Seiten.
 * Gibt einen Zeiger auf das Buch zurück.
 * Gibt NULL zurück falls books == NULL oder count <= 0.
 */
Book *find_longest_book(Book *books, int count);

/*
 * Zählt wie viele Bücher mindestens min_rating besitzen.
 */
int count_books_above_rating(const Book *books, int count, float min_rating);

/*
 * Sortiert die Bücher aufsteigend nach Seitenanzahl.
 */
void sort_books_by_pages(Book *books, int count);

#endif