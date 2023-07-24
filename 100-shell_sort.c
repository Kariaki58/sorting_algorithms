#include "sort.h"

/**
 * shell_sort - sort an array of integers using shell sort
 * @array: array of integers
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	unsigned int gap, i, j, temp;

	if (size < 2)
		return;
	gap = 1;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > (int)temp; j -= gap)
			{
				array[j] = array[j - gap];	
			}
			array[j] = temp;
		}
		print_array(array, size);

	}
}
