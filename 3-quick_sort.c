#include "sort.h"
#include <stdio.h>

void quick_sort(int *array, size_t size);
void quicksort_helper(int *array, int low, int high, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);

/**
 * quick_sort - sorts an array of integers in ascending order using
 *              the Quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quicksort_helper(array, 0, size - 1, size);
}

/**
 * quicksort_helper - recursive helper function for quick sort
 * @array: array to sort
 * @low: starting index of the partition to be sorted
 * @high: ending index of the partition to be sorted
 * @size: size of the array
 */
void quicksort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quicksort_helper(array, low, pi - 1, size);
		quicksort_helper(array, pi + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for quick sort
 * @array: array to partition
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 *
 * Return: index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j, temp;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			print_array(array, size);
		}
	}
	temp = array[i + 1];
	array[i + 1] = array[high];
	array[high] = temp;
	print_array(array, size);
	return (i + 1);
}
