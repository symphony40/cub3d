# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjuricko <vjuricko@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 12:18:07 by vjuricko          #+#    #+#              #
#    Updated: 2024/06/12 11:08:33 by vjuricko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= libftprintf.a
INCLUDE		= include
LIBFT		= libft
SRC_DIR		= src/
OBJ_DIR		= obj/
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I

SRC_FILES	=	ft_printf handle_x handle_p handle_i handle_s handle_u get_next_line get_next_line_utils


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))


OBJF		=	.cache_exists

all:		$(NAME)

$(NAME):	$(OBJ)
			make -C $(LIBFT)
			cp libft/libft.a .
			mv libft.a $(NAME)
			ar -rcs $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJF)
			$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJF):
			mkdir -p $(OBJ_DIR)

clean:
			rm -rf $(OBJ_DIR)
			make clean -C $(LIBFT)

fclean:		clean
			rm -rf $(NAME)
			rm -rf $(LIBFT)/libft.a

re:			fclean all
