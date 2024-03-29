# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 21:40:48 by oelazzou          #+#    #+#              #
#    Updated: 2019/05/28 02:03:34 by mel-idri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = 	draw_solution.c \
		error.c \
		main.c \
		parse_tetriminos.c \
		read.c \
		solve_puzzle.c \
		util.c \
		validate.c
OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wextra -Wall -Werror 

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft re
	$(CC) $(FLAGS) $(OBJ) -L libft -lft -o $(NAME)
$(OBJ): $(SRC)
	make -C libft re
	$(CC) $(FLAGS) -c $(SRC)
clean:
	make -C libft clean
	rm -f $(OBJ)
fclean:
	make -C libft fclean
	rm -f $(NAME) $(OBJ)
re: fclean all
