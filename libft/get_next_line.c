/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 12:50:01 by manguita          #+#    #+#             */
/*   Updated: 2025/05/01 22:00:41 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_joinfree(char *text, char *temp_line)
{
	char	*joined_str;

	joined_str = gnl_strjoin(text, temp_line);
	free (text);
	return (joined_str);
}

char	*read_line(int fd, char *text)
{
	char	*temp_line;
	int		chars_read;

	if (!text)
		text = gnl_calloc(1, 1);
	temp_line = gnl_calloc(sizeof(char), BUFFER_SIZE + 1);
	chars_read = 1;
	while (chars_read > 0)
	{
		chars_read = read(fd, temp_line, BUFFER_SIZE);
		if (chars_read == -1)
		{
			free (temp_line);
			free (text);
			return (NULL);
		}
		temp_line[chars_read] = '\0';
		text = ft_joinfree (text, temp_line);
		if (ft_strchr (text, '\n'))
			break ;
	}
	free (temp_line);
	return (text);
}

char	*get_line(char *text)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!text)
		return (NULL);
	while (text[i] && text[i] != '\n')
		i++;
	temp = gnl_calloc(sizeof(char), i + 2);
	while (j < i)
	{
		temp[j] = text[j];
		j++;
	}
	if (text[j] == '\n')
		temp[j] = '\n';
	return (temp);
}

char	*rest(char *text)
{
	int		i;
	int		j;
	char	*rest_of_line;

	i = 0;
	j = 0;
	while (text[i] && text[i] != '\n')
		i++;
	if (text[i] == '\n')
		i++;
	while (text[i + j])
		j++;
	rest_of_line = gnl_calloc(sizeof(char), j + 1);
	j = 0;
	while (text[i])
		rest_of_line[j++] = text[i++];
	free (text);
	return (rest_of_line);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd == -1)
	{
		free(text);
		text = NULL;
		return (NULL);
	}
	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	text = read_line(fd, text);
	if (!text || *text == '\0')
	{
		free (text);
		text = NULL;
		return (NULL);
	}
	line = get_line(text);
	text = rest(text);
	return (line);
}
