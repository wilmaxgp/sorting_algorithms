#include "sort.h"
#include <stdio.h>

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap_nodes(listint_t **a, listint_t **b)
{
	listint_t *tmp;

	tmp = (*a)->prev;
	if (tmp)
		tmp->next = *b;
	(*b)->prev = tmp;
	(*a)->prev = *b;
	(*a)->next = (*b)->next;
	if ((*b)->next)
		(*b)->next->prev = *a;
	(*b)->next = *a;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm
 * @list: Double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL, *end = NULL;

	if (list == NULL || *list == NULL)
		return;

	while (swapped)
	{
		swapped = 0;
		for (start = *list; start->next != end; start = start->next)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(&start, &(start->next));
				if (start->prev == NULL)
					*list = start;
				print_list(*list);
				swapped = 1;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		end = start;
		for (; start->prev != NULL; start = start->prev)
		{
			if (start->n < start->prev->n)
			{
				swap_nodes(&(start->prev), &start);
				if (start->prev == NULL)
					*list = start;
				print_list(*list);
				swapped = 1;
			}
		}
	}
}
