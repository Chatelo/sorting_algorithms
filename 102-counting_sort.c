#include "sort.h"
#include <stdio.h>

#include <stdlib.h>
#include <stdio.h>

/**
 * counting_sort - sorts an array of integers in ascending order using Counting sort
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
    int *counter = NULL;
    int max_value = 0;
    size_t i, j;

    if (array == NULL || size < 2)
        return;

    // Find the maximum value in the array
    for (i = 0; i < size; i++)
    {
        if (array[i] > max_value)
            max_value = array[i];
    }

    // Allocate memory for the counter array and initialize it to 0
    counter = malloc((max_value + 1) * sizeof(int));
    if (counter == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    for (i = 0; i <= max_value; i++)
        counter[i] = 0;

    // Count the occurrences of each element in the input array
    for (i = 0; i < size; i++)
        counter[array[i]]++;

    // Perform the sorting by modifying the original array
    j = 0;
    for (i = 0; i <= max_value; i++)
    {
        while (counter[i] > 0)
        {
            array[j] = i;
            j++;
            counter[i]--;
        }
    }

    // Print the counting array
    printf("Counting array: ");
    for (i = 0; i <= max_value; i++)
        printf("%d ", counter[i]);
    printf("\n");

    // Free the allocated memory
    free(counter);
}

