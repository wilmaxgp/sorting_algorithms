#include "sort.h"
#include <stdlib.h>

/**
 * radix_sort - Sorts an array of integers in ascending order using the
 *              Radix sort algorithm (LSD)
 * @array: Pointer to the array to sort
 * @size: Size of the array
 **/
void radix_sort(int *array, size_t size)
{
	int count[10];
	size_t i;
	int exp, max;

	if (array == NULL || size < 2)
		return;

	/* Find the maximum number to determine the number of digits */
	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	/* Perform counting sort for every digit */
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		int *output = malloc(size * sizeof(int));
		if (output == NULL)
			return;

		/* Initialize count array */
		for (i = 0; i < 10; i++)
			count[i] = 0;

		/* Count occurrences of digits at current exp */
		for (i = 0; i < size; i++)
			count[(array[i] / exp) % 10]++;

		/* Modify count to store actual position of digits */
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];

		/* Build the output array */
		for (i = size; i > 0; i--)
		{
			output[count[(array[i - 1] / exp) % 10] - 1] = array[i - 1];
			count[(array[i - 1] / exp) % 10]--;
		}

		/* Copy the output array to the original array */
		for (i = 0; i < size; i++)
			array[i] = output[i];

		/* Print the array after each significant digit */
		print_array(array, size);

		free(output);
	}
}
