/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:27:40 by mairivie          #+#    #+#             */
/*   Updated: 2025/06/02 16:15:30 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

void	ft_setup_hooks(t_data *data)
{
    t_infra *infra;

    infra = &data->infra;
    mlx_hook(infra->win, DestroyNotify, StructureNotifyMask, 
        close_window, &infra);
    mlx_key_hook(infra->win, handle_keypress, &infra);
	//mlx_mouse_hook(infra->win, handle_mouse_event, &infra);
}


int	handle_keypress(int keycode, t_infra *infra)
{
	if (keycode == XK_Escape)
		close_window(infra);
	return (SUCCESS);
}

//ICI COREDUMP

int	close_window(t_infra *infra)
{
	mlx_destroy_image(infra->mlx, infra->img_now->new_img);
	mlx_destroy_image(infra->mlx, infra->img_nxt->new_img);
	mlx_destroy_window(infra->mlx, infra->win);
	mlx_destroy_display(infra->mlx);
	free(infra->mlx);
	free(infra->img_now);
	free(infra->img_nxt);
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