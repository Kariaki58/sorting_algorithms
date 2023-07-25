#include "sort.h"

void merge(int *array, int *temp, size_t left, size_t mid, size_t right)
{
	size_t i = left;
	size_t j = mid + 1;
	size_t k = left, l;

	while (i <= mid && i <= right)
	{
		if (array[i] <= array[j])
		{
			temp[k] = array[i];
			k++;
			i++;
		}
		else
		{
			temp[k] = array[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		temp[k] = array[i];
		k++;
		i++;
	}
	while (j <= right)
	{
		temp[k] = array[j];
		k++;
		j++;
	}
	for (l = left; l <= right; l++)
		array[l] = temp[l];
}

void merge_sort_recursion(int *array, int *temp, size_t left, size_t right)
{
	size_t mid;

	if (left >= right)
		return;
	mid = left + (right - left) / 2;
	merge_sort_recursion(array, temp, left, mid);
	merge_sort_recursion(array, temp, mid + 1, right);
	merge(array, temp, left, mid, right);
}

void merge_sort(int *array, size_t size)
{
	int *temp;

	temp = malloc(size * sizeof(int));
	if (!temp)
		return;
	merge_sort_recursion(array, temp, 0, size - 1);
	free(temp);
}
