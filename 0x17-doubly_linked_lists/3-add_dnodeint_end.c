#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - Adds a new node at
 * the end of a dlistint_t list
 * @head: Pointer to the head of the list
 * @n: Integer value for the new node
 *
 * Return: Address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *current;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	/* Initialize the new node */
	new_node->n = n;
	new_node->next = NULL;

	/* If the list is empty, make the new node the head */
	if (*head == NULL)
	{
		new_node->prev = NULL;
		*head = new_node;
		return (new_node);
	}

	/* Traverse to the end of the list */
	current = *head;
	while (current->next != NULL)
		current = current->next;

	/* Update pointers for the new node and the current last node */
	new_node->prev = current;
	current->next = new_node;

	return (new_node);
}
