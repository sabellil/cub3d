/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:26:02 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/04 17:55:11 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	has_single_dot(const char *filename, int len_file)
{
	int	i;
	int	dot_count;

	i = 0;
	dot_count = 0;
	while (i < len_file)
	{
		if (filename[i] == '.')
			dot_count++;
		i++;
	}
	if (dot_count != 1)
		return (0);
	return (1);
}

int	ft_starts_with(const char *str, const char *prefix)
{
	int	i;

	if (!str || !prefix)
		return (0);
	i = 0;
	while (prefix[i])
	{
		if (str[i] != prefix[i])
			return (0);
		i++;
	}
	return (1);
}