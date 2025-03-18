/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:10:11 by manguita          #+#    #+#             */
/*   Updated: 2024/05/15 20:13:27 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
