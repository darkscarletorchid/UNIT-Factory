# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/01 13:04:37 by atrepyto          #+#    #+#              #
#    Updated: 2017/04/01 14:00:42 by atrepyto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRC = ./main.c ./map.c ./map_visualizer.c ./env.c ./events.c ./image.c \
	  ./error.c ./raycast.c ./keycodes.c ./start_page.c ./level2.c 

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

CC = gcc

INC = ./

LIB = -L ./libft/ -lft

MLX = -lmlx -framework OpenGL -framework AppKit

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "\033[1;34mCompiling started..."
	@echo "\033[33mCompiling library..."
	@make -C ./libft/
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(MLX)
	@echo "\033[32;05mReady to run"

%.o: %.c
	@$(CC) $(FLAGS) -I $(INC) -c $<

clean:
	@echo "\033[1;32mCleaned"
	@make clean -C ./libft/
	@rm -rf $(OBJ)

fclean: clean
	@make fclean -C./libft/
	@rm -rf $(NAME)

re: fclean all
