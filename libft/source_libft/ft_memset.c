/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <marivie@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:27:57 by mairivie          #+#    #+#             */
/*   Updated: 2023/12/15 11:02:52 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The memset() function writes len bytes of value c (converted to an 
 * unsigned char) to the string b.
 *
 * RETURN VALUES: The memset() function returns its first argument.*/

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*object;

	i = 0;
	object = s;
	while (i < n)
	{
		object[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
