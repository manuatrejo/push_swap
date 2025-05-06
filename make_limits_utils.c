/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_limits_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 20:05:28 by manguita          #+#    #+#             */
/*   Updated: 2025/05/06 05:41:24 by manguita         ###   ########.fr       */
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

int	optimal(t_list **stk_a, t_list **stk_b)
{
	if (!stk_a || !stk_b || !*stk_a || !*stk_b
			|| !(*stk_a)->next || !(*stk_b)->next)
		return (0);
	if ((*stk_a)->cont > (*stk_a)->next->cont
			&& (*stk_b)->cont < (*stk_b)->next->cont)
		return (ss(stk_a, stk_b), 1);
	return (0);
}
