# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreveret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 19:22:00 by mreveret          #+#    #+#              #
#    Updated: 2019/11/25 19:23:39 by mreveret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mreveret.filler

CFLAGS = -Wall -Wextra -Werror -I.

DIR = ./

PATH_SRC = ./srcs/

SRCS =	$(PATH_SRC)filler.c \
		$(PATH_SRC)tabopti.c \
		$(PATH_SRC)map.c \
		$(PATH_SRC)check_pieces.c \
		$(PATH_SRC)main.c \

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	gcc $(CFLAGS) $(SRCS) -L./libft -lft -o $(NAME)

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS)

clean:
	rm -f srcs/*.o
	rm -f libft/*.o

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all

.PHONY: all clean fclean re
