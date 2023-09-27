#include "sort.h"

/**
* _partition - find and return the the index of the pivot
* which is the middle index for dividing array
* @array: half of array of integers
* @size: length of the array
* @left_i: left-most of half
* @right_i: right-most of half
*
* Return: size_t
*/
size_t _partition(
	int *array, size_t size,
	long int left_i, long int right_i)
{
	long int i, j;
	int pivot = array[right_i], tmp;

	i = left_i - 1;
	for (j = left_i; j <= right_i; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i == j)
				continue;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
			print_array(array, size);
		}
	}

	return (i);
}

/**
* _sort - sort elements on the left and right
* @array: array of integers
* @size: length of the array
* @left_i: left-most boundary of array
* @right_i: right-most boundary of array
*/
void _sort(
	int *array, size_t size,
	long int left_i, long int right_i
)
{
	long int p;

	if (left_i >= right_i || left_i < 0)
		return;

	p = _partition(array, size, left_i, right_i);

	_sort(array, size, left_i, p - 1);
	_sort(array, size, p + 1, right_i);
}

/**
* quick_sort - algorithm to
* sort an array of integers with lomuto partiioning
* @array: array of integers
* @size: length of the array
*/
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	_sort(array, size, 0, (long int) (size - 1));
}
