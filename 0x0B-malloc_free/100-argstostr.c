#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
* argstostr - concatenates all the arguments of the program.
* @ac: The number of arguments.
* @av: An array of pointers to the arguments.
*
* Return: A pointer to the new concatenated string.
*         NULL if ac == 0 or av == NULL or if malloc fails.
*/
char *argstostr(int ac, char **av)
{
char *str;
int i, j, k, len = 0;

if (ac == 0 || av == NULL)
return (NULL);

for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
len++;
len++; /* add space for newline character */
}
len++; /* add space for null terminator */

str = malloc(sizeof(char) * len);

if (str == NULL)
return (NULL);

k = 0;
for (i = 0; i < ac; i++)
{
for (j = 0; av[i][j]; j++)
{
str[k] = av[i][j];
k++;
}
str[k] = '\n'; /* add newline character */
k++;
}
str[k] = '\0'; /* add null terminator */

return (str);
}
