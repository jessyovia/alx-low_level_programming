#include "main.h"

/**
* get_endianness - Determines the endianness of the system.
*
* Description: This function works by storing the value 1 in an
* unsigned integer variable num. Then, it interprets the
* memory location of num as a character pointer endian_check.
*
* Return:0 if big endian, 1 if little endian.
*/
int get_endianness(void)
{
	unsigned int temp = 1;
	char *endian_num = (char *)&temp;

	if (*endian_num == 1) /* Check the value at the lowest memory address */
		return (1); /* Little-endian */
	else
		return (0); /* Big-endian */
}
