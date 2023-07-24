#include "sort.h"
#include <stdio.h>

/**
 * pivot_position - divide and conqure to get the main position of pivot
 * @array: array of integers
 * @low: low bound of the array
 * @high: higher bound of the array
 * @size: size of the array
 * Return: return the index of pivot
 */
int pivot_position(int *array, int low, int high, size_t size)
{
	int i, j = low - 1, temp;
	int pivot = array[high];

	for (i = low; i < high; i++)
	{
		if (array[i] < pivot && array[++j] != array[i])
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	j++;
	if (array[j] != array[high])
	{
		temp = array[j];
		array[j] = array[high];
		array[high] = temp;
		print_array(array, size);
	}
	return (j);
}

/**
 * call_recursion - call the recursive code for the function
 * @array: array of integers
 * @low: lower bound of the array
 * @high: higher bound of the array
 * @size: size of the array
 * Return: return the index of pivot
 */
void call_recursion(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = pivot_position(array, low, high, size);
		call_recursion(array, low, pivot - 1, size);
		call_recursion(array, pivot + 1, high, size);
	}
}
/**
 * quick_sort - sort an array of integer using quick sort algorithm
 * @array: array of numbers
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	call_recursion(array, 0, size - 1, size);
}
