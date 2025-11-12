/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:09:41 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/11 00:45:38 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	result;
	int		a;
	int		sign;

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
			return (2147483648);
	}
	return (sign * result);
}
