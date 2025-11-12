/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:10:50 by maanguit          #+#    #+#             */
/*   Updated: 2025/09/30 17:10:51 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlength(int n)
{
	int			length;
	long long	aux;

	aux = n;
	length = 0;
	if (aux < 0)
	{
		aux *= -1;
		length++;
	}
	if (aux == 0)
		return (1);
	while (aux > 0)
	{
		aux /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	size_t		a;
	size_t		b;
	char		*punt;
	long long	nbr;

	a = 0;
	nbr = n;
	b = intlength(n);
	punt = malloc(b + 1);
	if (!punt)
		return (NULL);
	if (nbr < 0)
		nbr *= -1;
	if (n < 0)
		punt[0] = '-';
	if (nbr == 0)
		punt[0] = '0';
	while (nbr != 0)
	{
		punt[(b - 1) - a] = nbr % 10 + '0';
		nbr /= 10;
		a++;
	}
	punt[b] = '\0';
	return (punt);
}
