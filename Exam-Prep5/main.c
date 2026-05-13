#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "task1_rekursion.h"
#include "task2_linked_list.h"
#include "task3_matrix.h"
#include "task4_encoding.h"

// ============================================================================
// TEST SWITCHES -- Setze auf 1 um die jeweilige Aufgabe zu testen
// ============================================================================
#define TEST_TASK_1 0 /* Rekursion                        */
#define TEST_TASK_2 1 /* Einfach verkettete Liste         */
#define TEST_TASK_3 0 /* Matrix                           */
#define TEST_TASK_4 0 /* Encoding / Caesar & RLE          */

// ----------------------------------------------------------------------------
static void print_result(const char *name, int passed)
{
    printf("  %s %s\n", passed ? "[ OK ]" : "[FAIL]", name);
}

// ============================================================================
int main(void)
{
    printf("=== Klausur -- C Uebungsserie ===\n\n");

// ----------------------------------------------------------------------------
#if TEST_TASK_1
    printf("--- Aufgabe 1: Rekursion ---\n");

    /* fast_power */
    print_result("fast_power(2, 0) == 1", fast_power(2, 0) == 1);
    print_result("fast_power(2, 1) == 2", fast_power(2, 1) == 2);
    print_result("fast_power(2, 10) == 1024", fast_power(2, 10) == 1024);
    print_result("fast_power(3, 4) == 81", fast_power(3, 4) == 81);
    print_result("fast_power(5, 3) == 125", fast_power(5, 3) == 125);
    print_result("fast_power(1, 99) == 1", fast_power(1, 99) == 1);

    /* gcd */
    print_result("gcd(12, 8) == 4", gcd(12, 8) == 4);
    print_result("gcd(7, 3) == 1", gcd(7, 3) == 1);
    print_result("gcd(100, 75) == 25", gcd(100, 75) == 25);
    print_result("gcd(0, 5) == 5", gcd(0, 5) == 5);
    print_result("gcd(9, 9) == 9", gcd(9, 9) == 9);

    /* digit_sum */
    print_result("digit_sum(0) == 0", digit_sum(0) == 0);
    print_result("digit_sum(5) == 5", digit_sum(5) == 5);
    print_result("digit_sum(123) == 6", digit_sum(123) == 6);
    print_result("digit_sum(999) == 27", digit_sum(999) == 27);
    print_result("digit_sum(100) == 1", digit_sum(100) == 1);

    /* binary_search */
    {
        int arr[] = {1, 3, 5, 7, 9, 11, 13};
        int n = 7;
        print_result("binary_search: gefunden idx 0", binary_search(arr, 0, n - 1, 1) == 0);
        print_result("binary_search: gefunden idx 3", binary_search(arr, 0, n - 1, 7) == 3);
        print_result("binary_search: gefunden idx 6", binary_search(arr, 0, n - 1, 13) == 6);
        print_result("binary_search: nicht gefunden -> -1", binary_search(arr, 0, n - 1, 6) == -1);
        print_result("binary_search: nicht gefunden -> -1", binary_search(arr, 0, n - 1, 0) == -1);
    }

    /* count_char */
    print_result("count_char('l' in 'hallo') == 2", count_char("hallo", 'l') == 2);
    print_result("count_char('a' in 'banana') == 3", count_char("banana", 'a') == 3);
    print_result("count_char('z' in 'hallo') == 0", count_char("hallo", 'z') == 0);
    print_result("count_char: leerer String == 0", count_char("", 'a') == 0);
    print_result("count_char: NULL == 0", count_char(NULL, 'a') == 0);

    printf("\n");
#endif

// ----------------------------------------------------------------------------
#if TEST_TASK_2
    printf("--- Aufgabe 2: Einfach verkettete Liste ---\n");

    /* slist_create / slist_destroy */
    {
        SList *list = slist_create();
        print_result("slist_create: not NULL", list != NULL);
        print_result("slist_create: size == 0", list && list->size == 0);
        print_result("slist_create: head == NULL", list && list->head == NULL);
        print_result("slist_create: tail == NULL", list && list->tail == NULL);
        slist_destroy(list);
        print_result("slist_destroy: kein Absturz", 1);
        slist_destroy(NULL);
        print_result("slist_destroy(NULL): kein Absturz", 1);
    }

    /* slist_push_front / slist_push_back */
    {
        SList *list = slist_create();

        print_result("push_front: gibt 0 zurueck", slist_push_front(list, 10) == 0);
        print_result("push_front: size == 1", list->size == 1);
        print_result("push_front: head->value == 10", list->head && list->head->value == 10);
        print_result("push_front: tail == head", list->head == list->tail);

        slist_push_front(list, 20);
        print_result("push_front zweimal: head->value == 20", list->head->value == 20);
        print_result("push_front zweimal: tail->value == 10", list->tail->value == 10);
        print_result("push_front zweimal: size == 2", list->size == 2);

        slist_push_back(list, 30);
        print_result("push_back: tail->value == 30", list->tail->value == 30);
        print_result("push_back: size == 3", list->size == 3);

        slist_destroy(list);
    }

    /* slist_pop_front */
    {
        SList *list = slist_create();
        slist_push_back(list, 1);
        slist_push_back(list, 2);
        slist_push_back(list, 3);

        int err;
        int v = slist_pop_front(list, &err);
        print_result("pop_front: Wert == 1", v == 1 && err == 0);
        print_result("pop_front: size == 2", list->size == 2);
        print_result("pop_front: head->value == 2", list->head->value == 2);

        slist_pop_front(list, &err);
        slist_pop_front(list, &err);
        print_result("pop_front: Liste jetzt leer", list->size == 0 && list->head == NULL);

        slist_pop_front(list, &err);
        print_result("pop_front: leere Liste: err == -1", err == -1);

        slist_destroy(list);
    }

    /* slist_remove_at */
    {
        SList *list = slist_create();
        slist_push_back(list, 10);
        slist_push_back(list, 20);
        slist_push_back(list, 30);
        slist_push_back(list, 40);

        print_result("remove_at(1): gibt 0", slist_remove_at(list, 1) == 0);
        print_result("remove_at: size == 3", list->size == 3);
        print_result("remove_at: head == 10", list->head->value == 10);
        print_result("remove_at: head->next == 30", list->head->next->value == 30);

        /* Letztes Element entfernen */
        slist_remove_at(list, 2);
        print_result("remove_at letztes: tail == 30", list->tail->value == 30);
        print_result("remove_at letztes: size == 2", list->size == 2);

        /* Erstes Element entfernen */
        slist_remove_at(list, 0);
        print_result("remove_at(0): head == 30", list->head->value == 30);

        print_result("remove_at ungueltig -> -1", slist_remove_at(list, 99) == -1);
        print_result("remove_at negativ -> -1", slist_remove_at(list, -1) == -1);

        slist_destroy(list);
    }

    /* slist_to_array */
    {
        SList *list = slist_create();
        slist_push_back(list, 5);
        slist_push_back(list, 10);
        slist_push_back(list, 15);

        int *arr = slist_to_array(list);
        print_result("to_array: arr != NULL", arr != NULL);
        print_result("to_array: arr[0] == 5", arr && arr[0] == 5);
        print_result("to_array: arr[1] == 10", arr && arr[1] == 10);
        print_result("to_array: arr[2] == 15", arr && arr[2] == 15);
        free(arr);

        print_result("to_array: NULL-Liste -> NULL", slist_to_array(NULL) == NULL);

        slist_destroy(list);
    }

    /* slist_reverse */
    {
        SList *list = slist_create();
        slist_push_back(list, 1);
        slist_push_back(list, 2);
        slist_push_back(list, 3);

        slist_reverse(list);
        print_result("reverse: head == 3", list->head->value == 3);
        print_result("reverse: tail == 1", list->tail->value == 1);
        print_result("reverse: head->next == 2", list->head->next->value == 2);
        print_result("reverse: size unveraendert == 3", list->size == 3);

        slist_reverse(NULL); /* kein Absturz */
        print_result("reverse(NULL): kein Absturz", 1);

        slist_destroy(list);
    }

    printf("\n");
#endif

// ----------------------------------------------------------------------------
#if TEST_TASK_3
    printf("--- Aufgabe 3: Matrix ---\n");

    /* matrix_create / matrix_free */
    {
        int **m = matrix_create(3, 4);
        print_result("matrix_create: not NULL", m != NULL);
        /* Alle Felder sollten 0 sein (calloc) */
        int all_zero = 1;
        for (int i = 0; i < 3 && all_zero; i++)
            for (int j = 0; j < 4 && all_zero; j++)
                if (m[i][j] != 0)
                    all_zero = 0;
        print_result("matrix_create: alle Felder 0", all_zero);

        matrix_free(m, 3);
        print_result("matrix_free: kein Absturz", 1);
        matrix_free(NULL, 3);
        print_result("matrix_free(NULL): kein Absturz", 1);
    }

    /* matrix_scale */
    {
        int **m = matrix_create(2, 2);
        m[0][0] = 1;
        m[0][1] = 2;
        m[1][0] = 3;
        m[1][1] = 4;

        matrix_scale(m, 2, 2, 3);
        print_result("matrix_scale: m[0][0] == 3", m[0][0] == 3);
        print_result("matrix_scale: m[0][1] == 6", m[0][1] == 6);
        print_result("matrix_scale: m[1][0] == 9", m[1][0] == 9);
        print_result("matrix_scale: m[1][1] == 12", m[1][1] == 12);

        matrix_free(m, 2);
    }

    /* matrix_add */
    {
        int **a = matrix_create(2, 3);
        int **b = matrix_create(2, 3);

        a[0][0] = 1;
        a[0][1] = 2;
        a[0][2] = 3;
        a[1][0] = 4;
        a[1][1] = 5;
        a[1][2] = 6;

        b[0][0] = 9;
        b[0][1] = 8;
        b[0][2] = 7;
        b[1][0] = 6;
        b[1][1] = 5;
        b[1][2] = 4;

        int **c = matrix_add(a, b, 2, 3);
        print_result("matrix_add: c != NULL", c != NULL);
        print_result("matrix_add: c[0][0] == 10", c && c[0][0] == 10);
        print_result("matrix_add: c[0][2] == 10", c && c[0][2] == 10);
        print_result("matrix_add: c[1][1] == 10", c && c[1][1] == 10);
        print_result("matrix_add: c[1][2] == 10", c && c[1][2] == 10);
        /* Originale unveraendert */
        print_result("matrix_add: a unveraendert", a[0][0] == 1);

        matrix_free(a, 2);
        matrix_free(b, 2);
        if (c)
            matrix_free(c, 2);
    }

    /* matrix_is_symmetric */
    {
        int **sym = matrix_create(3, 3);
        sym[0][0] = 1;
        sym[0][1] = 2;
        sym[0][2] = 3;
        sym[1][0] = 2;
        sym[1][1] = 5;
        sym[1][2] = 6;
        sym[2][0] = 3;
        sym[2][1] = 6;
        sym[2][2] = 9;
        print_result("matrix_is_symmetric: symmetrisch -> 1", matrix_is_symmetric(sym, 3) == 1);

        sym[0][1] = 99; /* Symmetrie brechen */
        print_result("matrix_is_symmetric: nicht symmetrisch -> 0", matrix_is_symmetric(sym, 3) == 0);

        print_result("matrix_is_symmetric: NULL -> 0", matrix_is_symmetric(NULL, 3) == 0);

        matrix_free(sym, 3);
    }

    /* matrix_trace */
    {
        int **m = matrix_create(3, 3);
        m[0][0] = 1;
        m[0][1] = 9;
        m[0][2] = 9;
        m[1][0] = 9;
        m[1][1] = 2;
        m[1][2] = 9;
        m[2][0] = 9;
        m[2][1] = 9;
        m[2][2] = 3;

        print_result("matrix_trace: Spur == 6", matrix_trace(m, 3) == 6);
        print_result("matrix_trace: NULL -> 0", matrix_trace(NULL, 3) == 0);

        matrix_free(m, 3);
    }

    /* transpose_matrix */
    {
        int **m = matrix_create(2, 3);
        m[0][0] = 1;
        m[0][1] = 2;
        m[0][2] = 3;
        m[1][0] = 4;
        m[1][1] = 5;
        m[1][2] = 6;

        int **t = transpose_matrix(m, 2, 3);
        print_result("transpose: t != NULL", t != NULL);
        print_result("transpose: t[0][0] == 1", t && t[0][0] == 1);
        print_result("transpose: t[0][1] == 4", t && t[0][1] == 4);
        print_result("transpose: t[1][0] == 2", t && t[1][0] == 2);
        print_result("transpose: t[2][0] == 3", t && t[2][0] == 3);
        print_result("transpose: t[2][1] == 6", t && t[2][1] == 6);

        matrix_free(m, 2);
        if (t)
            matrix_free(t, 3);
    }

    printf("\n");
#endif

// ----------------------------------------------------------------------------
#if TEST_TASK_4
    printf("--- Aufgabe 4: Encoding ---\n");

    /* caesar_encode */
    {
        char *enc = caesar_encode("hallo", 3);
        print_result("caesar_encode: 'hallo' shift 3 -> 'kdoor'",
                     enc && strcmp(enc, "kdoor") == 0);
        free(enc);

        enc = caesar_encode("xyz", 3);
        print_result("caesar_encode: 'xyz' shift 3 -> 'abc'",
                     enc && strcmp(enc, "abc") == 0);
        free(enc);

        enc = caesar_encode("Hello World!", 1);
        print_result("caesar_encode: Grossbuchstaben + Sonderzeichen korrekt",
                     enc && strcmp(enc, "Ifmmp Xpsme!") == 0);
        free(enc);

        enc = caesar_encode("abc", 26);
        print_result("caesar_encode: shift 26 -> unveraendert",
                     enc && strcmp(enc, "abc") == 0);
        free(enc);

        print_result("caesar_encode: NULL -> NULL", caesar_encode(NULL, 3) == NULL);
    }

    /* caesar_decode */
    {
        char *dec = caesar_decode("kdoor", 3);
        print_result("caesar_decode: 'kdoor' shift 3 -> 'hallo'",
                     dec && strcmp(dec, "hallo") == 0);
        free(dec);

        dec = caesar_decode("abc", 3);
        print_result("caesar_decode: 'abc' shift 3 -> 'xyz'",
                     dec && strcmp(dec, "xyz") == 0);
        free(dec);

        print_result("caesar_decode: NULL -> NULL", caesar_decode(NULL, 3) == NULL);
    }

    /* encode / decode Roundtrip */
    {
        char *enc = caesar_encode("Die Klausur ist schwer!", 13);
        char *dec = enc ? caesar_decode(enc, 13) : NULL;
        print_result("caesar roundtrip: encode->decode == original",
                     dec && strcmp(dec, "Die Klausur ist schwer!") == 0);
        free(enc);
        free(dec);
    }

    /* is_rotation */
    {
        print_result("is_rotation('abcd', 'cdab') -> 1", is_rotation("abcd", "cdab") == 1);
        print_result("is_rotation('abcd', 'dabc') -> 1", is_rotation("abcd", "dabc") == 1);
        print_result("is_rotation('abcd', 'abcd') -> 1", is_rotation("abcd", "abcd") == 1);
        print_result("is_rotation('abcd', 'abce') -> 0", is_rotation("abcd", "abce") == 0);
        print_result("is_rotation('abc',  'abcd') -> 0", is_rotation("abc", "abcd") == 0);
        print_result("is_rotation('', '')         -> 1", is_rotation("", "") == 1);
        print_result("is_rotation: NULL -> 0", is_rotation(NULL, "abc") == 0);
    }

    /* rle_encode */
    {
        char *enc = rle_encode("aaabbc");
        print_result("rle_encode: 'aaabbc' -> '3a2b1c'",
                     enc && strcmp(enc, "3a2b1c") == 0);
        free(enc);

        enc = rle_encode("a");
        print_result("rle_encode: 'a' -> '1a'",
                     enc && strcmp(enc, "1a") == 0);
        free(enc);

        enc = rle_encode("aabbcc");
        print_result("rle_encode: 'aabbcc' -> '2a2b2c'",
                     enc && strcmp(enc, "2a2b2c") == 0);
        free(enc);

        enc = rle_encode("");
        print_result("rle_encode: '' -> ''",
                     enc && strcmp(enc, "") == 0);
        free(enc);

        print_result("rle_encode: NULL -> NULL", rle_encode(NULL) == NULL);
    }

    /* rle_decode */
    {
        char *dec = rle_decode("3a2b1c");
        print_result("rle_decode: '3a2b1c' -> 'aaabbc'",
                     dec && strcmp(dec, "aaabbc") == 0);
        free(dec);

        dec = rle_decode("1a");
        print_result("rle_decode: '1a' -> 'a'",
                     dec && strcmp(dec, "a") == 0);
        free(dec);

        dec = rle_decode("2x2y");
        print_result("rle_decode: '2x2y' -> 'xxyy'",
                     dec && strcmp(dec, "xxyy") == 0);
        free(dec);

        dec = rle_decode("");
        print_result("rle_decode: '' -> ''",
                     dec && strcmp(dec, "") == 0);
        free(dec);

        print_result("rle_decode: NULL -> NULL", rle_decode(NULL) == NULL);
    }

    /* RLE Roundtrip */
    {
        char *enc = rle_encode("aaabbbcccc");
        char *dec = enc ? rle_decode(enc) : NULL;
        print_result("rle roundtrip: encode->decode == original",
                     dec && strcmp(dec, "aaabbbcccc") == 0);
        free(enc);
        free(dec);
    }

    printf("\n");
#endif

    printf("=== Tests abgeschlossen ===\n");
    return 0;
}
