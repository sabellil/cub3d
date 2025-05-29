/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 15:52:14 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 15:48:31 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: Allocate (with malloc(3)) and returns a copy of s1, without the 
 * characters specified in set at the beginning and the end of s1.
 *
 * PARAMETERS
 *   s1: string to trim
 *   set: characters to trim
 *
 * RETURN VALUES ft_strtrim() returns a trimmed copy of s1; NULL if the 
 * memory allocation failed.*/

#include "stdlib.h"
#include "libft.h"

static int	ft_check_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*new_s;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_check_set(s1[start], set) == 1)
		start++;
	end = ft_strlen (s1);
	while (end > start && ft_check_set(s1[end - 1], set) == 1)
		end--;
	new_s = malloc (((end - start) + 1) * sizeof(char));
	if (new_s == 0)
		return (0);
	i = 0;
	while (end > (start + i))
	{
		new_s[i] = s1[start + i];
		i++;
	}
	new_s[i] = '\0';
	return (new_s);
}
