# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jherrald <jherrald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/06 11:55:25 by jherrald          #+#    #+#              #
#    Updated: 2020/02/13 09:44:22 by jherrald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Werror -Wextra

NAME = libft.a

SRC = ft_atoi.c			ft_isdigit.c	ft_bzero.c		ft_isprint.c \
		ft_memset.c		ft_strchr.c		ft_strlen.c		ft_isalnum.c \
		ft_isalpha.c	ft_isascii.c	ft_tolower.c	ft_toupper.c	ft_strlcat.c \
		ft_strncmp.c	ft_strlcpy.c	ft_memccpy.c	ft_memchr.c		ft_strnstr.c \
		ft_memcpy.c		ft_substr.c		ft_strjoin.c	ft_strtrim.c \
		ft_memmove.c	ft_strdup.c		ft_putchar_fd.c	ft_calloc.c	\
		ft_putstr_fd.c	ft_putendl_fd.c	ft_putnbr_fd.c	ft_strmapi.c \
		ft_strrchr.c 	ft_itoa.c 		ft_memcmp.c 	ft_strlcpy.c 	ft_split.c \
		ft_putchar.c 	ft_str_upper.c 	ft_search_char.c \

SRC_B = ft_lstadd_back_bonus.c			ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c				ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c				ft_lstlast_bonus.c \
		ft_lstmap_bonus.c				ft_lstnew_bonus.c \
		ft_lstnew_bonus.c				ft_lstsize_bonus.c \

OBJ = $(SRC:.c=.o)

OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft.h
		ar rc $(NAME) $(OBJ) libft.h

bonus: $(OBJ_B) $(OBJ) libft.h
		ar rc $(NAME) $(OBJ) $(OBJ_B) libft.h

%.o: %.c
		$(CC) $(CCFLAGS) -c -o $@ $<

clean:
		rm -f $(OBJ) $(OBJ_B)

fclean: clean
		rm -f $(NAME)

re: fclean all
