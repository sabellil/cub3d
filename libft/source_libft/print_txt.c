/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:45:54 by mairivie          #+#    #+#             */
/*   Updated: 2024/09/09 15:11:04 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		ft_print_string("(null)");
		return (6);
	}
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
