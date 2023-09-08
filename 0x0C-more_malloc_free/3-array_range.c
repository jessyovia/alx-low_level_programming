#include <stdlib.h>
#include <stdio.h>

/**
 * array_range - function that creates an array of integers
 * @min: value 1
 * @max: value 2
 *
 * Return: pointer integer
 */

int *array_range(int min, int max)
{
	int *point;
	int positions, count = 0;

	if (min > max)
		return (NULL);
	positions = (max - min) + 1;
	point = malloc(positions * sizeof(int));
	if (point == NULL)
		return (NULL);
	for (; count < positions; count++)
	{
		point[count] = min;
		min += 1;
	}
	return (point);
}
