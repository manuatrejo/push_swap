/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:20:26 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/11 21:48:14 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_b_a(t_lst **stk_a, t_lst **stk_b, int *s_a, int *s_b)
{
	int	size;

	size = lst_size(*stk_a) + lst_size(*stk_b);
	size /= 2;
	size /= 2;
	while (*stk_b && (*stk_b)->cont > size)
	{
		sort_b_a(stk_a, stk_b, s_a, *s_b);
		aux_b_a(stk_a, stk_b, s_a, s_b);
	}
	sort_lowest(stk_a, stk_b, s_a, s_b);
}

void	sort_lowest(t_lst **stk_a, t_lst **stk_b, int *srt_a, int *srt_b)
{
	int	limit;
	int	size;

	while (lst_size(*stk_b) > 1 && !b_is_sorted(*stk_b))
	{
		limit = make_one_limit(stk_b);
		size = lst_size(*stk_b);
		while (size-- > 0 && !b_is_sorted(*stk_b))
		{
			if ((*stk_b && (*stk_b)->cont > limit))
				pa(stk_a, stk_b, srt_a, NULL);
			else if ((*stk_b)->cont <= limit)
				rb(stk_a, stk_b, NULL);
		}
	}
	if (*stk_b)
		*srt_b = (*stk_b)->cont;
}

void	three_b_a(t_lst **stk_a, t_lst **stk_b, int *s_a, int *s_b)
{
	while (*stk_b && (*stk_b)->cont > *s_b)
	{
		sort_b_a(stk_a, stk_b, s_a, *s_b);
		aux_b_a(stk_a, stk_b, s_a, s_b);
	}
}

void	aux_b_a(t_lst **stk_a, t_lst **stk_b, int *s_a, int *s_b)
{
	int	lims[3];
	int	n_rotates;

	n_rotates = 0;
	make_two_limits_ba(stk_b, *s_a, *s_b, lims);
	while (*stk_b && (*stk_b)->cont > lims[2] && (*stk_b)->cont > *s_b)
	{
		if ((*stk_b)->cont > lims[0])
			pa(stk_a, stk_b, s_a, NULL);
		else if (((*stk_b)->cont > lims[1] && !elm_bgr(*stk_b, lims[0]))
			|| ((*stk_b)->cont > lims[2] && !elm_bgr(*stk_b, lims[1])))
			pa(stk_a, stk_b, s_a, NULL);
		else if ((*stk_b)->cont <= lims[0])
			rb(stk_a, stk_b, &n_rotates);
	}
	while (n_rotates > 0 && *stk_b)
	{
		rrb(stk_b, &n_rotates);
		if ((*stk_b)->cont > lims[1])
			pa(stk_a, stk_b, s_a, NULL);
	}
	while (*stk_b && (*stk_b)->cont > lims[2] && (*stk_b)->cont > *s_b)
		pa(stk_a, stk_b, s_a, NULL);
}

void	sort_b_a(t_lst **stk_a, t_lst **stk_b, int *s_a, int s_b)
{
	int	n_r;
	int	ind_posit;
	int	n;

	n_r = 0;
	n = 50;
	while ((*stk_b && (*stk_a)->cont == *s_a && f_in(*stk_b, *s_a - 1) < n
			&& (*stk_b)->cont >= s_b) || n_r > 0)
	{
		ind_posit = f_in(*stk_b, (*s_a) - 1);
		if (ind_posit == 1)
			pa(stk_a, stk_b, s_a, NULL);
		else if (ind_posit == 2)
			sb(stk_a, stk_b);
		else if (n_r > 0)
			rrb(stk_b, &n_r);
		else if (ind_posit > 2 && ind_posit < n)
			aux_sort_ba(stk_a, stk_b, s_a, &n_r);
	}
}
