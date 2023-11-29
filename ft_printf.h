#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_strlen(const char *s);
int	print_char(int c);
int print_str(char *str);
int print_in_base(unsigned long n, char *base, int is_negative);
int print_pointer(void *p);
int print_format(char specifier, va_list ap);
int ft_printf(const char *format, ...);

#endif