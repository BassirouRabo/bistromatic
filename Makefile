# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brabo-hi <brabo-hi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 07:37:23 by brabo-hi          #+#    #+#              #
#    Updated: 2018/01/15 04:47:18 by brabo-hi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=calc
SRC=\
	add.c\
	addition.c\
	calcul.c\
	division.c\
	helper.c\
	init.c\
	main.c\
	modulos.c\
	multiplication.c\
	operate.c\
	parse.c\
	queue.c\
	set.c\
	shunting.c\
	stack.c\
	substraction.c\
	token.c\
	tools.c\
	util.c\
	validate.c

FLAGS=-Wextra -Wall -Werror -g
LIBFT=./libft

all:$(NAME)

$(NAME):
	@cd $(LIBFT) && make
	@gcc -c $(SRC) $(FLAGS)
	@gcc -g $(SRC:.c=.o) -o $(NAME) libft/libft.a

clean:
	@cd $(LIBFT) && make clean
	@/bin/rm -f $(SRC:.c=.o)

fclean: clean
	@cd $(LIBFT) && make fclean
	@/bin/rm -f $(NAME)

re: fclean
	@cd $(LIBFT) && make re
