#include "dhbw.h"

#include <stdio.h>

void dhbw_print_integer(const char* description, long long v) {
    printf("%s: %lli\n", description, v);
}

void dhbw_print_line(const char* text) {
    printf("%s\n", text);
}

void dhbw_print_float(const char* description, double v) {
    printf("%s: %.2lf\n", description, v);
}

void dhbw_print_bitwise_uint(const char *description, unsigned int v) {
    for (int i = 31; i >= 0; --i) {
        printf("%d", (v >> i) & 1);
    }
    printf(": %s\n", description);
}

void dhbw_print_bitwise_int(const char *description, int v) {
    dhbw_print_bitwise_uint(description, (unsigned int)v);
}

void dhbw_print_string(const char *description, const char *v) {
    printf("%s: %s\n", description, v);
}

void dhbw_print_address(const char *description, const void *v) {
    printf("%s: %p\n", description, v);
}

void dhbw_print_arr(const char *description, const float *arr, unsigned int size) {
    if (size) {
        printf("%s: { %.2f", description, arr[0]);
    } else {
        printf("%s: {", description);
    }
    for (unsigned int i = 1; i < size; ++i) {
        printf(", %.2f", arr[i]);
    }
    printf(" }\n");
}
