#include "sort.h"
#include <stdio.h>
/**
 *_calloc - this is calloc function
 *
 *@nmemb: number of the elemets
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
 *merge - make a merge
 *
 *@arr: one from start to mid
 *@tmp: temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@start: first element position
 *@mid: array middle
 *@end: last element position
 **/
void merge(int *arr, int *tmp, int start, int mid, int end)
{
	/*  sizes & temp arrays */
	int size_left = mid - start + 1, size_right = end - mid;
	int *array_left, *array_right;
	/* counters */
	int left, right, a = 0;

	array_left = &tmp[0];
	array_right = &tmp[size_right];
	for (left = 0; left < size_left; left++)
		array_left[left] = arr[start + left];
	for (right = 0; right < size_right; right++)
		array_right[right] = arr[mid + 1 + right];
	left = 0, right = 0, a = start;
	/* merging tmp arrays into one main array*/
	while (left < size_left && right < size_right)
	{
		if (array_left[left] <= array_right[right])
			arr[a] = array_left[left], left++;
		else
			arr[a] = array_right[right], right++;
		a++;
	}
	/* merging tmp arrays into one main array*/
	while (left < size_left)
		arr[a] = array_left[left], left++, a++;
	/* merging tmp arrays into one main array*/
	while (right < size_right)
		arr[a] = array_right[right], right++, a++;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(array_left, left);
	printf("[right]: ");
	print_array(array_right, right);
	printf("[Done]: ");
	print_array(&arr[start], left + right);
}
/**
 *mergesort - function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *
 *@array: array of integers
 *@tmp: temp array used in merge, was created outside to
 *optimize reducing the system calls
 *@start: fisrt element position
 *@end: last element position
 *Return: void
 */
void mergesort(int *array, int *tmp, int start, int end)
{
	int mid;

	mid = (start + end) / 2;
	if ((start + end) % 2 == 0)
		mid--;
	if (mid >= start)
	{
		mergesort(array, tmp, start, mid);
		mergesort(array, tmp, mid + 1, end);
		merge(array, tmp, start, mid, end);
	}
}
/**
 *merge_sort - function that sorts an array of integers
 *in ascending order using the Merge sort algorithm
 *
 *@size: size of the list
 *@array: array of integers
 *Return: void
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (!array || size < 2)
		return;
	tmp = _calloc(size, sizeof(int));
	mergesort(array, tmp, 0, size - 1);
	free(tmp);
}
