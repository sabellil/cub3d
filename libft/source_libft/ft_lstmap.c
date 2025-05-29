/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 13:50:07 by mairive           #+#    #+#             */
/*   Updated: 2023/12/14 15:22:21 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: Iterate over the list 'lst' and apply the function 'f' to the content
 * of each elements. Create a new list resulting of the successive applications
 * of 'f'. The function 'del' is used to destroy the content of an element 
 * if necessary. 
 *
 * PARAM:	lst: pointer adress to the first element
 * 			f: adress of the function to apply
 * 			del: adress of the function to delete an element's content 
 *
 * RETURN: the new list or NULL if malloc fails. */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, free);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst->next;
	}
	return (new_list);
}
