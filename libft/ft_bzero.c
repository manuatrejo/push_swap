/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:09:48 by maanguit          #+#    #+#             */
/*   Updated: 2025/09/30 17:09:51 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
