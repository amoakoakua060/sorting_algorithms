#include "sort.h"

/**
* bubble_sort - algorithm for sorting an
* array of integers
* @array: array of integers
* @size: size of array
*/
void bubble_sort(int *array, size_t size)
{
	int swapped = 0, tmp;
	size_t i, j;

	if (size < 2)
		return;

	i = 0;
	while (i < size)
	{
		swapped = 0;

		for (j = 0; j < size - 1; j++)
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				print_array(array, size);
				swapped = 1;
			}

		i++;
		if (!swapped)
			break;
	}
}
