/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 11:17:52 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/10 16:37:35 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	is_inside(char **map, int y, int x)
{
	return (y >= 0 && x >= 0 && map[y] && x < (int)ft_strlen(map[y]));
}

static int	is_surrounded(char **map, int y, int x)
{
	if (!is_inside(map, y - 1, x) || map[y - 1][x] == ' ')
		return (0);
	if (!is_inside(map, y + 1, x) || map[y + 1][x] == ' ')
		return (0);
	if (!is_inside(map, y, x - 1) || map[y][x - 1] == ' ')
		return (0);
	if (!is_inside(map, y, x + 1) || map[y][x + 1] == ' ')
		return (0);
	return (1);
}

int	is_map_closed(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == '0')
			{
				if (!is_surrounded(map, y, x))
					return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}
int	ft_is_map_lines(const char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '1' || line[i] == '0' ||
		line[i] == 'N' || line[i] == 'S' ||
		line[i] == 'E' || line[i] == 'W')
		return (1);
	return (0);
}
int	extract_map(char **file_lines, char ***out_map)//TODO A racourcir
{
	int	start;
	int	end;
	int	len;
	int	i;
	int	i_error;

	start = 0;
	while (file_lines[start] && !ft_is_map_line(file_lines[start]))//trouve la premiere ligne
		start++;
	if (!file_lines[start])
		return (FAILURE);
	end = start;
	while (file_lines[end] && ft_is_map_line(file_lines[end]))//trouve la derniere ligne
		end++;
	len = end - start;
	*out_map = (char **)malloc(sizeof(char *) * (len + 1));//allouer le tab de sortie et len +1 pour pointeur null final
	if (!*out_map)
		return (FAILURE);
	i = 0;
	while (i < len)
	{
		(*out_map)[i] = ft_strdup(file_lines[start + i]);//duplique les lignes de la carte
		if (!(*out_map)[i])//juste si echec du ft strdup
		{
			i_error = 0;
			while (i_error < i)
			{
				free((*out_map)[i_error]);
				i_error++;
			}
			free(*out_map);
			return (FAILURE);
		}
		ft_strip_newline((*out_map)[i]);//on enelve un eventuel \n
		i++;
	}
	(*out_map)[len] = NULL;//terminer le tab proprement avec un NULL
	return (SUCCESS);
}

int	is_line_part_of_map(char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1' || line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W' || line[i] == ' ')
			return (1);
		i++;
	}
	return (0);
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
