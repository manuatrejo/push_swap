/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:09:14 by manguita          #+#    #+#             */
/*   Updated: 2024/05/23 23:08:44 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	a;
	size_t	b;
	size_t	dstlen;

	dstlen = ft_strlen(dst);
	if (n <= ft_strlen(dst))
		return (n + ft_strlen(src));
	a = 0;
	b = 0;
	while (dst[a] && n > 1)
	{
		a++;
		n--;
	}
	while (src[b] && n > 1)
	{
		dst[a] = src[b];
		b++;
		a++;
		n--;
	}
	if (n != 0)
		dst[a] = '\0';
	return (ft_strlen(src) + dstlen);
}
