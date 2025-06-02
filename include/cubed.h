/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:41:55 by mairivie          #+#    #+#             */
/*   Updated: 2025/06/02 15:58:48 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <fcntl.h> // open
# include <math.h>
# include <stdio.h>    // printf perror
# include <stdlib.h>   // malloc free exit
# include <string.h>   // strerror
# include <sys/stat.h> // open
# include <sys/time.h> // gettimeofday
# include <unistd.h>   // write close read

# define WIDTH 1280
# define HEIGHT 720
# define MAX_LINES 1024

# define SUCCESS 0
# define FAILURE 1
# define ERR_ARG_COUNT 11
# define ERR_PARSE_FAIL 12
# define ERR_INFRA_FAIL 13

typedef struct s_img
{
	int			width;
	int			height;
}				t_img;

typedef struct s_game_data
{
	// Map
	char		**map;
	int			map_width;
	int			map_height;
	// Textures POUR PARSING
	char *path_no; // stocker chaine char * vers chemin fichier texture nord etc
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	// Textures POUR LAFFICHAGE GRAPHIQUE DIRECT, chaque tex_ vient avec sa boite outils t_img
	t_img tex_no;
		//image chargee depuis path_no (grace a mlx_xmp_file_to_image et get_data_addr)
	t_img		tex_so;
	t_img		tex_we;
	t_img		tex_ea;
	// Couleurs sol/plafond
	int			floor_color;
	int			ceiling_color;
	// Joueur
	double pos_x; //la position du joueur
	double		pos_y;
	double dir_x; //le regard du joueur
	double		dir_y;
	//Manquera le field of view (x et y aussi?)
}				t_game_data;

typedef struct s_infra
{
	void		*mlx;
	void		*win;
	t_img		img_now;
	t_img		img_nxt;
}				t_infra;

typedef struct s_data
{
	t_game_data	game;
	t_infra		infra;
}				t_data;

//INITALIZATION AND PARSING
int				ft_init_and_parse(t_game_data *game, char *filename);
int				ft_check_file_extension(const char *filename,
					const char *extension);
int				has_single_dot(const char *filename, int len_file);
void			free_file_lines_partial(char **lines, int count);
// void			print_file_lines(char **lines);
char			**read_lines_from_file(int fd);
int				ft_init_and_parse(t_game_data *game, char *filename);
char			**ft_read_cub_file(const char *filename);
int				parse_textures_and_colors(char **file_lines, t_game_data *game);
int				parse_map_and_player(char **file_lines, t_game_data *game);

//ERROR AND FREE MANAGEMENT
int				ft_handle_error(int code);
void			free_file_lines(char **file_lines);

//THE BIG BIG LOOP
int				ft_render_next_frame(void *param);

//OTHER FUNCTIONS JUST SO I CAN COMPILE
int				ft_init_infra(t_infra *infra, t_game_data *game);
void			ft_setup_hooks(t_data *data);
void			ft_clean_exit(t_data *data, int exit_code);
int				ft_render_next_frame(void *param);
#endif