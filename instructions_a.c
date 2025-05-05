/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:06:35 by manguita          #+#    #+#             */
/*   Updated: 2025/05/05 06:10:17 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **stk_a, t_list **stk_b, int **s_b, int *to_push)
{
	if (s_b && (*stk_a)->cont == (**s_b) + 1)
	{
		if ((*stk_b)->cont == (*stk_a)->cont + 1)
			(**s_b)++;
	}
	if (to_push)
		(*to_push)--;
	if (push(stk_a, stk_b))
		write(1, "pb\n", 3);
}

void	sa(t_list **stack_a)
{
	if (swap(stack_a))
		write(1, "sa\n", 3);
}

void	ra(t_list **stack_a, int *n_rot)
{
	if (n_rot)
		(*n_rot)++;
	if (rotate(stack_a))
		write(1, "ra\n", 3);
}

void	rra(t_list **stack_a, int *n_rot)
{
	if (n_rot)
		(*n_rot)--;
	if (reverse_rotate(stack_a))
		write(1, "rra\n", 4);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (rotate(stack_a) && rotate(stack_b))
		write(1, "rr\n", 3);
}
