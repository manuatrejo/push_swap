/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:13:08 by maanguit          #+#    #+#             */
/*   Updated: 2025/09/30 17:13:09 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
