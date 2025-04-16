#include "push_swap.h"

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(&stack_b, &stack_a);
	write(1, "pa\n", 3);
}

void	sa(t_list **stack_a)
{
	swap(&stack_a);
	write(1, "sa\n", 3);
}

void	ra(t_list **stack_a)
{
	rotate(&stack_a);
	write(1, "ra\n", 3);
}

void	rra(t_list **stack_a)
{
	reverse_rotate(&stack_a);
	write(1, "rra\n", 4);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(&stack_a);
	rotate(&stack_b);
	write(1, "rr\n", 3);
}