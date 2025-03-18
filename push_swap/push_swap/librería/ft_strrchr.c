/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 23:59:43 by manguita          #+#    #+#             */
/*   Updated: 2024/05/26 00:15:13 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	uc;
	int				len;

	uc = c;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == uc)
			return ((char *)&s[len]);
		len--;
	}
	return (NULL);
}
