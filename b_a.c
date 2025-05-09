/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:31:13 by manguita          #+#    #+#             */
/*   Updated: 2025/05/06 06:04:55 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_b_a(t_list **stk_a, t_list **stk_b, int **s_a, int **s_b)
{
	int	size;

	size = lst_size(*stk_a) + lst_size(*stk_b);
	size = size / 2 + size % 2;
	size = size / 2 + size % 2;
	while (*stk_b && (*stk_b)->cont > size)
	{
		sort_b_a(stk_a, stk_b, s_a, s_b);
		while (short_group_b_a(stk_a, stk_b, s_a, s_b) == 1)
			;
		aux_b_a(stk_a, stk_b, s_a, s_b);
	}
	sort_lowest(stk_a, stk_b, s_a, s_b);
}

void	sort_lowest(t_list **stk_a, t_list **stk_b, int **srt_a, int **srt_b)
{
	int	limit;
	int	size;

	while (lst_size(*stk_b) > 2)
	{
		limit = make_one_limit(stk_b, **srt_a, **srt_b);
		size = lst_size(*stk_b);
		while (size-- > -1)
		{
			if (lst_size(*stk_b) < 2)
				break ;
			if ((*stk_b && (*stk_b)->cont > limit) || ((*stk_b)->cont != 0
					&& lst_size(*stk_b) < 4))
				pa(stk_a, stk_b, srt_a, NULL);
			else
				rb(stk_a, stk_b, NULL);
		}
	}
	if (*stk_b)
		**srt_b = (*stk_b)->cont;
	sort_b_a(stk_a, stk_b, srt_a, srt_b);
}

void	three_b_a(t_list **stk_a, t_list **stk_b, int **s_a, int **s_b)
{
	while (*stk_b && (*stk_b)->cont > **s_b)
	{
		sort_b_a(stk_a, stk_b, s_a, s_b);
		while (short_group_b_a(stk_a, stk_b, s_a, s_b))
			;
		aux_b_a(stk_a, stk_b, s_a, s_b);
	}
}

void	aux_b_a(t_list **stk_a, t_list **stk_b, int **s_a, int **s_b)
{
	int	*limits;
	int	n_rotates;
	int	to_push;

	n_rotates = 0;
	limits = ft_calloc(sizeof(int), 3);
	make_two_limits(stk_b, **s_a, **s_b, &limits);
	while (*stk_b && (*stk_b)->cont > limits[2] && (*stk_b)->cont > **s_b)
	{
		sort_b_a(stk_a, stk_b, s_a, s_b);
		if ((*stk_b)->cont > limits[0])
			pa(stk_a, stk_b, s_a, NULL);
		else if ((*stk_b)->cont <= limits[0])
			rb(stk_a, stk_b, &n_rotates);
	}
	to_push = n_rotates;
	while ((n_rotates > 0 || to_push) && *stk_b)
	{
		if (n_rotates > 0)
			rrb(stk_a, stk_b, &n_rotates);
		if ((*stk_b)->cont > limits[1] || (to_push && n_rotates < 1))
			pa(stk_a, stk_b, s_a, &to_push);
	}
	free(limits);
}

void	sort_b_a(t_list **stk_a, t_list **stk_b, int **s_a, int **s_b)
{
	int	n_r;
	int	ind_posit;
	int	n;

	n_r = 0;
	n = 25;
	while ((*stk_b && (*stk_a)->cont == **s_a && f_in(*stk_b, **s_a - 1) < n
			&& (*stk_b)->cont >= **s_b) || n_r > 0)
	{
		ind_posit = f_in(*stk_b, (**s_a) - 1);
		if (ind_posit == 1 && (**s_a == (**s_b) + 1 || (*stk_b)->cont > **s_b))
			pa(stk_a, stk_b, s_a, NULL);
		else if (ind_posit == 2)
			sb(stk_a, stk_b);
		else if (ind_posit > 2 && ind_posit < n)
		{
			while (f_in(*stk_b, (**s_a) - 1) != 1)
				rb(stk_a, stk_b, &n_r);
		}
		else if (n_r > 0)
			rrb(stk_a, stk_b, &n_r);
	}
}

int	short_group_b_a(t_list **stk_a, t_list **stk_b, int **s_a, int** s_b)
{
	int		i;
	
	if (*stk_b && (*stk_b)->cont <= **s_b)
		return (0);
	sort_b_a(stk_a, stk_b, s_a, s_b);
	if (s_lim(*stk_b) < 0)
		return (0);
	i = f_lim(*stk_b) - s_lim(*stk_b);
	if (i < 4)
	{
		while (i-- && (*stk_b)->cont > **s_b)
			pa(stk_a, stk_b, s_a, NULL);
		return (1);
	}
	return (0);
}
