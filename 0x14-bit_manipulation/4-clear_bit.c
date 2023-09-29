#include "main.h"
#include <stddef.h>
/**
* clear_bit - Clears a bit at a given index to 0.
* @n: The pointer to a number where the bit should be cleared..
* @index: The index of the bit to clear, starting from 0.
*
* Description: This function checks if the index is within the range of
* valid bits (0 to 63 on a typical 64-bit system).
*If the index is valid, it uses bitwise operations to clear (set to 0)
*
* Return: 1 if successful, -1 if an error occurs.
*/
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 32) /* Ensure index is within a valid range (0-32) */
		return (-1);

	*n &= ~(1UL << index); /* Clear the bit at the specified index */

	return (1);
}
