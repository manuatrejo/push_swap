/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:34:37 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/11 23:10:00 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_lst **stk_a, t_lst **stk_b, int *s_b, int *to_push)
{
	if (stk_b && *stk_b && s_b && (*stk_b)->cont == (*s_b))
	{
		if ((*stk_b)->cont + 1 == (*stk_a)->cont)
			(*s_b)++;
	}
	if (to_push)
		(*to_push)--;
	if (push(stk_a, stk_b))
		write(1, "pb\n", 3);
}

void	sa(t_lst **stack_a, t_lst **stack_b)
{
	if (optimal(stack_a, stack_b))
		;
	else if (swap(stack_a))
		write(1, "sa\n", 3);
}

void	ra(t_lst **stack_a, t_lst **stack_b, int *n_rot)
{
	if (stack_a && *stack_a && (*stack_a)->next && !(*stack_a)->next->next)
		return (sa(stack_a, stack_b));
	if (n_rot)
		(*n_rot)++;
	if (rotate(stack_a))
		write(1, "ra\n", 3);
}

void	rra(t_lst **stack_a, t_lst **stack_b, int *n_rot)
{
	stack_b--;
	stack_b++;
	if (n_rot)
		(*n_rot)--;
	if (reverse_rotate(stack_a))
		write(1, "rra\n", 4);
}

void	rr(t_lst **stack_a, t_lst **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next || !stack_b
		|| !*stack_b || !(*stack_b)->next)
		return ;
	if (rotate(stack_a) && rotate(stack_b))
		write(1, "rr\n", 3);
}
