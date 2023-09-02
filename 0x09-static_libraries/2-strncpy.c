#include "main.h"

/**
 * _strncpy - Copies at most n bytes from source string to destination string.
 * @dest: The destination string.
 * @src: The source string.
 * @n: The maximum number of bytes to be copied.
 *
 * Return: A pointer to the resulting string @dest.
 */

char *_strncpy(char *dest, char *src, int n)
{
int i;

for (i = 0; i < n && src[i] != '\0'; i++)
dest[i] = src[i];

/* If the source string is shorter thans */
while (i < n)
{
dest[i] = '\0';
i++;
}

return (dest);
}
