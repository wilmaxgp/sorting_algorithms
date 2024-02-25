#include "sort.h"
#include <stdio.h>

/**
 * sift_down - Repair the heap whose root element is at index 'start'
 * @array: Array to heapify
 * @start: Starting index of the heap
 * @end: Ending index of the heap
 * @size: Size of the array
 **/
void sift_down(int *array, int start, int end, size_t size)
{
	int root = start, child, temp;

	while (2 * root + 1 <= end)
	{
		child = 2 * root + 1;
		if (child + 1 <= end && array[child] < array[child + 1])
			child++;
		if (array[root] < array[child])
		{
			temp = array[root];
			array[root] = array[child];
			array[child] = temp;
			print_array(array, size);
			root = child;
		}
		else
			return;
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order using the
 *             Heap sort algorithm
 * @array: Array to be sorted
 * @size: Size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int end = size - 1;
	int start;

	if (array == NULL || size < 2)
		return;

	for (start = (end - 1) / 2; start >= 0; start--)
		sift_down(array, start, end, size);

	while (end > 0)
	{
		int temp = array[end];
		array[end] = array[0];
		array[0] = temp;
		print_array(array, size);
		sift_down(array, 0, --end, size);
	}
}
