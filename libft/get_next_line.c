/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:44:15 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/11 22:00:47 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *text)
{
	char	tmp_line[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	if (!text)
	{
		text = malloc(1);
		if (!text)
			return (NULL);
		*text = 0;
	}
	while (bytes_read > 0)
	{
		bytes_read = read(fd, tmp_line, BUFFER_SIZE);
		if (bytes_read == -1 || (bytes_read == 0 && text && !*text))
			return (free(text), NULL);
		if (bytes_read == 0)
			break ;
		tmp_line[bytes_read] = 0;
		text = join_free(text, tmp_line);
		if (line_len(text) < (int)ft_strlen(text) || (text && *text
				&& text[ft_strlen(text) - 1] == '\n'))
			break ;
	}
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;
	int			i;
	int			j;

	if (fd == -2)
		return (free(rest), NULL);
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	rest = read_line(fd, rest);
	if (!rest)
		return (NULL);
	i = line_len(rest);
	line = rest;
	if (i == (int)ft_strlen(rest))
		return (rest = NULL, line);
	rest = malloc(ft_strlen(rest) - i + 1);
	if (!rest)
		return (free(line), NULL);
	j = -1;
	while (line[i + ++j])
		rest[j] = line[i + j];
	rest[j] = 0;
	line[i] = 0;
	return (line);
}
