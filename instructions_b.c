/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 21:34:47 by maanguit          #+#    #+#             */
/*   Updated: 2025/11/12 04:32:04 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_lst **stk_a, t_lst **stk_b, int *s_a, int *to_push)
{
	if (s_a && (*stk_a)->cont == (*s_a))
	{
		if ((*stk_a)->cont - 1 == (*stk_b)->cont)
		{
			(*s_a)--;
			put_flg(stk_b, (*s_a) - 1);
		}
	}
	if (to_push)
		(*to_push)--;
	if (push(stk_b, stk_a))
		write(1, "pa\n", 3);
}

void	sb(t_lst **stack_a, t_lst **stack_b)
{
	if (optimal(stack_a, stack_b))
		;
	else if (swap(stack_b))
		write(1, "sb\n", 3);
}

void	rb(t_lst **stack_a, t_lst **stack_b, int *n_rot)
{
	if (stack_b && *stack_b && (*stack_b)->next && !(*stack_b)->next->next)
		return (sb(stack_a, stack_b));
	if (n_rot)
		(*n_rot)++;
	if (rotate(stack_b))
		write(1, "rb\n", 3);
}

void	rrb(t_lst **stack_b, int *n_rot)
{
	if (n_rot)
		(*n_rot)--;
	if (reverse_rotate(stack_b))
		write(1, "rrb\n", 4);
}

void	rrr(t_lst **stack_b, t_lst **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next || !stack_b
		|| !*stack_b || !(*stack_b)->next)
		return ;
	if (reverse_rotate(stack_a) && reverse_rotate(stack_b))
		write(1, "rrr\n", 4);
}
