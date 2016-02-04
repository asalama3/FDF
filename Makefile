# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asalama <asalama@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/04 12:14:52 by asalama           #+#    #+#              #
#    Updated: 2016/02/04 12:16:06 by asalama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF

CC = gcc

CFLAGS = -Wall -Werror -Wextra -lmlx -framework OpenGL -framework Appkit

SRC = main.c		\
	  read_file.c 	\

OBJ = $(addprefix $(OBJ_PATH), $(SRC:%.c=%.o))

HEADER_PATH = -I includes/

LIBFT_PATH = libft/libft.a

OBJ_PATH = ./OBJ/

.PHONY: clean fclean re all

all: $(SRC) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(LIBFT_PATH) -o $(name)
	@$(MAKE) -C libft

$(OBJ_PATH)%.o : %.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PATH)
	@$(MAKE) clean -C libft

fclean: clean
	rm -rf $(NAME)

re: fclean all
