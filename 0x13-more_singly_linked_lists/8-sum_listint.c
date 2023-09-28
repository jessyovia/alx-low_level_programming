#include "lists.h"

/**
* sum_listint - calculates the sum of all data value in a listint_t linked list
* @head: The head pointer of the linked list
*
* Return: sum of all data values, or 0 if the list is empty
*/
int sum_listint(listint_t *head)
{
int sum = 0;
listint_t *temp = head;

while (temp != NULL)
{
sum += temp->n;
temp = temp->next;
}

return (sum);
}
