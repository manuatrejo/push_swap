/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 20:58:52 by manguita          #+#    #+#             */
/*   Updated: 2024/05/25 17:51:22 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
