/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:05:17 by manguita          #+#    #+#             */
/*   Updated: 2024/05/23 22:33:55 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	a;

	a = 0;
	if (!dst || !src)
		return (ft_strlen(src));
	while (src[a] && n > 1)
	{
		dst[a] = src[a];
		a++;
		n--;
	}
	if (n > 0)
		dst[a] = '\0';
	return (ft_strlen(src));
}
