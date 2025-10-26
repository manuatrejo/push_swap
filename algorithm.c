/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:15:59 by manguita          #+#    #+#             */
/*   Updated: 2025/05/06 06:16:41 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algorithm(t_list **stack_a, t_list **stack_b)
{
	int	*sorted_a;
	int	*sorted_b;

	sorted_a = ft_calloc(sizeof(int), 1);
	sorted_b = ft_calloc(sizeof(int), 1);
	if (lst_size(*stack_a) < 6)
		(simple_sort(stack_a, stack_b), exit(0));
	*sorted_a = lst_size(*stack_a);
	*sorted_b = -1;
	three_to_b(stack_a, stack_b, &sorted_a, &sorted_b);
	first_b_a(stack_a, stack_b, &sorted_a, &sorted_b);
	while (*sorted_a != *sorted_b + 1 && *sorted_a != *sorted_b)
	{
		three_a_b(stack_a, stack_b, &sorted_a, &sorted_b);
		if (*sorted_a != *sorted_b + 1 && *sorted_a != *sorted_b)
			three_b_a(stack_a, stack_b, &sorted_a, &sorted_b);
	}
	while (*stack_b)
		pa(stack_a, stack_b, NULL, NULL);
	(free(sorted_a), free(sorted_b));
}

void	make_two_limits(t_list **stk, int s_a, int s_b, int **lim)
{
	t_list	*temp;
	int		biggest;
	int		lowest;

	temp = *stk;
	biggest = s_b;
	lowest = s_a;
	while (temp && temp->cont < s_a && temp->cont > s_b && temp->cont < s_a
				&& ((s_lim(*stk) > f_lim(*stk) && temp->cont <= f_lim(*stk))
				|| (s_lim(*stk) < f_lim(*stk) && temp->cont > s_lim(*stk))))
	{
		if (temp->cont < lowest)
			lowest = temp->cont;
		if (temp->cont > biggest)
			biggest = temp->cont;
		temp = temp->next;
	}
	if (s_lim(*stk) > f_lim(*stk))
		(*lim)[2] = f_lim(*stk) + 1;
	else if (s_lim(*stk) <= f_lim(*stk))
		(*lim)[2] = s_lim(*stk);
	if (lowest > s_lim(*stk))
		lowest = s_lim(*stk) + 1;
	(*lim)[1] = put_flag(stk, ((1 + biggest - lowest) / 3) + lowest - 1);
	(*lim)[0] = put_flag(stk, ((1 + biggest - lowest) / 3) + (*lim)[1] - 1);
}

int	make_one_limit(t_list **stack, int sorted_a, int sorted_b)
{
	t_list	*temp;
	int		limit;
	int		biggest;
	int		lowest;

	temp = *stack;
	biggest = sorted_b;
	lowest = sorted_a;
	while (temp && temp->cont > sorted_b && temp->cont < sorted_a)
	{
		if (temp->cont < lowest)
			lowest = temp->cont;
		if (temp->cont > biggest)
			biggest = temp->cont;
		temp = temp->next;
	}
	limit = ((1 + biggest - lowest) / 2) + (1 + biggest - lowest) % 2 + lowest - 1;
	put_flag(stack, limit);
	return (limit);
}

int	put_flag(t_list **stack, int index)
{
	t_list	*temp;

	temp = *stack;
	while (temp)
	{
		if (index == temp->cont)
		{
			temp->flag = 1;
			return (index);
		}
		temp = temp->next;
	}
	return (index);
}

void	simple_sort(t_list **stack_a, t_list **stack_b)
{
	if (lst_size(*stack_a) == 3)
	{
		if ((*stack_a)->cont - 2 == (*stack_a)->next->cont
			|| (*stack_a)->cont - 2 == (*stack_a)->next->next->cont)
			ra(stack_a, stack_b, NULL);
		else if ((*stack_a)->next->cont - 2 == (*stack_a)->cont
			|| (*stack_a)->next->cont - 2 == (*stack_a)->cont)
			rra(stack_a, stack_b, NULL);
	}
	else if (lst_size(*stack_a) == 4 || lst_size(*stack_a) == 5)
	{
		while (lst_size(*stack_a) > 3)
		{
			if ((*stack_a)->cont < 2)
				pb(stack_a, stack_b, NULL, NULL);
			else
				ra(stack_a, stack_b, NULL);
		}
		simple_sort(stack_a, stack_b);
		pa(stack_a, stack_b, NULL, NULL);
	}
	if (!is_sorted(*stack_a))
		sa(stack_a, stack_b);
}
