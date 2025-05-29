/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <marivie@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 18:43:55 by mairivie          #+#    #+#             */
/*   Updated: 2023/12/15 10:58:01 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The isprint function tests for any printing char, including space
 * The value of the argument must representable as an unsigned char 
 * or the value of EOF.
 *
 * RETURN VALUES: The isprint function returns zero if the char tests false
 * and returns non-zero if the character tests true. */

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}
