#include <stdio.h>

/**
 * _memset - Fills memory with a specified byte value.
 * @s: A pointer to the memory area to be filled.
 * @b: The byte value to fill the memory with.
 * @n: The number of bytes to be filled.
 *
 * Return: A pointer to the memory area @s.
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
{
s[i] = b;
}
return (s);
}
