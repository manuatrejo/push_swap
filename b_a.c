/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_a.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:31:13 by manguita          #+#    #+#             */
/*   Updated: 2025/05/04 04:08:27 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	first_b_a(t_list **stk_a, t_list **stk_b, int **s_a, int **s_b)
{
	int	size;

	size = lst_size(*stk_a) + lst_size(*stk_b);
	size = size / 2 + size % 2;
	size = size / 2 + size % 2;
	while (*stk_b && (*stk_b)->cont > **s_b && (*stk_b)->cont > size)
	{
		while (short_group_b_a(stk_a, stk_b, s_a) == 1)
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
			if (lst_size(*stk_b) < 3)
				break ;
			if ((*stk_b)->cont >= limit)
				pa(stk_a, stk_b, srt_a, NULL);
			else
				rb(stk_b, NULL);
		}
	}
	if ((*stk_b)->next && (*stk_b)->cont < (*stk_b)->next->cont)
		sb(stk_b);
	**srt_b = (*stk_b)->cont;
}

void	three_b_a(t_list **stk_a, t_list **stk_b, int **s_a, int **s_b)
{
	while (*stk_b && (*stk_b)->cont > **s_b)
	{
		while (short_group_b_a(stk_a, stk_b, s_a))
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
		sort_b_a(stk_a, stk_b, s_a);
		if ((*stk_b)->cont > limits[0])
			pa(stk_a, stk_b, s_a, NULL);
		else
			rb(stk_b, &n_rotates);
	}
	to_push = n_rotates;
	while ((0 < n_rotates || to_push) && *stk_b && (*stk_b)->cont < **s_b)
	{
		if ((*stk_b)->cont > limits[1] || (to_push && n_rotates < 1))
			pa(stk_a, stk_b, s_a, &to_push);
		else if (n_rotates > 0)
			rrb(stk_b, &n_rotates);
	}
	free(limits);
}

void	sort_b_a(t_list **stk_a, t_list **stk_b, int **max)
{
	int	n_rot;
	int	ind_posit;

	n_rot = 0;
	while ((*stk_b && f_ind(*stk_b, (**max) - 1) < 6
			&& (*stk_a)->cont == **max) || n_rot != 0)
	{
		ind_posit = f_ind(*stk_b, (**max) - 1);
		if (ind_posit == 1)
			(pa(stk_a, stk_b, max, NULL), put_flag(stk_b, (**max) - 1));
		else if (ind_posit == 2)
			sb(stk_b);
		else if (ind_posit < 0 && ind_posit > -5)
			rrb(stk_b, &n_rot);
		else if (ind_posit > 2 && ind_posit < 6)
		{
			while (f_ind(*stk_b, (**max) - 1) != 1)
				rb(stk_b, &n_rot);
		}
		else if (n_rot < 0)
			rb(stk_b, &n_rot);
		else if (n_rot > 0)
			rrb(stk_b, &n_rot);
	}
}

int	short_group_b_a(t_list **stk_a, t_list **stk_b, int **s_a)
{
	t_list	*temp;
	int		bigger;
	int		i;

	temp = *stk_b;
	bigger = -1;
	i = 0;
	while (temp)
	{
		if (bigger != -1 && temp->flag == 1)
			break ;
		if (temp->flag == 1)
			bigger = temp->cont;
		i++;
		temp = temp->next;
	}
	if (i > 3)
		return (0);
	else
	{
		while (i--)
			pa(stk_a, stk_b, s_a, NULL);
		return (1);
	}
}
