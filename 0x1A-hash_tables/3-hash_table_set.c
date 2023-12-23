#include "hash_tables.h"
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

/**
 * hash_table_set - Adds an element to the hash table
 * @ht: Pointer to the hash table
 * @key: Key
 * @value: Value
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *new_node;
	char *value_duplicate;
	unsigned long int index;
	unsigned long int current_index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	value_duplicate = strdup(value);
	if (value_duplicate == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	current_index = index;

	while (ht->array[current_index])
	{
		if (strcmp(ht->array[current_index]->key, key) == 0)
		{
			/* Key already exists, update the value and free the duplicate */
			free(ht->array[current_index]->value);
			ht->array[current_index]->value = value_duplicate;
			return (1);
		}
		current_index++;
		if (current_index == ht->size)
			current_index = 0; /* Wrap around to the beginning if necessary */
		if (current_index == index)
			break; /* Entire hash table checked, break the loop */
	}

	/* Allocate and initialize a new node */
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
	{
		free(value_duplicate);
		return (0);
	}

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(value_duplicate);
		free(new_node);
		return (0);
	}

	new_node->value = value_duplicate;
	new_node->next = ht->array[index];
	ht->array[index] = new_node;

	return (1);
}
