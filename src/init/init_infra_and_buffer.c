/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_infra_and_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:27:40 by mairivie          #+#    #+#             */
/*   Updated: 2025/06/24 15:37:57 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

int	init_double_buffer(t_infra *infra)
{
	infra->img_now = ft_calloc(1, sizeof(t_img));
	if (infra->img_now == NULL)
		return (ERR_INFRA_FAIL);
	infra->img_now->new_img = mlx_new_image(infra->mlx, WIDTH, HEIGHT);
	if (infra->img_now->new_img == NULL)
		return (ERR_INFRA_FAIL);
	infra->img_now->pix_grid = mlx_get_data_addr(infra->img_now->new_img,
			&infra->img_now->bit_per_pix, &infra->img_now->grid_len,
			&infra->img_now->endien);
	infra->img_nxt = ft_calloc(1, sizeof(t_img));
	if (infra->img_nxt == NULL)
		return (ERR_INFRA_FAIL);
	infra->img_nxt->new_img = mlx_new_image(infra->mlx, WIDTH, HEIGHT);
	if (infra->img_nxt->new_img == NULL)
		return (ERR_INFRA_FAIL);
	infra->img_nxt->pix_grid = mlx_get_data_addr(infra->img_nxt->new_img,
			&infra->img_nxt->bit_per_pix, &infra->img_nxt->grid_len,
			&infra->img_nxt->endien);
	return (SUCCESS);
}

int	ft_init_infra(t_infra *infra)
{
	infra->mlx = mlx_init();
	if (infra->mlx == NULL)
		return (ft_handle_error(ERR_INFRA_FAIL));
	infra->win = mlx_new_window(infra->mlx, WIDTH, HEIGHT, NAME);
	if (infra->win == NULL)
		return (ft_handle_error(ERR_INFRA_FAIL));
	if (init_double_buffer(infra) == ERR_INFRA_FAIL)
		return (ft_handle_error(ERR_INFRA_FAIL));
	infra->ratio = 2;
	return (SUCCESS);
}
