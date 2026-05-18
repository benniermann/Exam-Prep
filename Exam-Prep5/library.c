#include "library.h"
#include <stdlib.h>

float average_rating(const Book *books, int count)
{
    if (books == NULL || count == 0)
        return 0;

    float avg = 0, sum = 0;

    for (int i = 0; i < count; i++)
    {
        sum += books[i].rating;
    }

    avg = sum / count;

    return avg;
}

Book *find_longest_book(Book *books, int count)
{
    int longest = books[0].pages;
    int index = 0;

    for (int i = 1; i < count; i++)
    {
        if (books[i].pages > longest)
        {
            longest = books[i].pages;
            index = i;
        }
    }
    return &books[index];
}

int count_books_above_rating(const Book *books, int count, float min_rating)
{
    if (books == NULL || count <= 0)
        return 0;

    int cnt = 0;

    for (int i = 0; i < count; i++)
    {
        if (books[i].rating >= min_rating)
        {
            cnt++;
        }
    }
    return cnt;
}

static int compare_notes(const void *p1, const void *p2)
{
    const Book *n1 = (const Book *)p1;
    const Book *n2 = (const Book *)p2;
    if (n1->pages != n2->pages)
        return n1->pages - n2->pages;
}

void sort_books_by_pages(Book *books, int count)
{
    if (count == 0)
        return;

    qsort(books, count, sizeof(Book), compare_notes);
}