#include <stdio.h>
#include <math.h>
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
unsigned long int num = 612852475143;
unsigned long int i;
while (num % 2 == 0)
{
num /= 2;
}
for (i = 3; i <= sqrt(num); i += 2)
{
while (num % i == 0)
{
num /= i;
}
}
if (num > 2)
{
printf("%lu\n", num);
}
else
{
printf("Prime factor not found.\n");
}
return (0);
}
