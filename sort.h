#ifndef HEADER_H
#define HEADER_H
#include <stdlib.h>

/**
 * struct listint_s - Double linked list node
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
void swap(int *a, int *b);
void insertion_sort_list(listint_t **list);
int linkend_list_length(listint_t *list);
void selection_sort(int *array, size_t size);
#endif