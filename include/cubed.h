/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:41:55 by mairivie          #+#    #+#             */
/*   Updated: 2025/07/16 18:07:45 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_H
# define CUBED_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>      // define minilibX
# include <X11/keysym.h> // define Key_events minilibX
# include <fcntl.h>      // open
# include <math.h>       // pour cos et sin, sqrt, floor
# include <stdio.h>      // printf perror
# include <stdlib.h>     // malloc free exit
# include <string.h>     // strerror
# include <sys/stat.h>   // open
# include <sys/time.h>   // gettimeofday
# include <unistd.h>     // write close read

# define WIDTH 1280
# define HEIGHT 720
# define MAX_LINES 1024
# define NAME "(=*.*=) cub3d_cat (=*.*=)"
# define FOV 1.0f
# define PI 3.1416f
# define TEXTURE_SIZE 64

# define SUCCESS 0
# define FAILURE 1
# define ERR_ARG_COUNT 11
# define ERR_PARSE_FAIL 12
# define ERR_INFRA_FAIL 13

# define GREEN 1703705
# define YELLOW 16435200
# define BLUE 1645055
# define ORANGE 16416000

typedef struct s_asset t_asset;

typedef struct s_tile_info
{
	int				x;
	int				y;
	int				size;
	char			tile;
}					t_tile_info;

typedef struct s_pairf
{
    float x;
    float y;
}               t_pairf;

typedef struct s_dst_side
{
	int 	side;
	float	wall_dst;
}			t_dst_side;

typedef struct s_param_w
{
	t_asset 	*texture;
	t_dst_side  dst_side;
	float		texture_x;
	float		texture_pos;
	float		y;
	float		alpha;
}				t_param_w;


typedef struct s_square
{
	int				x;
	int				y;
	int				size;
	int				color;
}					t_square;

typedef struct s_img
{
	void			*new_img;
	char			*pix_grid;
	int				grid_len;
	int				bit_per_pix;
	int				endien;
}					t_img;

typedef struct s_asset
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}					t_asset;

typedef struct s_game_data
{
	struct s_data	*data;
	char			**map;
	int				map_width;
	int				map_height;
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	t_asset			tex_no;
	t_asset			tex_so;
	t_asset			tex_we;
	t_asset			tex_ea;
	int				floor_color;
	int				ceiling_color;
	// Joueur
	float			pos_x;
	float			pos_y;
	float			dir_x;
	float			dir_y;
	int				player_found;
	float			angle; //angle directeur
}					t_game_data;

typedef struct s_infra
{
	void			*mlx;
	void			*win;
	t_img			*img_now;
	t_img			*img_nxt;
	double			ratio;
	struct s_data	*data;
}					t_infra;

typedef struct s_data
{
	t_game_data		game;
	t_infra			infra;
}					t_data;

// PARSING
int					ft_first_parsing(char *filename, char ***file_lines_out);
int					ft_check_file_extension(const char *filename,
						const char *extension);
char				**ft_read_cub_file(const char *filename);
char				**read_lines_from_file(int fd);
// PARSING UTILS
char				**read_lines_from_file(int fd);
int					has_single_dot(const char *filename, int len_file);

//INITALIZATION
int					ft_second_parsing_and_init(char **file_lines,
						t_game_data *game);
int					parse_textures_and_colors(char **file_lines,
						t_game_data *game);
int					ft_parse_texture_line(char *line, t_game_data *game);
int					ft_parse_color_line(char *line, t_game_data *game);
int					parse_map_and_player(char **file_lines, t_game_data *game);
int					ft_set_texture(t_asset *dest, char *path_str,
						void *mlx_ptr);
int					ft_starts_with(const char *str, const char *prefix);
int					parse_map_and_player(char **file_lines, t_game_data *game);
int					scan_map(char **map, t_game_data *game);
int					extract_map(char **file_lines, char ***map_out);
int					is_line_part_of_map(char *line);
int					is_map_closed(char **map);
int					count_and_set_player(t_game_data *game, int y, int x,
						char c);
int					is_valid_player_char(char c);
int					get_map_width(char **map);
int					get_map_height(char **map);

//INITALIZATION UTILS
void				print_file_lines(char **lines);
int					ft_strarr_len(char **arr);
void				ft_free_strarr(char **arr);
int					ft_isdigit_str(const char *str);
int					ft_is_empty_line(const char *line);
int					ft_is_map_line(const char *line);
void				ft_strip_newline(char *s);

//ERROR AND FREE MANAGEMENT
int					ft_handle_error(int code);
void				free_file_lines(char **file_lines);
void				free_textures(t_game_data *game, void *mlx);
void				free_map(char **map);
int					ft_free_and_fail(char *tmp, char **split);
void				destroy_images_and_window(t_infra *infra);
void				free_mlx_and_data(t_infra *infra);

//INFRA
int					close_window(t_infra *infra);
int					handle_keypress(int keycode, t_infra *infra);
int					ft_init_infra(t_infra *infra);
void				ft_setup_hooks(t_data *data);

//GRID VIEW
void				draw_minimap(t_data *data);

//GRAPHIC N RENDER
int					what_color_is_this_pixel(double x, double y,
						t_infra *infra);
int					ft_render(t_data *data);
int 				ft_paint_the_wall(t_game_data *game);
void				put_pixel(t_img *image, int color, int x, int y);
int					move_down(t_infra *infra);
int					move_up(t_infra *infra);
int					move_right(t_infra *infra);
int					move_left(t_infra *infra);
int					move_turn(t_infra *infra, int keycode);
int					ft_is_it_a_wall(t_game_data *game, float x, float y);
int					ft_check_if_wall_to_redo(float dst, int color, t_game_data *game, int x);
void				free_file_lines_partial(char **lines, int count);
void    free_file_lines(char **file_lines);

#endif