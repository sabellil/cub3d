/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:15:05 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/10 16:50:45 by sabellil         ###   ########.fr       */
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

int	ft_set_color(int *dest, char *color_str)// CORRIGER exemple C 22,30,0
{
	char	**split;
	char	*tmp;
	int		r;
	int		g;
	int		b;

	split = ft_split(color_str, ',');
	if (!split || ft_strarr_len(split) != 3)
	{
		ft_free_strarr(split);
		return (FAILURE);
	}
	tmp = ft_strtrim(split[0], " ");
	if (parse_rgb_component(tmp, &r) != SUCCESS)
		return (ft_free_and_fail(tmp, split));
	free(tmp);
	tmp = ft_strtrim(split[1], " ");
	if (parse_rgb_component(tmp, &g) != SUCCESS)
		return (ft_free_and_fail(tmp, split));
	free(tmp);
	tmp = ft_strtrim(split[2], " ");
	if (parse_rgb_component(tmp, &b) != SUCCESS)
		return (ft_free_and_fail(tmp, split));
	free(tmp);
	*dest = (r << 16) | (g << 8) | b;
	ft_free_strarr(split);
	return (SUCCESS);
}

int	ft_parse_color_line(char *line, t_game_data *game)
{
	char	*ptr;

	if (ft_starts_with(line, "F "))
	{
		ptr = line + 1;
		while (*ptr == ' ')
			ptr++;
		if (ft_set_color(&game->floor_color, ptr) == SUCCESS)
			return (SUCCESS);
		return (FAILURE);
	}
	if (ft_starts_with(line, "C "))
	{
		ptr = line + 1;
		while (*ptr == ' ')
			ptr++;
		if (ft_set_color(&game->ceiling_color, ptr) == SUCCESS)
			return (SUCCESS);
		return (FAILURE);
	}
	return (FAILURE);
}
