#include "lists.h"

/**
* add_nodeint - adds a new node at the beginning of a listint_t list
* @head: The head pointer of the list
* @n: value to be stored in the new node
*
* Return: address of the new element, or NULL on failure
*/
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_element;

new_element = malloc(sizeof(listint_t));
if (new_element == NULL)
return (NULL);

new_element->n = n;
new_element->next = *head;
*head = new_element;

return (new_element);
}
