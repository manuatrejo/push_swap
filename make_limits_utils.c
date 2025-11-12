/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_limits_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:36:31 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/12 03:25:44 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	f_lim(t_lst *stack)
{
	t_lst	*temp;

	temp = stack;
	while (temp)
	{
		if (temp->flag == 1)
			return (temp->cont);
		temp = temp->next;
	}
	return (-1);
}

int	s_lim(t_lst *stack)
{
	t_lst	*temp;
	int		first;

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

int	put_flg(t_lst **stack, int index)
{
	t_lst	*temp;

	temp = *stack;
	while (temp)
	{
		if (index == temp->cont)
		{
			temp->flag = 1;
			return (index);
		}
		temp = temp->next;
	}
	return (-1);
}
