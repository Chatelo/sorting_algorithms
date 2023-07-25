#include "sort.h"
#include <stdio.h>

/**
 * counting_sort - this is a counting sort method implementation
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
    int index, maximun = 0, *counter = NULL;
    size_t i;

    if (array == NULL || size < 2)
        return;
    /* find maximum number */
    for (i = 0; i < size; i++)
        if (array[i] > maximun)
            maximun = array[i];
    counter = _calloc(maximun + 1, sizeof(int));
    if (counter == NULL)
        return; // Handle memory allocation failure

    /* count the array elements */
    for (i = 0; i < size; i++)
        counter[array[i]]++;

    /* get the new array sorted */
    index = 0;
    for (i = 0; i <= maximun; i++)
    {
        while (counter[i] > 0)
        {
            array[index] = i;
            index++;
            counter[i]--;
        }
    }
    free(counter);
}

