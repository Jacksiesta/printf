# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jherrald <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 18:12:37 by jherrald          #+#    #+#              #
#    Updated: 2020/01/28 16:42:08 by jherrald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

LIBFT_P = libft_for_printf

SRC = libftprintf.c libftprintfspec.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ) libftprintf.h
	make -C $(LIBFT_P) all
	cp $(LIBFT_P)/libft.a $(NAME)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	make -C $(LIBFT_P) clean
	rm -f $(OBJ)

fclean: clean
	rm -rf $(NAME)
	rm -rf $(LIBFT_P)/libft.a

re: fclean all

