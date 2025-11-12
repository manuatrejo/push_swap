/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:11:07 by maanguit          #+#    #+#             */
/*   Updated: 2025/09/30 18:06:15 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*string1;
	const unsigned char	*string2;
	unsigned int		a;

	a = 0;
	string1 = (const unsigned char *)s1;
	string2 = (const unsigned char *)s2;
	while (n > 0 && string1[a] == string2[a])
	{
		n--;
		a++;
	}
	if (n == 0)
		return (0);
	return (string1[a] - string2[a]);
}
