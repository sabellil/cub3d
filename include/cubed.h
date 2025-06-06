/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabellil <sabellil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:41:55 by mairivie          #+#    #+#             */
/*   Updated: 2025/06/06 16:23:09 by sabellil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>      // define minilibX
# include <X11/keysym.h> // define Key_events minilibX
# include <fcntl.h>      // open
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
# define NAME "(=*.*=) cub3d_cat (=*.*=)"

# define SUCCESS 0
# define FAILURE 1
# define ERR_ARG_COUNT 11
# define ERR_PARSE_FAIL 12
# define ERR_INFRA_FAIL 13

typedef struct s_img
{
	void		*new_img;
	char		*pix_grid;
	int			grid_len;
	int			bit_per_pix;
	int			endien;
}				t_img;

typedef struct s_asset
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_asset;

typedef struct s_game_data
{
	char		**map;
	int			map_width;
	int			map_height;
	char		*path_no;
	char		*path_so;
	char		*path_we;
	char		*path_ea;
	t_asset		tex_no;
	t_asset		tex_so;
	t_asset		tex_we;
	t_asset		tex_ea;
	int			floor_color;
	int			ceiling_color;
	// Joueur
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
}				t_game_data;

typedef struct s_infra
{
	void		*mlx;
	void		*win;
	t_img		*img_now;
	t_img		*img_nxt;
}				t_infra;

typedef struct s_data
{
	t_game_data	game;
	t_infra		infra;
}				t_data;

// PARSING
int				ft_first_parsing(char *filename, char ***file_lines_out);
int				ft_check_file_extension(const char *filename,
							const char *extension);
char			**ft_read_cub_file(const char *filename);
char			**read_lines_from_file(int fd);

//INITALIZATION
int				ft_second_parsing_and_init(char **file_lines,
								t_game_data *game);
int				parse_textures_and_colors(char **file_lines, t_game_data *game);
int				ft_parse_texture_line(char *line, t_game_data *game);
int				ft_parse_color_line(char *line, t_game_data *game);
int				parse_map_and_player(char **file_lines, t_game_data *game);
int				ft_set_texture(t_asset *dest, const char *path_str,
					void *mlx_ptr);

//INITALIZATION AND PARSING - UTILS
void			free_file_lines_partial(char **lines, int count);
int				has_single_dot(const char *filename, int len_file);
int				ft_starts_with(const char *str, const char *prefix);
void			print_file_lines(char **lines);
char			**read_lines_from_file(int fd);
int				ft_strarr_len(char **arr);
void			ft_free_strarr(char **arr);
int				ft_isdigit_str(const char *str);

//ERROR AND FREE MANAGEMENT
int				ft_handle_error(int code);
void			free_file_lines(char **file_lines);

//THE BIG BIG LOOP
int				ft_render_next_frame(void *param);

//INFRA
int				close_window(t_infra *infra);
int				handle_keypress(int keycode, t_infra *infra);
int				ft_init_infra(t_infra *infra);

//OTHER FUNCTIONS JUST SO I CAN COMPILE
void			ft_setup_hooks(t_data *data);
void			ft_clean_exit(t_data *data, int exit_code);
int				ft_render_next_frame(void *param);
#endif