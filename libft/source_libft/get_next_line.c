/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 14:40:56 by mairivie          #+#    #+#             */
/*   Updated: 2024/10/15 16:51:53 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*resize_line(char *line, ssize_t *size_line, ssize_t *i_line)
{
	char	*temp_line;

	*size_line = *size_line + BUFFER_SIZE;
	temp_line = malloc(*size_line);
	if (temp_line == NULL)
		return (free_all(temp_line));
	ft_memcpy(temp_line, line, *i_line);
	free(line);
	return (temp_line);
}

void	refill_buffer(int fd, struct s_gnl *data)
{
	data->res_read = read(fd, data->buffer, BUFFER_SIZE);
	data->i_buffer = 0;
}

char	*read_line(int fd, char *line, ssize_t *size_line, struct s_gnl *data)
{
	ssize_t	i_line;

	i_line = 0;
	while (1)
	{
		if (i_line == *size_line - 1)
		{
			line = resize_line(line, size_line, &i_line);
		}
		if (data->i_buffer >= data->res_read)
		{
			refill_buffer(fd, data);
			if (i_line > 0 && data->res_read == 0)
				return (end_string(line, &i_line));
			if (data->res_read <= 0)
				return (free_all(line));
		}
		line[i_line] = data->buffer[data->i_buffer];
		++i_line;
		++data->i_buffer;
		if (data->buffer[data->i_buffer - 1] == '\n')
		{
			return (end_string(line, &i_line));
		}
	}
}

char	*get_next_line(int fd)
{
	static struct s_gnl		data;
	char					*line;
	ssize_t					size_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	size_line = BUFFER_SIZE;
	line = malloc(size_line);
	if (line == NULL)
		free_all(line);
	line = read_line(fd, line, &size_line, &data);
	return (line);
}
