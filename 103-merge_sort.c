#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

void merge(int *array, int left, int mid, int right, int *temp);
void split_merge(int *array, int left, int right, size_t size, int *temp);

/**
 * merge - Merges two subarrays of array[]
 * @array: The array to be sorted
 * @left: Starting index of left subarray
 * @mid: Ending index of left subarray
 * @right: Ending index of right subarray
 * @temp: Temporary array for merging
 **/
void merge(int *array, int left, int mid, int right, int *temp)
{
	int i = left, j = mid + 1, k = 0;

	printf("[left]: ");
	print_array(array + left, mid - left + 1);
	printf("[right]: ");
	print_array(array + mid + 1, right - mid);

	while (i <= mid && j <= right)
	{
		if (array[i] <= array[j])
			temp[k++] = array[i++];
		else
			temp[k++] = array[j++];
	}

	while (i <= mid)
		temp[k++] = array[i++];

	while (j <= right)
		temp[k++] = array[j++];

	for (i = left, k = 0; i <= right; i++, k++)
		array[i] = temp[k];

	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}

/**
 * merge_sort - Sorts an array of integers in ascending order using the
 *              Merge sort algorithm
 * @array: Pointer to the array to sort
 * @size: Size of the array
 **/
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (array == NULL || size < 2)
		return;

	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;

	split_merge(array, 0, size - 1, size, temp);

	free(temp);
}

/**
 * split_merge - Recursively splits the array and merges
 * @array: The array to be sorted
 * @left: Starting index of subarray
 * @right: Ending index of subarray
 * @size: Size of the array
 * @temp: Temporary array for merging
 **/
void split_merge(int *array, int left, int right, size_t size, int *temp)
{
	if (left < right)
	{
		int mid = (left + right) / 2;

		split_merge(array, left, mid, size, temp);
		split_merge(array, mid + 1, right, size, temp);
		merge(array, left, mid, right, temp);
	}
}
