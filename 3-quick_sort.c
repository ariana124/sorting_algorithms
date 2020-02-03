#include "sort.h"

/**
 * swap - function that swaps two elements
 * @i: value being swapped
 * @j: value to swap
 *
 * Return: void
 */
void swap(int *i, int *j)
{
	int s;

	s = *i;
	*i = *j;
	*j = s;
}


/**
 * partition - function that sorts low values before the pivot and high values
 * after the pivot
 * @array: array
 * @low: low value
 * @high: high value
 * @size: size of the array
 *
 * Return: the value after the smallest index of the array
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	if (pivot < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}


/**
 * quicksort - function that sorts an array of integers in ascending order
 * @array: array to be sorted
 * @low: low value
 * @high: high value
 * @size: size of array
 *
 * Return: void
 */
void quicksort(int *array, int low, int high, size_t size)
{
	int part_index;

	if (low < high)
	{
		part_index = partition(array, low, high, size);

		quicksort(array, low, part_index - 1, size);
		quicksort(array, part_index + 1, high, size);
	}
}


/**
 * quick_sort - function that sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array
 * @size: size of the array
 *
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	quicksort(array, 0, size - 1, size);
}
