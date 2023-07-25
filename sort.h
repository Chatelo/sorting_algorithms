#ifndef SORT_H
#define SORT_H

#include <stdint.h>
#include <stdio.h>
#include <stddef.h>
#include <sys/types.h>
#include <stdlib.h>



/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);

void quick_sort(int *array, size_t size);
void sort_alg(int *arr, int left, int right, size_t size);
int split(int *arr, int left, int right, size_t size);


void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *array, int *tmp, int start, int mid, int end);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);

void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);


void swap(int *a, int *b);

/* Function to swap two nodes in a linked list */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

#endif /* SORT_H */

