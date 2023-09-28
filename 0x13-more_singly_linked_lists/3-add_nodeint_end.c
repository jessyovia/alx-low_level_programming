#include "lists.h"

/**
* add_nodeint_end - adds a new node at the end of a listint_t list
* @head: The head pointer of the list
* @n: value to insert at the end of the list
*
* Return: address of the new element, or NULL on failure
*/
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *temp;
listint_t *last;

temp = malloc(sizeof(listint_t));
if (temp == NULL)
return (NULL);

temp->n = n;
temp->next = NULL;

if (*head == NULL)
{
*head = temp;
}
else
{
last = *head;
while (last->next != NULL)
{
last = last->next;
}
last->next = temp;
}

return (temp);
}
