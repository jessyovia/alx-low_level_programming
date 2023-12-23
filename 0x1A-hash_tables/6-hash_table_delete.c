#include "hash_tables.h"

/**
 * hash_table_delete - Deletes a hash table
 * @ht: Pointer to a hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *table_head;
	hash_node_t *current_node;
	hash_node_t *next_node;
	unsigned long int index;

	table_head = ht;

	for (index = 0; index < ht->size; index++)
	{
		if (ht->array[index] != NULL)
		{
			current_node = ht->array[index];
			while (current_node != NULL)
			{
				next_node = current_node->next;
				free(current_node->key);
				free(current_node->value);
				free(current_node);
				current_node = next_node;
			}
		}
	}
	free(table_head->array);
	free(table_head);
}
