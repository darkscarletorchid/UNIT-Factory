# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrepyto <atrepyto@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/01 17:23:31 by atrepyto          #+#    #+#              #
#    Updated: 2017/04/29 15:56:00 by atrepyto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RTv1

SRC = ray.c render.c render_help.c vector.c main.c vector_calcul.c \
	  matrices.c image.c init_obj.c trace.c init_params.c

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
