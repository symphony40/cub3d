# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 14:21:14 by vejurick          #+#    #+#              #
#    Updated: 2024/07/30 17:44:24 by vejurick         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
CC			=	cc
FLAG		=	-Wall -Wextra -Werror
LIBFT_PATH	=	./libft/
LIBFT_FILE	=	libftprintf.a
MLX_FILE	=	libmlx.a
LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))
MLX_FLAG	=	-lX11 -lXext
MLX_PATH	=	./minilibx-linux/
MLX_LIB		=	$(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_EX		=	$(MLX_LIB) $(MLX_FLAG)
C_FILE		=	main.c parsing.c error.c parsing_floor_ceiling.c parsing_map.c parsing_textures.c find_player_and_map_size.c
SRC_DIR		=	./src/
INC_DIR		=	./include/
SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))
OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@

all: $(NAME)

lib:
	make -C $(LIBFT_PATH)

mlx:
	make -sC $(MLX_PATH)

$(NAME): lib mlx $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)

clean:
	make clean -sC $(LIBFT_PATH)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_PATH)

re: fclean all

.PHONY: all clean fclean re