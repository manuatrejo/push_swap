# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manguita <manguita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 18:52:57 by manguita          #+#    #+#              #
#    Updated: 2024/11/06 19:29:36 by manguita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = lists.c movements1.c\
		librería/libft.a

OBJ = $(SRC:.c=.o)

CC = gcc

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) :
	make all -C librería
	gcc $(CFLAGS) $(SRC) -o $(NAME)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)
	make clean -C librería

fclean: clean
	rm -f $(NAME)
	make fclean -C librería

re: fclean all
