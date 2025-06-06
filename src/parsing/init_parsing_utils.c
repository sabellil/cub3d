/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:26:02 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/06 16:16:56 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

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

char	**read_lines_from_file(int fd)
{
	char **lines;
	char *line;
	int i;

	lines = malloc(sizeof(char *) * (MAX_LINES + 1));
	if (!lines)
		return (NULL);
	i = 0;
	while (i < MAX_LINES)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		lines[i] = line;
		if (!lines[i])
		{
			free_file_lines_partial(lines, i);
			return (NULL);
		}
		i++;
	}
	lines[i] = NULL;
	return (lines);
}