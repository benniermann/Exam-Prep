#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "task1_fileio.h"
#include "task2_queue.h"
#include "task3_strings.h"
#include "task4_bitops.h"
#include "task5_dynarray.h"

// ============================================================================
// TEST SWITCHES -- Setze auf 1 um die jeweilige Aufgabe zu testen
// ============================================================================
#define TEST_TASK_1 0 /* File I/O                        */
#define TEST_TASK_2 0 /* FIFO-Queue                      */
#define TEST_TASK_3 1 /* String-Operationen              */
#define TEST_TASK_4 0 /* Bit-Manipulation                */
#define TEST_TASK_5 0 /* Dynamisches double-Array        */

// ----------------------------------------------------------------------------
static void print_result(const char *name, int passed)
{
    printf("  %s %s\n", passed ? "[ OK ]" : "[FAIL]", name);
}

// ============================================================================
int main(void)
{
    printf("=== Klausurvorbereitung -- Uebungsserie 4 ===\n\n");

// ----------------------------------------------------------------------------
#if TEST_TASK_1
    printf("--- Aufgabe 1: File I/O ---\n");

    /* Hilfsfunktionen: Erstelle Testdateien direkt mit stdio */
    {
        /* --- count_lines --- */
        FILE *f = fopen("test_lines.txt", "w");
        if (f)
        {
            fprintf(f, "hallo\nwelt\ntest\n");
            fclose(f);
        }
        print_result("count_lines: 3 Zeilen", count_lines("test_lines.txt") == 3);

        f = fopen("test_empty.txt", "w");
        if (f)
            fclose(f);
        print_result("count_lines: leere Datei -> 0", count_lines("test_empty.txt") == 0);

        /* Zeile ohne abschliessendes \n */
        f = fopen("test_nonewline.txt", "w");
        if (f)
        {
            fprintf(f, "abc\ndef");
            fclose(f);
        }
        print_result("count_lines: letzte Zeile ohne \\n -> 2",
                     count_lines("test_nonewline.txt") == 2);

        print_result("count_lines: nicht existierende Datei -> -1",
                     count_lines("nicht_vorhanden_xyz.txt") == -1);
        print_result("count_lines: NULL -> -1", count_lines(NULL) == -1);
    }

    {
        /* --- read_ints_from_file --- */
        FILE *f = fopen("test_ints.txt", "w");
        if (f)
        {
            fprintf(f, "10\n-3\n42\n0\n999\n");
            fclose(f);
        }

        int buf[10] = {0};
        int n = read_ints_from_file("test_ints.txt", buf, 10);
        print_result("read_ints: liest 5 Werte", n == 5);
        print_result("read_ints: buf[0] == 10", buf[0] == 10);
        print_result("read_ints: buf[1] == -3", buf[1] == -3);
        print_result("read_ints: buf[4] == 999", buf[4] == 999);

        /* max_count kleiner als Datei */
        int buf2[3] = {0};
        int m = read_ints_from_file("test_ints.txt", buf2, 3);
        print_result("read_ints: max_count=3 -> liest 3", m == 3);
        print_result("read_ints: buf2[2] == 42", buf2[2] == 42);

        print_result("read_ints: NULL out -> -1",
                     read_ints_from_file("test_ints.txt", NULL, 10) == -1);
        print_result("read_ints: max_count=0 -> -1",
                     read_ints_from_file("test_ints.txt", buf, 0) == -1);
    }

    {
        /* --- file_max --- */
        FILE *f = fopen("test_max.txt", "w");
        if (f)
        {
            fprintf(f, "5\n-100\n77\n42\n-1\n");
            fclose(f);
        }

        int max_val = 0;
        print_result("file_max: max == 77",
                     file_max("test_max.txt", &max_val) == 0 && max_val == 77);

        /* Einelementige Datei */
        f = fopen("test_one.txt", "w");
        if (f)
        {
            fprintf(f, "42\n");
            fclose(f);
        }
        print_result("file_max: einziges Element -> 42",
                     file_max("test_one.txt", &max_val) == 0 && max_val == 42);

        print_result("file_max: leere Datei -> -1",
                     file_max("test_empty.txt", &max_val) == -1);
        print_result("file_max: NULL out -> -1",
                     file_max("test_max.txt", NULL) == -1);
        print_result("file_max: NULL filename -> -1",
                     file_max(NULL, &max_val) == -1);
    }

    {
        /* --- write_squares --- */
        print_result("write_squares: n=4 -> 0",
                     write_squares("test_squares.txt", 4) == 0);
        print_result("write_squares: n<=0 -> -1",
                     write_squares("test_squares.txt", 0) == -1);

        int buf[4] = {0};
        read_ints_from_file("test_squares.txt", buf, 4);
        print_result("write_squares: buf[0]==1", buf[0] == 1);
        print_result("write_squares: buf[1]==4", buf[1] == 4);
        print_result("write_squares: buf[2]==9", buf[2] == 9);
        print_result("write_squares: buf[3]==16", buf[3] == 16);
    }

    {
        /* --- number_lines --- */
        FILE *f = fopen("test_src.txt", "w");
        if (f)
        {
            fprintf(f, "erste\nzweite\ndritte\n");
            fclose(f);
        }

        int copied = number_lines("test_src.txt", "test_dst.txt");
        print_result("number_lines: gibt 3 zurueck", copied == 3);

        /* Pruefen ob Zieldatei korrekte Praefix hat */
        char line[64] = {0};
        FILE *dst = fopen("test_dst.txt", "r");
        int ok = 0;
        if (dst)
        {
            fgets(line, sizeof(line), dst);
            ok = (strncmp(line, "1: erste", 8) == 0);
            fclose(dst);
        }
        print_result("number_lines: erste Zeile beginnt mit '1: '", ok);

        print_result("number_lines: src nicht vorhanden -> -1",
                     number_lines("nicht_da.txt", "out.txt") == -1);
        print_result("number_lines: NULL src -> -1",
                     number_lines(NULL, "out.txt") == -1);
        print_result("number_lines: NULL dst -> -1",
                     number_lines("test_src.txt", NULL) == -1);
    }

    /* Temporaere Dateien aufraeumen */
    remove("test_lines.txt");
    remove("test_empty.txt");
    remove("test_nonewline.txt");
    remove("test_ints.txt");
    remove("test_max.txt");
    remove("test_one.txt");
    remove("test_squares.txt");
    remove("test_src.txt");
    remove("test_dst.txt");
    remove("out.txt");
    printf("\n");
#endif

// ----------------------------------------------------------------------------
#if TEST_TASK_2
    printf("--- Aufgabe 2: FIFO-Queue ---\n");

    /* create / destroy */
    {
        Queue *q = queue_create();
        print_result("queue_create: not NULL", q != NULL);
        print_result("queue_create: size == 0", q && q->size == 0);
        print_result("queue_create: capacity == 4", q && q->capacity == 4);
        print_result("queue_is_empty: neue Queue", queue_is_empty(q) == 1);
        print_result("queue_size: neue Queue -> 0", queue_size(q) == 0);
        queue_destroy(q);
        print_result("queue_destroy: kein Absturz", 1);
        queue_destroy(NULL);
        print_result("queue_destroy(NULL): kein Absturz", 1);
    }

    /* enqueue / dequeue -- FIFO-Reihenfolge */
    {
        Queue *q = queue_create();

        queue_enqueue(q, 10);
        queue_enqueue(q, 20);
        queue_enqueue(q, 30);

        print_result("size nach 3x enqueue == 3", queue_size(q) == 3);
        print_result("is_empty == 0", queue_is_empty(q) == 0);

        int err;
        int v1 = queue_dequeue(q, &err);
        print_result("dequeue: erstes Element == 10 (FIFO)", v1 == 10 && err == 0);
        print_result("size nach dequeue == 2", queue_size(q) == 2);

        int v2 = queue_dequeue(q, &err);
        print_result("dequeue: zweites Element == 20", v2 == 20 && err == 0);

        int v3 = queue_dequeue(q, &err);
        print_result("dequeue: drittes Element == 30", v3 == 30 && err == 0);
        print_result("queue jetzt leer", queue_is_empty(q) == 1);

        queue_dequeue(q, &err);
        print_result("dequeue auf leere Queue: err == -1", err == -1);

        queue_destroy(q);
    }

    /* peek */
    {
        Queue *q = queue_create();
        queue_enqueue(q, 42);
        queue_enqueue(q, 99);

        int err;
        int p = queue_peek(q, &err);
        print_result("peek: gibt 42 zurueck", p == 42 && err == 0);
        print_result("peek: size unveraendert == 2", queue_size(q) == 2);

        queue_dequeue(q, &err);
        print_result("peek nach dequeue: gibt 99", queue_peek(q, &err) == 99);

        queue_dequeue(q, &err);
        queue_peek(q, &err);
        print_result("peek auf leere Queue: err == -1", err == -1);

        queue_destroy(q);
    }

    /* Kapazitaetsverdopplung -- viele Elemente */
    {
        Queue *q = queue_create();
        for (int i = 0; i < 20; i++)
            queue_enqueue(q, i);
        print_result("enqueue 20 Elemente: size == 20", queue_size(q) == 20);
        print_result("capacity nach Wachstum >= 20", q->capacity >= 20);

        int err, ok = 1;
        for (int i = 0; i < 20; i++)
        {
            int v = queue_dequeue(q, &err);
            if (v != i || err != 0)
                ok = 0;
        }
        print_result("dequeue 20 Elemente: korrekte FIFO-Reihenfolge", ok);
        print_result("queue nach allem leer", queue_is_empty(q) == 1);
        queue_destroy(q);
    }
    printf("\n");
#endif

// ----------------------------------------------------------------------------
#if TEST_TASK_3
    printf("--- Aufgabe 3: String-Operationen ---\n");

    /* str_trim */
    {
        char *t;
        t = str_trim("  hallo  ");
        print_result("trim: '  hallo  ' -> 'hallo'", t && strcmp(t, "hallo") == 0);
        free(t);
        t = str_trim("\t test\n");
        print_result("trim: '\\t test\\n' -> 'test'", t && strcmp(t, "test") == 0);
        free(t);
        t = str_trim("ok");
        print_result("trim: 'ok' -> 'ok'", t && strcmp(t, "ok") == 0);
        free(t);
        t = str_trim("   ");
        print_result("trim: nur Leerzeichen -> ''", t && strcmp(t, "") == 0);
        free(t);
        t = str_trim("");
        print_result("trim: leerer String -> ''", t && strcmp(t, "") == 0);
        free(t);
        print_result("trim: NULL -> NULL", str_trim(NULL) == NULL);
    }

    /* str_to_int */
    {
        int out = 0;
        print_result("str_to_int: '42' -> 42", str_to_int("42", &out) == 0 && out == 42);
        print_result("str_to_int: ' -7' -> -7", str_to_int(" -7", &out) == 0 && out == -7);
        print_result("str_to_int: '0' -> 0", str_to_int("0", &out) == 0 && out == 0);
        print_result("str_to_int: '3abc' -> -1", str_to_int("3abc", &out) == -1);
        print_result("str_to_int: '' -> -1", str_to_int("", &out) == -1);
        print_result("str_to_int: NULL -> -1", str_to_int(NULL, &out) == -1);
    }

    /* str_starts_with */
    {
        print_result("starts_with: 'hallo welt', 'hallo' -> 1", str_starts_with("hallo welt", "hallo") == 1);
        print_result("starts_with: 'hallo', 'hallo welt' -> 0", str_starts_with("hallo", "hallo welt") == 0);
        print_result("starts_with: 'Test', 'test' -> 0", str_starts_with("Test", "test") == 0);
        print_result("starts_with: '', '' -> 1", str_starts_with("", "") == 1);
        print_result("starts_with: 'abc', '' -> 1", str_starts_with("abc", "") == 1);
        print_result("starts_with: NULL -> 0", str_starts_with(NULL, "a") == 0);
        print_result("starts_with: prefix NULL -> 0", str_starts_with("abc", NULL) == 0);
    }

    /* str_count_vowels */
    {
        print_result("count_vowels: 'Hallo Welt' -> 3", str_count_vowels("Hallo Welt") == 3);
        print_result("count_vowels: 'AEIOU' -> 5", str_count_vowels("AEIOU") == 5);
        print_result("count_vowels: 'xyz' -> 0", str_count_vowels("xyz") == 0);
        print_result("count_vowels: '' -> 0", str_count_vowels("") == 0);
        print_result("count_vowels: NULL -> 0", str_count_vowels(NULL) == 0);
        print_result("count_vowels: 'aAeEiIoOuU' -> 10", str_count_vowels("aAeEiIoOuU") == 10);
    }

    /* str_to_upper */
    {
        char *u;
        u = str_to_upper("hallo Welt!");
        print_result("to_upper: 'hallo Welt!' -> 'HALLO WELT!'", u && strcmp(u, "HALLO WELT!") == 0);
        free(u);
        u = str_to_upper("123abc");
        print_result("to_upper: '123abc' -> '123ABC'", u && strcmp(u, "123ABC") == 0);
        free(u);
        u = str_to_upper("");
        print_result("to_upper: '' -> ''", u && strcmp(u, "") == 0);
        free(u);
        print_result("to_upper: NULL -> NULL", str_to_upper(NULL) == NULL);
    }

    /* str_repeat */
    {
        char *r;
        r = str_repeat("ab", 3);
        print_result("repeat: 'ab' x3 -> 'ababab'", r && strcmp(r, "ababab") == 0);
        free(r);
        r = str_repeat("x", 1);
        print_result("repeat: 'x' x1 -> 'x'", r && strcmp(r, "x") == 0);
        free(r);
        r = str_repeat("hi", 0);
        print_result("repeat: 'hi' x0 -> ''", r && strcmp(r, "") == 0);
        free(r);
        print_result("repeat: NULL -> NULL", str_repeat(NULL, 3) == NULL);
        print_result("repeat: n<0 -> NULL", str_repeat("ab", -1) == NULL);
    }
    printf("\n");
#endif

// ----------------------------------------------------------------------------
#if TEST_TASK_4
    printf("--- Aufgabe 4: Bit-Manipulation ---\n");

    /* bit_set */
    print_result("bit_set(0, 0) == 1", bit_set(0u, 0) == 1u);
    print_result("bit_set(0b0101, 1) == 0b0111", bit_set(5u, 1) == 7u);
    print_result("bit_set(0b1111, 2) == 0b1111", bit_set(15u, 2) == 15u);
    print_result("bit_set(0, 31) == 0x80000000", bit_set(0u, 31) == 0x80000000u);

    /* bit_clear */
    print_result("bit_clear(0b1111, 0) == 14", bit_clear(15u, 0) == 14u);
    print_result("bit_clear(0b0101, 2) == 1", bit_clear(5u, 2) == 1u);
    print_result("bit_clear(0b0000, 1) == 0", bit_clear(0u, 1) == 0u);
    print_result("bit_clear(0xFF, 7) == 0x7F", bit_clear(0xFFu, 7) == 0x7Fu);

    /* bit_toggle */
    print_result("bit_toggle(0, 3) == 8", bit_toggle(0u, 3) == 8u);
    print_result("bit_toggle(0b1010, 1) == 8", bit_toggle(10u, 1) == 8u);
    print_result("bit_toggle(0b1010, 3) == 2", bit_toggle(10u, 3) == 2u);
    print_result("bit_toggle doppelt = original", bit_toggle(bit_toggle(42u, 5), 5) == 42u);

    /* bit_get */
    print_result("bit_get(0b1010, 1) == 1", bit_get(10u, 1) == 1);
    print_result("bit_get(0b1010, 0) == 0", bit_get(10u, 0) == 0);
    print_result("bit_get(0b1010, 3) == 1", bit_get(10u, 3) == 1);
    print_result("bit_get(0, 15) == 0", bit_get(0u, 15) == 0);
    print_result("bit_get(0xFFFFFFFF, 31) == 1", bit_get(0xFFFFFFFFu, 31) == 1);

    /* count_ones */
    print_result("count_ones(0) == 0", count_ones(0u) == 0);
    print_result("count_ones(0b1111) == 4", count_ones(15u) == 4);
    print_result("count_ones(0b10110100) == 4", count_ones(0b10110100u) == 4);
    print_result("count_ones(0xFFFFFFFF) == 32", count_ones(0xFFFFFFFFu) == 32);
    print_result("count_ones(1) == 1", count_ones(1u) == 1);

    /* is_power_of_two */
    print_result("is_power_of_two(0) == 0", is_power_of_two(0u) == 0);
    print_result("is_power_of_two(1) == 1", is_power_of_two(1u) == 1);
    print_result("is_power_of_two(2) == 1", is_power_of_two(2u) == 1);
    print_result("is_power_of_two(4) == 1", is_power_of_two(4u) == 1);
    print_result("is_power_of_two(6) == 0", is_power_of_two(6u) == 0);
    print_result("is_power_of_two(32) == 1", is_power_of_two(32u) == 1);
    print_result("is_power_of_two(33) == 0", is_power_of_two(33u) == 0);

    /* reverse_byte */
    print_result("reverse_byte(0b10110001) == 0b10001101", reverse_byte(0b10110001u) == 0b10001101u);
    print_result("reverse_byte(0b00000001) == 128", reverse_byte(1u) == 128u);
    print_result("reverse_byte(0b11111111) == 255", reverse_byte(0xFFu) == 0xFFu);
    print_result("reverse_byte(0b00000000) == 0", reverse_byte(0u) == 0u);
    print_result("reverse_byte(0b10000000) == 1", reverse_byte(0x80u) == 1u);
    printf("\n");
#endif

// ----------------------------------------------------------------------------
#if TEST_TASK_5
    printf("--- Aufgabe 5: Dynamisches double-Array ---\n");

    /* create / destroy */
    {
        DynArray *a = da_create();
        print_result("da_create: not NULL", a != NULL);
        print_result("da_create: size == 0", a && a->size == 0);
        print_result("da_create: capacity == 4", a && a->capacity == 4);
        da_destroy(a);
        print_result("da_destroy: kein Absturz", 1);
        da_destroy(NULL);
        print_result("da_destroy(NULL): kein Absturz", 1);
    }

    /* da_push / da_get */
    {
        DynArray *a = da_create();
        da_push(a, 1.5);
        da_push(a, 2.5);
        da_push(a, 3.5);

        print_result("size nach 3x push == 3", a->size == 3);

        int err;
        print_result("da_get(0) == 1.5", fabs(da_get(a, 0, &err) - 1.5) < 1e-9 && err == 0);
        print_result("da_get(1) == 2.5", fabs(da_get(a, 1, &err) - 2.5) < 1e-9 && err == 0);
        print_result("da_get(2) == 3.5", fabs(da_get(a, 2, &err) - 3.5) < 1e-9 && err == 0);

        da_get(a, 3, &err);
        print_result("da_get(3) ungueltig: err == -1", err == -1);
        da_get(a, -1, &err);
        print_result("da_get(-1) ungueltig: err == -1", err == -1);

        da_destroy(a);
    }

    /* da_remove_at */
    {
        DynArray *a = da_create();
        da_push(a, 1.0);
        da_push(a, 2.0);
        da_push(a, 3.0);
        da_push(a, 4.0);

        int err;
        print_result("da_remove_at(1) -> 0", da_remove_at(a, 1) == 0);
        print_result("size nach remove == 3", a->size == 3);
        print_result("a[0] == 1.0 nach remove", fabs(da_get(a, 0, &err) - 1.0) < 1e-9);
        print_result("a[1] == 3.0 nach remove", fabs(da_get(a, 1, &err) - 3.0) < 1e-9);
        print_result("a[2] == 4.0 nach remove", fabs(da_get(a, 2, &err) - 4.0) < 1e-9);

        print_result("da_remove_at ungueltig -> -1", da_remove_at(a, 99) == -1);
        print_result("da_remove_at negativ -> -1", da_remove_at(a, -1) == -1);

        /* Erstes Element entfernen */
        da_remove_at(a, 0);
        print_result("a[0] nach remove(0) == 3.0", fabs(da_get(a, 0, &err) - 3.0) < 1e-9);

        da_destroy(a);
    }

    /* da_min / da_max / da_mean */
    {
        DynArray *a = da_create();
        da_push(a, 5.0);
        da_push(a, -2.0);
        da_push(a, 8.5);
        da_push(a, 1.0);

        int err;
        print_result("da_min == -2.0", fabs(da_min(a, &err) - (-2.0)) < 1e-9 && err == 0);
        print_result("da_max == 8.5", fabs(da_max(a, &err) - 8.5) < 1e-9 && err == 0);
        print_result("da_mean == 3.125", fabs(da_mean(a, &err) - 3.125) < 1e-9 && err == 0);

        /* Einelementiges Array */
        DynArray *b = da_create();
        da_push(b, 7.0);
        print_result("da_min einelem == 7.0", fabs(da_min(b, &err) - 7.0) < 1e-9);
        print_result("da_max einelem == 7.0", fabs(da_max(b, &err) - 7.0) < 1e-9);
        print_result("da_mean einelem == 7.0", fabs(da_mean(b, &err) - 7.0) < 1e-9);
        da_destroy(b);

        /* Leeres Array */
        DynArray *c = da_create();
        da_min(c, &err);
        print_result("da_min leer: err == -1", err == -1);
        da_max(c, &err);
        print_result("da_max leer: err == -1", err == -1);
        da_mean(c, &err);
        print_result("da_mean leer: err == -1", err == -1);
        da_destroy(c);

        da_destroy(a);
    }

    /* da_sort */
    {
        DynArray *a = da_create();
        da_push(a, 3.0);
        da_push(a, 1.5);
        da_push(a, 4.0);
        da_push(a, 1.0);
        da_push(a, 5.0);

        da_sort(a);

        int err;
        print_result("da_sort: a[0] == 1.0", fabs(da_get(a, 0, &err) - 1.0) < 1e-9);
        print_result("da_sort: a[1] == 1.5", fabs(da_get(a, 1, &err) - 1.5) < 1e-9);
        print_result("da_sort: a[2] == 3.0", fabs(da_get(a, 2, &err) - 3.0) < 1e-9);
        print_result("da_sort: a[3] == 4.0", fabs(da_get(a, 3, &err) - 4.0) < 1e-9);
        print_result("da_sort: a[4] == 5.0", fabs(da_get(a, 4, &err) - 5.0) < 1e-9);

        /* Kapazitaetswachstum: 20 Elemente */
        DynArray *b = da_create();
        for (int i = 19; i >= 0; i--)
            da_push(b, (double)i);
        da_sort(b);
        int sorted = 1;
        for (int i = 0; i < 20; i++)
            if (fabs(da_get(b, i, &err) - (double)i) > 1e-9)
                sorted = 0;
        print_result("da_sort: 20 Elemente korrekt sortiert", sorted);
        print_result("da_sort: size unveraendert == 20", b->size == 20);
        da_destroy(b);

        da_sort(NULL); /* kein Absturz */
        print_result("da_sort(NULL): kein Absturz", 1);
        da_destroy(a);
    }
    printf("\n");
#endif

    printf("=== Tests abgeschlossen ===\n");
    return 0;
}
