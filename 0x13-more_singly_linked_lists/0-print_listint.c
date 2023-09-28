#include <stdio.h>
#include "lists.h"

/**
* print_listint - print all elements of a listint_t list
* @h: pointer to the head of the list
*
* Return: number of nodes (elements) in the list
*/
size_t print_listint(const listint_t *h)
{
size_t element_count = 0;

while (h != NULL)
{
printf("%d\n", h->n);
h = h->next;
element_count++;
}

return (element_count);
}
