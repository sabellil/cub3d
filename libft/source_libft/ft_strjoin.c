/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:16:32 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 15:35:25 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: Allocate (with malloc(3)) and returns a new string resulting from the 
 * concatenation of s1 and s2.
 *
 * PARAMETERS
 * 	s1: prefix string
 * 	s2: suffix string
 *
 * 	RETURN VALUES: ft_strjoin() returns the new string; NULL if the memory 
 * 	allocation failed.*/

#include "libft.h"
#include "stdlib.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	size = (ft_strlen(s1) + ft_strlen(s2));
	result = malloc(size + 1 * sizeof(char));
	if (result == NULL)
		return (NULL);
	while (i < (ft_strlen(s1)))
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (i + j <= size)
	{
		result[i + j] = s2[j];
		j++;
	}
	return (result);
}
/*
int	main(void)
{
	char const	*s1;
	char const	*s2;

	s1[6] = "abcde";
	s2[6] = "fghij";
	ft_strjoin(s1, s2);
	return (0);
}*/
