/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:13:13 by maanguit          #+#    #+#             */
/*   Updated: 2025/09/30 17:20:40 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_in_s(char c, const char *set)
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
	while (set_in_s(s1[a], set) && s1[a])
		a++;
	while (set_in_s(s1[length - 1], set) && (length > a))
		length--;
	punt = malloc(length + 1 - a);
	if (!punt)
		return (punt);
	while (length > a)
		punt[b++] = s1[a++];
	punt[b] = '\0';
	return (punt);
}
