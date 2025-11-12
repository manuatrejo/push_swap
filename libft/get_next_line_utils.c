/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:09:39 by maanguit          #+#    #+#             */
/*   Updated: 2025/10/21 00:01:50 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_free(char *text, char *to_add)
{
	char	*joined_str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	joined_str = malloc(ft_strlen(text) + ft_strlen(to_add) + 1);
	if (!joined_str)
		return (NULL);
	while (text[++i])
		joined_str[i] = text[i];
	while (to_add[++j])
		joined_str[i + j] = to_add[j];
	joined_str[i + j] = 0;
	free(text);
	return (joined_str);
}

int	line_len(char *prev_line)
{
	int	i;

	if (!prev_line || !*prev_line)
		return (0);
	i = 1;
	while (prev_line[i] && prev_line[i - 1] != '\n')
		i++;
	return (i);
}
