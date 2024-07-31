#include "main.h"
#include <unistd.h>
#include <stdarg.h>

/**
 * choose_specifier - handles format specifiers
 * @fpointer: current position in the format string
 * @args: list of arguments
 * @characters_printed: number of characters printed
 */

void choose_specifier(const char **fpointer, va_list args,
int *characters_printed)
{
switch (**fpointer)
{
case 'c':
print_char(args, characters_printed);
break;
case 's':
print_string(args, characters_printed);
break;
case '%':
print_percent(characters_printed);
break;
case 'i':
case 'd':
print_int(args, characters_printed);
break;
default:
write(1, *fpointer, 1);
characters_printed++;
break;
}
}
