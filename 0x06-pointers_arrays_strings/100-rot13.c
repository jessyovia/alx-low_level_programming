#include "main.h"

/**
 * rot13 - Encodes a string using rot13.
 * @str: The input string.
 *
 * Return: A pointer to the modified string.
 */

char *rot13(char *str)
{
char *alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char *rot13_alphabet = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
int i, j;

i = 0;
while (str[i] != '\0')
{
j = 0;
while (alphabet[j] != '\0')
{
if (str[i] == alphabet[j])
{
str[i] = rot13_alphabet[j];
break; /* Break the inner loop once a replacement is made */
}
j++;
}
i++;
}

return (str);
}
