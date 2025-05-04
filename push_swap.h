/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:04:50 by manguita          #+#    #+#             */
/*   Updated: 2025/05/04 01:06:51 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_list
{
	struct s_list	*next;
	int				cont;
	int				flag;
}	t_list;

t_list	*index_list(t_list *list);
t_list	*make_list(char **av);
void	num_to_list(t_list **list, int n);
int		valid_numbers(char **argv);
int		push(t_list **src_stack, t_list **dst_stack);
int		swap(t_list **stack);
int		rotate(t_list **stack);
int		reverse_rotate(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b, int **s_a, int *to_push);
void	pb(t_list **stack_a, t_list **stack_b, int **s_b, int *to_push);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ra(t_list **stack_a, int *n_rot);
void	rb(t_list **stack_b, int *n_rot);
void	rra(t_list **stack_a, int *n_rot);
void	rrb(t_list **stack_b, int *n_rot);
int		lst_size(t_list *list);
int		f_ind(t_list *list, int index);
void	free_list(t_list **list);
void	free_array(char **array);
int		is_sorted(t_list *list);
int		b_is_sorted(t_list *list);
void	simple_sort(t_list **stack_a, t_list **stack_b);
void	three_to_b(t_list **stack_a, t_list **stack_b, int **s_a, int **s_b);
void	make_two_limits(t_list **stack, int s_a, int s_b, int **limits);
int		make_one_limit(t_list **stack, int s_a, int s_b);
int		put_flag(t_list **stack, int index);
void	aux_b_a(t_list **stack_a, t_list **stack_b, int **s_a, int **s_b);
void	aux_a_b(t_list **stack_a, t_list **stack_b, int **s_a, int **s_b);
void	sort_a_b(t_list **stack_a, t_list **stack_b, int s_a, int **s_b);
void	sort_b_a(t_list **stack_a, t_list **stack_b, int **s_a);
void	sort_biggest(t_list **stack_a, t_list **stack_b, int **s_a, int **s_b);
void	sort_lowest(t_list **stack_a, t_list **stack_b, int **s_a, int **s_b);
void	three_a_b(t_list **stack_a, t_list **stack_b, int **s_a, int **s_b);
void	three_b_a(t_list **stack_a, t_list **stack_b, int **s_a, int **s_b);
void	algorithm(t_list **stack_a, t_list **stack_b);
int		short_group_b_a(t_list **stk_a, t_list **stk_b, int **s_a);
int		short_group_a_b(t_list **stk_a, t_list **stk_b, int **s_b);
void	first_b_a(t_list **stk_a, t_list **stk_b, int **s_a, int **s_b);

void	print_list(t_list *list);

#endif
