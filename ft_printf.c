/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:39:52 by aezzahir          #+#    #+#             */
/*   Updated: 2023/12/02 11:42:17 by aezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_format(char specifier, va_list ap)
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
		count += print_in_base((unsigned long)(va_arg(ap, int)),
				"0123456789", (va_arg(ap, int)) < 0);
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

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	count = 0;
	va_start(ap, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*(++format) == '\0')
			{
				va_end(ap);
				return (count);
			}
			count += print_format(*format, ap);
		}
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
