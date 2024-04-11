#include "search_algos.h"

/**
 * jump_list - Func searches for a value in a sorted list
 * @list: Ptr to the head of the list to search in
 * @size: Number of nodes in the list
 * @value: The value to search for
 *
 * Return: Ptr to the first node, or NULL if not found
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t i = 0, stp = sqrt(size);
	listint_t *node, *n_jump;

	if (!list || size == 0)
		return (NULL);

	for (node = n_jump = list; n_jump->index + 1 < size && n_jump->n < value;)
	{
		node = n_jump;
		for (i += stp; n_jump->index < i; n_jump = n_jump->next)
		{
			if (n_jump->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", n_jump->index, n_jump->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			node->index, n_jump->index);

	for (; node->index < n_jump->index && node->n < value; node = node->next)
		printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);
	printf("Value checked at index [%ld] = [%d]\n", node->index, node->n);

	return (node->n == value ? node : NULL);
}
