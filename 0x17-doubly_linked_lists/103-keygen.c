#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
 * main - Generates a key based on input string
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	char entry[7], *u;
	int len = strlen(argv[1]), k, v;

	u = "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZeF3Qa1rPhdKIouk";

	v = (len ^ 59) & 63;
	entry[0] = u[v];

	v = 0;
	for (k = 0; k < len; k++)
		v += argv[1][k];
	entry[1] = u[(v ^ 79) & 63];

	v = 1;
	for (k = 0; k < len; k++)
		v *= argv[1][k];
	entry[2] = u[(v ^ 85) & 63];

	v = 0;
	for (k = 0; k < len; k++)
	{
		if (argv[1][k] > v)
			v = argv[1][k];
	}
	srand(v ^ 14);
	entry[3] = u[rand() & 63];

	v = 0;
	for (k = 0; k < len; k++)
		v += (argv[1][k] * argv[1][k]);
	entry[4] = u[(v ^ 239) & 63];

	for (k = 0; k < argv[1][0]; k++)
		v = rand();
	entry[5] = u[(v ^ 229) & 63];

	entry[6] = '\0';
	printf("%s", entry);
	return (0);
}
