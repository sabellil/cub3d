/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:33:51 by mairivie          #+#    #+#             */
/*   Updated: 2025/06/24 15:11:08 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	put_pixel(t_img *image, int color, int x, int y)
{
	int		shifting;
	char	*pix_target;

	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
		return ;
	shifting = y * image->grid_len + x * (image->bit_per_pix / 8);
	pix_target = image->pix_grid + shifting;
	*(unsigned int *)pix_target = color;
}

float	ft_min(size_t n, size_t n2)
{
	if (n < n2)
		return (n);
	return (n2);
}
