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
 * bubble_sort - sorts an array of integers
 * @array: array of integers
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	unsigned int i, j, swap_check;

	if (size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		swap_check = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				swap_check = 1;
				print_array(array, size);
			}
		}
		if (!swap_check)
			break;
	}
}
