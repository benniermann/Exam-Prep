#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "task1_strings.h"
#include "task2_structs.h"
#include "task3_stack.h"
#include "task4_list.h"

// ============================================================================
// TEST SWITCHES -- Setze auf 1 um die jeweilige Aufgabe zu testen
// ============================================================================
#define TEST_TASK_1 0   /* Strings      */
#define TEST_TASK_2 0   /* Structs      */
#define TEST_TASK_3 0   /* Stack        */
#define TEST_TASK_4 0   /* Linked List  */

// ----------------------------------------------------------------------------
static void print_result(const char *name, int passed)
{
    printf("  %s %s\n", passed ? "[ OK ]" : "[FAIL]", name);
}

// ============================================================================
int main(void)
{
    printf("=== Klausurvorbereitung -- Uebungsserie 2 ===\n\n");

// ----------------------------------------------------------------------------
#if TEST_TASK_1
    printf("--- Aufgabe 1: Strings ---\n");

    /* is_palindrome */
    print_result("is_palindrome: \"racecar\"",  is_palindrome("racecar") == 1);
    print_result("is_palindrome: \"Racecar\"",  is_palindrome("Racecar") == 1);
    print_result("is_palindrome: \"hello\"",    is_palindrome("hello")   == 0);
    print_result("is_palindrome: \"\"",         is_palindrome("")        == 1);
    print_result("is_palindrome: \"a\"",        is_palindrome("a")       == 1);
    print_result("is_palindrome: \"ab\"",       is_palindrome("ab")      == 0);

    /* count_words */
    print_result("count_words: \"hello world\"",    count_words("hello world")    == 2);
    print_result("count_words: \"  foo  bar  \"",   count_words("  foo  bar  ")   == 2);
    print_result("count_words: \"\"",               count_words("")               == 0);
    print_result("count_words: \"one\"",            count_words("one")            == 1);
    print_result("count_words: \"  \"",             count_words("  ")             == 0);

    /* str_reverse */
    {
        char *r = str_reverse("hello");
        print_result("str_reverse: \"hello\" -> \"olleh\"", r && strcmp(r, "olleh") == 0);
        free(r);

        r = str_reverse("");
        print_result("str_reverse: \"\" -> \"\"", r && strcmp(r, "") == 0);
        free(r);

        print_result("str_reverse: NULL -> NULL", str_reverse(NULL) == NULL);
    }

    /* str_replace_char */
    {
        char buf[] = "hello world";
        int  n     = str_replace_char(buf, 'l', 'r');
        print_result("str_replace_char: count == 3",          n == 3);
        print_result("str_replace_char: result == \"herro worrd\"",
                     strcmp(buf, "herro worrd") == 0);

        char buf2[] = "aaa";
        str_replace_char(buf2, 'x', 'y');
        print_result("str_replace_char: no match -> unchanged", strcmp(buf2, "aaa") == 0);

        print_result("str_replace_char: NULL -> -1", str_replace_char(NULL, 'a', 'b') == -1);
    }
    printf("\n");
#endif

// ----------------------------------------------------------------------------
#if TEST_TASK_2
    printf("--- Aufgabe 2: Structs ---\n");

    Student students[] = {
        {1, "Alice",   {1.0, 2.0, 1.3}, 3},
        {2, "Bob",     {3.0, 4.0, 2.0}, 3},
        {3, "Charlie", {1.7, 1.3, 1.0}, 3},
        {4, "Diana",   {5.0, 4.0, 3.0}, 3},
        {5, "Eve",     {},               0},
    };

    /* student_average */
    print_result("student_average: Alice  ~= 1.43",
                 fabs(student_average(&students[0]) - (1.0+2.0+1.3)/3.0) < 0.01);
    print_result("student_average: Eve (0 grades) == 0.0",
                 student_average(&students[4]) == 0.0);
    print_result("student_average: NULL == 0.0",
                 student_average(NULL) == 0.0);

    /* find_best_student */
    {
        Student *best = find_best_student(students, 4);
        print_result("find_best_student: Charlie (lowest avg)",
                     best != NULL && best->id == 3);
        print_result("find_best_student: NULL input -> NULL",
                     find_best_student(NULL, 4) == NULL);
        print_result("find_best_student: n=0 -> NULL",
                     find_best_student(students, 0) == NULL);
    }

    /* student_passed_all */
    print_result("student_passed_all: Alice  -> 1", student_passed_all(&students[0]) == 1);
    print_result("student_passed_all: Bob    -> 1", student_passed_all(&students[1]) == 1);
    print_result("student_passed_all: Diana  -> 0", student_passed_all(&students[3]) == 0);
    print_result("student_passed_all: Eve    -> 0", student_passed_all(&students[4]) == 0);
    print_result("student_passed_all: NULL   -> 0", student_passed_all(NULL)         == 0);

    /* sort_students_by_average */
    {
        Student arr[] = {
            {1, "A", {3.0, 3.0}, 2},
            {2, "B", {1.0, 1.0}, 2},
            {3, "C", {2.0, 2.0}, 2},
        };
        sort_students_by_average(arr, 3);
        print_result("sort_by_average: B first (avg 1.0)", arr[0].id == 2);
        print_result("sort_by_average: C second (avg 2.0)", arr[1].id == 3);
        print_result("sort_by_average: A last  (avg 3.0)", arr[2].id == 1);
    }
    printf("\n");
#endif

// ----------------------------------------------------------------------------
#if TEST_TASK_3
    printf("--- Aufgabe 3: Stack ---\n");

    /* create / destroy */
    {
        Stack *s = stack_create();
        print_result("stack_create: not NULL",       s != NULL);
        print_result("stack_create: size == 0",      s && s->size == 0);
        print_result("stack_create: capacity == 4",  s && s->capacity == 4);
        print_result("stack_is_empty: empty stack",  stack_is_empty(s) == 1);
        stack_destroy(s);
        print_result("stack_destroy: no crash",      1);
        stack_destroy(NULL);
        print_result("stack_destroy(NULL): no crash", 1);
    }

    /* push / peek / pop */
    {
        Stack *s = stack_create();
        int err;

        stack_push(s, 10);
        stack_push(s, 20);
        stack_push(s, 30);

        print_result("stack_push: size == 3",      s->size == 3);
        print_result("stack_is_empty: not empty",  stack_is_empty(s) == 0);

        int top = stack_peek(s, &err);
        print_result("stack_peek: value == 30",    top == 30 && err == 0);
        print_result("stack_peek: size unchanged", s->size == 3);

        int v1 = stack_pop(s, &err);
        print_result("stack_pop: value == 30",     v1 == 30 && err == 0);
        int v2 = stack_pop(s, &err);
        print_result("stack_pop: value == 20",     v2 == 20 && err == 0);
        int v3 = stack_pop(s, &err);
        print_result("stack_pop: value == 10",     v3 == 10 && err == 0);
        print_result("stack_pop: now empty",       stack_is_empty(s) == 1);

        stack_pop(s, &err);
        print_result("stack_pop on empty: err == -1", err == -1);

        stack_peek(s, &err);
        print_result("stack_peek on empty: err == -1", err == -1);

        stack_destroy(s);
    }

    /* capacity doubling */
    {
        Stack *s = stack_create();
        for (int i = 0; i < 8; i++) stack_push(s, i);
        print_result("capacity doubling: size == 8",     s->size == 8);
        print_result("capacity doubling: capacity >= 8", s->capacity >= 8);
        int err, last = stack_pop(s, &err);
        print_result("capacity doubling: pop returns 7", last == 7 && err == 0);
        stack_destroy(s);
    }
    printf("\n");
#endif

// ----------------------------------------------------------------------------
#if TEST_TASK_4
    printf("--- Aufgabe 4: Linked List ---\n");

    /* list_sum */
    {
        Node *head = NULL;
        print_result("list_sum: empty list == 0", list_sum(head) == 0);
        list_append(&head, 1);
        list_append(&head, 2);
        list_append(&head, 3);
        print_result("list_sum: 1+2+3 == 6",      list_sum(head) == 6);
        list_free(&head);
    }

    /* list_is_sorted */
    {
        Node *head = NULL;
        print_result("list_is_sorted: empty -> 1", list_is_sorted(head) == 1);
        list_append(&head, 1);
        print_result("list_is_sorted: single -> 1", list_is_sorted(head) == 1);
        list_append(&head, 3);
        list_append(&head, 5);
        print_result("list_is_sorted: 1->3->5 -> 1", list_is_sorted(head) == 1);
        list_append(&head, 2);
        print_result("list_is_sorted: 1->3->5->2 -> 0", list_is_sorted(head) == 0);
        list_free(&head);
    }

    /* list_remove_duplicates */
    {
        Node *head = NULL;
        list_append(&head, 1);
        list_append(&head, 2);
        list_append(&head, 2);
        list_append(&head, 3);
        list_append(&head, 2);
        list_remove_duplicates(&head);

        int ok = 1;
        Node *cur = head;
        int expected[] = {1, 2, 3};
        for (int i = 0; i < 3 && cur != NULL; i++, cur = cur->next)
            if (cur->data != expected[i]) ok = 0;
        if (cur != NULL) ok = 0;

        print_result("list_remove_duplicates: 1->2->2->3->2 => 1->2->3", ok);
        list_free(&head);

        /* no duplicates */
        list_append(&head, 5);
        list_append(&head, 6);
        list_remove_duplicates(&head);
        print_result("list_remove_duplicates: no dups unchanged",
                     head && head->data == 5 && head->next && head->next->data == 6
                     && head->next->next == NULL);
        list_free(&head);
    }

    /* list_insert_sorted */
    {
        Node *head = NULL;
        list_append(&head, 1);
        list_append(&head, 3);
        list_append(&head, 5);

        list_insert_sorted(&head, 4);
        list_insert_sorted(&head, 0);
        list_insert_sorted(&head, 6);

        int ok = 1;
        Node *cur = head;
        int expected[] = {0, 1, 3, 4, 5, 6};
        for (int i = 0; i < 6 && cur != NULL; i++, cur = cur->next)
            if (cur->data != expected[i]) ok = 0;
        if (cur != NULL) ok = 0;

        print_result("list_insert_sorted: 0,1,3,4,5,6 in order", ok);
        print_result("list_is_sorted after inserts", list_is_sorted(head) == 1);
        list_free(&head);
    }
    printf("\n");
#endif

    printf("=== Tests abgeschlossen ===\n");
    return 0;
}