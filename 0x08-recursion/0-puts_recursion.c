#include <stdio.h>
/**
 * _puts_recursion - function that fills memory with a constant byte
 *@s: first value
 *
 */
void _puts_recursion(char *s)
{

	if (s[0] == '\0')
		putchar('\n');
	else
	{
		putchar(s[0]);
		s++;
		_puts_recursion(s);
	}
}
