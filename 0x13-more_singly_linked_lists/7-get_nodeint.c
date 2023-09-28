#include "lists.h"

/**
* get_nodeint_at_index - returns the nth node of a listint_t linked list
* @head: The head pointer of the linked list
* @index: index of the node to retrieve (starting from 0)
*
* Return: pointer to the nth node, or NULL if the node is not found
*/
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
unsigned int temp = 0;
listint_t *new_node = head;

while (new_node != NULL)
{
if (temp == index)
{
return (new_node);
}
new_node = new_node->next;
temp++;
}

return (NULL);
}
