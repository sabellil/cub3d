/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:24:08 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/09 15:09:37 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

void	ft_clean_exit(t_data *data, int exit_code)
{
	(void)data;
	exit(exit_code);
}

int	ft_render_next_frame(void *param)
{
	(void)param;
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	**file_lines;
memset(&data, 0, sizeof(t_data)); // ou t_game_data si tu utilises juste la structure game

	if (argc != 2)
		return (ft_handle_error(ERR_ARG_COUNT));
	if((ft_first_parsing(argv[1], &file_lines)) != SUCCESS)
		return (ft_handle_error(ERR_PARSE_FAIL));
	if(ft_init_infra(&data.infra)!= SUCCESS)
		return (ft_handle_error(ERR_INFRA_FAIL));
	if (ft_second_parsing_and_init(file_lines, &data.game) != SUCCESS)
		return (ft_handle_error(ERR_PARSE_FAIL));
	ft_setup_hooks(&data);
	mlx_loop_hook(data.infra.mlx, ft_render_next_frame, &data);
	mlx_loop(data.infra.mlx);
	ft_clean_exit(&data, SUCCESS);
	return (SUCCESS);
}
