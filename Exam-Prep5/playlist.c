#include <stdlib.h>
#include <string.h>
#include "playlist.h"

Song *playlist_push_back(Song *head, const char *name, int duration)
{
    Song *new_node = malloc(sizeof(Song));
    if (new_node == NULL)
        return head;

    int i = 0;
    while (name[i] != '\0' && i < MAX_NAME_LEN - 1)
    {
        new_node->name[i] = name[i];
        i++;
    }
    new_node->name[i] = '\0';

    new_node->duration = duration;
    new_node->next = NULL;

    if (head == NULL)
    {
        return new_node;
    }

    Song *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = new_node;

    return head;
}

int playlist_total_duration(const Song *head)
{
    int total = 0;
    const Song *curr = head;
    while (curr != NULL)
    {
        total += curr->duration;
        curr = curr->next;
    }
    return total;
}

Song *playlist_remove(Song *head, const char *name)
{
    if (head == NULL)
        return NULL;

    int match = 0;
    int i = 0;
    while (head->name[i] == name[i])
    {
        if (head->name[i] == '\0')
        {
            match = 1;
            break;
        }
        i++;
    }

    if (match)
    {
        Song *new_head = head->next;
        free(head);
        return new_head;
    }

    Song *curr = head;
    while (curr->next != NULL)
    {
        match = 0;
        i = 0;
        while (curr->next->name[i] == name[i])
        {
            if (curr->next->name[i] == '\0')
            {
                match = 1;
                break;
            }
            i++;
        }

        if (match)
        {
            Song *to_delete = curr->next;
            curr->next = curr->next->next;
            free(to_delete);
            break;
        }
        curr = curr->next;
    }

    return head;
}

void playlist_destroy(Song *head)
{
    Song *curr = head;
    while (curr != NULL)
    {
        Song *next = curr->next;
        free(curr);
        curr = next;
    }
}