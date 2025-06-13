/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:33:51 by mairivie          #+#    #+#             */
/*   Updated: 2025/06/13 11:59:24 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

int	what_color_is_this_pixel(double x, double y, t_infra *infra)
{
	int	color;

	color = 7556677;
	(void)x;
	if (y <= HEIGHT / infra->ratio)
		color = 100000;
	return (color);
}
