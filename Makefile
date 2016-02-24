# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalama <asalama@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 12:14:52 by asalama           #+#    #+#              #
#    Updated: 2016/02/24 18:44:31 by asalama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Werror -Wextra

MLXFLAGS = -lmlx -framework OpenGL -framework Appkit

SRC = main.c		\
	  read_file.c 	\
	  fdf.c			\
	  calcul.c		\
	  zoom_relief.c	\
	  move.c		\
	  pro.c			\
	  rotate.c		\
	  key_hook.c	\

OBJ = $(addprefix $(OBJ_PATH), $(SRC:%.c=%.o))

HEADER_PATH = -I includes/

LIBFT_PATH = libft/libft.a

OBJ_PATH = ./OBJ/

.PHONY: clean fclean re all

all: $(SRC) $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C libft
	@$(CC) $(OBJ) $(MLXFLAGS) $(LIBFT_PATH) -o $(NAME)

$(OBJ_PATH)%.o : %.c
	@echo "\033[1;32m" "Compiling $< into $@" "\033[0m"
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(HEADER_PATH) -c $< -o $@

clean:
	@rm -rf $(OBJ_PATH)
	@$(MAKE) clean -C libft

fclean: clean
	@rm -rf $(NAME)

re: fclean all
