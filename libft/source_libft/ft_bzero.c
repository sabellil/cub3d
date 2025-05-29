/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <marivie@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:46:48 by mairivie          #+#    #+#             */
/*   Updated: 2023/12/15 11:14:18 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The bzero() function writes n zeroed bytes to the string s. 
 * If n is zero, bzero() does nothing. */

#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*object;

	i = 0;
	object = (char *) s;
	while (i < n)
	{
		object[i] = 0;
		i++;
	}
}
