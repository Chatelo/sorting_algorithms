#include "sort.h"
#include <stdio.h>

/**
*_calloc - this is a calloc function
*
*@nmemb: number of elemets
*@size: bit size of each element
*Return: pointer to memory assignement
*/
void *_calloc(unsigned int nmemb, unsigned int size)
{
unsigned int a = 0;
char *p;

if (nmemb == 0 || size == 0)
return ('\0');
p = malloc(nmemb * size);
if (p == NULL)
return ('\0');
for (a = 0; a < (nmemb * size); a++)
p[a] = '\0';
return (p);
}
/**
* counting_sort - this is a counting sort method implementation
* @array: array to sort
* @size: array size
*/
void counting_sort(int *array, size_t size)
{
int index, maximun = 0, *counter = '\0', *tmp = '\0';
size_t a;

if (array == NULL || size < 2)
return;
/* find maximun number */
for (a = 0; a < size; a++)
if (array[a] > maximun)
maximun = array[a];
counter = _calloc(maximun + 1, sizeof(int));
tmp = _calloc(size + 1, sizeof(int));
/* count the array elements */
for (a = 0; a < size; a++)
counter[array[a]]++;
/* get the accumulative values */
for (index = 1; index <= maximun; index++)
counter[index] += counter[index - 1];
print_array(counter, maximun + 1);
/* get the new array sorted */
for (a = 0; a < size; ++a)
{
tmp[counter[array[a]] - 1] = array[a];
counter[array[a]]--;
}
/* replace old array to new array sorted */
for (a = 0; a < size; a++)
array[a] = tmp[a];
free(tmp);
free(counter);
}
