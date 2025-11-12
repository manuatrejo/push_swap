/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:40:09 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/11 21:43:04 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest(t_lst *stk_a, int s_b)
{
	int	lowest;
	int	current;
	int	i;
	int	n;

	i = 1;
	lowest = 500;
	while (1)
	{
		n = 0;
		current = f_in(stk_a, s_b + i);
		while (++n < i)
		{
			if (current < f_in(stk_a, s_b + n)
				&& f_in(stk_a, s_b + n) < lowest)
				lowest = f_in(stk_a, s_b + n);
		}
		if (current > lowest || current == 0)
			break ;
		i++;
	}
	return (i - 1);
}

static void	manage_rotations(t_lst **stk_a, t_lst **stk_b, int *s_b, int bgst)
{
	while ((*stk_a)->cont < (*stk_b)->cont)
		rb(stk_a, stk_b, NULL);
	pb(stk_a, stk_b, s_b, NULL);
	while (!f_in(*stk_a, *s_b + 1) && *s_b + 1 <= bgst)
	{
		rrb(stk_b, NULL);
		(*s_b)++;
	}
}

void	aux_sort_ab(t_lst **stk_a, t_lst **stk_b, int *s_b, int *n_r)
{
	int	bgst_ind;
	int	highest;
	int	i;
	int	n;

	bgst_ind = 0;
	n = 0;
	i = find_highest(*stk_a, *s_b);
	highest = *s_b + i;
	while (++n < i)
		if (bgst_ind < f_in(*stk_a, *s_b + n))
			bgst_ind = f_in(*stk_a, *s_b + n);
	while (bgst_ind-- > 0)
	{
		if ((*stk_a)->cont <= highest)
			manage_rotations(stk_a, stk_b, s_b, highest);
		else
			ra(stk_a, stk_b, n_r);
	}
}
