/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:06:25 by manguita          #+#    #+#             */
/*   Updated: 2025/05/02 04:06:26 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *list)
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

int	b_is_sorted(t_list *list)
{
	if (list && !list->next)
		return (1);
	while (list->next)
	{
		if (list->cont - 1 != list->next->cont)
			return (0);
		list = list->next;
	}
	return (1);
}
