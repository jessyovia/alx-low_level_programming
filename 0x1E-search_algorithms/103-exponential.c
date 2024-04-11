#include "search_algos.h"

/**
 * bi_search - Searches for a value
 * in a sorted array via binary search
 * @arr: Pointer to the first element of the array to search in
 * @bgn: Starting index
 * @end: Ending index
 * @val: The value to search for
 *
 * Return: The index where the value is located, -1 Otherwise
 */
int bi_search(int *arr, size_t bgn, size_t end, int val)
{
	size_t mid, i;

	if (!arr)
		return (-1);

	while (end >= bgn)
	{
		printf("Searching in array: ");
		for (i = bgn; i < end; i++)
			printf("%d, ", arr[i]);
		printf("%d\n", arr[i]);

		mid = bgn + (end - bgn) / 2;
		if (arr[mid] == val)
			return (mid);
		if (arr[mid] > val)
			end = mid - 1;
		else
			bgn = mid + 1;
	}

	return (-1);
}

/**
 * exponential_search - Searches for a value in a sorted array
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 *
 * Return: The index where the value is located, -1 Otherwise
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t k, j;

	if (!array)
		return (-1);

	if (array[0] != value)
	{
		for (k = 1; k < size && array[k] <= value; k *= 2)
			printf("Value checked array[%ld] = [%d]\n", k, array[k]);
	}

	j = (k < size) ? k : (size - 1);
	printf("Value found between indexes [%ld] and [%ld]\n", k / 2, j);
	return (bi_search(array, k / 2, j, value));
}
