/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:10:01 by maanguit          #+#    #+#             */
/*   Updated: 2025/10/08 22:31:23 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	void	*punt;

	punt = malloc(number * size);
	if (punt)
	{
		ft_bzero(punt, (number * size));
		return (punt);
	}
	return (NULL);
}
