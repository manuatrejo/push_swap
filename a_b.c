/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_b.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:31:54 by manguita          #+#    #+#             */
/*   Updated: 2025/05/04 20:04:46 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	short_group_a_b(t_list **stk_a, t_list **stk_b, int **s_b)
{
	t_list	*temp;
	int		bigger;
	int		i;

	temp = *stk_a;
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
			pa(stk_a, stk_b, s_b, NULL);
		return (1);
	}
}

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
			(pb(stk_a, stk_b, NULL, NULL), rb(stk_b, NULL));
		else if ((*stk_a)->cont > limit1)
			rra(stk_a, NULL);
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
		while (size-- > -1)
		{
			if (lst_size(*stk_a) < 3)
				break ;
			if ((*stk_a)->cont <= limit)
				pb(stk_a, stk_b, NULL, NULL);
			else
				ra(stk_a, NULL);
		}
	}
	if ((*stk_a)->next && (*stk_a)->cont > (*stk_a)->next->cont)
		sa(stk_a);
	**s_a = (*stk_a)->cont;
}

void	three_a_b(t_list **stk_a, t_list **stk_b, int **sort_a, int **sort_b)
{
	while (*stk_a && (*stk_a)->cont < **sort_a)
	{
		while (short_group_a_b(stk_a, stk_b, sort_b))
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
		if ((*stk_a)->cont < limits[1])
			pb(stk_a, stk_b, s_b, NULL);
		else
			ra(stk_a, &n_rotates);
	}
	to_push = n_rotates;
	while ((0 < n_rotates || to_push) && *stk_a && (*stk_a)->cont > **s_a)
	{
		if ((*stk_a)->cont < limits[0] || (to_push && n_rotates < 1))
			pb(stk_a, stk_b, s_b, &to_push);
		if (n_rotates > 0)
			rra(stk_a, &n_rotates);
	}
	free(limits);
}

void	sort_a_b(t_list **stk_a, t_list **stk_b, int sorted_a, int **min)
{
	int	n_r;
	int	index_position;

	n_r = 0;
	while ((f_in(*stk_a, (**min) + 1) < 6 || n_r > 0) && (*stk_b)->cont == **min)
	{
		index_position = f_in(*stk_a, (**min) + 1);
		if ((*stk_a)->cont >= sorted_a)
			index_position = 10;
		if (index_position == 1)
			(pb(stk_a, stk_b, min, NULL));
		else if (index_position == 2)
			sa(stk_b);
		else if (index_position > 2 && index_position < 6)
		{
			while (f_in(*stk_a, (**min) + 1) != 1)
				ra(stk_a, &n_r);
		}
		else if (n_r > 0)
			rra(stk_a, &n_r);
		else if (n_r < 0)
			ra(stk_a, &n_r);
	}
}
