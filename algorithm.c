/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:20:15 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/12 04:08:00 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	simple_sort(t_lst **stack_a, t_lst **stack_b)
{
	int	size;

	size = lst_size(*stack_a);
	while (lst_size(*stack_a) > 3)
	{
		if ((*stack_a)->cont < size - 3)
			pb(stack_a, stack_b, NULL, NULL);
		else
			ra(stack_a, stack_b, NULL);
	}
	if (lst_size(*stack_a) == 3)
	{
		if ((*stack_a)->cont == size - 1)
			ra(stack_a, stack_b, NULL);
		else if ((*stack_a)->next->cont == size - 1)
			rra(stack_a, NULL);
		if (!is_sorted(*stack_a))
			sa(stack_a, stack_b);
	}
	while (size-- > 3)
		pa(stack_a, stack_b, NULL, NULL);
	if (!is_sorted(*stack_a))
		sa(stack_a, stack_b);
}

void	algorithm(t_lst **stack_a, t_lst **stack_b)
{
	int	sorted_a;
	int	sorted_b;

	if (lst_size(*stack_a) < 6)
		(simple_sort(stack_a, stack_b), exit(0));
	sorted_a = lst_size(*stack_a);
	sorted_b = -1;
	three_to_b(stack_a, stack_b, &sorted_a);
	first_b_a(stack_a, stack_b, &sorted_a, &sorted_b);
	while (sorted_a > sorted_b + 1)
	{
		three_a_b(stack_a, stack_b, &sorted_a, &sorted_b);
		if (sorted_a > sorted_b + 1)
			three_b_a(stack_a, stack_b, &sorted_a, &sorted_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b, NULL, NULL);
}

void	make_two_limits_ab(t_lst **stk, int s_a, int s_b, int *lim)
{
	t_lst	*temp;
	int		bgst;
	int		lwst;

	lwst = s_a;
	bgst = s_b;
	temp = *stk;
	lim[2] = f_lim(*stk) + 1;
	while (temp && temp->cont < s_a && temp->cont < lim[2])
	{
		if (temp->cont < lwst)
			lwst = temp->cont;
		if (temp->cont > bgst)
			bgst = temp->cont;
		temp = temp->next;
	}
	lim[1] = (1 + bgst - lwst) / 3 + lwst - 1;
	if ((bgst - lwst + 1) % 3 != 0)
		lim[1]++;
	lim[0] = ((1 + bgst - lwst) / 3) + lim[1] - 1;
	if ((bgst - lwst + 1) % 3 == 2)
		lim[0]++;
	put_flg(stk, lim[1]);
	put_flg(stk, lim[0]);
}

void	make_two_limits_ba(t_lst **stk, int s_a, int s_b, int *lim)
{
	t_lst	*temp;
	int		bgst;
	int		lwst;

	lwst = s_a;
	bgst = s_b;
	temp = *stk;
	lim[2] = s_lim(*stk);
	while (temp && temp->cont > s_b && temp->cont > lim[2])
	{
		if (temp->cont < lwst)
			lwst = temp->cont;
		if (temp->cont > bgst)
			bgst = temp->cont;
		temp = temp->next;
	}
	lim[1] = (1 + bgst - lwst) / 3 + lwst - 1;
	if ((bgst - lwst + 1) % 3 != 0)
		lim[1]++;
	lim[0] = ((1 + bgst - lwst) / 3) + lim[1] - 1;
	if ((bgst - lwst + 1) % 3 == 2)
		lim[0]++;
	put_flg(stk, lim[1]);
	put_flg(stk, lim[0]);
}

int	make_one_limit(t_lst **stack)
{
	t_lst	*temp;
	int		limit;
	int		biggest;
	int		lowest;

	temp = *stack;
	biggest = -1;
	lowest = 2147483647;
	while (temp && temp->cont > -1)
	{
		if (temp->cont < lowest)
			lowest = temp->cont;
		if (temp->cont > biggest)
			biggest = temp->cont;
		temp = temp->next;
	}
	limit = ((biggest - lowest) / 2) + lowest;
	put_flg(stack, limit);
	return (limit);
}
