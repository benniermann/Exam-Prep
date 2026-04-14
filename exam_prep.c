#include "exam_prep.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void compress_rle(const char* src, char* dest)
{
    
    if (src[0] == '\0') 
    {
        dest[0] = '\0';
        return;
    }

    char current = src[0];
    int count = 1;
    int pos = 0;

    for (int i = 1; src[i] != '\0'; i++)
    {
        if(current == src[i]) count++;
        else
        {
            pos += sprintf(dest + pos, "%c%d", current, count);
            current = src[i];
            count = 1;
        }
    }
    sprintf(dest + pos, "%c%d", current, count);
}

Item* find_lowest_stock(Item* items, int length)
{
    Item* lowest = &items[0];
    for(int i = 0; i < length; i++)
    {
        if(items[i].quantity < lowest->quantity)
        {
            lowest = &items[i];
        }
    }
    return lowest;
}

void apply_discount(Item* items, int length, const char* target_category, float discount_percent)
{
    for(int i = 0; i < length; i++)
    {
        if(strcmp(items[i].category, target_category) == 0)
        {
            items[i].price = items[i].price * (1 - (discount_percent / 100)); 
        }
    }
}

int** create_matrix(int rows, int cols)
{
    int** matrix = malloc(sizeof(int*) * rows);

    for(int i = 0; i < rows; i++)
    {
        matrix[i] = malloc(sizeof(int) * cols);
        if(matrix[i] == NULL)
        {
            for (int j = 0; j < i; j++)
            {
                free(matrix[j]);
            }                
            free(matrix);
            return NULL;

        }
    }
    return matrix;
}

int** transpose_matrix(int** matrix, int rows, int cols)
{
    int** matrix1 = create_matrix(cols, rows);
    for (int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            matrix1[j][i] = matrix[i][j];
        }
    }
    return matrix1;
}

void free_matrix(int** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        free(matrix[i]);
        
    }
    free(matrix);
}

void list_append(Node** head_ref, int value)
{  
    Node* new_node = malloc(sizeof(Node));
    if(new_node == NULL) return;

    new_node->data = value;
    new_node->next = NULL;

    if(*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    Node* current = *head_ref;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
}

void list_filter_even(Node** head_ref)
{
    Node* current = *head_ref;
    while(current->next != NULL && current != NULL)
    {
        if(current->next->data % 2 == 0)
        {
            Node* delete = current->next;
            current->next = current->next->next;
            free(delete);
        }
        else
        {
            current = current->next;
        }
    }
}

void list_free(Node** head_ref)
{
    Node* current = *head_ref;
    while(current != NULL)
    {
        Node* next = current->next;
        free(current);
        current = next;
    }
    *head_ref = NULL;
}
