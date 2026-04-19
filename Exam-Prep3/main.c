#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "task1_recursion.h"
#include "task2_bank.h"
#include "task3_matrix.h"
#include "task4_dlist.h"

// ============================================================================
// TEST SWITCHES -- Setze auf 1 um die jeweilige Aufgabe zu testen
// ============================================================================
#define TEST_TASK_1 0   /* Rekursion           */
#define TEST_TASK_2 0   /* Bank / Structs      */
#define TEST_TASK_3 0   /* Matrizen            */
#define TEST_TASK_4 1   /* Doppelt verk. Liste */

// ----------------------------------------------------------------------------
static void print_result(const char *name, int passed)
{
    printf("  %s %s\n", passed ? "[ OK ]" : "[FAIL]", name);
}

// ============================================================================
int main(void)
{
    printf("=== Klausurvorbereitung -- Uebungsserie 3 ===\n\n");

// ----------------------------------------------------------------------------
#if TEST_TASK_1
    printf("--- Aufgabe 1: Rekursion ---\n");

    /* fib */
    print_result("fib(0)  == 0",          fib(0)  == 0);
    print_result("fib(1)  == 1",          fib(1)  == 1);
    print_result("fib(2)  == 1",          fib(2)  == 1);
    print_result("fib(7)  == 13",         fib(7)  == 13);
    print_result("fib(10) == 55",         fib(10) == 55);
    print_result("fib(-1) == -1",         fib(-1) == -1);

    /* digit_sum */
    print_result("digit_sum(0)    == 0",  digit_sum(0)    == 0);
    print_result("digit_sum(9)    == 9",  digit_sum(9)    == 9);
    print_result("digit_sum(1234) == 10", digit_sum(1234) == 10);
    print_result("digit_sum(999)  == 27", digit_sum(999)  == 27);

    /* binary_search */
    {
        int arr[] = {1, 3, 5, 7, 9, 11, 13};
        int len   = 7;
        print_result("binary_search: finds 1  at idx 0", binary_search(arr, 0, len-1, 1)  == 0);
        print_result("binary_search: finds 7  at idx 3", binary_search(arr, 0, len-1, 7)  == 3);
        print_result("binary_search: finds 13 at idx 6", binary_search(arr, 0, len-1, 13) == 6);
        print_result("binary_search: 4 not found -> -1", binary_search(arr, 0, len-1, 4)  == -1);
        print_result("binary_search: 0 not found -> -1", binary_search(arr, 0, len-1, 0)  == -1);
    }

    /* count_char */
    print_result("count_char: 'l' in \"hello\" == 2", count_char("hello", 'l') == 2);
    print_result("count_char: 'a' in \"banana\" == 3", count_char("banana", 'a') == 3);
    print_result("count_char: 'x' in \"hello\" == 0", count_char("hello", 'x') == 0);
    print_result("count_char: NULL -> 0",              count_char(NULL, 'a')    == 0);
    print_result("count_char: empty string -> 0",      count_char("", 'a')      == 0);
    printf("\n");
#endif

// ----------------------------------------------------------------------------
#if TEST_TASK_2
    printf("--- Aufgabe 2: Bank ---\n");

    /* deposit / withdraw */
    {
        Account a = {1, "Alice", ACCOUNT_CHECKING, 100.0};

        print_result("deposit 50.0 -> OK",        account_deposit(&a, 50.0)  == 0);
        print_result("balance after deposit",      fabs(a.balance - 150.0)   < 0.001);
        print_result("deposit -10 -> -1",          account_deposit(&a, -10.0) == -1);
        print_result("balance unchanged after bad deposit", fabs(a.balance - 150.0) < 0.001);
        print_result("deposit NULL -> -1",         account_deposit(NULL, 10.0) == -1);

        print_result("withdraw 50.0 -> OK",        account_withdraw(&a, 50.0)  == 0);
        print_result("balance after withdraw",     fabs(a.balance - 100.0)   < 0.001);
        print_result("withdraw too much -> -1",    account_withdraw(&a, 200.0) == -1);
        print_result("balance unchanged after bad withdraw", fabs(a.balance - 100.0) < 0.001);
        print_result("withdraw NULL -> -1",        account_withdraw(NULL, 10.0) == -1);
    }

    /* find_richest */
    {
        Account accounts[] = {
            {1, "Alice",   ACCOUNT_CHECKING, 500.0},
            {2, "Bob",     ACCOUNT_SAVINGS,  1200.0},
            {3, "Charlie", ACCOUNT_CHECKING, 300.0},
            {4, "Diana",   ACCOUNT_SAVINGS,  1200.0},
        };
        Account *r = find_richest(accounts, 4);
        print_result("find_richest: Bob (idx 1, first with 1200)", r && r->id == 2);
        print_result("find_richest: NULL -> NULL", find_richest(NULL, 4) == NULL);
        print_result("find_richest: n=0  -> NULL", find_richest(accounts, 0) == NULL);
    }

    /* total_balance_by_type */
    {
        Account accounts[] = {
            {1, "A", ACCOUNT_CHECKING, 200.0},
            {2, "B", ACCOUNT_SAVINGS,  300.0},
            {3, "C", ACCOUNT_CHECKING, 100.0},
        };
        double cb = total_balance_by_type(accounts, 3, ACCOUNT_CHECKING);
        double sb = total_balance_by_type(accounts, 3, ACCOUNT_SAVINGS);
        print_result("total_balance CHECKING == 300.0", fabs(cb - 300.0) < 0.001);
        print_result("total_balance SAVINGS  == 300.0", fabs(sb - 300.0) < 0.001);
        print_result("total_balance NULL -> 0.0",
                     fabs(total_balance_by_type(NULL, 3, ACCOUNT_CHECKING)) < 0.001);
    }

    /* account_transfer */
    {
        Account from = {1, "Alice", ACCOUNT_CHECKING, 500.0};
        Account to   = {2, "Bob",   ACCOUNT_SAVINGS,  100.0};

        print_result("transfer 200 -> OK",          account_transfer(&from, &to, 200.0) == 0);
        print_result("from balance after transfer", fabs(from.balance - 300.0) < 0.001);
        print_result("to   balance after transfer", fabs(to.balance   - 300.0) < 0.001);
        print_result("transfer too much -> -1",     account_transfer(&from, &to, 999.0) == -1);
        print_result("balances unchanged after fail",
                     fabs(from.balance - 300.0) < 0.001 && fabs(to.balance - 300.0) < 0.001);
        print_result("transfer amount <= 0 -> -1",  account_transfer(&from, &to, 0.0)   == -1);
        print_result("transfer NULL from  -> -1",   account_transfer(NULL,  &to, 10.0)  == -1);
        print_result("transfer NULL to    -> -1",   account_transfer(&from, NULL, 10.0) == -1);
    }
    printf("\n");
#endif

// ----------------------------------------------------------------------------
#if TEST_TASK_3
    printf("--- Aufgabe 3: Matrizen ---\n");

    /* matrix_create / matrix_free */
    {
        int **m = matrix_create(3, 4);
        print_result("matrix_create: not NULL", m != NULL);
        int all_zero = 1;
        for (int i = 0; i < 3 && m; i++)
            for (int j = 0; j < 4; j++)
                if (m[i][j] != 0) all_zero = 0;
        print_result("matrix_create: all zeros", all_zero);
        matrix_free(m, 3);
        print_result("matrix_free: no crash", 1);
        matrix_free(NULL, 3);
        print_result("matrix_free(NULL): no crash", 1);
    }

    /* matrix_scale */
    {
        int **m = matrix_create(2, 2);
        m[0][0]=1; m[0][1]=2;
        m[1][0]=3; m[1][1]=4;
        matrix_scale(m, 2, 2, 3);
        print_result("matrix_scale: m[0][0] == 3",  m[0][0] == 3);
        print_result("matrix_scale: m[1][1] == 12", m[1][1] == 12);
        matrix_free(m, 2);
    }

    /* matrix_add */
    {
        int **a = matrix_create(2, 2);
        int **b = matrix_create(2, 2);
        a[0][0]=1; a[0][1]=2; a[1][0]=3; a[1][1]=4;
        b[0][0]=5; b[0][1]=6; b[1][0]=7; b[1][1]=8;
        int **c = matrix_add(a, b, 2, 2);
        print_result("matrix_add: c[0][0] == 6",  c && c[0][0] == 6);
        print_result("matrix_add: c[0][1] == 8",  c && c[0][1] == 8);
        print_result("matrix_add: c[1][0] == 10", c && c[1][0] == 10);
        print_result("matrix_add: c[1][1] == 12", c && c[1][1] == 12);
        matrix_free(a, 2); matrix_free(b, 2); matrix_free(c, 2);
    }

    /* matrix_is_symmetric */
    {
        int **s = matrix_create(3, 3);
        /* symmetrisch */
        s[0][0]=1; s[0][1]=2; s[0][2]=3;
        s[1][0]=2; s[1][1]=5; s[1][2]=6;
        s[2][0]=3; s[2][1]=6; s[2][2]=9;
        print_result("matrix_is_symmetric: symmetric -> 1",    matrix_is_symmetric(s, 3) == 1);
        s[0][1] = 99;
        print_result("matrix_is_symmetric: not symmetric -> 0", matrix_is_symmetric(s, 3) == 0);
        print_result("matrix_is_symmetric: NULL -> 0",          matrix_is_symmetric(NULL, 3) == 0);
        matrix_free(s, 3);
    }

    /* matrix_trace */
    {
        int **m = matrix_create(3, 3);
        m[0][0]=1; m[1][1]=5; m[2][2]=9;
        m[0][1]=2; m[0][2]=3; m[1][0]=4;
        print_result("matrix_trace: 1+5+9 == 15", matrix_trace(m, 3) == 15);
        print_result("matrix_trace: NULL -> 0",   matrix_trace(NULL, 3) == 0);
        matrix_free(m, 3);
    }
    printf("\n");
#endif

// ----------------------------------------------------------------------------
#if TEST_TASK_4
    printf("--- Aufgabe 4: Doppelt verkettete Liste ---\n");

    /* create / destroy */
    {
        DList *l = dlist_create();
        print_result("dlist_create: not NULL",     l != NULL);
        print_result("dlist_create: size == 0",    l && l->size == 0);
        print_result("dlist_create: head == NULL", l && l->head == NULL);
        print_result("dlist_create: tail == NULL", l && l->tail == NULL);
        dlist_destroy(l);
        print_result("dlist_destroy: no crash",    1);
        dlist_destroy(NULL);
        print_result("dlist_destroy(NULL): no crash", 1);
    }

    /* push_front / push_back */
    {
        DList *l = dlist_create();

        dlist_push_back(l, 2);
        dlist_push_front(l, 1);
        dlist_push_back(l, 3);
        /* Erwartet: 1 <-> 2 <-> 3 */

        print_result("size == 3",                   l->size == 3);
        print_result("head->data == 1",             l->head && l->head->data == 1);
        print_result("tail->data == 3",             l->tail && l->tail->data == 3);
        print_result("head->prev == NULL",          l->head && l->head->prev == NULL);
        print_result("tail->next == NULL",          l->tail && l->tail->next == NULL);
        print_result("head->next->data == 2",       l->head && l->head->next && l->head->next->data == 2);
        print_result("tail->prev->data == 2",       l->tail && l->tail->prev && l->tail->prev->data == 2);

        dlist_destroy(l);
    }

    /* pop_back */
    {
        DList *l = dlist_create();
        dlist_push_back(l, 10);
        dlist_push_back(l, 20);
        dlist_push_back(l, 30);

        int err;
        int v = dlist_pop_back(l, &err);
        print_result("pop_back: returns 30",        v == 30 && err == 0);
        print_result("pop_back: size == 2",         l->size == 2);
        print_result("pop_back: new tail == 20",    l->tail && l->tail->data == 20);
        print_result("pop_back: new tail->next == NULL", l->tail && l->tail->next == NULL);

        dlist_pop_back(l, &err);
        dlist_pop_back(l, &err);
        print_result("pop_back: list now empty",    l->size == 0 && l->head == NULL && l->tail == NULL);

        dlist_pop_back(l, &err);
        print_result("pop_back on empty: err == -1", err == -1);

        dlist_destroy(l);
    }

    /* dlist_is_consistent */
    {
        DList *l = dlist_create();
        print_result("consistent: empty list -> 1", dlist_is_consistent(l) == 1);

        dlist_push_back(l, 1);
        dlist_push_back(l, 2);
        dlist_push_back(l, 3);
        print_result("consistent: 1<->2<->3 -> 1",  dlist_is_consistent(l) == 1);

        /* Konsistenz kaputt machen */
        l->head->next->prev = NULL;
        print_result("consistent: broken prev -> 0", dlist_is_consistent(l) == 0);

        dlist_destroy(l);
    }
    printf("\n");
#endif

    printf("=== Tests abgeschlossen ===\n");
    return 0;
}
