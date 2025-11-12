/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ba.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 06:19:17 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/12 02:07:35 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_lowest(t_lst *stk_b, int s_a)
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
		current = f_in(stk_b, s_a - i);
		while (++n < i)
		{
			if (current < f_in(stk_b, s_a - n)
				&& f_in(stk_b, s_a - n) < lowest)
				lowest = f_in(stk_b, s_a - n);
		}
		if (current > lowest || current == 0)
			break ;
		i++;
	}
	return (i - 1);
}

static int	rotate_find_biggest(t_lst *stk_b, int s_a, int n_r)
{
	int	biggest;
	int	current;
	int	i;
	int	n;

	i = 1;
	biggest = -1;
	while (1)
	{
		n = 0;
		current = f_in(stk_b, s_a - i);
		if (current - 1 < lst_size(stk_b) - n_r)
			break ;
		while (++n < i)
		{
			if (current > f_in(stk_b, s_a - n)
				&& f_in(stk_b, s_a - n) > biggest)
				biggest = f_in(stk_b, s_a - n);
		}
		if (current < biggest || current == 0)
			break ;
		i++;
	}
	return (i - 1);
}

static void	manage_rotations(t_lst **stk_a, t_lst **stk_b, int *s_a, int lowest)
{
	while ((*stk_a)->cont < (*stk_b)->cont)
		ra(stk_a, stk_b, NULL);
	pa(stk_a, stk_b, s_a, NULL);
	while (!f_in(*stk_b, *s_a - 1) && *s_a - 1 >= lowest)
	{
		rra(stk_a, stk_b, NULL);
		put_flg(stk_b, --(*s_a) - 1);
	}
}

void	aux_sort_ba(t_lst **stk_a, t_lst **stk_b, int *s_a, int *n_r)
{
	int	lowest;

	lowest = *s_a - find_lowest(*stk_b, *s_a);
	while (*s_a != lowest)
	{
		if ((*stk_b)->cont >= lowest)
			manage_rotations(stk_a, stk_b, s_a, lowest);
		else
			rb(stk_a, stk_b, n_r);
	}
	lowest = *s_a - rotate_find_biggest(*stk_b, *s_a, *n_r);
	while (*s_a != lowest && *n_r > 0)
	{
		rrb(stk_b, n_r);
		if ((*stk_b)->cont >= lowest)
			manage_rotations(stk_a, stk_b, s_a, lowest);
	}
}
