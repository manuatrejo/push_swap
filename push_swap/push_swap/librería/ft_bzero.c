/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:45:42 by manguita          #+#    #+#             */
/*   Updated: 2024/05/23 20:58:05 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

void	*ft_bzero(void *s, size_t n)
{
	char	*memoria_s;

	memoria_s = (char *)s;
	while (n > 0)
	{
		*memoria_s = 0;
		memoria_s++;
		n--;
	}
	return (s);
}
