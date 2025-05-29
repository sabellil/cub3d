/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:29:32 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 14:27:43 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The memcmp() function compares byte string s1 against byte string s2.
 * Both strings are assumed to be n bytes long.
 *
 * RETURN VALUES: The memcmp() function returns zero if the two strings are 
 * identical, otherwise returns the difference betwee the first two differing 
 * bytes (treated as unsigned char values, so that '\200' is greater than '\0',
 *  for example).
 * Zero-length strings are always identical. This behaviour is not required by
 * C and portable code should only depend on the sign of the returned value.*/

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1_us;
	unsigned char	*s2_us;

	i = 0;
	s1_us = (unsigned char *)s1;
	s2_us = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (i < (n - 1) && (s1_us[i] == s2_us[i]))
		i++;
	if (s1_us[i] != s2_us[i])
		return (s1_us[i] - s2_us[i]);
	else
		return (0);
}
