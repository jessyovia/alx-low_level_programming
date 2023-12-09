#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes the node at a given index
 * @head: Pointer to the head of the list
 * @index: Index of the node to be deleted (starts at 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *temp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);

	current = *head;

	if (index == 0)
	{
		*head = current->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	while (current != NULL && i < index - 1)
	{
		current = current->next;
		i++;
	}

	if (current == NULL || current->next == NULL)
		return (-1);

	temp = current->next;
	current->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = current;

	free(temp);

	return (1);
}
