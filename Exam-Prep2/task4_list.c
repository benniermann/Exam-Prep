#include "task4_list.h"
#include <stdlib.h>

void list_append(Node **head, int value) 
{
    if (head == NULL) return;

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) return;
    
    new_node->data = value;
    new_node->next = NULL;

    if (*head == NULL) 
    {
        *head = new_node;
        return;
    }

    Node *curr = *head;
    while (curr->next != NULL) 
    {
        curr = curr->next;
    }
    curr->next = new_node;
}

void list_free(Node **head) 
{
    if (head == NULL) return;

    Node *curr = *head;
    while (curr != NULL) 
    {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

int list_sum(const Node *head) 
{
    int sum = 0;
    const Node *curr = head;
    
    while (curr != NULL) 
    {
        sum += curr->data;
        curr = curr->next;
    }
    
    return sum;
}

void list_remove_duplicates(Node **head) 
{
    if (head == NULL || *head == NULL) return;

    Node *curr = *head;
    
    while (curr != NULL) 
    {
        Node *runner = curr;
        
        while (runner->next != NULL) 
        {
            if (runner->next->data == curr->data) 
            {
                Node *duplicate = runner->next;
                runner->next = runner->next->next;
                free(duplicate);
            } 
            else 
            {
                runner = runner->next;
            }
        }
        curr = curr->next;
    }
}

int list_is_sorted(const Node *head) 
{
    if (head == NULL || head->next == NULL) return 1;

    const Node *curr = head;
    
    while (curr->next != NULL) 
    {
        if (curr->data > curr->next->data) return 0;
        curr = curr->next;
    }
    
    return 1;
}

void list_insert_sorted(Node **head, int value) 
{
    if (head == NULL) return;

    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL) return;
    
    new_node->data = value;

    if (*head == NULL || (*head)->data >= value) 
    {
        new_node->next = *head;
        *head = new_node;
        return;
    }

    Node *curr = *head;
    while (curr->next != NULL && curr->next->data < value) 
    {
        curr = curr->next;
    }
    
    new_node->next = curr->next;
    curr->next = new_node;
}