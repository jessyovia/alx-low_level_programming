#include "lists.h"

/**
* reverse_listint - reverses a listint_t linked list in-place
* @head: The head pointer of the linked list
*
* Return: pointer to the first node of the reversed list
*/
listint_t *reverse_listint(listint_t **head)
{
listint_t *prev = NULL;
listint_t *next = NULL;
listint_t *node = *head;

while (node != NULL)
{
next = node->next;
node->next = prev;
prev = node;
node = next;
}

*head = prev;

return (*head);
}
