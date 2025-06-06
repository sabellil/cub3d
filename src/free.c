/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:16:22 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/06 16:16:26 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

void	free_file_lines_partial(char **lines, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	free_file_lines(char **file_lines)
{
	int	i;

	if (!file_lines)
		return ;
	i = 0;
	while (file_lines[i])
	{
		free(file_lines[i]);
		i++;
	}
	free(file_lines);
}
