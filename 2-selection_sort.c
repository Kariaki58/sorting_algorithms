#include "sort.h"

/**
 * swap - swap two integers
 * @a: int1
 * @b: int2
 */
void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - sort an array
 * @array: array to be sorted
 * @size: size of array
*/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min_idx, key;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (a[min_idx] > a[j])
				min_idx = j;
		key = a[min_idx];
		for (k = min_idx; k > i; k--)
			a[k] = a[k - 1];
		a[i] = key;
	}
}
