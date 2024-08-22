# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vejurick <vejurick@student.42prague.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 14:21:14 by vejurick          #+#    #+#              #
#    Updated: 2024/08/22 21:12:29 by vejurick         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR = \033[0;34m
RESET_COLOR = \033[0m

NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = src/
INCDIR = include
OBJDIR = obj
LIBMLX = MLX42
LIBFT = ./libft/
LIBFT_FILE	=	libftprintf.a
LIBFT_LIB	=	$(addprefix $(LIBFT), $(LIBFT_FILE))
LIB_BREW = /Users/${USER}/.brew/Cellar/glfw/3.4/lib
HEADERS	= -I $(INCDIR) -I $(LIBMLX)/include
LIBFT_FLAGS = -L$(LIBFT)
LMX_FLAGS = -L$(LIBMLX)/build -L$(LIB_BREW) -lmlx42 -ldl -pthread -lglfw -lm
LIBS_FLAGS = $(LIBFT_FLAGS) $(LMX_FLAGS)
SRCS =  $(SRCDIR)/main.c  \
		$(SRCDIR)/error.c  \
		$(SRCDIR)/find_player_and_map_size.c  \
		$(SRCDIR)/map_checks.c  \
		$(SRCDIR)/mlx_actions.c  \
		$(SRCDIR)/parsing_floor_ceiling.c  \
		$(SRCDIR)/parsing_map.c  \
		$(SRCDIR)/parsing_textures.c  \
		$(SRCDIR)/parsing.c  \
		$(SRCDIR)/raycasting.c  \
		$(SRCDIR)/movement.c  \
		$(SRCDIR)/draw.c  \
		$(SRCDIR)/raycasting_utils.c  \

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@make -C $(LIBMLX)/build -j4
	@make -C $(LIBFT)
	@$(CC) $(OBJS) $(CFLAGS) $(LIBS_FLAGS) $(HEADERS) $(LIBFT_LIB) -o $(NAME)
	@echo "$(COLOR)Compiling and linking: done$(RESET_COLOR)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

clean:
	@rm -f $(OBJS)
	@rm -rf $(OBJDIR)
	@make -C $(LIBFT) clean
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean
	@echo "$(COLOR)Full clean: done$(RESET_COLOR)"

re: fclean all

.PHONY: all clean fclean re