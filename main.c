#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Binde hier deinen Header ein
#include "exam_prep.h"

// ============================================================================
// TEST SWITCHES - Setze die Werte auf 1, um die jeweilige Aufgabe zu testen
// ============================================================================
#define TEST_TASK_1 0
#define TEST_TASK_2 0
#define TEST_TASK_3 0
#define TEST_TASK_4 0

// Hilfsfunktion für einfache Tests
void print_test_result(const char* test_name, int passed) {
    if (passed) {
        printf("[ OK ] %s\n", test_name);
    } else {
        printf("[FAIL] %s\n", test_name);
    }
}

int main() {
    printf("=== Start der Informatik I Klausurvorbereitung ===\n\n");

#if TEST_TASK_1
    printf("--- Teste Aufgabe 1: Strings ---\n");
    char dest_buffer[100] = {0};
    
    compress_rle("AAAABBBCCDAA", dest_buffer);
    print_test_result("RLE Test 1", strcmp(dest_buffer, "A4B3C2D1A2") == 0);
    
    memset(dest_buffer, 0, sizeof(dest_buffer));
    compress_rle("X", dest_buffer);
    print_test_result("RLE Test 2 (Single Char)", strcmp(dest_buffer, "X1") == 0);
    
    memset(dest_buffer, 0, sizeof(dest_buffer));
    compress_rle("", dest_buffer);
    print_test_result("RLE Test 3 (Empty String)", strcmp(dest_buffer, "") == 0);
    printf("\n");
#endif

#if TEST_TASK_2
    printf("--- Teste Aufgabe 2: Structs ---\n");
    Item inventory[] = {
        {1, "Laptop", "Electronics", 999.99, 10},
        {2, "Mouse", "Electronics", 25.50, 50},
        {3, "Desk", "Furniture", 150.00, 2},
        {4, "Keyboard", "Electronics", 45.00, 15}
    };
    
    Item* lowest = find_lowest_stock(inventory, 4);
    print_test_result("Find lowest stock", lowest != NULL && lowest->id == 3);
    
    apply_discount(inventory, 4, "Electronics", 10.0);
    // Erwarte Laptop Preis: 999.99 * 0.9 = ~899.99
    print_test_result("Apply discount", fabs(inventory[0].price - 899.991) < 0.01);
    printf("\n");
#endif

#if TEST_TASK_3
    printf("--- Teste Aufgabe 3: Dynamic Memory ---\n");
    int rows = 2, cols = 3;
    int** mat = create_matrix(rows, cols);
    
    if (mat != NULL) {
        int counter = 1;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                mat[i][j] = counter++;
            }
        }
        
        int** transposed = transpose_matrix(mat, rows, cols);
        if (transposed != NULL) {
            print_test_result("Transpose Check Value", transposed[1][0] == 2 && transposed[0][1] == 4);
            free_matrix(transposed, cols); // transponierte hat 'cols' Zeilen
            print_test_result("Free transposed matrix (No crash)", 1);
        } else {
            print_test_result("Transpose returns NULL", 0);
        }
        
        free_matrix(mat, rows);
        print_test_result("Free original matrix (No crash)", 1);
    } else {
        print_test_result("Create matrix returns NULL", 0);
    }
    printf("\n");
#endif

#if TEST_TASK_4
    printf("--- Teste Aufgabe 4: Linked Lists ---\n");
    Node* head = NULL;
    
    list_append(&head, 1);
    list_append(&head, 2);
    list_append(&head, 3);
    list_append(&head, 4);
    
    print_test_result("Append nodes", head != NULL && head->data == 1 && head->next->next->data == 3);
    
    list_filter_even(&head);
    // Übrig sein sollten nur 1 und 3
    int valid = (head != NULL && head->data == 1 && head->next != NULL && head->next->data == 3 && head->next->next == NULL);
    print_test_result("Filter even numbers", valid);
    
    list_free(&head);
    print_test_result("Free list", head == NULL);
    printf("\n");
#endif

    printf("=== Tests abgeschlossen ===\n");
    return 0;
}
