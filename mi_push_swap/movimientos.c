#include "push_swap.h"

void	push(t_list **src_stack, t_list **dst_stack)
{
	t_list	*temp;

	if (!*src_stack)
		return ;
	temp = *dst_stack;
	*dst_stack = *src_stack;
	*src_stack = (*src_stack)->next;
	(*dst_stack)->next = temp;
}

void	swap(t_list **stack)
{
	t_list	*temp;

	if (!*stack || !(*stack)->next)
		return ;
	temp = *stack;
	*stack = (*stack)->next;
	temp->next =(*stack)->next;
	(*stack)->next = temp;
}

void	rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	temp2 = *stack;
	*stack = (*stack)->next;
	while (temp2->next != NULL)
		temp2 = temp2->next;
	temp2->next = temp;
	temp->next = NULL;
}

void	reverse_rotate(t_list **stack)
{
	t_list	*temp;
	t_list	*temp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	while (temp->next->next != NULL)
		temp = temp->next;
	temp2 = temp->next;
	temp->next = NULL;
	temp2->next = *stack;
	*stack = temp2;
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	swap(&stack_a);
	swap(&stack_b);
	write(1, "ss\n", 3);
}
