/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 18:51:27 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/11 01:21:56 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_hexa(const char *str)
{
	long	result;
	int		a;

	result = 0;
	a = 0;
	while ((str[a] >= '0' && str[a] <= '9') || (str[a] >= 'a' && str[a] <= 'f')
		|| (str[a] >= 'A' && str[a] <= 'F'))
	{
		if (str[a] >= 'a' && str[a] <= 'f')
			result = result * 16 + str[a] - 'a' + 10;
		else if (str[a] >= 'A' && str[a] <= 'F')
			result = result * 16 + str[a] - 'A' + 10;
		else
			result = result * 16 + str[a] - '0';
		a++;
		if (result > INT_MAX || result < INT_MIN)
			return (0);
	}
	return (result);
}
