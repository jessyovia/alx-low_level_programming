#include "hash_tables.h"

/**
 * key_index - Computes the index for storing a key/value pair in a hash table
 * @key: Key
 * @size: Size of the hash table
 *
 * Return: The index where the key/value pair should be stored
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	/* Use the djb2 hash algorithm to compute the hash value */
	unsigned long int hash_value = hash_djb2(key);

	/* Calculate the index based on the hash value */
	unsigned long int index = hash_value % size;

	return (index);
}
