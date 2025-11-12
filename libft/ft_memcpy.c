/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:11:21 by maanguit          #+#    #+#             */
/*   Updated: 2025/10/01 18:27:37 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
