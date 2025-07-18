# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 15:01:27 by sabellil          #+#    #+#              #
#    Updated: 2025/07/16 18:17:02 by mairivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

COMPIL = cc
CFLAGS = -Wall -Wextra -Werror -g -I include -MD

SRC_DIR = src/
SRC_LIST = main.c \
			errors.c \
			free.c \
			game/draw_minimap.c \
			game/graphic.c \
			game/paint_walls.c \
			game/ray_casting_generator.c \
			game/handle_events.c \
			game/move_handlers.c \
			parsing/parse_and_init.c \
			parsing/init_parsing_utils.c \
			init/init_map.c \
			init/init_map_utils.c \
			init/init_utils.c \
			init/init_infra_and_buffer.c \
			init/handle_colors.c \
			init/handle_textures.c \
			init/handle_map.c \
			init/handle_map_utils.c \
			init/handle_player.c

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))

OBJ_DIR = obj/
OBJ_LIST = $(SRC_LIST:.c=.o)

OBJ = $(addprefix $(OBJ_DIR), $(OBJ_LIST))

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

MLX_DIR = minilibx-linux/
MLX = $(MLX_DIR)libmlx_Linux.a

all: $(MLX) $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	
$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(COMPIL) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -lXext -lX11 -lm -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(COMPIL) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) clean -C $(LIBFT_DIR) 

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
	
re: fclean all

val: 
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--gen-suppressions=all \
		--read-var-info=yes \
		--log-file=valgrind_report.log \
		./cub3d 

 valclean:
	rm -f valgrind_report.log

.PHONY: all clean fclean re val valclean

-include $(OBJ:.o=.d)
	