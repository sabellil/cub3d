/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:14:24 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 15:30:47 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The strdup() function allocates sufficient memory for a copy of the 
 * string s, does the copy, and returns a pointer to it. The pointer may 
 * subsequently be used as an argument to the function free(3).
 *
 * If insufficient memory is available, NULL is returned.*/

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		size_s;
	char	*new_str;

	i = 0;
	size_s = ft_strlen(s);
	new_str = malloc((size_s + 1) * sizeof(char));
	if (new_str == 0)
		return (0);
	while (i < size_s)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
