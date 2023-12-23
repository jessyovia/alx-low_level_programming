#include "hash_tables.h"

/**
 * hash_djb2 - Implements the djb2 hash algorithm
 * @str: Input string
 *
 * Return: Computed hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hash_value; /* Computed hash value */
	int current_char; /* Current character being processed */

	hash_value = 5381; /* Initial hash value, a prime number */

	while ((current_char = *str++))
	{
		/* Update the hash value using the formula: hash * 33 + current_char */
		hash_value = ((hash_value << 5) + hash_value) + current_char;
	}

	return (hash_value);
}
