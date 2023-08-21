#include "main.h"

/**
 * rev_string - Reverses a string.
 * @s: The string to be reversed.
 */

void rev_string(char *s)
{
int len = 0, start, end;
char temp;

while (s[len] != '\0')
len++;

end = len - 1;

for (start = 0; start < len / 2; start++)
{
temp = s[start];
s[start] = s[end];
s[end] = temp;
end--;
}
}
