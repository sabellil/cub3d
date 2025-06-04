/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:53:47 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/04 18:45:25 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"
// Nettoyer le chemin (path_str) et le stocker dans la structure (dest)
int	ft_set_texture(char *dest, char *path_str)
{
	char	*trimmed;

	trimmed = ft_strtrim(path_str, " \t");
	if (!trimmed)
		return (FAILURE);
	if (*dest)
		free(dest);
	dest = ft_strdup(trimmed);
	free(trimmed);
	if (!*dest)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_parse_texture_line(char *line, t_game_data *game)
{
	if (ft_starts_with(line, "NO "))
		return (ft_set_texture(&game->tex_no, line + 2));//src/parsing_init/parsing_texture.c:34:26: error: incompatible pointer types passing 't_img *' (aka 'struct s_img *') to parameter of type 'char *' [-Werror,-Wincompatible-pointer-types] return (ft_set_texture(&game->tex_no, line + 2));
	if (ft_starts_with(line, "SO "))
		return (ft_set_texture(&game->tex_so, line + 2));
	if (ft_starts_with(line, "WE "))
		return (ft_set_texture(&game->tex_we, line + 2));
	if (ft_starts_with(line, "EA "))
		return (ft_set_texture(&game->tex_ea, line + 2));
	return (FAILURE);
}
