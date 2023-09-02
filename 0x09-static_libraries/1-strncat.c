#include "main.h"

/**
 * _strncat - Concatenates two strings, using at most n bytes from src.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes from src to be concatenated.
 *
 * Return: A pointer to the resulting string @dest.
 */

char *_strncat(char *dest, char *src, int n)
{
int dest_len = 0;
int i, j;

/* Calculate length of dest */
while (dest[dest_len] != '\0')
dest_len++;

/* Concatenate at most n bytes from src */
for (i = dest_len, j = 0; j < n && src[j] != '\0'; i++, j++)
dest[i] = src[j];

/* Null-terminate the concatenated string */
dest[i] = '\0';

return (dest);
}
