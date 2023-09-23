#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
* add_node_end - add a new node to the end of a linked list
* @head: a pointer to a pointer to the head node
* @str: the string to be stored in the new node
*
* Return: a pointer to the newly created node, or NULL on failure
*/
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new_node;
list_t *last;

if (str == NULL)
return (NULL);

new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

new_node->str = strdup(str);
if (new_node->str == NULL)
{
free(new_node);
return (NULL);
}

new_node->len = strlen(str);
new_node->next = NULL;

if (*head == NULL)
{
*head = new_node;
}
else
{
last = *head;
while (last->next != NULL)
{
last = last->next;
}
last->next = new_node;
}

return (new_node);
}
