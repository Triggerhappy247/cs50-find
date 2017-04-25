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
    else if(values[mid] < value)
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
    // declare counting array and index 
    int count[MAX], sortValues[n];
    // Loop to initialize all values of count to 0
    for(int i = 0; i < MAX; i++)
    {
        count[i] = 0;
    }
    // Loop to count elements in values and store their
    // occurences in count[]
    for(int i = 0; i < n; i++)
    {
        count[values[i]]++;
    }
    
    // Determine starting postion of each number 
    for(int i = 1; i < MAX; i++)
    {
        count[i] += count[i - 1];
    }

    // Place elements in right postion
    for(int i = n - 1; i >= 0; i--)
    {
        sortValues[count[values[i]] - 1] = values[i];
        count[i]--;
    }
    
    // Transfer back sorted elements
    for(int i = 0; i < n; i++)
    {
        values[i] = sortValues[i];
    }
    return;
}