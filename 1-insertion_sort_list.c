#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: The list to be modified
 * @node: The node var for swaps
 */
listint_t *swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *current = node;
	listint_t *previous = node->prev;
	previous->next = current->next;
	if (current->next)
		current->next->prev = previous;
	current->next = previous;
	current->prev = previous->prev;
	previous->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}

/**
 * insertion_sort_list - Sort doubly linked list of ints in ascending order
 * using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;

	if (!list || !(*list))
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		while ((current->prev) && (current->n < current->prev->n))
		{
			current = swap_nodes(list, current);
			print_list(*list);
		}
		current = current->next;
	}
}
