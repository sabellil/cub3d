/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:29:20 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 14:11:34 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The strchr() function locates the first occurence of c (converted to 
 * a char) in the string pointed to by s. The terminating null character is 
 * considered to be part of the string; therefor if c is '\0', the function 
 * locate the terminating '\0'.
 *
 * RETURN VALUES:The function strchr() return a pointer to the located 
 * character, or NULL if the character does not appear in the string.*/

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return (&((char *)s)[i]);
}
