/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 21:07:56 by manguita          #+#    #+#             */
/*   Updated: 2024/05/17 21:31:33 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
