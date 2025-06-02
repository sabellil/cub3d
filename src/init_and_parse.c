/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:10:09 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/02 13:29:35 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

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
	char	*line;
	char	**lines;
	int		i;
	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = malloc(sizeof(char *) * (MAX_LINES + 1));
	if (!lines)
		return (NULL);
	i = 0;
	while (i < MAX_LINES)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		lines[i] = line;
		if (!lines[i])
		{
			free_file_lines_partial(lines, i);
			close(fd);
			return (NULL);
		}
		i++;
	}
	lines[i] = NULL;
	close(fd);
	printf("ft_read_cub_file va retourner lines\n");
	return (lines);
}


int	parse_textures_and_colors(char **file_lines, t_game_data *game)
{
	(void)file_lines;
	(void)game;
	return (SUCCESS);
}

int	parse_map_and_player(char **file_lines, t_game_data *game)
{
	(void)file_lines;
	(void)game;
	return (SUCCESS);
}

int	ft_init_and_parse(t_game_data *game, char *filename)
{
	char **file_lines;

	if (ft_check_file_extension(filename, ".cub") != SUCCESS)// verifier extension .cub
		return (ERR_PARSE_FAIL);
	printf("ft_check_file_extension OK\n");
	file_lines = ft_read_cub_file(filename);//TODO ouvrir et lire .cub dans double tableau
	if (!file_lines)
		return (ERR_PARSE_FAIL);
	printf("ft_read_cub_file OK\n");
	if (parse_textures_and_colors(file_lines, game) != SUCCESS)// TODO extraire textures et couleurs (NO, SO, WE, EA, F, C)
	{
		free_file_lines(file_lines); // TODO
		return (ERR_PARSE_FAIL);
	}
	printf("parse_textures_and_colors OK\n");
	if (parse_map_and_player(file_lines, game) != SUCCESS)// TODO extraire map et initialiser joueur
	{
		free_file_lines(file_lines);
		return (ERR_PARSE_FAIL);
	}
	printf("parse_map_and_player OK\n");
	free_file_lines(file_lines); // plus besoin de file_lines apres parsing
	return (SUCCESS);
}