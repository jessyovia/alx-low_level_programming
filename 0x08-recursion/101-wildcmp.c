#include "main.h"

/**
 * wildcmp - Compares two strings and checks for wildcard match
 * @s1: The first string
 * @s2: The second string with wildcard support
 *
 * Return: 1 if strings match, 0 otherwise
 */
int wildcmp(char *s1, char *s2)
{
if (*s2 == '*')
{
if (*(s2 + 1) == '\0')
return (1);
if (*(s2 + 1) == '*')
return (wildcmp(s1, s2 + 1));
if (*s1 == '\0')
return (wildcmp(s1, s2 + 1));
return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
}

if (*s1 == *s2)
{
if (*s1 == '\0')
return (1);
return (wildcmp(s1 + 1, s2 + 1));
}

return (0);
}
