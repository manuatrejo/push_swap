/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:11:31 by maanguit          #+#    #+#             */
/*   Updated: 2025/09/30 17:11:32 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
