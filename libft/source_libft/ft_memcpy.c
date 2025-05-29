/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <marivie@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:20:00 by mairivie          #+#    #+#             */
/*   Updated: 2023/12/15 11:16:32 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The memcpy() function copies n bytes from memory area src to memory 
 * area dst. If dst and src overlap, behavior is undefined. Applications in 
 * which dst and src might overlap should use memove(3) instead.
 *
 * RETURN VALUES: The memcpy() function returns the original value of dst */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*dest_copy;
	const char		*src_copy;

	if (dest == 0 && src == 0)
		return (NULL);
	i = 0;
	dest_copy = dest;
	src_copy = src;
	while (i < n)
	{
		dest_copy[i] = src_copy[i];
		i++;
	}
	return (dest);
}
