/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <marivie@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:20:00 by mairivie          #+#    #+#             */
/*   Updated: 2023/12/15 11:18:04 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The memmove() function copies len bytes from string src to string dst.
 * The two strings may overlap; the copy is always done in a 
 * non-destructive manner.
 *
 * RETURN VALUES: The memmove() function returns the original value of dst.*/

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_copy;
	char		*src_copy;

	if (dest == 0 && src == 0)
		return (NULL);
	i = 0;
	dest_copy = (char *)dest;
	src_copy = (char *)src;
	if (dest_copy > src_copy)
	{
		while (n-- > 0)
			dest_copy[n] = src_copy[n];
	}
	else
	{
		while (i < n)
		{
			dest_copy[i] = src_copy[i];
			i++;
		}
	}
	return (dest);
}
