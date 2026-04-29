#include <stdlib.h>
#include "task5_dynarray.h"

DynArray *da_create(void)
{
    DynArray *a = malloc(sizeof(DynArray));
    if (!a)
    {
        return NULL;
    }

    a->data = malloc(4 * sizeof(double));
    if (!a->data)
    {
        free(a);
        return NULL;
    }

    a->size = 0;
    a->capacity = 4;

    return a;
}

void da_destroy(DynArray *a)
{
    if (a)
    {
        if (a->data)
        {
            free(a->data);
        }
        free(a);
    }
}

int da_push(DynArray *a, double value)
{
    if (!a)
    {
        return -1;
    }

    if (a->size == a->capacity)
    {
        int new_capacity = (a->capacity == 0) ? 4 : a->capacity * 2;
        double *new_data = realloc(a->data, new_capacity * sizeof(double));

        if (!new_data)
        {
            return -1;
        }

        a->data = new_data;
        a->capacity = new_capacity;
    }

    a->data[a->size] = value;
    a->size++;

    return 0;
}

double da_get(const DynArray *a, int index, int *err)
{
    if (!a || index < 0 || index >= a->size)
    {
        if (err)
        {
            *err = -1;
        }
        return 0.0;
    }

    if (err)
    {
        *err = 0;
    }

    return a->data[index];
}

int da_remove_at(DynArray *a, int index)
{
    if (!a || index < 0 || index >= a->size)
    {
        return -1;
    }

    for (int i = index; i < a->size - 1; i++)
    {
        a->data[i] = a->data[i + 1];
    }

    a->size--;

    return 0;
}

double da_min(const DynArray *a, int *err)
{
    if (!a || a->size == 0)
    {
        if (err)
        {
            *err = -1;
        }
        return 0.0;
    }

    double min_val = a->data[0];
    for (int i = 1; i < a->size; i++)
    {
        if (a->data[i] < min_val)
        {
            min_val = a->data[i];
        }
    }

    if (err)
    {
        *err = 0;
    }

    return min_val;
}

double da_max(const DynArray *a, int *err)
{
    if (!a || a->size == 0)
    {
        if (err)
        {
            *err = -1;
        }
        return 0.0;
    }

    double max_val = a->data[0];
    for (int i = 1; i < a->size; i++)
    {
        if (a->data[i] > max_val)
        {
            max_val = a->data[i];
        }
    }

    if (err)
    {
        *err = 0;
    }

    return max_val;
}

double da_mean(const DynArray *a, int *err)
{
    if (!a || a->size == 0)
    {
        if (err)
        {
            *err = -1;
        }
        return 0.0;
    }

    double sum = 0.0;
    for (int i = 0; i < a->size; i++)
    {
        sum += a->data[i];
    }

    if (err)
    {
        *err = 0;
    }

    return sum / a->size;
}

static int compare_doubles(const void *p1, const void *p2)
{
    double d1 = *(const double *)p1;
    double d2 = *(const double *)p2;

    if (d1 < d2)
    {
        return -1;
    }
    if (d1 > d2)
    {
        return 1;
    }
    return 0;
}

void da_sort(DynArray *a)
{
    if (!a || a->size <= 1)
    {
        return;
    }

    qsort(a->data, a->size, sizeof(double), compare_doubles);
}