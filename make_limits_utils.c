/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_limits_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:05:28 by manguita          #+#    #+#             */
/*   Updated: 2025/05/05 04:36:18 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_lim(t_list *stack)
{
	t_list	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->flag == 1)
			return (temp->cont);
		temp = temp->next;
	}
	return (-1);
}

int	s_lim(t_list *stack)
{
	t_list	*temp;
	int		first;
//si el primero es el mayor hay que ver si hay algun elemento con flag e índice mayor al primero 
	first = f_lim(stack);
	if (first == -1)
		return (-1);
	temp = stack;
	while (temp)
	{
		if (temp->flag == 1 && temp->cont != first)
			return (temp->cont);
		temp = temp->next;
	}
	return (-1);
}
