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
	unsigned int i, j, min_idx;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[min_idx])
				min_idx = j;
		if (min_idx != i)
		{
			swap(&array[min_idx], &array[i]);
			print_array(array, size);
		}

	}
}
