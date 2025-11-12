/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:13:01 by maanguit          #+#    #+#             */
/*   Updated: 2025/10/07 19:32:41 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;

	a = 0;
	if (!needle[a] || !needle)
		return ((char *)haystack);
	while (haystack[a] && len > a)
	{
		b = 0;
		while (haystack[a + b] == needle[b] && len > a + b)
		{
			if (needle[b + 1] == '\0')
				return ((char *)&haystack[a]);
			b++;
		}
		a++;
	}
	return (NULL);
}
