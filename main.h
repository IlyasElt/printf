#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
void print_char(va_list args, int *characters_printed);
void print_string(va_list args, int *characters_printed);
void print_percent(int *characters_printed);
void num_to_string(int num, char *str);
void print_int(va_list args, int *characters_printed);
void print_unsignedint_to_binary(va_list args, int *characters_printed);
void choose_specifier(const char **fpointer, va_list args,
int *characters_printed);

#endif /* MAIN_H */
