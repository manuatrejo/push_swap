/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:01:36 by manguita          #+#    #+#             */
/*   Updated: 2024/05/25 23:58:16 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (d < s)
		return (ft_memcpy(d, s, n));
	while (n > 0)
	{
		d[n - 1] = s[n - 1];
		n--;
	}
	return (dest);
}
