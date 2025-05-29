/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 18:52:59 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 14:20:20 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: the memchr() function locates the first occurence of c (convered to 
 * an unsigned char) in string s.
 * 
 * RETURN VALUES: The memchr() function returns a pointer to the byte located, 
 * or NULL if no such byte exists within n bytes.*/

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	c_uns_char;
	unsigned char	*s_uns_char;
	void			*match;

	i = 0;
	c_uns_char = c;
	s_uns_char = (unsigned char *)s;
	while (i < n)
	{
		if (s_uns_char[i] == c_uns_char)
		{
			match = &s_uns_char[i];
			return (match);
		}
		i++;
	}
	return (NULL);
}
