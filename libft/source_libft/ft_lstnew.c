/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:22:36 by mairive           #+#    #+#             */
/*   Updated: 2023/12/14 15:42:52 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: Allocate with malloc and return a new element/node. 
 * Initialize element->content with whatever is in 'content' and next to NULL.
 * 
 * PARAM: content: the content of the new element.
 *
 * RETURN: the new element. */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list) * 1);
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
