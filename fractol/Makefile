# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/27 12:30:37 by atrepyto          #+#    #+#              #
#    Updated: 2017/02/28 16:19:30 by atrepyto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = ./main.c ./draw.c ./key_hooks.c ./fractals.c ./color.c ./mouse_hooks.c \
	  ./cantor_set.c ./threads.c

OBJ = $(SRC:.c=.o)

CC = gcc

FLGS = -Wall -Werror -Wextra

INC = ./

LIB =  -L ./libft/ -lft

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[1;5;34mCompiling started..."
	@echo "\033[1;33mCompiling library..."
	@make -C ./libft/
	@$(CC) -o $(NAME) $(OBJ) $(LIB) -lmlx -framework OpenGL -framework AppKit
	@echo "\033[1;32mReady to run"

%.o: %.c
	@$(CC) $(FLG) -I $(INC) -c $<

clean:
	@echo "\033[1;5;32mCleaned"
	@make -C ./libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@make -C ./libft/ fclean
	@rm -rf $(NAME)

re: fclean all
