#ifndef PLAYLIST_H
#define PLAYLIST_H

#define MAX_NAME_LEN 64

typedef struct Song
{
    char name[MAX_NAME_LEN];
    int duration;
    struct Song *next;
} Song;

/*
 * Fügt einen neuen Song am Ende der Liste ein.
 * Gibt den neuen Listenanfang zurück.
 */
Song *playlist_push_back(Song *head, const char *name, int duration);

/*
 * Berechnet die Gesamtdauer aller Songs.
 */
int playlist_total_duration(const Song *head);

/*
 * Löscht den ersten Song mit passendem Namen.
 * Gibt den neuen Listenanfang zurück.
 */
Song *playlist_remove(Song *head, const char *name);

/*
 * Gibt den Speicher der gesamten Liste frei.
 */
void playlist_destroy(Song *head);

#endif