/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:24:08 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/10 12:54:46 by sabellil         ###   ########.fr       */
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
	data.infra.data = &data;
	if (ft_second_parsing_and_init(file_lines, &data.game) != SUCCESS)
	{
		close_window(&data.infra);
		// free_infra(&data.infra);
		return (ft_handle_error(ERR_PARSE_FAIL));
	}
	ft_setup_hooks(&data);
	mlx_loop_hook(data.infra.mlx, ft_render, &data);
	mlx_loop(data.infra.mlx);
	return (SUCCESS);
}
