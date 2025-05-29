/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:20:37 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 16:20:17 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: Write the string s on the file descriptor fd.
 *
 * PARAMETERS
    s: string to write
    fd: file descriptor on which to write */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}
