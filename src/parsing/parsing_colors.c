/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:15:05 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/06 13:03:26 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

static int	parse_rgb_component(const char *str, int *component)
{
	int	value;

	if (!ft_isdigit_str(str))
		return (FAILURE);
	value = ft_atoi(str);
	if (value < 0 || value > 255)
		return (FAILURE);
	*component = value;
	return (SUCCESS);
}

int	ft_set_color(int *dest, char *color_str)
{
	char	**split;
	int		r, g, b;

	split = ft_split(color_str, ',');
	if (!split || ft_strarr_len(split) != 3)
	{
		ft_free_strarr(split);
		return (FAILURE);
	}
	if (parse_rgb_component(split[0], &r) != SUCCESS
		|| parse_rgb_component(split[1], &g) != SUCCESS
		|| parse_rgb_component(split[2], &b) != SUCCESS)
	{
		ft_free_strarr(split);
		return (FAILURE);
	}
	*dest = (r << 16) | (g << 8) | b;
	ft_free_strarr(split);
	return (SUCCESS);
}

int	ft_parse_color_line(char *line, t_game_data *game)
{
	if (ft_starts_with(line, "F "))
		return (ft_set_color(&game->floor_color, line + 1));
	if (ft_starts_with(line, "C "))
		return (ft_set_color(&game->ceiling_color, line + 1));// TODO
	return (FAILURE);
}
