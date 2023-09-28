#include "lists.h"

/**
* free_listint2 - frees a listint_t linked list and sets the head to NULL
* @head: The head pointer head of the linked list
*/
void free_listint2(listint_t **head)
{
listint_t *new_node, *next;

if (head == NULL || *head == NULL)
return;

new_node = *head;
while (new_node != NULL)
{
next = new_node->next;
free(new_node);
new_node = next;
}

*head = NULL;
}
