#include "lists.h"

/**
 * add_dnodeint - Adds a new node at
 * the beginning of a dlistint_t list
 * @head: Pointer to the head of the list
 * @n: Integer value for the new node
 *
 * Return: Address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *new_node, *current_head;

	/* Allocate memory for the new node */
	new_node = malloc(sizeof(dlistint_t));
	if (!new_node)
		return (NULL);

	/* Initialize the new node */
	new_node->n = n;
	new_node->prev = NULL;

	/* Find the current head of the list */
	current_head = *head;

	/* Traverse to the first node if the list is not empty */
	if (current_head != NULL)
	{
		while (current_head->prev != NULL)
			current_head = current_head->prev;
	}

	/* Update pointers for the new node and the current head */
	new_node->next = current_head;
	if (current_head != NULL)
		current_head->prev = new_node;

	/* Update the head to point to the new node */
	*head = new_node;

	return (new_node);
}
