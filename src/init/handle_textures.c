/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:41:28 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/24 14:19:36 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	ft_is_empty_line(const char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_map_line(const char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

int	ft_set_texture(t_asset *dest, char *path_str, void *mlx_ptr)
{
	char	*trimmed;
	int		width;
	int		height;

	trimmed = ft_strtrim(path_str, " \t\n\r");
	if (!trimmed)
		return (FAILURE);
	dest->img = mlx_xpm_file_to_image(mlx_ptr, trimmed, &width, &height);
	if (!dest->img)
	{
		free(trimmed);
		return (FAILURE);
	}
	dest->width = width;
	dest->height = height;
	free(trimmed);
	return (SUCCESS);
}
int	ft_parse_texture_line(char *line, t_game_data *game)
{
	if (ft_starts_with(line, "NO "))
	{
		int ret = ft_set_texture(&game->tex_no, line + 3, ((t_data *)game)->infra.mlx);
		return (ret);
	}
	if (ft_starts_with(line, "SO "))
	{
		int ret = ft_set_texture(&game->tex_so, line + 3, ((t_data *)game)->infra.mlx);
		return (ret);
	}
	if (ft_starts_with(line, "WE "))
	{
		int ret = ft_set_texture(&game->tex_we, line + 3, ((t_data *)game)->infra.mlx);
		return (ret);
	}
	if (ft_starts_with(line, "EA "))
	{
		int ret = ft_set_texture(&game->tex_ea, line + 3, ((t_data *)game)->infra.mlx);
		return (ret);
	}
	return (FAILURE);
}
