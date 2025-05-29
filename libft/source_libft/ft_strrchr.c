/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:32:12 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 14:16:04 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The strrchr() function is identical to strchr(), except it locates 
 * the last occurence of c.
 *
 * RETURN VALUES: The function strrchr() returns a pointer to the located 
 * character, or NULL if the character does not appear in the string.*/

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	len;

	len = ft_strlen(s);
	while (s[len] != (char)c)
	{
		if (len == 0)
			return (NULL);
		len--;
	}
	return (&((char *)s)[len]);
}
