#include "sort.h"

/**
 * find_pivot - find the pivot position
 * @array: array of integers
 * @l: left index
 * @r: right index
 * @size: size
 * Return: return 0.
 */
int find_pivot(int *array, int l, int r, size_t size)
{
	int pivot, temp;
	unsigned int i, j;

	pivot = array[r];
	i = l - 1;
	j = r + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i >= j)
			return (i);
		if (i != j)
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	return (0);
}

/**
 * call_function - recurvis to swap array
 * @array: array of integers
 * @l: l
 * @r: r
 * @size: size
 */
void call_function(int *array, int l, int r, size_t size)
{
	int pivot;

	if (l < r)
	{
		pivot = find_pivot(array, l, r, size);
		call_function(array, l, pivot - 1, size);
		call_function(array, pivot, r, size);
	}
}
/**
 * quick_sort_hoare - sorts an array of integers
 * @array: array of numbers
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;
	call_function(array, 0, size - 1, size);
}
