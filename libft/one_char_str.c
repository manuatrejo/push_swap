/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_char_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:59:07 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/11 01:04:48 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	only_char_str(char *str, unsigned char c)
{
	while (*str)
	{
		if ((unsigned char)*str != c)
			return (0);
		str++;
	}
	return (1);
}
