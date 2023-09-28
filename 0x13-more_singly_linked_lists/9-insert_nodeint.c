#include "lists.h"

/**
* insert_nodeint_at_index - inserts a node at a position in a listint_t linked
* @head: The head pointer of the linked list
* @idx: index of the position where the new node is to be inserted
* @n: data of the new node
*
* Return: pointer to the new node, or NULL on failure
*/
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
unsigned int temp = 0;
listint_t *new_node, *current;

if (head == NULL)
return (NULL);

new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;

if (idx == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}

current = *head;
while (current != NULL && temp < idx - 1)
{
current = current->next;
temp++;
}

if (current == NULL)
{
free(new_node);
return (NULL);
}

new_node->next = current->next;
current->next = new_node;

return (new_node);
}
