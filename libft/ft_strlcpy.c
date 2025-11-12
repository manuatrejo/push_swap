/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:12:37 by maanguit          #+#    #+#             */
/*   Updated: 2025/09/30 17:12:38 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
