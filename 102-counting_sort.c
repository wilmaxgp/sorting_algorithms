#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * counting_sort - Sorts an array of integers in ascending order using the
 *                 Counting sort algorithm
 * @array: Pointer to the array to sort
 * @size: Size of the array
 */
void counting_sort(int *array, size_t size)
{
	size_t i, j;
	int max;

	/* Move variable declarations to the beginning of the block */
	int *count;

	if (array == NULL || size < 2)
		return;

	max = array[0];

	/* Find the maximum element in the array */
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Create counting array of size max + 1 */
	count = (int *)malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;

	/* Initialize counting array elements to 0 */
	for (i = 0; i <= (size_t)max; i++)
		count[i] = 0;

	/* Count occurrences of each element */
	for (i = 0; i < size; i++)
		count[array[i]]++;

	/* Print the counting array */
	printf("Counting array: ");
	print_array(count, max + 1);
	
	/* Update array with sorted elements */
	j = 0;
	for (i = 0; i <= (size_t)max; i++)
	{
		while (count[i] > 0)
		{
			array[j++] = (int)i;
			count[i]--;
		}
	}

	free(count);
}
