/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <marivie@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:42:30 by mairivie          #+#    #+#             */
/*   Updated: 2023/12/15 11:00:09 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The strlen() function computes the length of the string s.
 *
 * RETURN VALUES: The strlen() function returns the number of characters that 
 * precede the terminating NUL character.*/

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length] != '\0')
		length++;
	return (length);
}
