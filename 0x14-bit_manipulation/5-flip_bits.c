#include "main.h"

/**
* flip_bits - The number of bits that need to be flipped to get from n to m.
* @n: The first unsigned long number.
* @m: The second unsigned long number.
*
* Description: This function calculates the XOR (exclusive OR) of the two
* numbers, which results in a number with bits set to 1, two numbers differ.
*
* Return: The number of bits to flip..
*/
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned int count = 0;
	unsigned long int  xor_result = n ^ m;

	while (xor_result > 0)
	{
		count += xor_result & 1;
		xor_result >>= 1;
	}

	return (count);
}
