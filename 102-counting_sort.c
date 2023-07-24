#include "sort.h"

/**
 * counting_sort - sort an array
 * @array: array to sort
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	unsigned int status, max = 0, i, dump;
	int *temp_array, *count_array;

	if (size < 2)
		return;
	count_array = malloc(size * sizeof(int));
	for (status = 0; status < size; status++)
	{
		if (array[status] > (int)max)
			max = array[status];
		count_array[status] = array[status];
	}
	max++;
	temp_array = malloc(sizeof(int) * (max));
	if (!temp_array || !count_array)
		return;
	/*fill array with 0s*/
	for (i = 0; i < max; i++)
		temp_array[i] = 0;
	for (status = 0; status < size; status++)
		temp_array[array[status]]++;
	for (i = 1; i < max; i++)
		temp_array[i] += temp_array[i - 1];
	for (status = 0; status < size; status++)
	{
		dump = temp_array[count_array[status]] - 1;
		array[dump] = count_array[status];
	}
	print_array(temp_array, max);
	free(temp_array);
	free(count_array);
}
