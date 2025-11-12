/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:12:32 by maanguit          #+#    #+#             */
/*   Updated: 2025/09/30 17:12:33 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
