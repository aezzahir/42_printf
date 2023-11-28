#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	print_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
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















int	main(void)
{
	int	count;

	count = ft_printf("Hello, %s\n", "John");
	ft_printf("The chars written are %d\n", count);

	return (0);
}
