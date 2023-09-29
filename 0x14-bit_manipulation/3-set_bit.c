#include "main.h"

/**
* set_bit - Sets the value of a bit to 1 at a given index.
* @n: A pointer to the number to modify.
* @index: The index of the bit to the set to retrieve, starting from 0.
*
* Description: This function checks if the index is within the range of
* of valid bits (0 to 63 on a typical 64-bit system).
*
* Return: The value of the bit at the given index or -1 if an error occurs.
*/
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index > 32) /* Ensure index is within a valid range (0-32) */
		return (-1);

	*n |= (1 << index); /* Set the bit at the specified index to 1 */

	return (1);
}
