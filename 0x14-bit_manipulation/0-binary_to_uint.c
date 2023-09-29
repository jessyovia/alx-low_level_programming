#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - function that converts a binary number to an unsigned int
 * @b: Is pointing to a string of 0 and 1 chars
 * Return: the converted number, or 0 if
 * there is one or more chars in the string b that is not 0 or 1
 * b is NULL
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;
	unsigned int powerof2 = 1;
	int index = 0;

	if (b == NULL)
		return (0);

	while (b[index])
	{
		if (b[index] != '0' && b[index] != '1')
			return (0);
		index++;
	}

	index--;

	while (index >= 0)
	{
		if (b[index] == '1')
			result += powerof2;

		powerof2 *= 2;
		index--;
	}

	return (result);
}
