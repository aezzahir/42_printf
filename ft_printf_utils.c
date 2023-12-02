/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aezzahir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 11:40:17 by aezzahir          #+#    #+#             */
/*   Updated: 2023/12/02 11:46:38 by aezzahir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[count] != '\0')
	{
		print_char(str[count]);
		++count;
	}
	return (count);
}

int	print_in_base(unsigned long n, char *base, int is_negative)
{
	int				count;
	unsigned long	len;

	len = (unsigned long)ft_strlen(base);
	count = 0;
	if (is_negative)
	{
		write(1, "-", 1);
		return (1 + print_in_base(-n, base, 0));
	}
	if (n < len)
		return (count + print_char(base[n]));
	else
	{
		count += print_in_base(n / len, base, 0);
		return (count + print_char(base[n % len]));
	}
}

int	print_pointer(void *p)
{
	unsigned long	ptr;

	ptr = (unsigned long)p;
	write(1, "0x", 2);
	return (2 + print_in_base(ptr, "0123456789abcdef", 0));
}
