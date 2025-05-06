/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:31:54 by manguita          #+#    #+#             */
/*   Updated: 2025/05/06 06:05:09 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_to_b(t_list **stk_a, t_list **stk_b, int **s_a, int **s_b)
{
	int	limit1;
	int	limit2;

	limit1 = make_one_limit(stk_a, **s_a, **s_b);
	limit2 = limit1 / 2 + limit1 % 2;
	put_flag(stk_a, limit2);
	while (lst_size(*stk_a) >= lst_size(*stk_b))
	{
		if ((*stk_a)->cont <= limit1 && (*stk_a)->cont > limit2)
			pb(stk_a, stk_b, NULL, NULL);
		else if ((*stk_a)->cont <= limit1 && (*stk_a)->cont <= limit2)
			(pb(stk_a, stk_b, NULL, NULL), rb(stk_a, stk_b, NULL));
		else if ((*stk_a)->cont > limit1)
			rra(stk_a, stk_b, NULL);
	}
	sort_biggest(stk_a, stk_b, s_a, s_b);
}

void	sort_biggest(t_list **stk_a, t_list **stk_b, int **s_a, int **s_b)
{
	int		limit;
	int		size;

	while (lst_size(*stk_a) > 2)
	{
		limit = make_one_limit(stk_a, **s_a, **s_b);
		size = lst_size(*stk_a);
		while (--size > -1)
		{
			if (lst_size(*stk_a) < 3)
				break ;
			if ((*stk_a)->cont <= limit)
				pb(stk_a, stk_b, NULL, NULL);
			else if ((*stk_a)->cont > limit)
				ra(stk_a, stk_b, NULL);
		}
	}
	if ((*stk_a)->next && (*stk_a)->cont > (*stk_a)->next->cont)
		sa(stk_a, stk_b);
	if ((*stk_a)->next && (*stk_a)->cont < (*stk_a)->next->cont)
		pb(stk_a, stk_b, NULL, NULL);
	**s_a = (*stk_a)->cont;
	put_flag(stk_b, (**s_a) - 1);
}

void	three_a_b(t_list **stk_a, t_list **stk_b, int **sort_a, int **sort_b)
{
	while (*stk_a && (*stk_a)->cont < **sort_a)
	{
		sort_a_b(stk_a, stk_b, **sort_a, sort_b);
		while (short_group_a_b(stk_a, stk_b, **sort_a, sort_b))
			;
		aux_a_b(stk_a, stk_b, sort_a, sort_b);
	}
}

void	aux_a_b(t_list **stk_a, t_list **stk_b, int **s_a, int **s_b)
{
	int	*limits;
	int	n_rotates;
	int	to_push;

	n_rotates = 0;
	limits = ft_calloc(sizeof(int), 3);
	make_two_limits(stk_a, **s_a, **s_b, &limits);
	while (*stk_a && (*stk_a)->cont < limits[2] && (*stk_a)->cont < **s_a)
	{
		sort_a_b(stk_a, stk_b, **s_a, s_b);
		if ((*stk_a)->cont <= limits[1])
			pb(stk_a, stk_b, s_b, NULL);
		else if ((*stk_a)->cont > limits[1])
			ra(stk_a, stk_b, &n_rotates);
	}
	to_push = n_rotates;
	while ((n_rotates > 0 || to_push) && *stk_a)
	{
		if (n_rotates > 0)
			rra(stk_a, stk_b, &n_rotates);
		if ((*stk_a)->cont <= limits[0] || (to_push && n_rotates < 1))
			pb(stk_a, stk_b, s_b, &to_push);
	}
	free(limits);
}

void	sort_a_b(t_list **stk_a, t_list **stk_b, int s_a, int **s_b)
{
	int	n_r;
	int	index_position;
	int	n;

	n_r = 0;
	n = 25;
	while ((f_in(*stk_a, (**s_b) + 1) < n && (*stk_a)->cont < s_a
			&& (*stk_b)->cont == **s_b) || n_r > 0)
	{
		index_position = f_in(*stk_a, (**s_b) + 1); 
		if (index_position == 1 && (*stk_a)->cont < s_a)
			(pb(stk_a, stk_b, s_b, NULL));
		else if (index_position == 2)
			sa(stk_a, stk_b);
		else if (index_position > 2 && index_position < n)
		{
			while (f_in(*stk_a, (**s_b) + 1) != 1)
				ra(stk_a, stk_b, &n_r);
		}
		else if (n_r > 0)
			rra(stk_a, stk_b, &n_r);
	}
}

int	short_group_a_b(t_list **stk_a, t_list **stk_b, int s_a, int **s_b)
{
	t_list	*tmp;
	int		lowest;
	int		i;
	
	if (*stk_a && (*stk_a)->cont >= s_a)
		return (0);
	sort_a_b(stk_a, stk_b, s_a, s_b);
	tmp = *stk_a;
	lowest = f_lim(*stk_a);
	while (tmp && tmp->cont < f_lim(*stk_a))
	{
		if (tmp->cont < lowest)
			lowest = tmp->cont;
		tmp = tmp->next;
	}
	i = f_lim(*stk_a) - lowest + 1;
	if (i < 4 && i > 0)
	{
		while (i-- && (*stk_a)->cont < s_a)
			pb(stk_a, stk_b, s_b, NULL);
		return (1);
	}
	return (0);
}
