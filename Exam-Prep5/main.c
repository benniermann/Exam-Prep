#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "library.h"
#include "sensor.h"
#include "text_utils.h"
#include "recursion.h"
#include "playlist.h"

#define FLOAT_EPSILON 0.001

static void print_result(const char *test_name, int passed)
{
       if (passed)
              printf("[PASS] %s\n", test_name);
       else
              printf("[FAIL] %s\n", test_name);
}

int main(void)
{
       printf("=====================================\n");
       printf("PROGRAMMIEREN I - TESTSUITE\n");
       printf("=====================================\n\n");

       /*
        * =====================================
        * AUFGABE 1: BOOKS
        * =====================================
        */

       printf("===== AUFGABE 1: BOOKS =====\n");

       Book books[] = {
           {1, "C Grundlagen", 250, 2.3f},
           {2, "Algorithmen", 500, 1.7f},
           {3, "Netzwerke", 320, 2.0f}};

       float avg = average_rating(books, 3);

       print_result(
           "average_rating",
           fabs(avg - 2.0f) < FLOAT_EPSILON);

       Book *longest = find_longest_book(books, 3);

       print_result(
           "find_longest_book",
           longest != NULL &&
               strcmp(longest->title, "Algorithmen") == 0);

       int count = count_books_above_rating(books, 3, 2.0f);

       print_result(
           "count_books_above_rating",
           count == 2);

       sort_books_by_pages(books, 3);

       int sorted_correct =
           books[0].pages == 250 &&
           books[1].pages == 320 &&
           books[2].pages == 500;

       print_result(
           "sort_books_by_pages",
           sorted_correct);

       printf("\n");

       /*
        * =====================================
        * AUFGABE 2: SENSOR
        * =====================================
        */

       printf("===== AUFGABE 2: SENSOR =====\n");

       Sensor *sensors = create_sensor_array(4);

       int create_ok = (sensors != NULL);

       print_result(
           "create_sensor_array",
           create_ok);

       if (sensors != NULL)
       {
              sensors[0].temperature = 20.5;
              sensors[0].active = 1;

              sensors[1].temperature = 35.2;
              sensors[1].active = 1;

              sensors[2].temperature = 12.0;
              sensors[2].active = 1;

              sensors[3].temperature = 40.1;
              sensors[3].active = 0;

              double sensor_avg =
                  average_active_temperature(sensors, 4);

              print_result(
                  "average_active_temperature",
                  fabs(sensor_avg - 22.566) < 0.01);

              deactivate_below_threshold(sensors, 4, 15.0);

              print_result(
                  "deactivate_below_threshold",
                  sensors[2].active == 0);

              int hottest = find_hottest_sensor(sensors, 4);

              print_result(
                  "find_hottest_sensor",
                  hottest == 3);

              free(sensors);
       }

       printf("\n");

       /*
        * =====================================
        * AUFGABE 3: STRINGS
        * =====================================
        */

       printf("===== AUFGABE 3: STRINGS =====\n");

       int freq = char_frequency("banane", 'a');

       print_result(
           "char_frequency",
           freq == 2);

       char *nodigits = remove_digits("a1b2c3d4");

       int remove_digits_ok =
           nodigits != NULL &&
           strcmp(nodigits, "abcd") == 0;

       print_result(
           "remove_digits",
           remove_digits_ok);

       free(nodigits);

       int uppercase = is_uppercase_string("HELLOWORLD");

       print_result(
           "is_uppercase_string",
           uppercase == 1);

       char *rev = reverse_words("programmieren macht spass");

       int reverse_ok =
           rev != NULL &&
           strcmp(rev, "spass macht programmieren") == 0;

       print_result(
           "reverse_words",
           reverse_ok);

       free(rev);

       printf("\n");

       /*
        * =====================================
        * AUFGABE 4: REKURSION
        * =====================================
        */

       printf("===== AUFGABE 4: REKURSION =====\n");

       int sum = recursive_sum(10);

       print_result(
           "recursive_sum",
           sum == 55);

       int nums[] = {1, 2, 3, 4, 5, 6};

       int even_count =
           recursive_count_even(nums, 6);

       print_result(
           "recursive_count_even",
           even_count == 3);

       int is_number =
           recursive_is_number("123456");

       print_result(
           "recursive_is_number",
           is_number == 1);

       long long power =
           recursive_power(2, 10);

       print_result(
           "recursive_power",
           power == 1024);

       printf("\n");

       /*
        * =====================================
        * AUFGABE 5: LINKED LIST
        * =====================================
        */

       printf("===== AUFGABE 5: LINKED LIST =====\n");

       Song *playlist = NULL;

       playlist = playlist_push_back(
           playlist,
           "Song A",
           120);

       playlist = playlist_push_back(
           playlist,
           "Song B",
           200);

       playlist = playlist_push_back(
           playlist,
           "Song C",
           150);

       int total =
           playlist_total_duration(playlist);

       print_result(
           "playlist_total_duration",
           total == 470);

       playlist = playlist_remove(
           playlist,
           "Song B");

       int total_after_remove =
           playlist_total_duration(playlist);

       print_result(
           "playlist_remove",
           total_after_remove == 270);

       playlist_destroy(playlist);

       printf("\n=====================================\n");
       printf("TESTS ABGESCHLOSSEN\n");
       printf("=====================================\n");

       return 0;
}