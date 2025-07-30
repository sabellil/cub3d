/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:10:09 by sabellil          #+#    #+#             */
/*   Updated: 2025/07/30 12:19:24 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	ft_check_file_extension(const char *filename, const char *extension)
{
	int	len_file;
	int	len_ext;
	int	start;

	if (!filename || !extension)
		return (FAILURE);
	len_file = ft_strlen(filename);
	len_ext = ft_strlen(extension);
	if (len_file <= len_ext)
		return (FAILURE);
	start = len_file - len_ext;
	if (ft_strncmp(filename + start, extension, len_ext) != 0)
		return (FAILURE);
	if (!has_single_dot(filename, len_file))
		return (FAILURE);
	return (SUCCESS);
}

char	**ft_read_cub_file(const char *filename)
{
	int		fd;
	char	**lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = read_lines_from_file(fd);
	close(fd);
	return (lines);
}

int	ft_first_parsing(char *filename, char ***file_lines_out)
{
	char	**file_lines;

	if (ft_check_file_extension(filename, ".cub") != SUCCESS)
		return (ERR_PARSE_FAIL);
	file_lines = ft_read_cub_file(filename);
	if (!file_lines)
		return (ERR_PARSE_FAIL);
	*file_lines_out = file_lines;
	return (SUCCESS);
}

void	init_game_data(t_game_data *game)
{
	game->floor_color = -1;
	game->ceiling_color = -1;
}
