/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 01:09:45 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/12 04:16:04 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	elm_lwr(t_lst *lst, int cont)
{
	while (lst)
	{
		if (lst->cont < cont)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	elm_bgr(t_lst *lst, int cont)
{
	while (lst)
	{
		if (lst->cont > cont)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int	optimal(t_lst **stk_a, t_lst **stk_b)
{
	if (!stk_a || !stk_b || !*stk_a || !*stk_b
		|| !(*stk_a)->next || !(*stk_b)->next)
		return (0);
	if ((*stk_a)->cont > (*stk_a)->next->cont
		&& (*stk_b)->cont < (*stk_b)->next->cont)
		return (ss(stk_a, stk_b), 1);
	return (0);
}
