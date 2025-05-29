/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:49:53 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 15:50:41 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: Allocate (with malloc(3)) and returns an array of strings obtained by 
 * 	splitting s with the character c, used as delimiter.
 * 	The returned array must be NUL-terminated.
 *
 * PARAMETERS
 * 	s: string to split
 * 	c: delimiter character
 *
 * RETURN VALUES: ft_split() returns an array of strings resulting from the 
 * 	splitting of s; NULL if the memory allocation failed */

#include "libft.h"
#include "stdlib.h"
#include "stdio.h"

static size_t	ft_string_count(char const *s, char c)
{
	long	i;
	size_t	nbr;
	int		string;

	i = 0;
	nbr = 0;
	string = 0;
	while (s[i])
	{
		if (s[i] != c && string == 0)
		{
			nbr++;
			string = 1;
		}
		if (s[i] == c)
			string = 0;
		i++;
	}
	return (nbr);
}

static char	*ft_slice(char const *s, size_t start, size_t end)
{
	char	*slice;
	size_t	i;

	slice = malloc(sizeof(char) * ((end - start) + 1));
	if (slice == NULL)
		return (free(slice), NULL);
	i = 0;
	while (i < (end - start))
	{
		slice[i] = s[start + i];
		i++;
	}
	slice[i] = '\0';
	return (slice);
}

static char	**ft_store_string(char const *s, char c,
		size_t string_nbr, char **array)
{
	size_t	i;
	size_t	start;
	size_t	j;

	i = 0;
	start = 0;
	j = 0;
	while (j < string_nbr)
	{
		while (s[i] == c && s[i])
		{
			start++;
			i++;
		}
		while (s[i] != c && s[i])
			i++;
		array[j] = ft_slice(s, start, i);
		j++;
		i++;
		start = i;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	size_t	string_nbr;
	char	**array;

	if (s == NULL)
		return (NULL);
	string_nbr = ft_string_count(s, c);
	array = malloc((string_nbr + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array = ft_store_string(s, c, string_nbr, array);
	array[string_nbr] = NULL;
	return (array);
}
/*
int	main()
{
	ft_split("p pouet", ' ');
	return (0);
}*/
