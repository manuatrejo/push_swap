/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:55:58 by manguita          #+#    #+#             */
/*   Updated: 2024/05/23 23:24:58 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	long long	result;
	int			a;
	int			sign;

	sign = 1;
	result = 0;
	a = 0;
	while (str[a] == ' ' || (str[a] < 14 && str[a] > 8))
		a++;
	if (str[a] == '-')
		sign *= -1;
	if (str[a] == '+' || str[a] == '-')
		a++;
	while (str[a] >= '0' && str[a] <= '9')
	{
		result = result * 10 + str[a] - '0';
		a++;
		if (result * sign > INT_MAX || result * sign < INT_MIN)
			return (0);
	}
	return (sign * result);
}
