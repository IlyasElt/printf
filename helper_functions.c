#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * print_char - prints a character
 * @args: list of arguments
 * @characters_printed: pointer to the character count
 */
void print_char(va_list args, int *characters_printed)
{
char c;

c = va_arg(args, int);
write(1, &c, 1);
(*characters_printed)++;
}

/**
 * print_string - prints a string
 * @args: list of arguments
 * @characters_printed: pointer to the character count
 */
void print_string(va_list args, int *characters_printed)
{
int i;
char *str;

str = va_arg(args, char *);
if (str == NULL)
{
str = "(null)";
}

for (i = 0; str[i] != '\0'; i++)
{
write(1, &(str[i]), 1);
(*characters_printed)++;
}
}

/**
 * print_percent - prints a percent sign
 * @characters_printed: pointer to the character count
 */
void print_percent(int *characters_printed)
{
char percent = '%';

write(1, &percent, 1);
(*characters_printed)++;
}

/**
 * num_to_string - transforms an int to a string
 * @num: number to transform
 * @str: the new string
 */
void num_to_string(int num, char *str)
{
int i = 0, j, sign;
char placeholder;

long number = num;

sign = number;

if (sign < 0)
{
number = -number;
}

do {
str[i++] = (number % 10) + '0';
} while ((number /= 10) > 0);

if (sign < 0)
{
str[i++] = '-';
}

str[i] = '\0';

for (j = 0, i--; j < i; j++, i--)
{
placeholder = str[j];
str[j] = str[i];
str[i] = placeholder;
}
}

/**
 * print_int - prints an int
 * @args: list of arguments
 * @characters_printed: pointer to the number of characters printed
 */
void print_int(va_list args, int *characters_printed)
{
char str[20];
int i, number;

number = va_arg(args, int);

num_to_string(number, str);

for (i = 0; str[i] != '\0'; i++)
{
write(1, &(str[i]), 1);
(*characters_printed)++;
}
}
