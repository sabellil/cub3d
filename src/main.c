/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:24:08 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/24 13:51:13 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

int	main(int argc, char **argv)
{
	t_data	data;
	char	**file_lines;
	
	ft_memset(&data, 0, sizeof(t_data));
	if (argc != 2)
		return (ft_handle_error(ERR_ARG_COUNT));
	if((ft_first_parsing(argv[1], &file_lines)) != SUCCESS)
		return (ft_handle_error(ERR_PARSE_FAIL));
	if(ft_init_infra(&data.infra)!= SUCCESS)
		return (ft_handle_error(ERR_INFRA_FAIL));
	data.infra.data = &data;// pour que close window qui prend t_infra puisse recuperer la data entiere et donc liberer
	if (ft_second_parsing_and_init(file_lines, &data.game) != SUCCESS)
	{		
		ft_handle_error(ERR_PARSE_FAIL);
		close_window(&data.infra);
	}
	ft_setup_hooks(&data);
	mlx_loop_hook(data.infra.mlx, ft_render, &data);
	mlx_loop(data.infra.mlx);
	return (SUCCESS);
}
