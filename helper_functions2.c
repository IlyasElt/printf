#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_unsignedint_to_binary - converts an unsigned
 * int into binary and then prints it
 * @args: list of arguments
 * @characters_printed: number of characters printed
 */

void print_unsignedint_to_binary(va_list args, int *characters_printed)
{
char digit;
int i, j;
unsigned int num;
int binary_num[32];

num = va_arg(args, unsigned int);

if (num == 0)
{
write(1, "0", 1);
(*characters_printed)++;
return;
}

for (i = 0; num > 0; i++)
{
binary_num[i] = num % 2;
num /= 2;
}

for (j = i - 1; j >= 0; j--)
{
digit = binary_num[j] + '0';
write(1, &(digit), 1);
(*characters_printed)++;
}
}
