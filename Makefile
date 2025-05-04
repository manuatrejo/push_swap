# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manguita <manguita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 18:16:26 by manguita          #+#    #+#              #
#    Updated: 2025/04/29 18:16:26 by manguita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

FLAGS = -Wall -Wextra -Werror -g3

SRCS = algorithm.c instructions_a.c instructions_b.c is_sorted.c lst_utils.c\
		movements.c main.c b_a.c a_b.c make_limits_utils.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cc $(FLAGS) -g $(OBJS) libft/libft.a -o $(NAME)

%.o: %.c
	cc $(FLAGS) -g -c $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re: fclean all
