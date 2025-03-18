/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:33:44 by manguita          #+#    #+#             */
/*   Updated: 2024/05/25 22:21:41 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	setins1(char c, const char *set)
{
	int	d;

	d = 0;
	while (set[d])
		if (c == set[d++])
			return (1);
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	a;
	size_t	b;
	size_t	length;
	char	*punt;

	a = 0;
	b = 0;
	if (!s1)
		return (NULL);
	length = ft_strlen(s1);
	while (setins1(s1[a], set) && s1[a])
		a++;
	while (setins1(s1[length - 1], set) && (length > a))
		length--;
	punt = malloc(length + 1 - a);
	if (!punt)
		return (punt);
	while (length > a)
		punt[b++] = s1[a++];
	punt[b] = '\0';
	return (punt);
}
