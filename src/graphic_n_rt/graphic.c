/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:33:51 by mairivie          #+#    #+#             */
/*   Updated: 2025/06/10 18:20:22 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	what_color_is_this_pixel(double x, double y, t_infra *infra)
{	
	int	color;

	// color = 7556677;
	color = infra->data->game.floor_color;
    (void)x;
	if (y <= HEIGHT / infra->ratio)
		color = infra->data->game.ceiling_color;
	return (color);
}