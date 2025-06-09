/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:15:05 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/09 12:51:06 by sabellil         ###   ########.fr       */
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
	int r, g, b;

	printf("DEBUG: ft_set_color reçoit '%s'\n", color_str);
	split = ft_split(color_str, ',');
	if (!split || ft_strarr_len(split) != 3)
	{
		printf("DEBUG: Mauvais split ou taille split: %d\n", split ? ft_strarr_len(split) : -1);
		ft_free_strarr(split);
		return (FAILURE);
	}
	if (parse_rgb_component(ft_strtrim(split[0], " "), &r) != SUCCESS
		|| parse_rgb_component(ft_strtrim(split[1], " "), &g) != SUCCESS
		|| parse_rgb_component(ft_strtrim(split[2], " "), &b) != SUCCESS)
	{
		printf("DEBUG: parse_rgb_component KO : '%s','%s','%s'\n", split[0], split[1], split[2]);
		ft_free_strarr(split);
		return (FAILURE);
	}
	*dest = (r << 16) | (g << 8) | b;
	ft_free_strarr(split);
	printf("DEBUG: Couleur obtenue : %06X\n", *dest);
	return (SUCCESS);
}

int ft_parse_color_line(char *line, t_game_data *game)
{
    printf("DEBUG: ft_parse_color_line reçoit : '%s'\n", line);
	
    if (ft_starts_with(line, "F "))
    {
        char *ptr = line + 1;
        while (*ptr == ' ') ptr++;
        printf("DEBUG: On passe à ft_set_color avec '%s'\n", ptr);
        if (ft_set_color(&game->floor_color, ptr) == SUCCESS)
            return (SUCCESS);
        return (FAILURE);
    }
    if (ft_starts_with(line, "C "))
    {
        char *ptr = line + 1;
        while (*ptr == ' ') ptr++;
        printf("DEBUG: On passe à ft_set_color avec '%s'\n", ptr);
        if (ft_set_color(&game->ceiling_color, ptr) == SUCCESS)
            return (SUCCESS);
        return (FAILURE);
    }
    return (FAILURE);
}

