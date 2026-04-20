#include "task1_fileio.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

int count_lines(const char *filename)
{
    if(filename == NULL) return -1;

    FILE *file = fopen(filename, "r");
    if(!file) return -1;

    int count = 0;
    int ch;
    int last_char = EOF;

    while ((ch = fgetc(file)) != EOF) 
    {
        if (ch == '\n') 
        {
            count++;
        }
        last_char = ch; // Aktuelles Zeichen für später merken
    }

    if (last_char != EOF && last_char != '\n') 
    {
        count++;
    }

    fclose(file);

    return count;
}

int read_ints_from_file(const char *filename, int *out, int max_count)
{
    if (filename == NULL || out == NULL || max_count <= 0)
    {
        return -1;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return -1;
    }

    int count = 0;
    char buffer[256];

    while (count < max_count && fgets(buffer, sizeof(buffer), file))
    {
        int value;
        if (sscanf(buffer, "%d", &value) == 1)
        {
            out[count] = value;
            count++;
        }
    }

    fclose(file);
    return count;
}

int file_max(const char *filename, int *out_max)
{
    if (filename == NULL || out_max == NULL)
    {
        return -1;
    }

    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        return -1;
    }

    int max_val;
    int found_any = 0;
    char buffer[256];

    while (fgets(buffer, sizeof(buffer), file))
    {
        int val;
        if (sscanf(buffer, "%d", &val) == 1)
        {
            if (!found_any)
            {
                max_val = val;
                found_any = 1;
            }
            else if (val > max_val)
            {
                max_val = val;
            }
        }
    }

    fclose(file);

    if (!found_any)
    {
        return -1;
    }

    *out_max = max_val;
    return 0;
}

int write_squares(const char *filename, int n)
{
    if (filename == NULL || n <= 0)
    {
        return -1;
    }

    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        return -1;
    }

    for (int i = 1; i <= n; i++)
    {
        fprintf(file, "%d\n", i * i);
    }

    fclose(file);
    return 0;
}

int number_lines(const char *src, const char *dst)
{
    if (src == NULL || dst == NULL)
    {
        return -1;
    }

    FILE *file1 = fopen(src, "r");
    if (file1 == NULL)
    {
        return -1;
    }

    FILE *file2 = fopen(dst, "w");
    if (file2 == NULL)
    {
        fclose(file1);
        return -1;
    }

    int count = 0;
    int ch;
    int new_line = 1;

    while ((ch = fgetc(file1)) != EOF)
    {
        if (new_line)
        {
            count++;
            fprintf(file2, "%d: ", count);
            new_line = 0;
        }

        fputc(ch, file2);

        if (ch == '\n')
        {
            new_line = 1;
        }
    }

    fclose(file1);
    fclose(file2);

    return count;
}