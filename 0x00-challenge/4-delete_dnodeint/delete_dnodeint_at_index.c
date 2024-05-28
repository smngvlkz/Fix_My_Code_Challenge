#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete (0-based)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *prev_node;

	if (*head == NULL)
		return (-1);

	current = *head;
	prev_node = NULL;

	while (index > 0 && current != NULL)
	{
		prev_node = current;
		current = current->next;
		index--;
	}

	if (current == NULL)
		return (-1);

	if (prev_node != NULL)
		prev_node->next = current->next;
	else
		*head = current->next;

	if (current->next != NULL)
		current->next->prev = prev_node;

	free(current);
	return (1);
}
