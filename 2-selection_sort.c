#include "sort.h"

/**
* selection_sort - algorithm to
* sort an array of integers
* @array: array of integers
* @size: length of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j, min_i;
	int tmp;

	while (i < size)
	{
		min_i = i;
		for (j = i + 1; j < size; j++)
			if (array[min_i] > array[j])
				min_i = j;

		if (min_i != i)
		{
			tmp = array[i];
			array[i] = array[min_i];
			array[min_i] = tmp;
			print_array(array, size);
		}

		i++;
	}
}
