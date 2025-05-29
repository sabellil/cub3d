/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:01:13 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 14:08:20 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The tolower() function converts an upper-case letter to the 
 * corresponding lower-case letter. The argument must be representable as an 
 * unsigned char or the value of EOF. 
 *
 * RETURN VALUES: If the argument is an upper-case letter, the tolower() 
 * function returns the corresponding lower-case letter if there is one; 
 * otherwise, the argument is returned unchanged. */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c - ('A' - 'a');
	return (c);
}
