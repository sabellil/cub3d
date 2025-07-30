/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cubed_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 15:41:55 by mairivie          #+#    #+#             */
/*   Updated: 2025/07/30 14:33:30 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBED_BONUS_H
# define CUBED_BONUS_H

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
# define MAX_MAP_WIDTH 25
# define MAX_MAP_HEIGHT 25
# define VERTI_Y 1
# define HORIZ_H 0
# define COLOR_WALL 0x222222
# define COLOR_FLOOR 0xFFFFFF
# define COLOR_UNKNOWN 0x888888
# define COLOR_PLAYER_DOT 0xFF0000
# define SUCCESS 0
# define FAILURE 1
# define ERR_ARG_COUNT 11
# define ERR_PARSE_FAIL 12
# define ERR_INFRA_FAIL 13

# define GREEN 1703705
# define YELLOW 16435200
# define BLUE 1645055
# define ORANGE 16416000
# define COLOR_INVALID 0 
//# define COLOR_INVALID 0xFF00FF // rose vif pour debug

typedef struct s_asset	t_asset;

typedef struct s_tile_info
{
	int					x;
	int					y;
	int					size;
	char				tile;
}						t_tile_info;

typedef struct s_pairf
{
	float				x;
	float				y;
}						t_pairf;

typedef struct s_impact_data 
{
	int					axis_hit;
	float				wall_dst;
	t_pairf				hit;
}						t_impact_data;

typedef struct s_ray_data
{
	t_asset 		*texture;
	t_impact_data	impact;
	float			texture_x; 
	float			tex_x_pos;
	float			x_img;
	float			alpha;
}					t_ray_data;

typedef struct s_data_dda
{
	t_pairf				map_case;
	t_pairf				dir;
	t_pairf				step;
	t_pairf				delta_dist;
	t_pairf				wall_dist_on;
}						t_data_dda;

typedef struct s_square
{
	int					x;
	int					y;
	int					size;
	int					color;
}						t_square;

typedef struct s_img
{
	void				*new_img;
	char				*pix_grid;
	int					grid_len;
	int					bit_per_pix;
	int					endien;
}						t_img;

typedef struct s_asset
{
	void				*img;
	char				*addr;
	int					bpp;
	int					line_len;
	int					endian;
	int					width;
	int					height;
}						t_asset;

typedef struct s_game_data
{
	struct s_data		*data;
	char				**map;
	int					map_width;
	int					map_height;
	char				*path_no;
	char				*path_so;
	char				*path_we;
	char				*path_ea;
	t_asset				tex_no;
	t_asset				tex_so;
	t_asset				tex_we;
	t_asset				tex_ea;
	int					floor_color;
	int					ceiling_color;
	float				pos_x;
	float				pos_y;
	float				dir_x;
	float				dir_y;
	int					player_found;
	float				angle;
}						t_game_data;

typedef struct s_infra
{
	void				*mlx;
	void				*win;
	t_img				*img_now;
	t_img				*img_nxt;
	double				ratio;
	struct s_data		*data;
}						t_infra;

typedef struct s_data
{
	t_game_data			game;
	t_infra				infra;
}						t_data;

// PARSING
int						ft_first_parsing(char *filename,
							char ***file_lines_out);
int						ft_check_file_extension(const char *filename,
							const char *extension);
char					**ft_read_cub_file(const char *filename);
char					**read_lines_from_file(int fd);
int						ft_is_map_lines_in_cub(const char *line);
// PARSING UTILS
char					**read_lines_from_file(int fd);
int						has_single_dot(const char *filename, int len_file);

// INITALIZATION
void					init_game_data(t_game_data *game);
int						ft_second_parsing_and_init(char **file_lines,
							t_game_data *game);
int						parse_textures_and_colors(char **file_lines,
							t_game_data *game);
int						ft_parse_texture_line(char *line, t_game_data *game);
int						ft_parse_color_line(char *line, t_game_data *game);
int						parse_map_and_player(char **file_lines,
							t_game_data *game);
int						ft_set_texture(t_asset *dest, char *path_str,
							void *mlx_ptr);
int						ft_starts_with(const char *str, const char *prefix);
int						parse_map_and_player(char **file_lines,
							t_game_data *game);
int						scan_map(char **map, t_game_data *game);
int						extract_map(char **file_lines, char ***map_out);
int						is_line_part_of_map(char *line);
int						is_map_closed(char **map);
int						count_and_set_player(t_game_data *game, int y, int x,
							char c);
int						is_valid_player_char(char c);
int						get_map_width(char **map);
int						get_map_height(char **map);

// INITALIZATION UTILS
int						ft_strarr_len(char **arr);
void					ft_free_strarr(char **arr);
int						ft_isdigit_str(const char *str);
int						ft_is_empty_line(const char *line);
int						ft_is_map_line(const char *line);
void					ft_strip_newline(char *s);

// ERROR AND FREE MANAGEMENT
int						ft_handle_error(int code);
void					free_file_lines(char **file_lines);
void					free_textures(t_game_data *game, void *mlx);
void					free_map(char **map);
int						ft_free_and_fail(char *tmp, char **split);
void					destroy_images_and_window(t_infra *infra);
void					free_mlx_and_data(t_infra *infra);
void					free_file_lines_partial(char **lines, int count);
void					free_file_lines(char **file_lines);

// INFRA
int						close_window(t_infra *infra);
int						handle_keypress(int keycode, t_infra *infra);
int						ft_init_infra(t_infra *infra);
void					ft_setup_hooks(t_data *data);

// GRID VIEW
void					draw_minimap(t_data *data);

// MOVE
int						move_down(t_infra *infra);
int						move_up(t_infra *infra);
int						move_right(t_infra *infra);
int						move_left(t_infra *infra);
int						move_turn(t_infra *infra, int keycode);

// STRUCTURE TOOLS
t_data_dda				init_data_dda(float alpha, float *curr_x,
							float *curr_y);
t_ray_data				*get_ray_data_to_draw_wall_line(t_game_data *game,
							float alpha_tmp, float y);
t_impact_data			get_impact_data_with_dda(t_game_data *game, float alpha,
							float *curr_x, float *curr_y);
void 					fill_impact_data(t_data_dda d, t_impact_data *impact,
							float *curr_x, float *curr_y);
t_asset					*get_texture_by_orientation(t_game_data *game,
							int axis_hit, float alpha);

// RAYCASTING
int						ft_render(t_data *data);
int						paint_the_wall(t_game_data *game);
void					put_pixel(t_img *image, int color, int x, int y);
unsigned int			what_color_is_hit_pixel(t_asset *texture, int hit_x,
							int hit_y);
int						draw_wall_line_with_texture(t_game_data *game,
							float angle_tmp, float x_img);

#endif