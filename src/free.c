/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:16:22 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/10 12:05:09 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

void	free_file_lines(char **file_lines)
{
	int	i;

	if (!file_lines)
		return ;
	i = 0;
	while (file_lines[i])
	{
		free(file_lines[i]);
		i++;
	}
	free(file_lines);
}
void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_textures(t_game_data *game, void *mlx)
{
	if (game->path_no)
		free(game->path_no);
	if (game->path_so)
		free(game->path_so);
	if (game->path_we)
		free(game->path_we);
	if (game->path_ea)
		free(game->path_ea);
	if (mlx && game->tex_no.img)
		mlx_destroy_image(mlx, game->tex_no.img);
	if (mlx && game->tex_so.img)
		mlx_destroy_image(mlx, game->tex_so.img);
	if (mlx && game->tex_we.img)
		mlx_destroy_image(mlx, game->tex_we.img);
	if (mlx && game->tex_ea.img)
		mlx_destroy_image(mlx, game->tex_ea.img);
}

int	ft_free_and_fail(char *tmp, char **split)
{
	if (tmp)
		free(tmp);
	if (split)
		ft_free_strarr(split);
	return (FAILURE);
}