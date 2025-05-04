/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:55:58 by manguita          #+#    #+#             */
/*   Updated: 2025/05/04 19:40:59 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(const char *str, int *error)
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
		{
			write(1, "Error\n", 6);
			*error = 0;
		}
	}
	*error = 1;
	return (sign * result);
}
