/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:21:56 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 15:57:50 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: Apply the function 'f' to each characters in the string 's' to create 
 * a new string (with malloc) resulting of the successive applications of 'f'.
 *
 * PARAMETERS
    s: string over which to iterate
    f: function to apply to each character
	
 * RETURN VALUES: ft_strmapi() returns a new string resulting of the 
 * successive applications of 'f'; NULL if the memory allocations failed.*/

#include "libft.h"
#include "stdlib.h"
#include "stdio.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			len;
	char			*result;

	if (s == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	result = malloc(len + 1 * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[len] = '\0';
	return (result);
}
/*
char	ft_index(unsigned int i, char str)
{
	printf("My inner function: index = %d and %c\n", i, str);
	return (str - 32);
}

int	main(void)
{
	char	*str;
	char	*result;

	str = "AsDfGhJk12345jklMNB";
	printf("prompt %s \n", str);
	result = ft_strmapi(str, ft_index);
	printf("result %s \n", result);
	return (0);
}*/
