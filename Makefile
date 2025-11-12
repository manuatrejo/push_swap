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

BONUS = checker

FLAGS = -Wall -Wextra -Werror -g3

SRCS = algorithm.c instructions_a.c instructions_b.c is_sorted.c lst_utils.c\
		movements.c main.c b_a.c a_b.c make_limits_utils.c alg_utils.c \
		sort_ba.c sort_ab.c check_input.c

SRCS_BONUS = check_input.c checker_bonus.c movements.c is_sorted.c lst_utils.c\
		make_limits_utils.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	cc $(FLAGS) $(OBJS) libft/libft.a -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(OBJS_BONUS)
	make -C libft
	cc $(FLAGS) $(OBJS_BONUS) libft/libft.a -o $(BONUS)

%.o: %.c
	cc $(FLAGS)  -c $< -o $@

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME)
	$(RM) $(BONUS)
	make fclean -C libft

re: fclean all
