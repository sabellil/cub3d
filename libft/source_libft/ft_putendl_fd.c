/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:48:26 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 16:21:31 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: ft_putendl_fd() writes the string s, followed by a newline, on the 
 * file descriptor fd
 *
 * PARAMETERS
    s: string to write
    fd: the file descriptor on which to write */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
