/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:15:05 by sabellil          #+#    #+#             */
/*   Updated: 2025/07/28 16:13:17 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

static int	parse_rgb_component(char *str, int *out)
{
	int	len;
	int	value;

	len = 0;
	if (!str || str[0] == '\0')
		return (FAILURE);
	while (str[len])
	{
		if (!ft_isdigit(str[len]))
			return (FAILURE);
		len++;
	}
	if (len > 1 && str[0] == '0')
		return (FAILURE);
	if (len > 3)
		return (FAILURE);
	value = ft_atoi(str);
	if (value < 0 || value > 255)
		return (FAILURE);
	*out = value;
	return (SUCCESS);
}

static int	parse_component_and_store(char *str, int *out, char **split)
{
	char	*trimmed;

	trimmed = ft_strtrim(str, " ");
	if (!trimmed)
	{
		ft_free_strarr(split);
		return (FAILURE);
	}
	if (parse_rgb_component(trimmed, out) != SUCCESS)
		return (ft_free_and_fail(trimmed, split));
	free(trimmed);
	return (SUCCESS);
}

int	ft_set_color(int *dest, char *color_str)
{
	char	**split;
	int		r;
	int		g;
	int		b;

	split = ft_split(color_str, ',');
	if (!split || ft_strarr_len(split) != 3)
	{
		ft_free_strarr(split);
		return (FAILURE);
	}
	if (parse_component_and_store(split[0], &r, split) != SUCCESS
		|| parse_component_and_store(split[1], &g, split) != SUCCESS
		|| parse_component_and_store(split[2], &b, split) != SUCCESS)
		return (FAILURE);
	*dest = (r << 16) | (g << 8) | b;
	ft_free_strarr(split);
	return (SUCCESS);
}

int	ft_parse_color_line(char *line, t_game_data *game)
{
	char	*ptr;

	if (ft_starts_with(line, "F "))
	{
		if (game->floor_color != -1)
			return (FAILURE);
		ptr = line + 1;
		while (*ptr == ' ')
			ptr++;
		if (ft_set_color(&game->floor_color, ptr) == SUCCESS)
			return (SUCCESS);
		return (FAILURE);
	}
	if (ft_starts_with(line, "C "))
	{
		if (game->ceiling_color != -1)
			return (FAILURE);
		ptr = line + 1;
		while (*ptr == ' ')
			ptr++;
		if (ft_set_color(&game->ceiling_color, ptr) == SUCCESS)
			return (SUCCESS);
		return (FAILURE);
	}
	return (FAILURE);
}
