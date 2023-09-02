#include "main.h"

/**
 * _strcat - Concatenates two strings.
 * @dest: The destination string.
 * @src: The source string.
 *
 * Return: A pointer to the resulting string @dest.
 */

char *_strcat(char *dest, char *src)
{
int dest_len = 0;
int src_len = 0;
int i, j;

while (dest[dest_len] != '\0')
dest_len++;

while (src[src_len] != '\0')
src_len++;

for (i = dest_len, j = 0; j <= src_len; i++, j++)
dest[i] = src[j];

return (dest);
}
