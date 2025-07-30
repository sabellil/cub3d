/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 18:33:51 by mairivie          #+#    #+#             */
/*   Updated: 2025/07/30 14:45:02 by sabellil         ###   ########.fr       */
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

unsigned int	what_color_is_hit_pixel(t_asset *texture, int hit_x, int hit_y)
{
	char	*char_of_pix_on_xpm;
	int		color;

	if (!texture || !texture->addr)
		return (COLOR_INVALID);
	if (hit_x < 0 || hit_x >= texture->width || hit_y < 0
		|| hit_y >= texture->height)
		return (COLOR_INVALID);
	char_of_pix_on_xpm = texture->addr + (hit_y * texture->line_len) + (hit_x
			* (texture->bpp / 8));
	color = *(unsigned int *)char_of_pix_on_xpm;
	return (color);
}

t_asset	*get_texture_by_orientation(t_game_data *game, int axis_hit,
		float alpha)
{
	t_asset *texture;

	texture = NULL;
	if (axis_hit == HORIZ_X)
	{
		if (cosf(alpha) >= 0)
			texture = &game->tex_ea;
		else
			texture = &game->tex_we;
	}
	if (axis_hit == VERTI_Y)
	{
		if (sinf(alpha) >= 0)
			texture = &game->tex_no;
		else
			texture = &game->tex_so;
	}
	return (texture);
}
