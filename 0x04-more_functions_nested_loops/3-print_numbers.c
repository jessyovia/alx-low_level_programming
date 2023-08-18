#include "main.h"
/**
 * print_numbers - Prints the numbers from 0 to 9 followed by a new line.
 */
void print_numbers(void)
{
int i;
char numbers[] = "0123456789\n";
for (i = 0; i < 11; i++)
{
_putchar(numbers[i]);
}
}
