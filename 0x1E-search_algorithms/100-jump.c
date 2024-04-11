#include "search_algos.h"

/**
 * jump_search - Searches for a value in a sorted array of integers
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: Index of the value, or -1 if not found
 */
int jump_search(int *array, size_t size, int value)
{
	size_t left = 0, right = 0;
	size_t step = sqrt(size);

	if (!array)
		return (-1);

	while ((right < size) && (*(array + right) < value))
	{
		printf("Value checked array[%d] = [%d]\n", (int)right, *(array + right));
		left = right;
		right += step;
		if (left >= size)
			return (-1);
	}
	printf("Value found between indexes [%d] and [%d]\n", (int)left, (int)right);
	right = right >= size ? size - 1 : right;

	for (; (left <= right) && (*(array + left) <= value); left++)
	{
		printf("Value checked array[%d] = [%d]\n", (int)left, *(array + left));
		if (*(array + left) == value)
			return ((int)left);
	}
	return (-1);
}
