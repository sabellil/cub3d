/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:37:16 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/06 16:02:29 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"


int	ft_is_empty_line(char *lines)
{
	(void)lines;
	return (SUCCESS);
}
int	ft_is_map_line(char *lines)
{
	(void)lines;
	return (SUCCESS);
}

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
	free_file_lines(file_lines);
	return (SUCCESS);
}
