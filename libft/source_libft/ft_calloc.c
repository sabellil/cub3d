/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 16:35:37 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 15:28:21 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: The calloc() function allocates memory.
 * The allocated memory is aligned such that it can be used for any data type.
 * The calloc() function contigously allocates enough space for count objects
 * that are size bytes of memory each and returns a pointer to the 
 * allocated memory.
 * The allocated memory is filled with bytes of value zero.
 *
 * RETURN VALUES: If successful, calloc() returns a pointer to allocated memory
 * If there is an error, they return NULL*/

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer_to_memory;

	pointer_to_memory = 0;
	if (nmemb > 0 && (4294967295 / nmemb < size))
		return (NULL);
	pointer_to_memory = malloc(nmemb * size);
	if (pointer_to_memory == 0)
		return (NULL);
	ft_bzero(pointer_to_memory, (nmemb * size));
	return (pointer_to_memory);
}
