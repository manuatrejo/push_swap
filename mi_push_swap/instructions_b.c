#include "push_swap.h"

void	pa(t_list **stack_b, t_list **stack_a)
{
	push(&stack_a, &stack_b);
	write(1, "pb\n", 3);
}

void	sb(t_list **stack_b)
{
	swap(&stack_b);
	write(1, "sb\n", 3);
}

void	rb(t_list **stack_b)
{
	rotate(&stack_b);
	write(1, "rb\n", 3);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(&stack_b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **stack_b, t_list **stack_a)
{
	reverse_rotate(&stack_a);
	reverse_rotate(&stack_b);
	write(1, "rrr\n", 4);
}