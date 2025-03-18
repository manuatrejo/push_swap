/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:57:39 by manguita          #+#    #+#             */
/*   Updated: 2024/05/25 17:44:59 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*a;
	char	*b;

	if (!dest && !src)
		return (NULL);
	a = (char *)src;
	b = (char *)dest;
	while (n > 0)
	{
		*b = *a;
		a++;
		b++;
		n--;
	}
	return ((void *)dest);
}
