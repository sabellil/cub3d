/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <marivie@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:41:35 by mairivie          #+#    #+#             */
/*   Updated: 2023/12/15 10:50:38 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The isdigit() function tests for a decimal digit character. 
 * The value of the argument must be representable as an unsigned char 
 * or the value of EOF.
 *
 * RETURN VALUES: The isdigit function return zero if the character tests false
 * and return non-zero if the character tests true. */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
