#include "sort.h"


/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: A pointer to a pointer to the head of the doubly linked list
 * @node: The node to be swapped with its previous node
 */
void swap_nodes(listint_t **list, listint_t *node)
{
	listint_t *prev_node, *next_node;

	if (node == NULL || node->prev == NULL)
		return;

	prev_node = node->prev;
	next_node = node->next;

	prev_node->next = next_node;
	if (next_node != NULL)
		next_node->prev = prev_node;

	node->prev = prev_node->prev;
	node->next = prev_node;

	if (prev_node->prev != NULL)
		prev_node->prev->next = node;
	else
		*list = node;
	prev_node->prev = node;
}
/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: A pointer to a pointer to the head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || *list == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		prev = current->prev;
		while (prev != NULL && current->n < prev->n)
		{
			swap_nodes(list, current);
			prev = current->prev;
			print_list(*list);
		}
		current = current->next;
	}
}
