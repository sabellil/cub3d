/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:07:45 by mairive           #+#    #+#             */
/*   Updated: 2023/12/14 13:45:45 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* PARAM lst: pointer adress to one element \ f: function to apply
 * DESC: Iterate over the list 'lst' and apply the function 'f' to the content
 * of all elements. */

#include "libft.h"
#include <stdlib.h>

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst != NULL)
	{
		f(lst->content);
		lst = lst->next;
	}
}
