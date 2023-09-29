#include "main.h"

/**
* get_bit - Gets the value of a bit at a given index.
* @n: The number the bit is extracted from.
* @index: The index of the bit to retrieve, starting from 0.
*
* Description: This function checks if the index is within the range
* of valid bits (0 to 63 on a typical 64-bit system)
* If the index is valid, it uses bitwise operations
*
* Return: The value of the bit at the given index, or -1 if an error occur.
*/
int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
	return (-1);

	return ((n >> index) & 1);
}
