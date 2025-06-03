/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:24:08 by sabellil          #+#    #+#             */
/*   Updated: 2025/06/02 16:08:20 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cubed.h"

void	ft_setup_hooks(t_data *data)
{
	(void)data;
}
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
// int	ft_init_infra(t_infra *infra, t_game_data *game)
// {
// 	(void)infra;
// 	(void)game;
// 	return (SUCCESS);
// }
int	main(int argc, char **argv)
{
	t_data	data;
    int res_game;
    int res_infra;
    
	if (argc != 2)
		return (ft_handle_error(ERR_ARG_COUNT));
	ft_bzero(&data, sizeof(t_data));
	res_game = ft_init_and_parse(&data.game, argv[1]);
	if (res_game != SUCCESS)
		return (ft_handle_error(ERR_PARSE_FAIL));
	res_infra = ft_init_infra(&data.infra);
	if (res_infra != SUCCESS)
		return (ft_handle_error(ERR_INFRA_FAIL));
	ft_setup_hooks(&data);
	mlx_loop_hook(data.infra.mlx, ft_render_next_frame, &data);
	mlx_loop(data.infra.mlx);
	ft_clean_exit(&data, SUCCESS);
	return (SUCCESS);
}