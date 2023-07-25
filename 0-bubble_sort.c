#include "sort.h"

/**
 * bubble_sort - Sorts array of ints in ascending order using
 *               the Bubble sort algorithm
 *
 * @array: The array to sort
 * @size:  The size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, b;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (a = 0; a < size - 1; a++)
	{
		for (b = 0; b < size - a - 1; b++)
		{
			if (array[b] > array[b + 1])
			{
				tmp = array[b];
				array[b] = array[b + 1];
				array[b + 1] = tmp;
				print_array(array, size);
			}
		}
	}
}
