/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:18:00 by manguita          #+#    #+#             */
/*   Updated: 2024/05/25 19:13:54 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	int			len;
	char		s[12];
	long long	nbr;

	nbr = n;
	len = 0;
	if (nbr < 0)
		nbr *= -1;
	if (nbr == 0)
		write (fd, "0", 1);
	while (nbr != 0)
	{
		s[len++] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n < 0)
		write (fd, "-", 1);
	len--;
	while (len > -1)
		write (fd, &s[len--], 1);
}
