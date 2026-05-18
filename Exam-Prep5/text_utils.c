#include <stdlib.h>
#include <string.h>
#include "text_utils.h"
#include <ctype.h>

int char_frequency(const char *text, char c)
{
    if (text == NULL)
        return 0;

    int count = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == c)
            count++;
    }

    return count;
}

char *remove_digits(const char *text)
{
    char *buf = malloc(strlen(text) + 1);
    int index = 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isdigit(text[i]))
        {
            buf[index] = text[i];
            index++;
        }
    }
    buf[index] = '\0';
    return buf;
}

int is_uppercase_string(const char *text)
{
    if (text == NULL)
        return 0;

    for (int i = 0; text[i] != '\0'; i++)
    {
        if (!isupper(text[i]))
            return 0;
    }

    return 1;
}

char *reverse_words(const char *text)
{
    if (text == NULL)
        return NULL;

    int len = strlen(text);
    char *result = malloc(len + 1);
    if (result == NULL)
        return NULL;

    strcpy(result, text);

    int start = 0;
    int end = len - 1;
    while (start < end)
    {
        char temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
    }

    int word_start = 0;
    for (int i = 0; i <= len; i++)
    {
        if (result[i] == ' ' || result[i] == '\0')
        {
            int w_start = word_start;
            int w_end = i - 1;
            while (w_start < w_end)
            {
                char temp = result[w_start];
                result[w_start] = result[w_end];
                result[w_end] = temp;
                w_start++;
                w_end--;
            }
            word_start = i + 1;
        }
    }

    return result;
}