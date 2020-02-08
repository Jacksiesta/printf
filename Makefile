# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jherrald <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/16 18:12:37 by jherrald          #+#    #+#              #
#    Updated: 2020/02/08 22:16:24 by jherrald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

LIBFT_P = libft_for_printf

SRC = libftprintf.c libftprintfspec.c convers_d.c convers_s.c convers_x.c

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

