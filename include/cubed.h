/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:41:55 by mairivie          #+#    #+#             */
/*   Updated: 2025/05/28 16:18:38 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <math.h>
# include <unistd.h> // write close read
# include <stdio.h> // printf perror
# include <stdlib.h> // malloc free exit
# include <fcntl.h> // open
# include <sys/stat.h> // open
# include <sys/time.h> // gettimeofday
# include <string.h> // strerror
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"


# define WIDTH 1280
# define HEIGHT 720

# define SUCCESS          0
# define ERR_ARG_COUNT    1
# define ERR_PARSE_FAIL   2
# define ERR_INFRA_FAIL   3

typedef struct s_img
{
	int		width;
	int		height;
}	t_img;

typedef struct s_game_data
{
	// Map
	char		**map;
	int			map_width;
	int			map_height;
	// Textures POUR PARSING
	char		*path_no;// stocker chaine char * vers chemin fichier texture nord etc
	char		*path_so;
	char		*path_we;
	char		*path_ea;
    // Textures POUR LAFFICHAGE GRAPHIQUE DIRECT, chaque tex_ vient avec sa boite outils t_img 
	t_img		tex_no;//image chargee depuis path_no (grace a mlx_xmp_file_to_image et get_data_addr)
	t_img		tex_so;
	t_img		tex_we;
	t_img		tex_ea;
	// Couleurs sol/plafond
	int			floor_color;
	int			ceiling_color;
	// Joueur
	double		pos_x;//la position du joueur 
	double		pos_y;
	double		dir_x;//le regard du joueur
	double		dir_y;
	//Manquera le field of view (x et y aussi?)
}	t_game_data;

typedef struct s_infra
{
	void	*mlx;
	void	*win;
	t_img	img_now;
	t_img	img_nxt;
}	t_infra;

typedef struct s_data
{
	t_game	game_game;
	t_infra	infra;
}