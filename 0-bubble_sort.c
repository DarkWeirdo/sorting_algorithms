#include <stdlib.h>
#include <stdio.h>
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
 * bubble_sort - Sorts an array of integers
 * using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped_no;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped_no = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_integers(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped_no = 1;
			}
		}
		/* If no two elements were swapped_no by inner loop, then break */
		if (swapped_no == 0)
			break;
	}
}

