#include "recursion.h"

int recursive_sum(int n)
{
    if (n <= 0)
        return 0;
    return n + recursive_sum(n - 1);
}

int recursive_count_even(const int *arr, int size)
{
    if (size <= 0)
        return 0;
    return (arr[0] % 2 == 0 ? 1 : 0) + recursive_count_even(arr + 1, size - 1);
}

int recursive_is_number(const char *text)
{
    if (*text == '\0')
        return 1;
    if (*text < '0' || *text > '9')
        return 0;
    return recursive_is_number(text + 1);
}

long long recursive_power(int x, int n)
{
    if (n == 0)
        return 1;
    return x * recursive_power(x, n - 1);
}