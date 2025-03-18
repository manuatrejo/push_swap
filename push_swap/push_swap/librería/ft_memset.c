/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:32:23 by manguita          #+#    #+#             */
/*   Updated: 2024/05/15 18:39:28 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*memoria_s;

	memoria_s = (unsigned char *)s;
	while (n > 0)
	{
		*memoria_s = c;
		memoria_s++;
		n--;
	}
	return (s);
}
