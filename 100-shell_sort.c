#include "sort.h"

void shell_sort(int *array, size_t size)
{
	size_t gap = 1;
	int temp;
	size_t i, j;

	while (gap <= size / 3)
		gap = gap * 3 + 1;
	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp; j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
