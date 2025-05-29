/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:09:51 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 16:18:49 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*DESC: The ft_putchar_fd() function writes the character c on the file 
 * descriptor fd.
 *
 * PARAMETERS
    c: character to write
    fd: file descriptor on which to write */

#include <unistd.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
