#include "main.h"

/**
 * _puts - Outputs a string to the standard output followed by a newline.
 * @str: A pointer to the string to be displayed.
 */
void _puts(char *str)
{
while (*str != '\0')
{
_putchar(*str);
str++;
}
_putchar('\n');
}
