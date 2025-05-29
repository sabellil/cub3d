/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:48:51 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 14:18:53 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The strncmp() function lexicographically compare the null-terminated 
 * strings s1 and s2.
 * The strncmp() function compares not more than n characters. Because strncmp()
 * is designed for comparing strings rather than binary data, characters that
 * appear after a '\0' character are not compared.
 *
 * RETURN VALUES: The strncmp() function returns an integer greater than, equal
 * to, or less than 0, according as the string s1 is greater than, equal to, 
 * or less than the string s2. The comparison is done using unsigned 
 * characters, so that '\200' is greater than '\0'.*/

#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && s1[i] == s2[i] && (s1[i] || s2[i]))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
