/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 * 
 */
/**
 * Доделать сортировку
*/
void printArray (int array[], int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    int l, r, z;
    l = 0;
    r = n;
    while (l < r)
    {
        z = (l + r)/2;
        if (values[z] == value)
        {
            return true;
        }
        else if (values[z] > value)
        {
            r = z - 1;
        }
        else if (values[z] < value)
        {
            l = z + 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    int min, temp, ind;
    for (int i = 0; i < n; i++)
    {
        min = values[i];
        for (int j = i+1; j < n; j++)
        {
            if (values[j] < min)
            {
                min = values[j];
                ind = j;
            }
        }
        temp = values[i];
        values[ind] = temp;
        values[i] = min;
    }
    return;
}

int main(void)
{
    int values[] = {8, 3, 4, 8, 2, 10, 8, 4, 2, 1, 9};
    int value = 3;
    int n = 11;
    
    sort(values, n);
    printArray(values, n);
    
    if (search(value, values, n))
    {
        printf("it is right");
    } else {
        printf("Not enought");
    }
}