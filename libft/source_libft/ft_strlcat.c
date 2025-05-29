/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <marivie@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:32:17 by mairivie          #+#    #+#             */
/*   Updated: 2023/12/15 13:52:21 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: strlcat function concatenate strings. It is designed to be safer, more 
 * consistent, and less error prone replacements for the easily misused 
 * function strncat(3).
 * 		strlcat() take the full size of the destination buffer and guarantee 
 * NUL-termination if there is room. Note that room for the NUL should be 
 * included in dstsize. Also note that strlcat() only operate on true ''C'' 
 * strings. This means that both src and dst must be NUL-terminated.
 * 		strlcat() appends string src to the end of dst. It will append at most 
 * dstsize - strlen(dst) - 1 characters. It will then NUL-terminate, unless 
 * dstsize is 0 or the original dst string was longer than dstsize (in practice
 * this should not happen as it means that either dstsize is incorrect or 
 * that dst is not a proper string).
 * 	If the src and dst strings overlap, the behavior is undefinded.
 *
 * RETURN VALUES: Like snprintf(3), strlcat() function return the total length
 * of the string it tried to create. That means the initial length of dst plus
 * the length of src.
 * If the return value is >= dstsize, the output string has been truncated.
 * It is the caller's responsibility to handle this.*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dst_len;
	size_t		total_len;
	const char	*s;

	if (size == 0)
		return (ft_strlen(src));
	s = src;
	dst_len = 0;
	while (*(dst + dst_len) && dst_len < size)
		dst_len++;
	if (dst_len < size)
		total_len = dst_len + ft_strlen(s);
	else
		return (size + ft_strlen(s));
	while (*s && (dst_len + 1) < size)
	{
		*(dst + dst_len) = *s++;
		dst_len++;
	}
	*(dst + dst_len) = '\0';
	return (total_len);
}
