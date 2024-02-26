#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two elements in an array
 * @a: First element
 * @b: Second element
 **/
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Partitions the array and returns the index of the pivot element
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 * Return: Index of the pivot element
 **/
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	if (array[high] < array[i + 1])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - Sorts a partition of the array using the Quick sort algorithm
 * @array: Array to sort
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 **/
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using the Quick sort algorithm
 * @array: Array to sort
 * @size: Size of the array
 **/
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
