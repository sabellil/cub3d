/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:37:16 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/12 12:52:59 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void ft_strip_newline(char *s)
{
    size_t len = ft_strlen(s);
    if (len > 0 && s[len - 1] == '\n')
        s[len - 1] = '\0';
}

int	parse_textures_and_colors(char **lines, t_game_data *game)
{
	int	i;
	int	found;

	i = 0;
	found = 0;
	while (lines[i] && found < 6)
	{
		ft_strip_newline(lines[i]);
		if (ft_is_empty_line(lines[i]) || ft_is_map_line(lines[i]))
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
	if (extract_map(file_lines, &game->map) != SUCCESS)
	{
		printf("1\n");
		return (ERR_PARSE_FAIL);
	}
	if (scan_map(game->map, game) != SUCCESS)
	{
		printf("2\n");
		return (ERR_PARSE_FAIL);
	}
	if (!is_map_closed(game->map))
	{
		printf("3\n");
		return (ERR_PARSE_FAIL);
	}
	return (SUCCESS);
}

int	get_map_width(char **map)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (map[i])
	{
		int	len = ft_strlen(map[i]);
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}

int	get_map_height(char **map)
{
	int	i = 0;

	while (map[i])
		i++;
	return (i);
}

int	ft_second_parsing_and_init(char **file_lines, t_game_data *game)
{
	if (parse_textures_and_colors(file_lines, game) != SUCCESS)
	{
		free_file_lines(file_lines);
		return (ERR_PARSE_FAIL);
	}
	if (parse_map_and_player(file_lines, game) != SUCCESS)
	{
		free_file_lines(file_lines);
		return (ERR_PARSE_FAIL);
	}
	game->map_width = get_map_width(game->map);//parcourir la map extraite en largeur pour dessiner la grille
	game->map_height = get_map_height(game->map);//en hauteur
	free_file_lines(file_lines);
	return (SUCCESS);
}
