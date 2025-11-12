/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:02:48 by manguita          #+#    #+#             */
/*   Updated: 2025/11/11 00:13:09 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_lst **src_stack, t_lst **dst_stack)
{
	t_lst	*temp;

	if (!*src_stack)
		return (0);
	temp = *dst_stack;
	*dst_stack = *src_stack;
	*src_stack = (*src_stack)->next;
	(*dst_stack)->next = temp;
	return (1);
}

int	swap(t_lst **stack)
{
	t_lst	*temp;

	if (!*stack || !(*stack)->next)
		return (0);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	return (1);
}

int	rotate(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*temp2;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	temp = *stack;
	temp2 = *stack;
	*stack = (*stack)->next;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
	temp->next = NULL;
	return (1);
}

int	reverse_rotate(t_lst **stack)
{
	t_lst	*temp;
	t_lst	*temp2;

	if (!stack || !*stack || !(*stack)->next)
		return (0);
	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = *stack;
	*stack = temp2;
	return (1);
}

void	ss(t_lst **stack_a, t_lst **stack_b)
{
	if (swap(stack_a) && swap(stack_b))
		write(1, "ss\n", 3);
}
