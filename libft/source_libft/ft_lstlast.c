/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:15:44 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 16:35:51 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: Returns the last element of the list
 *
 * PARAMETERS:
	lst: the start of the list

 * RETURN VALUES: Last element of the list */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;

	if (lst == NULL)
		return (0);
	current = lst;
	while (current->next != NULL)
		current = current->next;
	return (current);
}
