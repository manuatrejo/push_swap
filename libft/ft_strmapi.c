/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:12:51 by maanguit          #+#    #+#             */
/*   Updated: 2025/09/30 17:12:52 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	a;
	unsigned char	*punt;

	a = 0;
	if (!s || !f)
		return (NULL);
	punt = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!punt)
		return (NULL);
	while (*s)
	{
		punt[a] = f(a, *s);
		s++;
		a++;
	}
	punt[a] = '\0';
	return ((char *)punt);
}
