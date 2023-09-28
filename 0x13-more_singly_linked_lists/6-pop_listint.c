#include "lists.h"

/**
* pop_listint - deletes the head node from a listint_t linked list
* @head: The head pointer of the linked list
*
* Return: data that was in the deleted node, or 0 if the list is empty
*/
int pop_listint(listint_t **head)
{
int current_node = 0;
listint_t *temp;

if (head == NULL || *head == NULL)
return (0);

temp = *head;
current_node = temp->n;
*head = temp->next;

free(temp);

return (current_node);
}
