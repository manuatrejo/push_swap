/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 22:02:48 by manguita          #+#    #+#             */
/*   Updated: 2025/05/02 04:15:46 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_list **src_stack, t_list **dst_stack)
{
	t_list	*temp;

	if (!*src_stack)
		return (0);
	temp = *dst_stack;
	*dst_stack = *src_stack;
	*src_stack = (*src_stack)->next;
	(*dst_stack)->next = temp;
	return (1);
}

int	swap(t_list **stack)
{
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return (0);
	temp = *stack;
	*stack = (*stack)->next;
	temp->next = (*stack)->next;
	(*stack)->next = temp;
	return (1);
}

int	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

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

int	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

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

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) && swap(stack_b))
		write(1, "ss\n", 3);
}
