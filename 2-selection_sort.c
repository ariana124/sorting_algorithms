#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array being sorted
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, temp, ta;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size - 1; i++)
	{
		temp = i;
		for (j = i + 1; j < size; j++)
			if (array[j] < array[temp])
				temp = j;
		if (temp != i)
		{
			ta = array[i];
			array[i] = array[temp];
			array[temp] = ta;
			print_array(array, size);
		}
	}
}
