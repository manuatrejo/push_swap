/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:20:05 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/11 22:32:07 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_to_b(t_lst **stk_a, t_lst **stk_b, int *s_a)
{
	int	limit1;
	int	limit2;
	int	to_push;

	limit1 = make_one_limit(stk_a);
	limit2 = limit1 / 2;
	to_push = limit1 + 1;
	put_flg(stk_a, limit2);
	while (to_push > 0)
	{
		if ((*stk_a)->cont > limit1)
			ra(stk_a, stk_b, NULL);
		else if ((*stk_a)->cont <= limit1 && (*stk_a)->cont > limit2)
			pb(stk_a, stk_b, NULL, &to_push);
		else if ((*stk_a)->cont <= limit2)
		{
			pb(stk_a, stk_b, NULL, &to_push);
			if ((*stk_a)->cont > limit1 && (*stk_b)->next)
				rr(stk_a, stk_b);
			else
				rb(stk_a, stk_b, NULL);
		}
	}
	sort_biggest(stk_a, stk_b, s_a);
}

void	sort_biggest(t_lst **stk_a, t_lst **stk_b, int *s_a)
{
	int	limit;
	int	size;

	while (lst_size(*stk_a) > 1 && !is_sorted(*stk_a))
	{
		limit = make_one_limit(stk_a);
		size = lst_size(*stk_a);
		while (size-- > 0 && !is_sorted(*stk_a))
		{
			if ((*stk_a)->cont <= limit)
				pb(stk_a, stk_b, NULL, NULL);
			else if ((*stk_a)->cont > limit)
				ra(stk_a, stk_b, NULL);
		}
	}
	*s_a = (*stk_a)->cont;
	put_flg(stk_b, (*s_a));
}

void	three_a_b(t_lst **stk_a, t_lst **stk_b, int *sort_a, int *sort_b)
{
	while (*stk_a && (*stk_a)->cont < *sort_a)
	{
		sort_a_b(stk_a, stk_b, *sort_a, sort_b);
		aux_a_b(stk_a, stk_b, sort_a, sort_b);
	}
}

void	aux_a_b(t_lst **stk_a, t_lst **stk_b, int *s_a, int *s_b)
{
	int	lims[3];
	int	n_rotates;

	n_rotates = 0;
	make_two_limits_ab(stk_a, *s_a, *s_b, lims);
	while (*stk_a && (*stk_a)->cont < lims[2] && (*stk_a)->cont < *s_a)
	{
		if ((*stk_a)->cont <= lims[1])
			pb(stk_a, stk_b, s_b, NULL);
		else if (((*stk_a)->cont <= lims[0] && !elm_lwr(*stk_a, lims[1] + 1))
			|| ((*stk_a)->cont < lims[2] && !elm_lwr(*stk_a, lims[0] + 1)))
			pb(stk_a, stk_b, s_b, NULL);
		else if ((*stk_a)->cont > lims[1])
			ra(stk_a, stk_b, &n_rotates);
	}
	while (n_rotates > 0 && *stk_a)
	{
		rra(stk_a, stk_b, &n_rotates);
		if ((*stk_a)->cont <= lims[0])
			pb(stk_a, stk_b, s_b, NULL);
	}
	while (*stk_a && (*stk_a)->cont < lims[2] && (*stk_a)->cont < *s_a)
		pb(stk_a, stk_b, s_b, NULL);
}

void	sort_a_b(t_lst **stk_a, t_lst **stk_b, int s_a, int *s_b)
{
	int	n_r;
	int	ind_posit;
	int	n;

	n_r = 0;
	n = 15;
	while ((*stk_b && f_in(*stk_a, (*s_b) + 1) < n && (*stk_a)->cont < s_a
			&& (*stk_b)->cont == *s_b) || n_r > 0)
	{
		ind_posit = f_in(*stk_a, (*s_b) + 1);
		if (ind_posit == 1 && (*stk_a)->cont < s_a)
			pb(stk_a, stk_b, s_b, NULL);
		else if (ind_posit == 2)
			sa(stk_a, stk_b);
		else if (n_r > 0)
			rra(stk_a, stk_b, &n_r);
		else if (ind_posit > 2 && ind_posit < n)
			aux_sort_ab(stk_a, stk_b, s_b, &n_r);
	}
}
