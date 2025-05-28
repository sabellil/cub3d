/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 15:24:08 by sabellil          #+#    #+#             */
/*   Updated: 2025/05/28 17:27:04 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	main(int argc, char **argv)
{
	t_data	data;
    int game;
    int infra;
    
	if (argc != 2)
		return (ft_handle_error(ERR_ARG_COUNT));
	game = ft_init_and_parse(&data.game, argv[1]);
	if (game != SUCCESS)
		return (handle_error(ERR_PARSE_FAIL));
	infra = ft_init_infra(&data.infra, &data.game);
	if (infra != SUCCESS)
		return (handle_error(ERR_INFRA_FAIL));
	ft_setup_hooks(&data);
	mlx_loop_hook(data.infra.mlx, ft_render_next_frame, &data);
	mlx_loop(data.infra.mlx);
	ft_clean_exit(&data, SUCCESS);
	return (0);
}