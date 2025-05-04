/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:43:53 by manguita          #+#    #+#             */
/*   Updated: 2025/03/27 17:09:04 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static int	nstrings(const char *s, char c)
{
	int	count;
	int	a;

	count = 0;
	a = 0;
	while (s[a])
	{
		if (s[a] != c && (a == 0 || s[a - 1] == c))
			count++;
		a++;
	}
	return (count);
}

static int	ssl(const char *s, char c)
{
	int	length;

	length = 0;
	while (s[length] && s[length] != c)
		length++;
	return (length);
}

static char	**freeft(char **array, int x)
{
	while (x > 0)
	{
		x--;
		free(array[x]);
	}
	free(array);
	return (NULL);
}

static char	**stringss(char **array, const char *s, int n, char c)
{
	int	x;
	int	y;
	int	z;

	x = 0;
	z = 0;
	while (x < n && s[z])
	{
		while (c == s[z])
			z++;
		array[x] = (char *)malloc(sizeof(char) * (ssl(&s[z], c) + 1));
		if (!array[x])
			return (freeft(array, x));
		y = 0;
		while (s[z] != '\0' && s[z] != c)
		{
			array[x][y++] = s[z++];
		}
		array[x][y] = '\0';
		x++;
	}
	array[x] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	size_t	n;

	if (!s)
		return (NULL);
	n = nstrings(s, c);
	array = (char **)malloc(sizeof(char *) * (n + 1));
	if (!array)
		return (NULL);
	if (n == 0)
	{
		array[0] = NULL;
		return (array);
	}
	return (stringss(array, s, n, c));
}
