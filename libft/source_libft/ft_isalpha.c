/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:35:55 by mairivie          #+#    #+#             */
/*   Updated: 2023/12/15 10:48:08 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The isalpha() function tests for any character for which isupper(3) 
 * or islower(3) is true. 
 * The value of the argument must be resprensentable as an unsigned char 
 * or the value of EOF.
 *
 * RETURN VALUES: The isalpha function return zero if the character tests false
 * and returns non-zero if the character tests true. */

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	else
		return (0);
}
