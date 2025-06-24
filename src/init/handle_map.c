/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:17:52 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/24 15:37:13 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	copy_map(char **file_lines, char ***out_map, int start, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		(*out_map)[i] = ft_strdup(file_lines[start + i]);
		if (!(*out_map)[i])
		{
			while (--i >= 0)
				free((*out_map)[i]);
			free(*out_map);
			return (FAILURE);
		}
		ft_strip_newline((*out_map)[i]);
		i++;
	}
	(*out_map)[len] = NULL;
	return (SUCCESS);
}

int	extract_map(char **file_lines, char ***out_map)
{
	int	start;
	int	end;
	int	len;

	start = 0;
	while (file_lines[start] && !ft_is_map_line(file_lines[start]))
		start++;
	if (!file_lines[start])
		return (FAILURE);
	end = start;
	while (file_lines[end] && ft_is_map_line(file_lines[end]))
		end++;
	len = end - start;
	*out_map = (char **)malloc(sizeof(char *) * (len + 1));
	if (!*out_map)
		return (FAILURE);
	return (copy_map(file_lines, out_map, start, len));
}

int	scan_map(char **map, t_game_data *game)
{
	int		y;
	int		x;
	char	c;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			c = map[y][x];
			if (is_valid_player_char(c))
			{
				if (count_and_set_player(game, y, x, c) != SUCCESS)
					return (ERR_PARSE_FAIL);
			}
			else if (c != '0' && c != '1' && c != ' ')
				return (ERR_PARSE_FAIL);
			x++;
		}
		y++;
	}
	if (!game->player_found)
		return (ERR_PARSE_FAIL);
	return (SUCCESS);
}
