#include "main.h"

/**
* print_binary - Prints the binary representation of a decimal number.
* @n: The number which is to be printed in binary.
*
* Description:This function uses bitwise operations to extract each bit of the number n, prints most significant bit to least significant bit.
* The _putchar function is assumed to be available to print each bit as a character.
*/
void print_binary(unsigned long int n)
{
	if (n > 1)
	print_binary(n >> 1);

	_putchar((n & 1) + '0');
}
