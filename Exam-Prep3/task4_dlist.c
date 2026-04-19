#include "task4_dlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>

DList *dlist_create(void) 
{
    DList* l = malloc(sizeof(DList));
    if(!l) return NULL;

    l->head = NULL;
    l->tail = NULL;
    l->size = 0;

    return l;
}

void dlist_destroy(DList *list) 
{
    if(!list) return;

    DNode *cur = list->head;
    while(cur)
    {
        DNode *nxt = cur->next;
        free(cur);
        cur = nxt;
    }

    free(list);
}

int dlist_push_front(DList *list, int value)
{
    if(list == NULL) return -1;

    DNode* new_node = malloc(sizeof(DNode));
    if(new_node == NULL) return -1;

    new_node->data = value;
    new_node->next = list->head;
    new_node->prev = NULL;

    if(list->head != NULL)
        list->head->prev = new_node;

    list->head = new_node;

    if(list->size == 0) list->tail = new_node;

    list->size++;
    
    return 0;
}

int dlist_push_back(DList *list, int value)
{
    if(list == NULL) return -1;

    DNode* new_node = malloc(sizeof(DNode));
    if(new_node == NULL) return -1;

    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = NULL;

    if(list->size == 0)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }

    list->size++;
    
    return 0;
}

int dlist_pop_back(DList *list, int *err) 
{
    if (list == NULL || list->size == 0 || list->tail == NULL) 
    {
        if (err != NULL) *err = -1;
        return 0;
    }

    if (err != NULL) *err = 0;

    DNode *to_remove = list->tail;
    int value = to_remove->data;

    list->tail = to_remove->prev;

    if (list->tail != NULL) 
    {
        list->tail->next = NULL;
    } 
    else 
    {
        list->head = NULL;
    }

    list->size--;
    free(to_remove);

    return value;
}

int dlist_is_consistent(const DList *list) 
{
    if (list == NULL) return 1;

    if (list->size == 0) 
    {
        if (list->head == NULL && list->tail == NULL) return 1;
        return 0;
    }

    if (list->head == NULL || list->tail == NULL) return 0;
    if (list->head->prev != NULL) return 0;
    if (list->tail->next != NULL) return 0;

    const DNode *curr = list->head;
    int count = 0;

    while (curr != NULL) 
    {
        count++;
        if (curr->next != NULL && curr->next->prev != curr) return 0;
        if (curr->next == NULL && curr != list->tail) return 0;
        curr = curr->next;
    }

    if (count != list->size) return 0;

    return 1;
}