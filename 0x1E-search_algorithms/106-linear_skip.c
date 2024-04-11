#include "search_algos.h"

/**
 * linear_skip - Func searches a value in a sorted linked list
 * @list: The linked list with an express lane to search in
 * @value: The value to look for
 *
 * Return: Node with the value in the linked list,NULL otherwise
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	size_t i, stp;
	size_t u = 0, v = 0;
	skiplist_t *node, *next;

	if (!list)
		return (NULL);
	node = list;
	next = node->express ? node->express : node;

	while (next)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)next->index, next->n);
		if (next->n >= value)
			break;

		node = next;
		if ((node->n < value) && (node->express == NULL))
		{
			while (next->next)
				next = next->next;
			break;
		}
		next = node->express ? node->express : node;
	}

	u = node->index;
	v = next->index;
	printf("Value found between indexes [%d] and [%d]\n", (int)u, (int)v);

	while (node)
	{
		printf("Value checked at index [%d] = [%d]\n", (int)node->index, node->n);
		if (node->n == value)
			return (node);
		node = node->next;
	}

	return (NULL);
}
