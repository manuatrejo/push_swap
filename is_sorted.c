/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:35:01 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/11 21:35:02 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_lst *list)
{
	if (list && !list->next)
		return (1);
	while (list->next)
	{
		if (list->cont + 1 != list->next->cont)
			return (0);
		list = list->next;
	}
	return (1);
}

int	b_is_sorted(t_lst *list)
{
	if (list && !list->next && list->cont == 0)
		return (1);
	while (list && list->next)
	{
		if (list->cont - 1 != list->next->cont)
			return (0);
		list = list->next;
	}
	if (list && list->cont != 0)
		return (0);
	return (1);
}
