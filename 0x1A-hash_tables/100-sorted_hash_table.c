#include "hash_tables.h"

shash_table_t *shash_table_create(unsigned long int size);
int shash_table_set(shash_table_t *ht, const char *key, const char *value);
char *shash_table_get(const shash_table_t *ht, const char *key);
void shash_table_print(const shash_table_t *ht);
void shash_table_print_rev(const shash_table_t *ht);
void shash_table_delete(shash_table_t *ht);

/**
 * shash_table_create - Func creates a sorted hash table
 * @size: Size
 *
 * Return: NULL if error, otherwise a ptr
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int u;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (u = 0; u < size; u++)
		ht->array[u] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}
/**
 * shash_table_set - Func adds an elem to a sorted hash table
 * @ht: Ptr to the hash table
 * @key: Key
 * @value: Value
 *
 * Return: 0 if failed, -1 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new;
	shash_node_t *v;
	char *val_dup;
	unsigned long int dir;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	val_dup = strdup(value);
	if (val_dup == NULL)
		return (0);

	dir = key_index((const unsigned char *)key, ht->size);
	v = ht->shead;
	while (v)
	{
		if (strcmp(v->key, key) == 0)
		{
			free(v->value);
			v->value = val_dup;
			return (1);
		}
		v = v->snext;
	}

	new = malloc(sizeof(shash_node_t));
	if (new == NULL)
	{
		free(val_dup);
		return (0);
	}
	new->key = strdup(key);
	if (new->key == NULL)
	{
		free(val_dup);
		free(new);
		return (0);
	}
	new->value = val_dup;
	new->next = ht->array[dir];
	ht->array[dir] = new;

	if (ht->shead == NULL)
	{
		new->sprev = NULL;
		new->snext = NULL;
		ht->shead = new;
		ht->stail = new;
	}
	else if (strcmp(ht->shead->key, key) > 0)
	{
		new->sprev = NULL;
		new->snext = ht->shead;
		ht->shead->sprev = new;
		ht->shead = new;
	}
	else
	{
		v = ht->shead;
		while (v->snext != NULL && strcmp(v->snext->key, key) < 0)
			v = v->snext;
		new->sprev = v;
		new->snext = v->snext;
		if (v->snext == NULL)
			ht->stail = new;
		else
			v->snext->sprev = new;
		v->snext = new;
	}

	return (1);
}
/**
 * shash_table_get - Func retrieves the value in a sorted hash table
 * @ht: Ptr to the hash table
 * @key: Key
 *
 * Return: NULL if not found,Otherwise the value associated with key
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *elem;
	unsigned long int dir;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	dir = key_index((const unsigned char *)key, ht->size);
	if (dir >= ht->size)
		return (NULL);

	elem = ht->shead;
	while (elem != NULL && strcmp(elem->key, key) != 0)
		elem = elem->snext;

	return ((elem == NULL) ? NULL : elem->value);
}
/**
 * shash_table_print - Func prints a sorted hash table
 * @ht: Ptr to the hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *elem;

	if (ht == NULL)
		return;

	elem = ht->shead;
	printf("{");
	while (elem != NULL)
	{
		printf("'%s': '%s'", elem->key, elem->value);
		elem = elem->snext;
		if (elem != NULL)
			printf(", ");
	}
	printf("}\n");
}
/**
 * shash_table_print_rev - Func prints a sorted hash table in reverse
 * @ht: Ptr to the hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *elem;

	if (ht == NULL)
		return;

	elem = ht->stail;
	printf("{");
	while (elem != NULL)
	{
		printf("'%s': '%s'", elem->key, elem->value);
		elem = elem->sprev;
		if (elem != NULL)
			printf(", ");
	}
	printf("}\n");
}
/**
 * shash_table_delete - Func deletes a sorted hash table
 * @ht: Ptr to the hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_table_t *head;
	shash_node_t *elem;
	shash_node_t *v;

	head = ht;

	if (ht == NULL)
		return;

	elem = ht->shead;
	while (elem)
	{
		v = elem->snext;
		free(elem->key);
		free(elem->value);
		free(elem);
		elem = v;
	}

	free(head->array);
	free(head);
}
