/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:24:03 by mairive           #+#    #+#             */
/*   Updated: 2024/10/15 16:50:37 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* DESC: The atoi() function converts the initial portion of the string pointed
 * to by str to int representation. 
 * the string may begin with an arbitrary number of whitespaces as determinded
 *  by isspace(3).
 * After the whitespaces, there can be one single optional '+' or '-' sign.
 * The remainder of the string will be converted to an int,stopping at the 
 * first char wich is not a valid digit.
 *
 * RETURN VALUES: The int representation of the string.*/
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	if (str == NULL || *str == '\0')
		return (0);
	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (sign * number);
}
