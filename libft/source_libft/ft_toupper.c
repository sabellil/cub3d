/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:52:12 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 14:06:53 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The toupper() function converts a lower-case letter to the 
 * corresponding upper-case letter. The argument must be representable as an 
 * unsigned char or the value of EOF.
 *
 * RETURN VALUES: If the argument is a lower-case letter, the toupper() function
 * returns the corresponding upper-casse letter if there is one; otherwise, 
 * the argument is returned unchanged. */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - ('a' - 'A');
	return (c);
}
