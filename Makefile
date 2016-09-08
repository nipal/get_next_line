# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjanoty <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/05 14:59:47 by fjanoty           #+#    #+#              #
#    Updated: 2016/09/08 01:10:25 by fjanoty          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	test_gnl
SRC 	=	get_next_line.c \
			main.c

all :
		rm -rf $(NAME)
#		cd libft ; make re;
		gcc -Wall -Wextra -Werror $(SRC) libft/libft.a -I libft -o $(NAME)

clean :
		rm -rf *.o

fclean : clean
		rm -rf $(NAME)

re : fclean all

