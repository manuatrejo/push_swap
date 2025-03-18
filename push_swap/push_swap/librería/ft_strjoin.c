/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:24:54 by manguita          #+#    #+#             */
/*   Updated: 2024/05/15 20:30:41 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*punt;
	size_t	a;

	a = 0;
	punt = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!punt)
		return (punt);
	while (*s1)
	{
		punt[a] = *s1;
		s1++;
		a++;
	}
	while (*s2)
	{
		punt[a] = *s2;
		s2++;
		a++;
	}
	punt[a] = '\0';
	return (punt);
}
