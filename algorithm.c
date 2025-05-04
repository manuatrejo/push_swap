/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:15:59 by manguita          #+#    #+#             */
/*   Updated: 2025/05/04 21:10:06 by manguita         ###   ########.fr       */
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
	while (*sorted_a != *sorted_b + 1)
	{
		three_a_b(stack_a, stack_b, &sorted_a, &sorted_b);
		if (*sorted_a != *sorted_b + 1)
			three_b_a(stack_a, stack_b, &sorted_a, &sorted_b);
	}
	sort_b_a(stack_a, stack_b, &sorted_a);
	(free(sorted_a), free(sorted_b));
}

void	make_two_limits(t_list **stk, int sorted_a, int sorted_b, int **lim)
{
	t_list	*temp;
	int		biggest;
	int		lowest;

	temp = *stk;
	biggest = sorted_b;
	lowest = sorted_a;
	while (temp && temp->cont > sorted_b && temp->cont < sorted_a
		&& temp->cont != second_lim(*stk))//si no hay 2lim entonces tiene que 
	{
		if (temp->cont < lowest)
			lowest = temp->cont;
		if (temp->cont > biggest)
			biggest = temp->cont;
		temp = temp->next;
	}
	if (second_lim(*stk) > first_lim(*stk))
		(*lim)[2] = first_lim(*stk) + 1;
	else if (second_lim(*stk) <= first_lim(*stk))
		(*lim)[2] = second_lim(*stk);
	if (lowest > second_lim(*stk))
		lowest = second_lim(*stk) + 1;
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
	limit = ((1 + biggest - lowest) / 2) + (1 + biggest - lowest) % 2 + lowest;
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
			ra(stack_a, NULL);
		else if ((*stack_a)->next->cont - 2 == (*stack_a)->cont
			|| (*stack_a)->next->cont - 2 == (*stack_a)->cont)
			rra(stack_a, NULL);
	}
	else if (lst_size(*stack_a) == 4 || lst_size(*stack_a) == 5)
	{
		while (lst_size(*stack_a) > 3)
		{
			if ((*stack_a)->cont < 2)
				pb(stack_a, stack_b, NULL, NULL);
			else
				ra(stack_a, NULL);
		}
		simple_sort(stack_a, stack_b);
		pa(stack_a, stack_b, NULL, NULL);
	}
	if (!is_sorted(*stack_a))
		sa(stack_a);
}
