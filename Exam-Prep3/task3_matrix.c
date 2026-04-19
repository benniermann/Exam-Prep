#include "task3_matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <math.h>

int **matrix_create(int rows, int cols) 
{
    int** matrix = malloc(sizeof(int*) * rows);
    

    for(int i = 0; i < rows; i++)
    {
        matrix[i] = calloc(cols, sizeof(int));
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

void matrix_free(int **m, int rows) 
{
    if(m == NULL) return;

    for (int i = 0; i < rows; i++)
    {
        free(m[i]);   
    }
    free(m);
}

void matrix_scale(int **m, int rows, int cols, int factor) 
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            m[i][j] *= factor;
        }
    }

}

int **matrix_add(int **a, int **b, int rows, int cols) 
{
    int** matrix = matrix_create(rows, cols);
    if(!matrix) return NULL;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            matrix[i][j] = a[i][j] + b[i][j];
        }
    }

    return matrix;
}

int matrix_is_symmetric(int **m, int n) 
{
    if(m == NULL|| n <= 0) return 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(m[i][j] != m[j][i])
            {
                return 0;
            }
        }
    }

    return 1;
}

int matrix_trace(int **m, int n) 
{
    if(m == NULL || n <= 0) return 0;

    int sum = m[0][0];

    for(int i = 1; i < n; i++)
    {
        sum += m[i][i];
    }

    return sum;
}