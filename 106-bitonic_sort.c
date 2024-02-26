#include "sort.h"
#include <stdio.h>

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @start: Starting index of the subarray to be merged
 * @size: Size of the array
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 **/
void merge(int *array, size_t start, size_t size, int dir)
{
	if (size > 1)
	{
		size_t mid = size / 2;
		size_t i;

		for (i = start; i < start + mid; ++i)
		{
			if ((array[i] > array[i + mid]) == dir)
			{
				int temp = array[i];
				array[i] = array[i + mid];
				array[i + mid] = temp;
			}
		}
		merge(array, start, mid, dir);
		merge(array, start + mid, mid, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively sorts a bitonic sequence
 * @array: The array to be sorted
 * @start: Starting index of the subarray to be sorted
 * @size: Size of the array
 * @dir: Sorting direction (1 for ascending, 0 for descending)
 **/
void bitonic_sort_recursive(int *array, size_t start, size_t size, int dir)
{
	if (size > 1)
	{
		size_t mid = size / 2;
		printf("Merging [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
		print_array(array + start, size);

		bitonic_sort_recursive(array, start, mid, 1);
		bitonic_sort_recursive(array, start + mid, mid, 0);

		merge(array, start, size, dir);

		printf("Result [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
		print_array(array + start, size);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order using the
 *                Bitonic sort algorithm
 * @array: Pointer to the array to sort
 * @size: Size of the array
 **/
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sort_recursive(array, 0, size, 1);
}
