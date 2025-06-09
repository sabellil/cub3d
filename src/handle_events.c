/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 16:17:58 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/06 16:17:58 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

void	ft_setup_hooks(t_data *data)
{
    t_infra *infra;

    infra = &data->infra;
    mlx_hook(infra->win, DestroyNotify, StructureNotifyMask, 
        close_window, infra);
    mlx_key_hook(infra->win, handle_keypress, infra);
	//mlx_mouse_hook(infra->win, handle_mouse_event, infra);
}

int	handle_keypress(int keycode, t_infra *infra)
{
	if (keycode == XK_Escape)
		close_window(infra);
	return (SUCCESS);
}

//ICI COREDUM
int	close_window(t_infra *infra)
{
	if (infra->data)
	{
		free_map(infra->data->game.map);
		free_textures(&infra->data->game, infra->mlx);
	}
	if (infra->img_now)
	{
		if (infra->img_now->new_img)
			mlx_destroy_image(infra->mlx, infra->img_now->new_img);
		free(infra->img_now);
	}
	if (infra->img_nxt)
	{
		if (infra->img_nxt->new_img)
			mlx_destroy_image(infra->mlx, infra->img_nxt->new_img);
		free(infra->img_nxt);
	}
	if (infra->win)
		mlx_destroy_window(infra->mlx, infra->win);
	if (infra->mlx)
	{
		mlx_destroy_display(infra->mlx);
		free(infra->mlx);
	}
	infra->img_now = NULL;
	infra->img_nxt = NULL;
	infra->win = NULL;
	infra->mlx = NULL;
	exit(SUCCESS);
}



/*int	handle_mouse_event(int button, int x, int y, t_infra *infra)
{
	(void)x;
	(void)y;
	if (button == SCROLL_UP)
	{
        printf("scroll up\n");
	}
	if (button == SCROLL_DOWN)
	{
        printf("scroll up\n");
	}
	return (SUCCESS);
}*/