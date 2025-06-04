/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:15:05 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/04 17:55:30 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"


int	ft_parse_color_line(char *line, t_game_data *game)
{
	if (ft_starts_with(line, "F "))
		return (ft_set_color(&game->floor_color, line + 1));
	if (ft_starts_with(line, "C "))
		return (ft_set_color(&game->ceiling_color, line + 1));// TODO 
	return (FAILURE);
}


