/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_map_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 15:23:04 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/24 15:41:27 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

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
	if (line[i] == '1' || line[i] == '0'
		|| line[i] == 'N' || line[i] == 'S'
		|| line[i] == 'E' || line[i] == 'W')
		return (1);
	return (0);
}
