#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int ft_strlen(const char *s)
{
        int  i;

        i = 0;
        while (s[i] != '\0')
                i++;
        return (i);
}

int	print_char(int	c)
{
	return (write(1, &c, 1));
}
int	print_str(char *str)
{
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		print_char(str[count]);
		++count;
	}
	return (count);
}
int print_in_base(long n, char *base)
{
	int count;
	long	len;

	len = (long)ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", 1);
		return (print_in_base(-n, base), + 1);
	}
	else if(n < len)
		return (print_char(base[n]));
	else
	{
		count = print_in_base(n / len, base);
		return (count + print_in_base(n % len, base));
	}
}

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += print_char((va_arg(ap, int)));
	else if (specifier == 's')
		count += print_str((va_arg(ap, char *)));
	else if (specifier == 'd')
		count += print_in_base((va_arg(ap, int)), "0123456789");
	else if (specifier == 'u')
		count += print_in_base((unsigned int)(va_arg(ap, int)), "0123456789");
	else if (specifier == 'x')
		count += print_in_base((va_arg(ap, unsigned int)), "0123456789abcdef");
	else if (specifier == 'X')
		count += print_in_base((va_arg(ap, unsigned int)), "0123456789ABCDEF");
	else
		count += write(1, &specifier, 1);
	return (count);
}


int ft_printf(const char *format, ...)
{
	va_list ap;
	int	count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += print_format(*(++format), ap);
		else
			write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

int main()
{
	int	count;

	count = ft_printf("Hello %s\n", "Ayoub");
	ft_printf(" %u\n", -42);
	printf(" %u\n", -42);
	ft_printf("Hello %x\n", 42);
	printf("Hello %x\n", 42);
	ft_printf("Hello %X\n", -42);
	printf("Hello %X\n", -42);
	ft_printf("Hello %X\n", -42);
	printf("Hello %X\n", -42);
	ft_printf("Hello %i\n", -42);
	printf("Hello %i\n", -42);
	return (0);
}
