/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:53:47 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/06 16:21:11 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
// Nettoyer le chemin (path_str) et le stocker dans la structure (dest)

int	ft_set_texture(t_asset *dest, const char *path_str, void *mlx_ptr)
{
	int	width;
	int	height;
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
	dest->addr = mlx_get_data_addr(dest->img, &dest->bpp,
					&dest->line_len, &dest->endian);
	if (!dest->addr)
		return (1);
	printf("J'arrive au bout de ft set texture\n");
	return (0);
}


int	ft_parse_texture_line(char *line, t_game_data *game)
{
	if (ft_starts_with(line, "NO "))
	{
		return (ft_set_texture(&game->tex_no, line + 2, ((t_data *)game)->infra.mlx));//src/parsing_init/parsing_texture.c:34:26: error: incompatible pointer types passing 't_asset *' (aka 'struct s_img *') to parameter of type 'char *' [-Werror,-Wincompatible-pointer-types] return (ft_set_texture(&game->tex_no, line + 2));
		printf("NORD OK");
	}
	if (ft_starts_with(line, "SO "))
		return (ft_set_texture(&game->tex_so, line + 2, ((t_data *)game)->infra.mlx));
	if (ft_starts_with(line, "WE "))
		return (ft_set_texture(&game->tex_we, line + 2, ((t_data *)game)->infra.mlx));
	if (ft_starts_with(line, "EA "))
		return (ft_set_texture(&game->tex_ea, line + 2, ((t_data *)game)->infra.mlx));
	printf("Je vais retourner un failure\n");
	return (FAILURE);
}
