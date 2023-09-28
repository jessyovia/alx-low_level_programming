#include "lists.h"

/**
* print_listint_safe - prints a listint_t linked list to avoid infinite loops
* @head: The head pointer of the linked list
*
* Return: number of nodes in the list
*/
size_t print_listint_safe(const listint_t *head)
{
size_t node = 0;
const listint_t *temp = head;
const listint_t *tmp = NULL;
int new = 0;

while (temp != NULL)
{
if (new == 0)
{
tmp = temp;
printf("[%p] %d\n", (void *)temp, temp->n);
}
if (new == 1)
{
if (tmp <= temp)
{
printf("-> [%p] %d\n", (void *)temp, temp->n);
return (node);
}
printf("[%p] %d\n", (void *)temp, temp->n);
}
node += 1;
tmp = temp;
temp = temp->next;
new = 1;
}
return (node);
}
