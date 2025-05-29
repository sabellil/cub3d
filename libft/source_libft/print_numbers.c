/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:38:42 by mairivie          #+#    #+#             */
/*   Updated: 2024/12/20 01:00:32 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_nbr(int nbr)
{
	int		i;
	int		sign;
	char	*base;

	i = 0;
	sign = 0;
	base = "0123456789";
	if (nbr == -2147483648)
		return (ft_print_string("-2147483648"), 11);
	if (nbr >= 0 && nbr <= 9)
		i += ft_print_char(base[nbr]);
	else if (nbr < 0)
	{
		i += ft_print_char('-');
		sign = -1;
		i += ft_print_nbr(sign * nbr);
	}
	else
	{
		i += ft_print_nbr(nbr / 10);
		i += ft_print_nbr(nbr % 10);
	}
	return (i);
}

int	ft_print_unsigned(unsigned int unbr)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789";
	if (unbr <= 9)
		i += ft_print_char(base[unbr]);
	else
	{
		i += ft_print_nbr(unbr / 10);
		i += ft_print_nbr(unbr % 10);
	}
	return (i);
}

int	ft_print_hexa(char c, unsigned int hexa)
{
	int		i;
	char	*base;

	i = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (hexa <= 15)
		i += ft_print_char(base[hexa]);
	else
	{
		i += ft_print_hexa(c, hexa / 16);
		i += ft_print_hexa(c, hexa % 16);
	}
	return (i);
}

int	ft_print_ptr_hex(unsigned long long ptr)
{
	int		i;
	char	*base;

	i = 0;
	base = "0123456789abcdef";
	if (ptr <= 15)
		i += ft_print_char(base[ptr]);
	else
	{
		i += ft_print_ptr_hex(ptr / 16);
		i += ft_print_ptr_hex(ptr % 16);
	}
	return (i);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	i;

	if (!ptr)
	{
		i = ft_print_string("(nil)");
		return (i);
	}
	i = ft_print_string("0x");
	i += ft_print_ptr_hex(ptr);
	return (i);
}
