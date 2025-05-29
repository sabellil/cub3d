/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <marivie@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:57:22 by mairivie          #+#    #+#             */
/*   Updated: 2023/12/15 10:53:17 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The isalnum() function tests for any character for which isalpha(3) or
 * isdigit(3) is true. 
 * The value of the argument must be representable as an unsigned char 
 * or the value of EOF.
 *
 * RETURN VALUES: The isalnum() function returns zero if the character tests 
 * false and returns non-zero if the character tests true. */

int	ft_isalnum(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}
