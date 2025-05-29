/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:33:37 by mairive           #+#    #+#             */
/*   Updated: 2023/12/14 15:42:22 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: Add the 'new' element at the back of the list. 
 *
 * RETURN: No return value  
 *
 * PARAM:	lst: pointer adress of the first element of the list
 * 			new: pointer adress of the new element to add to the list */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (new == NULL)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
	last = ft_lstlast(*lst);
	last->next = new;
	}
	return ;
}
