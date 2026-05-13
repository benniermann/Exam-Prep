#include "task1_rekursion.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

long long fast_power(long long x, int n)
{
    if (n == 0)
        return 1;

    long long half = fast_power(x, n / 2);

    if ((n % 2) == 0)
    {
        half *= half;
    }
    else
    {
        half = x * half * half;
    }

    return half;
}

int gcd(int a, int b)
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}

int digit_sum(int n)
{
    if (n <= 0)
        return 0;

    return ((n % 10) + digit_sum(n / 10));
}

int binary_search(const int *arr, int low, int high, int target)
{
    if (low > high)
        return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        return binary_search(arr, low, mid - 1, target);
    return binary_search(arr, mid + 1, high, target);
}

int count_char(const char *s, char c)
{
    if (s == NULL || *s == '\0')
        return 0;
    if (*s == c)
        return 1 + count_char(s + 1, c);
    return count_char(s + 1, c);
}
