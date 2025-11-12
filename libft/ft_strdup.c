/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:12:14 by maanguit          #+#    #+#             */
/*   Updated: 2025/09/30 17:12:15 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*punt;
	size_t	a;

	a = 0;
	punt = malloc(ft_strlen(s) + 1);
	if (!punt)
		return (NULL);
	while (s[a] != '\0')
	{
		punt[a] = s[a];
		a++;
	}
	punt[a] = '\0';
	return (punt);
}
