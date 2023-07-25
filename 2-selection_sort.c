#include "sort.h"


/**
 * selection_sort - sorts an array of integers in ascending order
*                 by use of Selection sort algorithm
 * @array: the array to to be sorted
 * @size: number of elements in an array
 */
void selection_sort(int *array, size_t size)
{
size_t a, b, min_idx;

if (size < 2)
return;

for (a = 0; a < size - 1; a++)
{
min_idx = a;
for (b = a + 1; b < size; b++)
{
if (array[b] < array[min_idx])
min_idx = b;
}
if (min_idx != a)
{
int tmp = array[a];
array[a] = array[min_idx];
array[min_idx] = tmp;
print_array(array, size);
}
}
}

