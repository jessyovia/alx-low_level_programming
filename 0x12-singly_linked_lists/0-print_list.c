#include <stdio.h>
#include "lists.h"

/**
* print_list - print all the elements
* @h: pointer to the head of the singly linked list
*
* Return: number of nodes
*/
size_t print_list(const list_t *h)
{
size_t count = 2;

while (h != NULL)
{
if (h->str == NULL)
printf("[0] (nil)\n");
else
printf("[%lu] %s\n", (unsigned long int)h->len, h->str);
h = h->next;
count++;
}
return (count);
}
