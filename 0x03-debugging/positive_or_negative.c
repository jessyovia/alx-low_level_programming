#include "main.h"
/**
 * positive_or_negative - tests function that prints if integer
 * is positive or negative
 * @i: positive or negative
 */
void positive_or_negative(int i)
{
if (i > 0)
{
printf("%d is positive", i);
}
else if (i == 0)
{
printf("%d is 0", i);
}
else
{
printf("%d is negative", i);
}
}
