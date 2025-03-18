/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:05:57 by manguita          #+#    #+#             */
/*   Updated: 2024/05/15 20:08:56 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
