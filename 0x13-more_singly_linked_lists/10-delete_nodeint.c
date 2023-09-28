#include "lists.h"

/**
* delete_nodeint_at_index - deletes a node at a index in a listint_t linkd list
* @head: The head pointer of the linked list
* @index: index of the node to be deleted
*
* Return: 1 if successful, -1 on failure
*/
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
unsigned int count = 0;
listint_t *node, *reversed;

if (head == NULL || *head == NULL)
return (-1);

node = *head;

if (index == 0)
{
*head = node->next;
free(node);
return (1);
}

while (node != NULL && count < index - 1)
{
node = node->next;
node++;
}

if (node == NULL || node->next == NULL)
return (-1);

reversed  = node->next->next;
free(node->next);
node->next = reversed;

return (1);
}
