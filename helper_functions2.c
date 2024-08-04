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

/**
 * unsignedint_to_string - transforms an unsigned into into a string
 * @num: number to transform
 * @str: where the new string is stored
 */

void unsignedint_to_string(unsigned int num, char *str)
{
int i = 0, j;
char placeholder;

long number = num;

do {
str[i++] = (number % 10) + '0';
} while ((number /= 10) > 0);

str[i] = '\0';

for (j = 0, i--; j < i; j++, i--)
{
placeholder = str[j];
str[j] = str[i];
str[i] = placeholder;
}
}

/**
 * print_unsignedint - prints an unsigned int
 * @args: list of arguments
 * @characters_printed: number of characters printed
 */

void print_unsignedint(va_list args, int *characters_printed)
{
int i;
char str[20];
unsigned int num;

num = va_arg(args, unsigned int);

unsignedint_to_string(num, str);

for (i = 0; str[i] != '\0'; i++)
{
write(1, &(str[i]), 1);
(*characters_printed)++;
}
}

/**
 * print_unsignedint_to_octal - converts an unsigned
 * int into octal and then prints it
 * @args: list of arguments
 * @characters_printed: number of characters printed
 */

void print_unsignedint_to_octal(va_list args, int *characters_printed)
{
char digit;
int i, j;
unsigned int num;
int octal_num[32];

num = va_arg(args, unsigned int);

if (num == 0)
{
write(1, "0", 1);
(*characters_printed)++;
return;
}

for (i = 0; num > 0; i++)
{
octal_num[i] = num % 8;
num /= 8;
}

for (j = i - 1; j >= 0; j--)
{
digit = octal_num[j] + '0';
write(1, &(digit), 1);
(*characters_printed)++;
}
}

/**
 * print_unsignedint_to_hexadecimal - transform an into into
 * its hexademical format and then print it
 * @args: list of arguments
 * @characters_printed: number of characters printed
 * @hexaformat: format of hexadecimals to se (either MAJ or min)
 */

void print_unsignedint_to_hexadecimal(va_list args,
int *characters_printed, char *hexaformat)
{
int i, j;
unsigned int num;
char hexaNum[100];

num = va_arg(args, unsigned int);

if (num == 0)
{
write(1, "0", 1);
(*characters_printed)++;
return;
}
for (i = 0; num != 0; i++)
{
hexaNum[i] = hexaformat[num % 16];
num /= 16;
}

for (j = i - 1; j >= 0; j--)
{
write(1, &(hexaNum[j]), 1);
(*characters_printed)++;
}
}
