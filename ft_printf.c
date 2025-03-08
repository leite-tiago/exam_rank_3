
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tborges- <tborges-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:12:58 by tborges-          #+#    #+#             */
/*   Updated: 2025/03/07 01:17:59 by tborges-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	print_str(char *str)
{
	int	count;

	if (!str)
		return (write(1, "(null)", 6));
	count = 0;
	while (str[count])
	{
		count += write(1, &str[count], 1);
	}
	return (count);
}

int	print_nbr(int nbr)
{
	int	count;

	count = 0;
	if (nbr == -2147483648)
	{
		count += write(1, "-2147483648", 11);
	}
	else if (nbr < 0)
	{
		nbr *= -1;
		count += write(1, "-", 1);
		count += print_nbr(nbr);
	}
	else if (nbr <= 9)
	{
		nbr += '0';
		count += write(1, &nbr, 1);
	}
	else
	{
		count += print_nbr(nbr / 10);
		count += print_nbr(nbr % 10);
	}
	return (count);
}

int	print_hex(unsigned int num)
{
	int		count;
	char	buffer[17];
	char	*hex_digits;
	int		i;

	hex_digits = "0123456789abcdef";
	count = 0;
	i = 0;
	if (num == 0)
		count += write(1, "0", 1);
	else
	{
		while (num != 0)
		{
			buffer[i++] = hex_digits[num % 16];
			num /= 16;
		}
		while (i > 0)
			count += write(1, &buffer[--i], 1);
	}
	return (count);
}

int	print_format(char specifier, va_list *ap)
{
	if (specifier == 's')
		return (print_str(va_arg(*ap, char *)));
	else if (specifier == 'd')
		return (print_nbr(va_arg(*ap, int)));
	else if (specifier == 'x')
		return (print_hex(va_arg(*ap, unsigned int)));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (!format)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_format(*++format, &ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}

// int main()
// {
// 	ft_printf("string: %s\nnumber: %d\nhex: %x\n", "banana", 123, 64);
// }

// cc -Wall -Wextra -Werror ft_printf.c
