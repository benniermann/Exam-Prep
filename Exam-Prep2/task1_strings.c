#include "task1_strings.h"
#include <stddef.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int is_palindrome(const char *s) 
{
    if(s == NULL) return 0;

    int len = strlen(s);

    if (len == 0) return 1;

    int left = 0;
    int right = len - 1;

    while(left < right)
    {
        if(tolower(s[left]) != tolower(s[right]))
        {
            return 0;
        }
        
        left++;
        right--;
    }
    
    return 1;
}

int count_words(const char *s) 
{
    if(s == NULL) return 0;
    int count = 0;
    int i = 0;
    int in_word = 0;
    
    while (s[i] != '\0') 
    {
        if (s[i] != ' ') 
        {
            if (in_word == 0) 
            {
                count++;
                in_word = 1;
            }
        } 
        else 
        {
            in_word = 0; 
        }
        i++;
    }

    return count;
}

char *str_reverse(const char *s) 
{
    if (s == NULL) return NULL;

    int len = strlen(s);
    char *reversed = malloc(len + 1);

    if (reversed == NULL) return NULL;

    for (int i = 0; i < len; i++) 
    {
        reversed[i] = s[len - 1 - i];
    }
    
    reversed[len] = '\0';

    return reversed;
}

int str_replace_char(char *s, char old_char, char new_char) 
{
    if(s == NULL) return -1;
    
    int len = strlen(s);
    int count = 0;

    //for(int i = 0; s[i] != '\0'; i++)   damit braucht man strlen in diesem fall nicht
    for(int i = 0; i < len; i++)
    {
        if(s[i] == old_char)
        {
            s[i] = new_char;
            count++;
        }
    }

    return count;
}