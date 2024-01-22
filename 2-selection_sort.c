#include "sort.h"

/**
 * swap_integers - Swaps two integers in an array
 * @a: The first integer to swap
 * @b: The second integer to swap
 */
void swap_integers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * selection_sort - Sorts an array of integers in using the
 * Selection sort algorithm.
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap_integers(&array[min_idx], &array[i]);
			print_array(array, size);
		}
	}
}

