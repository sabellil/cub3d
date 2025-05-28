/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:10:09 by sabellil          #+#    #+#             */
/*   Updated: 2025/05/28 17:29:51 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	ft_check_file_extension(const char *filename, const char *extension)
{
	int	len_file;
	int	len_extension;
	int	start;

	if (!filename || !extension)
		return (0);
	len_file = ft_strlen(filename);
	len_extension = ft_strlen(extension);
	if (len_file <= len_extension)
		return (0);
	start = len_file - len_extension;
	if (ft_strncmp(filename + start, extension, len_extension) == 0)
		return (1);
	return (0);
}

int	ft_init_and_parse(t_game_data *game, char *filename)
{
	char **file_lines;

	if (!ft_check_file_extension(filename, ".cub"))// verifier extension .cub dans tous les sens
		return (ERR_PARSE_FAIL);
	file_lines = ft_read_cub_file(filename);//TODO ouvrir et lire .cub dans double tableau
	if (!file_lines)
		return (ERR_PARSE_FAIL);
	if (parse_textures_and_colors(file_lines, game) != SUCCESS)// TODO extraire textures et couleurs (NO, SO, WE, EA, F, C)
	{
		free_file_lines(file_lines); // TODO
		return (ERR_PARSE_FAIL);
	}
	if (parse_map_and_player(file_lines, game) != SUCCESS)// TODO extraire map et initialiser joueur
	{
		free_file_lines(file_lines);
		return (ERR_PARSE_FAIL);
	}
	free_file_lines(file_lines); // plus besoin de file_lines apres parsing
	return (SUCCESS);
}