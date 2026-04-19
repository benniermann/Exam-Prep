#include "task3_stack.h"
#include <stddef.h>
#include <stdlib.h>

Stack *stack_create(void) 
{
    Stack *s = malloc(sizeof(Stack));
    if (s == NULL) return NULL;

    s->data = malloc(4 * sizeof(int));
    if (s->data == NULL) 
    {
        free(s);
        return NULL;
    }

    s->size = 0;
    s->capacity = 4;

    return s;
}

void stack_destroy(Stack *s) 
{
    if(s == NULL) return;

    if (s->data != NULL) 
    {
        free(s->data);
    }

    free(s);
}

int stack_push(Stack *s, int value) 
{
    if (s == NULL) return -1;

    if (s->size == s->capacity) 
    {
        int new_capacity = (s->capacity == 0) ? 4 : s->capacity * 2;
        
        int *new_data = realloc(s->data, new_capacity * sizeof(int));
        
        if (new_data == NULL) return -1; 

        s->data = new_data;
        s->capacity = new_capacity;
    }

    s->data[s->size] = value;
    s->size++;

    return 0;
}

int stack_pop(Stack *s, int *err) 
{
    if (s == NULL || s->size == 0) 
    {
        if (err != NULL) *err = -1;
        return 0;
    }

    if (err != NULL) *err = 0;

    s->size--;
    return s->data[s->size];
}

int stack_peek(const Stack *s, int *err) 
{
    if (s == NULL || s->size == 0) 
    {
        if (err != NULL) *err = -1;
        return 0;
    }
    if (err != NULL) *err = 0;
    
    return s->data[s->size - 1];
}

int stack_is_empty(const Stack *s) 
{
    if(s == NULL || s->size == 0) return 1;

    return 0;
}