# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mreveret <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/21 14:18:33 by mreveret          #+#    #+#              #
#    Updated: 2019/10/23 19:41:22 by mreveret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mreveret_filler

CFLAGS = -Wall -Wextra -Werror -I.

DIR = ./

PATH_SRC = ./

SRCS = $(PATH_SRC)filler.c \
	  $(PATH_SRC)main.c \
	  $(PATH_SRC)tabopti.c \
	  $(PATH_SRC)check_piece.c \
	  $(PATH_SRC)int_map.c \

OBJS = $(SRCS:.c=.o)

LIBFT_PATH = ./libft/

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	gcc $(CFLAGS) $(SRCS) -L./libft -lft -o $(NAME)

%.o: %.c
	gcc -o $@ -c $< $(CFLAGS)

clean:
	rm -f $(OBJS)
	rm -f libft/*.o
	rm -f libft/libft.a

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
