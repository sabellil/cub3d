/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairive <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:20:55 by mairive           #+#    #+#             */
/*   Updated: 2023/12/15 16:01:46 by mairive          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DESC: Apply the function 'f' to each characters of the string 's', passing
 * its index as a first parameter.
 * Each character is transmitted by address to 'f' so it can be modified if 
 * necessary.*/

#include "libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;
	size_t			len;

	if (s == NULL)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		(*f)(i, s + i);
		i++;
	}
}
/*
void ft_list_char(unsigned int index, char* character) {
    printf("Index: %u, Character: %c\n", index, *character);
}

int main() {
    char str[] ="Hello";
    ft_striteri(str, ft_list_char);

    return 0;
}
*/
