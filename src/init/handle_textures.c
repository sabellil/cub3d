/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 17:41:28 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/09 12:38:30 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	ft_is_empty_line(const char *line)
{
	int	i;

	if (!line)
		return (1);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_map_line(const char *line)
{
	int	i;

	if (!line)
		return (0);
	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	// N'accepte que les lignes qui commencent par un chiffre (souvent 1 ou 0 pour les maps 42)
	if (line[i] == '1' || line[i] == '0')
		return (1);
	return (0);
}

int	ft_set_texture(t_asset *dest, char *path_str, void *mlx_ptr)
{
	char	*trimmed;
	int		width, height;

	// Enlève espaces et retours à la ligne
	trimmed = ft_strtrim(path_str, " \t\n\r");
	printf("DEBUG: ft_set_texture : path = '%s'\n", trimmed);

	if (!trimmed)
		return (FAILURE);

	dest->img = mlx_xpm_file_to_image(mlx_ptr, trimmed, &width, &height);
	if (!dest->img)
	{
		printf("Erreur : impossible de charger la texture '%s'\n", trimmed);
		free(trimmed);
		return (FAILURE);
	}
	dest->width = width;
	dest->height = height;
	free(trimmed);
	return (SUCCESS);
}
int	ft_parse_texture_line(char *line, t_game_data *game)
{
	printf("DEBUG: On teste la ligne: '%s'\n", line);

	if (ft_starts_with(line, "NO "))
	{
		printf("DEBUG: Ligne reconnue comme NORD\n");
		int ret = ft_set_texture(&game->tex_no, line + 3, ((t_data *)game)->infra.mlx);
		printf("DEBUG: ft_set_texture (NORD) retourne %d\n", ret);
		return (ret);
	}
	if (ft_starts_with(line, "SO "))
	{
		printf("DEBUG: Ligne reconnue comme SUD\n");
		int ret = ft_set_texture(&game->tex_so, line + 3, ((t_data *)game)->infra.mlx);
		printf("DEBUG: ft_set_texture (SUD) retourne %d\n", ret);
		return (ret);
	}
	if (ft_starts_with(line, "WE "))
	{
		printf("DEBUG: Ligne reconnue comme OUEST\n");
		int ret = ft_set_texture(&game->tex_we, line + 3, ((t_data *)game)->infra.mlx);
		printf("DEBUG: ft_set_texture (OUEST) retourne %d\n", ret);
		return (ret);
	}
	if (ft_starts_with(line, "EA "))
	{
		printf("DEBUG: Ligne reconnue comme EST\n");
		int ret = ft_set_texture(&game->tex_ea, line + 3, ((t_data *)game)->infra.mlx);
		printf("DEBUG: ft_set_texture (EST) retourne %d\n", ret);
		return (ret);
	}
	printf("Je vais retourner un failure\n");
	return (FAILURE);
}
