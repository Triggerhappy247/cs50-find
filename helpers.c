/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

#define LOW 0
#define MAX 65537

// Definition for Binary Search O(log n)
bool binarySearch(int low, int high, int value, int values[])
{   
    // if low is in front of high implies value is not present
    if (low > high)
    {
        return false;
    }
    int mid = (low + high) / 2;
    // check if value is present at mid
    if (values[mid] == value)
    {
        return true;
    }
    // If value might be present before mid
    else if (values[mid] > value)
    {
        return binarySearch(low, mid - 1, value, values);
    }
    // if value might be present after mid
    else
    {
        return binarySearch(mid + 1, high, value, values);
    }
}
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (n < 0)
    {
        return false;
    }
    
    return binarySearch(LOW, n, value, values);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    return;
}
