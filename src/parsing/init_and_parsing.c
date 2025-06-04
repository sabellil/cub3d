/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:10:09 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/04 18:21:42 by sabellil         ###   ########.fr       */
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
	char	**lines;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lines = read_lines_from_file(fd);
	close(fd);
	return (lines);
}
// Lire lignes avant MAP et extraire couleurs et textures

int	parse_textures_and_colors(char **lines, t_game_data *game)
{
	int i;
	int found;

	i = 0;
	found = 0;
	while (lines[i])
	{
		if (ft_is_empty_line(lines[i]) || ft_is_map_line(lines[i])) //TODO
		{
			i++;
			continue ;
		}
		if (ft_parse_texture_line(lines[i], game) == SUCCESS)
			found++;
		else if (ft_parse_color_line(lines[i], game) == SUCCESS)
			found++;
		else
			return (FAILURE);
		i++;
	}
	if (found < 6)
		return (FAILURE);
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
	char	**file_lines;

	if (ft_check_file_extension(filename, ".cub") != SUCCESS)// verifier extension .cub
		return (ERR_PARSE_FAIL);
	printf("ft_check_file_extension OK\n");
	file_lines = ft_read_cub_file(filename);
	if (!file_lines)
		return (ERR_PARSE_FAIL);
	print_file_lines(file_lines); //pour verifier que le tableau est bien rempli
	printf("ft_read_cub_file OK\n");
	if (parse_textures_and_colors(file_lines, game) != SUCCESS)// TODO EN COURS extraire textures et couleurs (NO, SO, WE, EA, F, C)
	{
		free_file_lines(file_lines);
		return (ERR_PARSE_FAIL);
	}
	printf("parse_textures_and_colors OK\n");
	if (parse_map_and_player(file_lines, game) != SUCCESS)// TODO extraire map et initialiser joueur
	{
		free_file_lines(file_lines);
		return (ERR_PARSE_FAIL);
	}
	printf("parse_map_and_player OK\n");
	free_file_lines(file_lines);
	return (SUCCESS);
}
//starting point, direction du regrd, dessin des murs sur la carte.