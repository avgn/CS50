/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */

#include "cs50.h"
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int lo = 0;
    int hi = n;

    while (hi > 0)
    {
        int mid = values[(hi - lo) / 2];

        if (mid == value)
            return true;
        else if (mid > value)
        {
            hi = hi / 2;
        }
        else if (mid < value)
        {
            lo = hi / 2 + 2;
        }
    }

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int min;

    for (int i = 0; i < n - 1; i++)
    {
        min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (values[j] < values[i])
            {
                min = j;
            }
        }

        values[i] = min;
    }
}
