/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:37:16 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/09 15:58:10 by sabellil         ###   ########.fr       */
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
		printf("DEBUG: line[%d] = '%s'\n", i, lines[i]);

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
	printf("Super retour ft second parisng and init\n");
	return (SUCCESS);
}

int	parse_map_and_player(char **file_lines, t_game_data *game)
{
	if (extract_map(file_lines, &game->map) != SUCCESS)
	{
		printf("Ca merdouille dnas extract map\n");
		return (ft_handle_error(ERR_PARSE_FAIL));
	}
	if (scan_map(game->map, game) != SUCCESS)
	{
		printf("Ca merdouille dnas scan map\n");
		return (ft_handle_error(ERR_PARSE_FAIL));
	}
	if (!is_map_closed(game->map))
	{
	printf("Ca merdouille dnas is map closed\n");
	return (ft_handle_error(ERR_PARSE_FAIL));

	}
	return (SUCCESS);
}

int	ft_second_parsing_and_init(char **file_lines, t_game_data *game)
{
	if (parse_textures_and_colors(file_lines, game) != SUCCESS)
	{
		printf("Ya une erreur dans parse etxtures and oclors\n");
		free_file_lines(file_lines);
		return (ft_handle_error(ERR_PARSE_FAIL));
	}
	if (parse_map_and_player(file_lines, game) != SUCCESS)
	{
		printf("Ya une erreur dans parse map and player\n");
		free_file_lines(file_lines);
		return (ft_handle_error(ERR_PARSE_FAIL));
	}
	free_file_lines(file_lines);
	return (SUCCESS);
}
