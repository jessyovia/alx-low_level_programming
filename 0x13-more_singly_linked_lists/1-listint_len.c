#include "lists.h"

/**
* listint_len - counts the number of elements in a linked list
* @h: The head pointer of the list
*
* Return: number of elements in the list
*/
size_t listint_len(const listint_t *h)
{
size_t element_count = 0;

while (h != NULL)
{
element_count++;
h = h->next;
}

return (element_count);
}
