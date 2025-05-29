/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:33:52 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 15:59:45 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: Allocate (with malloc(3)) and return a new string from the string s.
 * This new string starts at index 'start' and has a maximum size of 'len'.
 *
 * PARAMETERS
 * 	s: string from which to extract the new string
 * 	start: start index of the new string in the string 's'
 * 	len: maximum size of the new string
 *
 * RETURN VALUES
 * ft_substr() returns the new string; NULL if the memory allocation failed.*/

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*new_str;
	unsigned int	size_s;

	if (s == NULL)
		return (NULL);
	size_s = ft_strlen(s);
	if (len > size_s)
		len = size_s;
	if (start > size_s)
		len = 0;
	if (len > size_s - start)
		len = (size_s - start);
	new_str = malloc((len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while ((start + i) < size_s && i < (len))
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
