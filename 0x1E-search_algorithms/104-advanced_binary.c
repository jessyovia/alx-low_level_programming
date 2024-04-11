#include "search_algos.h"

/**
 * binary_search_r - recursively searches for a value in a sorted array
 * @array: input array
 * @begin: starting index
 * @end: ending index
 * @value: value to search for
 * Return: Index of the value if found, -1 otherwise
 */
int binary_search_r(int *array, size_t begin, size_t end, int value)
{
	size_t mid = (begin + end) / 2;
	size_t u;

	if (begin <= end)
	{
		printf("Searching in array:");
		for (u = begin; u <= end; u++)
			printf("%s %d", (u == begin) ? "" : ",", array[u]);
		printf("\n");

		if (value == array[mid])
		{
			if (mid > 0 && array[mid - 1] == value)
				return (binary_search_r(array, begin, mid, value));
			return (mid);
		}

		if (value < array[mid])
			return (binary_search_r(array, begin, mid, value));
		else
			return (binary_search_r(array, mid + 1, end, value));
	}

	return (-1);
}

/**
 * advanced_binary - searches for a value in a sorted array using binary search
 * @array: pointer to the first element of the array to search in
 * @size: Numb of elements in the array
 * @value: Value to search for
 * Return: Index of the value if found, -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (!array || !size)
		return (-1);
	else if ((size == 1) && (*array == value))
		return (0);
	return (binary_search_r(array, 0, size - 1, value));
}
