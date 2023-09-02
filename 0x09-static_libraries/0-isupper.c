#include "main.h"

/**
 * _isupper - Determines if a character is in uppercase.
 * @c: The character to be evaluated.
 *
 * Return: 1 if c is an uppercase letter, 0 otherwise.
 */
int _isupper(int c)
{
if (c >= 'A' && c <= 'Z')
return (1);
else
return (0);
}
