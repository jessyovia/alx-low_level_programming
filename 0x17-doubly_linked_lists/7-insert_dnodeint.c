#include "lists.h"
#include <stdlib.h>

dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n);

/**
 * insert_dnodeint_at_index - Inserts a new node at a given position
 * @h: Pointer to the head of the list
 * @idx: Index where the new node should be added (starts at 0)
 * @n: Integer value for the new node
 *
 * Return: Address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new_node, *current;
	unsigned int i = 0;

	if (h == NULL)
		return (NULL);

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (new_node == NULL)
		return (NULL);

	/* Initialize the new node */
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	/* If index is 0, update head and return new node */
	if (idx == 0)
	{
		new_node->next = *h;
		if (*h != NULL)
			(*h)->prev = new_node;
		*h = new_node;
		return (new_node);
	}

	/* Traverse to the node at position idx - 1 */
	current = *h;
	while (current != NULL && i < idx - 1)
	{
		current = current->next;
		i++;
	}

	/* If current is NULL, index is out of bounds, return NULL */
	if (current == NULL)
	{
		free(new_node);
		return (NULL);
	}

	/* Update pointers to insert the new node */
	new_node->next = current->next;
	if (current->next != NULL)
		current->next->prev = new_node;
	new_node->prev = current;
	current->next = new_node;

	return (new_node);
}
