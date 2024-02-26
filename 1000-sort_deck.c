#include "deck.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * card_value - Assigns a numerical value to a card
 * @value: Value of the card
 * Return: Numerical value of the card
 **/

int card_value(const char *value)
{
	if (value[0] == 'A')
		return (1);
	if (value[0] == '2')
		return (2);
	if (value[0] == '3')
		return (3);
	if (value[0] == '4')
		return (4);
	if (value[0] == '5')
		return (5);
	if (value[0] == '6')
		return (6);
	if (value[0] == '7')
		return (7);
	if (value[0] == '8')
		return (8);
	if (value[0] == '9')
		return (9);
	if (value[0] == '1')
		return (10);
	if (value[0] == 'J')
		return 11;
	if (value[0] == 'Q')
		return (12);
	if (value[0] == 'K')
		return (13);
	return (0);
}

/**
 * compare_cards - Compares two card values
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 * Return: Difference between the values
 **/

int compare_cards(const void *a, const void *b)
{
	return card_value((*(deck_node_t **)a)->card->value) -
		card_value((*(deck_node_t **)b)->card->value);
}

/**
 * sort_deck - Sorts a deck of cards in ascending order
 * @deck: Pointer to a pointer to the head of the deck
 **/

void sort_deck(deck_node_t **deck)
{
	size_t count = 0;
	deck_node_t *current = *deck;
	deck_node_t **cards_array = NULL;
	size_t i;

	while (current)
	{
		count++;
		current = current->next;
	}

	if (count <= 1)
		return;

	cards_array = (deck_node_t **)malloc(count * sizeof(deck_node_t *));
	if (cards_array == NULL)
		return;

	current = *deck;

	for (i = 0; i < count && current; i++)
	{
		cards_array[i] = current;
		current = current->next;
	}

	qsort(cards_array, count, sizeof(deck_node_t *), compare_cards);

	for (i = 0; i < count - 1; i++)
	{
		cards_array[i]->next = cards_array[i + 1];
		cards_array[i + 1]->prev = cards_array[i];
	}
	cards_array[0]->prev = NULL;
	cards_array[count - 1]->next = NULL;
	*deck = cards_array[0];

	free(cards_array);
}
