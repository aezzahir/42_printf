#include "ft_printf.h"

int print_format(char specifier, va_list ap)
{
    int	count;

	count = 0;
    if (specifier == 'c')
        count += print_char(va_arg(ap, int));
    else if (specifier == 's')
        count += print_str(va_arg(ap, char *));
	else if (specifier == 'p')
        count += print_pointer(va_arg(ap, void *));
    else if (specifier == 'd' || specifier == 'i') 
	{
        int n = va_arg(ap, int);
        count += print_in_base((unsigned long)n, "0123456789", n < 0);
    } 
	else if (specifier == 'u')
        count += print_in_base(va_arg(ap, unsigned int), "0123456789", 0);
    else if (specifier == 'x')
        count += print_in_base(va_arg(ap, unsigned int), "0123456789abcdef", 0);
    else if (specifier == 'X')
        count += print_in_base(va_arg(ap, unsigned int), "0123456789ABCDEF", 0);
    else if (specifier == '%')
        count += print_char('%');
    else
        count += write(1, &specifier, 1);
    return (count);
}

int ft_printf(const char *format, ...)
{
    va_list	ap;
    int	count;

	count = 0;
    va_start(ap, format);
	if (!format || !format[0] || !format[1])
		return (-1);
    while (*format != '\0') 
	{
        if (*format == '%')
            count += print_format(*(++format), ap);
        else
            count += write(1, format, 1);
        ++format;
	}
    va_end(ap);
    return (count);
}