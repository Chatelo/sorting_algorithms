#include "sort.h"

/**
* radix_sort - sorts an array of integers in ascending order using
* the Radix sort algorithm
*
* @array: Array to be sorted
* @size: Size of the array
*/
void radix_sort(int *array, size_t size)
{
int a, max_digit = 0, digit_place = 1;
int *tmp = NULL, *count = NULL;

if (array == NULL || size < 2)
return;

tmp = malloc(sizeof(int) * size);
if (tmp == NULL)
return;

for (a = 0; a < (int)size; a++)
if (array[a] > max_digit)
max_digit = array[a];

while (max_digit / digit_place > 0)
{
count = calloc(sizeof(int), 10);
if (count == NULL)
{
free(tmp);
return;
}

for (a = 0; a < (int)size; a++)
count[array[a] / digit_place % 10]++;

for (a = 1; a < 10; a++)
count[a] += count[a - 1];

for (a = (int)size - 1; a >= 0; a--)
tmp[--count[array[a] / digit_place % 10]] = array[a];

for (a = 0; a < (int)size; a++)
array[a] = tmp[a];

print_array(array, size);
digit_place *= 10;
free(count);
}
free(tmp);
}
