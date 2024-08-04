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
case 'b':
print_unsignedint_to_binary(args, characters_printed);
break;
case 'u':
print_unsignedint(args, characters_printed);
break;
case 'o':
print_unsignedint_to_octal(args, characters_printed);
break;
case 'x':
print_unsignedint_to_hexadecimal(args, characters_printed, "0123456789abcdef");
break;
case 'X':
print_unsignedint_to_hexadecimal(args, characters_printed, "0123456789ABCDEF");
break;
default:
write(1, "%", 1);
(*characters_printed)++;
if (write(1, *fpointer, 1) == -1)
{
return;
}
(*characters_printed)++;
break;
}
}
