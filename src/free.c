/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:16:22 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/06 17:50:24 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

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
