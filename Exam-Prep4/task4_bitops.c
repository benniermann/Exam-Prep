#include "task3_strings.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

unsigned int bit_set(unsigned int n, int pos)
{
    if (pos < 0 || pos > 31)
    {
        return n;
    }

    return n | (1 << pos);
}

unsigned int bit_clear(unsigned int n, int pos)
{
    if (pos < 0 || pos > 31)
    {
        return n;
    }

    return n & ~(1 << pos);
}

unsigned int bit_toggle(unsigned int n, int pos)
{
    if (pos < 0 || pos > 31)
    {
        return n;
    }

    return n ^ (1 << pos);
}

int bit_get(unsigned int n, int pos)
{
    if (pos < 0 || pos > 31)
    {
        return 0;
    }

    return (n >> pos) & 1;
}

int count_ones(unsigned int n)
{
    int count = 0;
    while (n != 0)
    {
        n &= (n - 1);
        count++;
    }
    return count;
}

int is_power_of_two(unsigned int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n & (n - 1)) == 0;
}

unsigned int reverse_byte(unsigned int n)
{
    unsigned int result = 0;
    n &= 0xFF;

    for (int i = 0; i < 8; i++)
    {
        result <<= 1;
        result |= (n & 1);
        n >>= 1;
    }

    return result;
}
