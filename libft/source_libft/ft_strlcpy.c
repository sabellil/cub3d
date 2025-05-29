/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <marivie@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:48:47 by mairivie          #+#    #+#             */
/*   Updated: 2023/12/15 11:35:12 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The strlcpy() function copy strings with the same input parameters and
 * output result as snprintf(3). It is designed to be safer, more consistent, 
 * and less error prone replacement for the easily misused function strncpy(3)
 * 	strlcpy() take the full size of the destination buffer and guarantee 
 * NUL-termination if there is room. Note that room for the NUL should be 
 * included in dstsize. Also note that strlcpy() only operate on true ''C'' 
 * strings. This means that for strlcpy() src must be NUL-terminated.
 * 	strlcpy() copies up to dstsize - 1 characters from the string src to dst, 
 * NUL-terminating the result if dstsize is not 0.
 * If the src and dst strings overlap, the behavior is undefined.
 *
 * RETURN VALUES:
 * The strlcpy() function return the total length of the strings it tried to 
 * create. That means the length of src. 
 * If the return value is >= dstsize, the output string has been truncated.
 * It is the caller's responsibility to handle this.*/

#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
