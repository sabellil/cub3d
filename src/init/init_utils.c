/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 14:52:02 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/09 12:38:00 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	ft_isdigit_str(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_strarr_len(char **arr)
{
	int	len;

	len = 0;
	if (!arr)
		return (0);
	while (arr[len])
		len++;
	return (len);
}

void	ft_free_strarr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_starts_with(const char *str, const char *prefix)
{
	int	i;

	if (!str || !prefix)
		return (0);
	i = 0;
	while (prefix[i])
	{
		if (str[i] != prefix[i])
			return (0);
		i++;
	}
	printf("J'arrive au bout de ft starts with\n");
	return (1);
}

void	print_file_lines(char **lines) //TODO A supprimer a la fin pour afficher le contenu de file_lines
{
	int i;

	if (!lines)
	{
		printf("file_lines est NULL\n");
		return ;
	}
	i = 0;
	while (lines[i])
	{
		printf("Ligne %d : %s", i, lines[i]);
		i++;
	}
}