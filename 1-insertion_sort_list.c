#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: The list to be modified
 * @node1: The first node to swap
 * @node2: The second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	if (node1->prev)
		node1->prev->next = node2;
	if (node2->next)
		node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	if (node1 == *list)
		*list = node2;
	else if (node2->prev == NULL)
		*list = node2;
	else
		node2->prev->next = node2;
}

/**
 * insertion_sort_list - Sort doubly linked list of ints in ascending order
 * using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !(*list))
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		temp = current;
		while ((temp->prev) && (temp->n < temp->prev->n))
		{
			swap_nodes(list, temp->prev, temp);
			print_list(*list);
			temp = temp->prev;
		}
		current = current->next;
	}
}
