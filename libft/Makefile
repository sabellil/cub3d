# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 13:02:42 by mairive           #+#    #+#              #
#    Updated: 2025/01/24 15:57:30 by mairivie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME = libft.a

COMPIL = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC_DIR = source_libft/
SRC_LIST = ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isprint.c ft_isascii.c \
           ft_memcpy.c ft_memmove.c ft_memset.c ft_memchr.c ft_memcmp.c \
           ft_bzero.c ft_strlcat.c ft_strlcpy.c \
           ft_strlen.c ft_strncmp.c ft_strchr.c ft_strrchr.c ft_strnstr.c \
           ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
           ft_toupper.c ft_tolower.c ft_atoi.c ft_itoa.c \
           ft_calloc.c ft_strdup.c ft_strjoin.c ft_strtrim.c ft_split.c \
           ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c get_next_line.c \
           get_next_line_utils.c ft_printf.c print_numbers.c print_txt.c \
           ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
           ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
           ft_lstmap.c ft_striteri.c ft_strmapi.c 

# BONUS_SRC_LIST =

SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
# BONUS_SRC = $(addprefix $(SRC_DIR), $(BONUS_SRC_LIST))

OBJ_DIR = obj/
OBJ_LIST = $(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))
# BONUS_OBJ_LIST = $(addprefix $(OBJ_DIR), $(BONUS_SRC_LIST:.c=.o))

# Règles

all: $(NAME)

$(NAME): $(OBJ_LIST)
	ar rc $(NAME) $^

# bonus: $(BONUS_OBJ_LIST)
# 	ar rc $(NAME) $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(COMPIL) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
