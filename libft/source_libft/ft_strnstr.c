/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:38:23 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 15:03:48 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The strnstr() function locates the first occurence of the 
 * null-terminated string little in the string big, where not more than 
 * len characters are searched.
 * Characters that appear after a '\0' character are not searched.
 *
 *
 * RETURN VALUES: If little is an empty string, big is returned; if little
 * occurs nowhere in big, NULL is returned; otherwise a pointer to the
 * first character of the first occurence of little is returned. */

#include <stddef.h>
#include "stdio.h"
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_bg;
	size_t	i_lt;

	if (little[0] == 0)
		return ((char *)big);
	i_bg = 0;
	while (i_bg < len && big[i_bg])
	{
		if (big[i_bg] == little[0])
		{
			i_lt = 0;
			while (big[i_bg + i_lt] == little[i_lt] && i_bg + i_lt < len)
			{
				i_lt++;
				if (little[i_lt] == '\0')
					return ((char *)big + i_bg);
			}
		}
		i_bg++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const char	big = "aaabcabcd";
	const char	little = "c";
	char		*result;

	result = ft_strnstr(big, little, -1);
	printf("The substring is: %s\n", result);
	return(0);
}*/
