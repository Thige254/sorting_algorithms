#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly-linked list
 * @list: double pointer to the beginning of the list
 * @node1: first node to swap
 * @node2: second node to swap, right after node1
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;

	if (node2->prev)
		node2->prev->next = node2;
	else
		*list = node2;
}

/**
 * insertion_sort_list - sorts a doubly-linked list
 * using the Insertion sort algorithm
 * @list: double pointer to the beginning of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev_node;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		prev_node = current->prev;
		while (prev_node && prev_node->n > current->n)
		{
			swap_nodes(list, prev_node, current);
			print_list(*list);
			prev_node = current->prev;
		}
		current = current->next;
	}
}
