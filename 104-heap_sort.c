#include "sort.h"

/**
 * swap - swap integer
 * @a: adress integer 1
 * @b: address integer 2
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * heapify - heapify recursion
 * @arr: arr
 * @size: size
 * @a: a
 * @b: b
 */
void heapify(int *arr, size_t size, size_t a, size_t b)
{
	size_t more, left, right;

	more = b;
	left = 2 * b + 1;
	right = 2 * b + 2;
	if (left < a && arr[left] > arr[more])
		more = left;
	if (right < a && arr[right] > arr[more])
		more = right;
	if (more != b)
	{
		swap(&arr[b], &arr[more]);
		print_array(arr, size);
		heapify(arr, size, a, more);
	}
}

/**
 * heap_sort - sort array
 * @array: array of intergers
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (size < 2)
		return;
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, size, i);
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, i, 0);
	}
}
