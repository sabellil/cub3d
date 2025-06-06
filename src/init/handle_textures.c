/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:41:28 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/06 17:51:54 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

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
	if (line[i] == '1' || line[i] == '0' || line[i] == 'N' || line[i] == 'S'
		|| line[i] == 'E' || line[i] == 'W')
		return (1);
	return (0);
}

int	ft_set_texture(t_asset *dest, const char *path_str, void *mlx_ptr)
{
	int		width;
	int		height;
	char	*trimmed;

	trimmed = ft_strtrim(path_str, " \t\n\r");
	if (!trimmed)
		return (1);
	printf("NORD 1\n");
	dest->img = mlx_xpm_file_to_image(mlx_ptr, trimmed, &width, &height);
	printf("NORD 2\n");
	free(trimmed);
	if (!dest->img)
		return (1);
	printf("NORD 3\n");
	dest->width = width;
	dest->height = height;
	dest->addr = mlx_get_data_addr(dest->img, &dest->bpp, &dest->line_len,
			&dest->endian);
	if (!dest->addr)
		return (1);
	printf("J'arrive au bout de ft set texture\n");
	return (0);
}

int	ft_parse_texture_line(char *line, t_game_data *game)
{
	if (ft_starts_with(line, "NO "))
	{
		return (ft_set_texture(&game->tex_no, line + 2,
				((t_data *)game)->infra.mlx)); //src/parsing_init/parsing_texture.c:34:26: error: incompatible pointer types passing 't_asset *' (aka 'struct s_img *') to parameter of type 'char *' [-Werror,-Wincompatible-pointer-types] return (ft_set_texture(&game->tex_no, line + 2));
		printf("NORD OK");
	}
	if (ft_starts_with(line, "SO "))
		return (ft_set_texture(&game->tex_so, line + 2,
				((t_data *)game)->infra.mlx));
	if (ft_starts_with(line, "WE "))
		return (ft_set_texture(&game->tex_we, line + 2,
				((t_data *)game)->infra.mlx));
	if (ft_starts_with(line, "EA "))
		return (ft_set_texture(&game->tex_ea, line + 2,
				((t_data *)game)->infra.mlx));
	printf("Je vais retourner un failure\n");
	return (FAILURE);
}
