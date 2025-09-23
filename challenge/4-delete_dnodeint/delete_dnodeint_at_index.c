#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Delete a node at a specific index from a list
 *
 * @head: A pointer to the first element of a list
 * @index: The index of the node to delete
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp;
	unsigned int p;

	if (head == NULL || *head == NULL)
	{
		return (-1);
	}

	tmp = *head;

	/* Handle deletion of first node (index 0) */
	if (index == 0)
	{
		*head = tmp->next;
		if (*head != NULL)
		{
			(*head)->prev = NULL;
		}
		free(tmp);
		return (1);
	}

	/* Traverse to find the node at the given index */
	p = 0;
	while (p < index && tmp != NULL)
	{
		tmp = tmp->next;
		p++;
	}

	/* If we didn't reach the index, it's out of bounds */
	if (p != index || tmp == NULL)
	{
		return (-1);
	}

	/* Update the previous node's next pointer */
	if (tmp->prev != NULL)
	{
		tmp->prev->next = tmp->next;
	}

	/* Update the next node's prev pointer */
	if (tmp->next != NULL)
	{
		tmp->next->prev = tmp->prev;
	}

	free(tmp);
	return (1);
}