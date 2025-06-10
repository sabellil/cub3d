/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:16:22 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/10 12:32:11 by sabellil         ###   ########.fr       */
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
#include "cubed.h"

/*
 * Dégage tout ce que ft_init_infra a alloué,
 * sans toucher à data.game (map, textures).
 */
void free_infra(t_infra *infra)
{
    if (!infra)
        return;
    if (infra->img_now)
    {
        free(infra->img_now->pix_grid);
        if (infra->img_now->new_img)
            mlx_destroy_image(infra->mlx, infra->img_now->new_img);
        free(infra->img_now);
        infra->img_now = NULL;
    }
    if (infra->img_nxt)
    {
        free(infra->img_nxt->pix_grid);
        if (infra->img_nxt->new_img)
            mlx_destroy_image(infra->mlx, infra->img_nxt->new_img);
        free(infra->img_nxt);
        infra->img_nxt = NULL;
    }
    if (infra->win)
        mlx_destroy_window(infra->mlx, infra->win);
    if (infra->mlx)
    {
        mlx_destroy_display(infra->mlx);
        free(infra->mlx);
        infra->mlx = NULL;
    }
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