/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:46:53 by mairive           #+#    #+#             */
/*   Updated: 2024/05/09 11:47:23 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: Allocate (with malloc(3)) and returns a string representing n.
 * 	Negative numbers must be handled.
 *
 * PARAMETERS
    n: int to convert
 *
 * RETURN VALUES: ft_itoa() returns the string representing n; 
 * 	NULL if the memory allocation failed.*/

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

static int	ft_size_mem(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}	

char	*ft_itoa(int n)
{
	char		*result;
	int			len;
	long		temp;
	int			sign;

	temp = n;
	sign = 0;
	len = (ft_size_mem(temp));
	result = malloc(len + 1 * sizeof(char));
	if (result == NULL)
		return (NULL);
	if (n < 0)
	{
		result[0] = '-';
		temp = -temp;
		sign = 1;
	}
	result[len] = '\0';
	len--;
	while (len >= sign)
	{
		result[len--] = temp % 10 + '0';
		temp = temp / 10;
	}
	return (result);
}

// int	main(void)
// {
// 	long	n;

// 	n = +0+0+0+0+0;
// 	printf("prompt %li result %s \n", n, ft_itoa(n));
// 	return (0);
// }
