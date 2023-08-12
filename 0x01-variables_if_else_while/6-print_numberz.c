#include <stdio.h>
/**
 * main - Entry point
 *
 * Description: Prints all single-digit numbers of base 10
 *              using the putchar function and no char variables.
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
int number;
for (number = 0; number <= 9; number++)
{
putchar(number + '0');
}
putchar('\n');
return (0);
}
