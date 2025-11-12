/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:12:25 by maanguit          #+#    #+#             */
/*   Updated: 2025/09/30 17:12:26 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
