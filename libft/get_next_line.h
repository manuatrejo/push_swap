/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:40:43 by manguita          #+#    #+#             */
/*   Updated: 2025/05/01 22:00:41 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

void	*gnl_calloc(size_t number, size_t size);
void	*ft_bzero(void *s, size_t n);
char	*ft_strchr(const char *s, int c);
char	*gnl_strjoin(const char *s1, const char *s2);
size_t	gnl_strlen(const char *s);
char	*ft_joinfree(char *text, char *temp_line);
char	*read_line(int fd, char *text);
char	*get_line(char *text);
char	*rest(char *text);
char	*get_next_line(int fd);
#endif
