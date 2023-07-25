#include "sort.h"


/**
 * shell_sort - Sorts array of ints in ascending order using
 *               the Bubble sort algorithm
 *
 * @array: The array to sort
 * @size:  The size of array
 */
void shell_sort(int *array, size_t size)
{
size_t gap = 1, a, b;
int temp;

if (array == NULL || size < 2)
return;

while (gap < size / 3)
gap = gap * 3 + 1;

while (gap > 0)
{
for (a = gap; a < size; a++)
{
temp = array[a];
for (b = a; b >= gap && array[b - gap] > temp; b -= gap)
array[b] = array[b - gap];
array[b] = temp;
}
gap = (gap - 1) / 3;
print_array(array, size);
}
}
