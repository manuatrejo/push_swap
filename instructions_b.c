/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:07:01 by manguita          #+#    #+#             */
/*   Updated: 2025/05/06 05:56:04 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stk_a, t_list **stk_b, int **s_a, int *to_push)
{
	if (s_a && (*stk_a)->cont == (**s_a))
	{
		if ((*stk_a)->cont == (*stk_b)->cont + 1)
		{
			(**s_a)--;
			put_flag(stk_b, (**s_a) - 1);
		}
	}
	if (to_push)
		(*to_push)--;
	if (push(stk_b, stk_a))
		write(1, "pa\n", 3);
	//optimal(stk_a, stk_b);
}

void	sb(t_list **stack_a, t_list **stack_b)
{
	if (optimal(stack_a, stack_b))
		;
	else if (swap(stack_b))
		write(1, "sb\n", 3);
}

void	rb(t_list **stack_a, t_list **stack_b, int *n_rot)
{
	stack_a--;
	stack_a++;
	stack_b--;
	stack_b++;
	if (n_rot)
		(*n_rot)++;
	if (rotate(stack_b))
		write(1, "rb\n", 3);
	//optimal(stack_a, stack_b);
}

void	rrb(t_list **stack_a, t_list **stack_b, int *n_rot)
{
	stack_a--;
	stack_a++;
	stack_b--;
	stack_b++;
	if (n_rot)
		(*n_rot)--;
	if (reverse_rotate(stack_b))
		write(1, "rrb\n", 4);
	//optimal(stack_a, stack_b);
}

void	rrr(t_list **stack_b, t_list **stack_a)
{
	if (reverse_rotate(stack_a) && reverse_rotate(stack_b))
		write(1, "rrr\n", 4);
}
