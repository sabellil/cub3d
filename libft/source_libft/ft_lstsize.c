/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:32:48 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 16:33:20 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: Count the number of elements of the list
 *
 * PARAMETERS: lst: start of the list
 *
 * RETURN VALUES: The size of the list */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int		numb;
	t_list	*current;

	numb = 0;
	current = lst;
	while (current != NULL)
	{
		numb++;
		current = current->next;
	}
	return (numb);
}
