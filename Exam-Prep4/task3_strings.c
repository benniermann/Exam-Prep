#include "task3_strings.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

char *str_trim(const char *s)
{
    if (s == NULL)
        return NULL;

    char *copy = malloc(strlen(s) + 1);
    if (!copy)
        return NULL;

    strcpy(copy, s);

    int start = 0;
    while (copy[start] == ' ' || copy[start] == '\t' || copy[start] == '\n' || copy[start] == '\r')
    {
        start++;
    }

    if (start > 0)
    {
        memmove(copy, copy + start, strlen(copy) - start + 1);
    }

    if (copy[0] == '\0')
    {
        return copy;
    }

    int end = strlen(copy) - 1;
    while (end >= 0 && (copy[end] == ' ' || copy[end] == '\t' || copy[end] == '\n' || copy[end] == '\r'))
    {
        end--;
    }

    copy[end + 1] = '\0';

    return copy;
}

int str_to_int(const char *s, int *out)
{
    if (!s || !out)
    {
        return -1;
    }

    while (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r')
    {
        s++;
    }

    if (*s == '\0')
    {
        return -1;
    }

    int sign = 1;
    if (*s == '-')
    {
        sign = -1;
        s++;
    }
    else if (*s == '+')
    {
        s++;
    }

    if (*s < '0' || *s > '9')
    {
        return -1;
    }

    int result = 0;
    while (*s != '\0')
    {
        if (*s < '0' || *s > '9')
        {
            return -1;
        }
        result = result * 10 + (*s - '0');
        s++;
    }

    *out = result * sign;

    return 0;
}

int str_starts_with(const char *s, const char *prefix)
{
    if (s == NULL || prefix == NULL)
        return 0;

    int i = 0;

    while (prefix[i] != '\0')
    {
        if (s[i] != prefix[i])
            return 0;

        i++;
    }

    return 1;
}

int str_count_vowels(const char *s)
{
    if (s == NULL)
        return 0;

    int count = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            count++;
        }
    }

    return count;
}

char *str_to_upper(const char *s)
{
    if (s == NULL)
    {
        return NULL;
    }

    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    char *result = malloc(len + 1);
    if (result == NULL)
    {
        return NULL;
    }

    for (int i = 0; i <= len; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            result[i] = s[i] - 32;
        }
        else
        {
            result[i] = s[i];
        }
    }

    return result;
}

char *str_repeat(const char *s, int n)
{
    if (s == NULL || n < 0)
        return NULL;

    char *copy = malloc(strlen(s) * n + 1);
    if (!copy)
        return NULL;

    if (n == 0)
    {
        copy[0] = '\0';
        return copy;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (s[j] != '\0')
        {
            copy[count] = s[j];
            count++;
            j++;
        }
    }
    copy[count] = '\0';

    return copy;
}