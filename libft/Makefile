# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: manguita <manguita@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/16 20:45:00 by manguita          #+#    #+#              #
#    Updated: 2025/03/25 22:51:42 by manguita         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c\
	ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c\
	ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c\
	ft_strlcpy.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strlen.c\
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c\
	ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_strlcat.c ft_strrchr.c\
	get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

CC = cc

CCFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) libft.h
	ar rcs $(NAME) $(OBJ)

%.o: %.c libft.h get_next_line.h
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
