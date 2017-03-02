# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atrepyto <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/12 19:12:54 by atrepyto          #+#    #+#              #
#    Updated: 2017/01/13 14:59:35 by atrepyto         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./check.c ./coordinates.c ./create.c ./main.c ./solve.c ./square.c \
	./ft_memset.c ./ft_putendl.c ./ft_strdel.c ./ft_strdup.c ./ft_strlen.c \
	./ft_strsub.c ./free.c

OBJ = $(SRC:.c=.o)	

CC = gcc

FLG = -Wall -Werror -Wextra

INC = ./

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o fillit

%.o: %.c
	$(CC) $(FLG) -I $(INC) -c $<

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
