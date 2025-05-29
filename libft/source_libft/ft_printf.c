/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 18:06:45 by mairivie          #+#    #+#             */
/*   Updated: 2024/09/09 15:10:18 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// printf (print formated) - format and print data.

// Minimalist printf reimplementation handling basic format specifiers: 
// %c, %p, %s, %d, %i, %u, %x, %X. Format string must be the first argument, 
// followed by variable arguments.

// Format specifiers
// % 	% followed by another % character writes % to the screen.
// c 	writes a single character.
// s 	writes a character string.
// p 	writes an implementation-defined character sequence defining a 
//		pointer address.
// d or i 	writes a signed integer to decimal representation.
// u 	writes an unsigned integer to decimal representation.
// x or X 	writes an unsigned int to hexadecimal representation (min or MAJ).

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

int	ft_print_type(char a, va_list args)
{
	int	length;

	length = 0;
	if (a == 'c')
		length = ft_print_char(va_arg (args, int));
	else if (a == 's')
		length = ft_print_string(va_arg (args, char *));
	else if (a == 'p')
		length = ft_print_ptr(va_arg (args, unsigned long long));
	else if (a == 'd' || a == 'i')
		length = ft_print_nbr(va_arg (args, int));
	else if (a == 'u')
		length = ft_print_unsigned(va_arg (args, unsigned int));
	else if (a == 'x' || a == 'X')
		length = ft_print_hexa(a, va_arg (args, unsigned int));
	else if (a == '%')
		length = ft_print_char('%');
	return (length);
}

int	ft_printf(const char *format, ...)
{
	va_list	list_args;
	int		i;
	int		length_printed;

	if (!format)
		return (-1);
	i = 0;
	length_printed = 0;
	va_start(list_args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			length_printed += ft_print_type(format[i + 1], list_args);
			i = i + 2;
		}
		else
		{
			length_printed += ft_print_char(format[i]);
			i++;
		}
	}	
	va_end(list_args);
	return (length_printed);
}

// int	main(void)
// {
// 	int	original;
// 	int	copy;
// 	int *ptr;

// 	ptr = &copy;
// 	original = printf(0);
// 	printf("%d characters were written\n", original);
// 	copy = ft_printf(0);
// 	ft_printf("%d characters were written\n", copy);
// 	return (0);
// }