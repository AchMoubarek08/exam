# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoubare <amoubare@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/27 09:43:56 by amoubare          #+#    #+#              #
#    Updated: 2022/11/01 23:44:05 by amoubare         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	ft_printf.c \
		ft_putnbr.c \
		ft_putchar.c ft_putstr.c ft_putnbr_hexa.c 

OBJ =	ft_printf.o \
		ft_putnbr.o \
		ft_putchar.o ft_putstr.o ft_putnbr_hexa.o

CC = gcc -Wall -Werror -Wextra -c

NAME = libftprintf.a

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(SRC)
	ar rc $(NAME) $(OBJ)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all


 