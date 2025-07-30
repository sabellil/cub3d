# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 15:01:27 by sabellil          #+#    #+#              #
#    Updated: 2025/07/30 13:04:51 by mairivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
BONUS_NAME	= cub3D_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -I include -MD
RM			= rm -f

SRC_PATH	= src
OBJ_PATH	= obj

LIBFT_DIR	= libft
MLX_DIR		= minilibx-linux
LIBFT		= $(LIBFT_DIR)/libft.a
MLX			= $(MLX_DIR)/libmlx_Linux.a

SRC =	main.c \
		errors.c \
		free.c \
		game/utils.c \
		game/get_dda_data.c \
		game/get_impact_data.c \
		game/get_ray_data.c \
		game/paint_walls.c \
		game/paint_image_and_render.c \
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

SRC_BONUS = main.c \
		errors.c \
		free.c \
		bonus/draw_minimap_bonus.c \
		game/utils.c \
		game/get_dda_data.c \
		game/get_impact_data.c \
		game/get_ray_data.c \
		game/paint_walls.c \
		bonus/paint_image_and_render_bonus.c \
		game/handle_events.c \
		bonus/move_handlers_bonus.c \
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

OBJS		= $(addprefix $(OBJ_PATH)/, $(SRC:.c=.o))
OBJS_BONUS	= $(addprefix $(OBJ_PATH)/, $(SRC_BONUS:.c=.o))

all: $(LIBFT) $(MLX) $(NAME)

bonus: $(LIBFT) $(MLX) $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) -lXext -lX11 -lm -o $(NAME)

$(BONUS_NAME): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) -lXext -lX11 -lm -o $(BONUS_NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) -r $(OBJ_PATH)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

val:
	valgrind \
		--leak-check=full \
		--show-leak-kinds=all \
		--track-origins=yes \
		--gen-suppressions=all \
		--read-var-info=yes \
		./$(NAME)

valclean:
	$(RM) valgrind_report.log

.PHONY: all bonus clean fclean re val valclean

-include $(OBJS:.o=.d)
-include $(OBJS_BONUS:.o=.d)
