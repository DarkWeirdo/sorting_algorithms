#include "sort.h"
/**
 * partition - Partitions the array around a pivot
 * @array: The array to be partitioned
 * @low: The lower bound of the array
 * @high: The upper bound of the array
 * @pivot_ndx: The index of the pivot
 *
 * Return: The index of the pivot after partitioning
 */
static size_t partition(int *array, size_t low, size_t high, size_t pivot_ndx)
{
	int pivot_value = array[pivot_ndx];
	size_t i;

	/* Move pivot to end */
	swap_integers(&array[pivot_ndx], &array[high]);
	pivot_ndx = high;

	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot_value)
		{
			swap_integers(&array[i], &array[low]);
			low++;
		}
	}

	/* Move pivot to correct position */
	swap_integers(&array[low], &array[pivot_ndx]);

	return (low);
}

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 * Quick sort algorithm.
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	size_t low, high, pivot_ndx;

	if (size < 2)
		return;

	low = 0;
	high = size - 1;

	while (low < high)
	{
		pivot_ndx = partition(array, low, high, high);

		if (pivot_ndx > low)
		{
			quick_sort(array, pivot_ndx);
		}

		low = pivot_ndx + 1;
	}

	print_array(array, size);
}

/**
 * swap_integers - Swaps the values of two integers
 * @a: First integer
 * @b: Second integer
 */
void swap_integers(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
