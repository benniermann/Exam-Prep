#include "task2_queue.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

Queue *queue_create(void)
{
    Queue *new_queue = malloc(sizeof(Queue));
    if (!new_queue)
        return NULL;

    new_queue->data = malloc(4 * sizeof(int));
    if (new_queue->data == NULL)
    {
        free(new_queue);
        return NULL;
    }

    new_queue->back = 0;
    new_queue->front = 0;
    new_queue->size = 0;
    new_queue->capacity = 4;

    return new_queue;
}

void queue_destroy(Queue *q)
{
    if (q == NULL)
        return;

    if (q->data != NULL)
    {
        free(q->data);
    }

    free(q);
}

int queue_enqueue(Queue *q, int value)
{
    if (q == NULL)
    {
        return -1;
    }

    if (q->size == q->capacity)
    {
        int new_capacity = (q->capacity == 0) ? 4 : q->capacity * 2;
        int *new_data = malloc(new_capacity * sizeof(int));

        if (new_data == NULL)
        {
            return -1;
        }

        for (int i = 0; i < q->size; i++)
        {
            new_data[i] = q->data[(q->front + i) % q->capacity];
        }

        free(q->data);

        q->data = new_data;
        q->front = 0;
        q->back = q->size;
        q->capacity = new_capacity;
    }

    q->data[q->back] = value;
    q->back = (q->back + 1) % q->capacity;
    q->size++;

    return 0;
}

int queue_dequeue(Queue *q, int *err)
{
    if (q == NULL || q->size == 0)
    {
        if (err != NULL)
        {
            *err = -1;
        }
        return 0;
    }

    int value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;

    if (err != NULL)
    {
        *err = 0;
    }

    return value;
}

int queue_peek(const Queue *q, int *err)
{
    if (q == NULL || q->size == 0)
    {
        if (err != NULL)
        {
            *err = -1;
        }
        return 0;
    }

    int value = q->data[q->front];

    if (err != NULL)
    {
        *err = 0;
    }

    return value;
}

int queue_is_empty(const Queue *q)
{
    if (q == NULL)
        return 1;

    return q->size == 0;
}

int queue_size(const Queue *q)
{
    if (q == NULL)
        return 0;

    return q->size;
}