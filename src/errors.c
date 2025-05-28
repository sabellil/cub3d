/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 16:19:42 by sabellil          #+#    #+#             */
/*   Updated: 2025/05/28 17:26:37 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cubed.h"

int ft_handle_error(int code)
{
    if (code == ERR_ARG_COUNT)
        ft_putstr_fd("Error\nExpected: ./cub3D <map.cub>\n", 2);
    else if (code == ERR_PARSE_FAIL)
        ft_putstr_fd("Error\nParsing or map initialization failed.\n", 2);
    else if (code == ERR_INFRA_FAIL)
        ft_putstr_fd("Error\nFailed to initialize graphics infrastructure.\n", 2);
    else
        ft_putstr_fd("Error\nUnknown error.\n", 2);
    return (1);
}