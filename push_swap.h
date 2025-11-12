/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maanguit <maanguit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 04:04:50 by manguita          #+#    #+#             */
/*   Updated: 2025/11/12 04:15:47 by maanguit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"

typedef struct s_lst
{
	struct s_lst	*next;
	int				cont;
	int				flag;
}	t_lst;

typedef struct s_utils
{
	int	min;
	int	max;
	int	lim;
}	t_utils;

t_lst	*index_list(t_lst *list);
t_lst	*make_list(char **av);
int		valid_numbers(char **argv);
int		push(t_lst **src_stack, t_lst **dst_stack);
int		swap(t_lst **stack);
int		rotate(t_lst **stack);
int		reverse_rotate(t_lst **stack);
void	ss(t_lst **stack_a, t_lst **stack_b);
void	rr(t_lst **stack_a, t_lst **stack_b);
void	rrr(t_lst **stack_a, t_lst **stack_b);
void	pa(t_lst **stack_a, t_lst **stack_b, int *s_a, int *to_push);
void	pb(t_lst **stack_a, t_lst **stack_b, int *s_b, int *to_push);
void	sa(t_lst **stack_a, t_lst **stack_b);
void	sb(t_lst **stack_a, t_lst **stack_b);
void	ra(t_lst **stack_a, t_lst **stack_b, int *n_rot);
void	rb(t_lst **stack_a, t_lst **stack_b, int *n_rot);
void	rra(t_lst **stack_a, int *n_rot);
void	rrb(t_lst **stack_b, int *n_rot);

int		lst_size(t_lst *list);
int		f_in(t_lst *list, int index);
void	free_list(t_lst **list);
void	free_array(char **array);
int		is_sorted(t_lst *list);
int		b_is_sorted(t_lst *list);
int		f_lim(t_lst *stack);
int		s_lim(t_lst *stack);

void	make_two_limits_ab(t_lst **stack, int s_a, int s_b, int *limits);
void	make_two_limits_ba(t_lst **stack, int s_a, int s_b, int *limits);
int		make_one_limit(t_lst **stack);
int		put_flg(t_lst **stack, int index);

void	algorithm(t_lst **stack_a, t_lst **stack_b);
void	three_to_b(t_lst **stack_a, t_lst **stack_b, int *s_a);
void	three_a_b(t_lst **stack_a, t_lst **stack_b, int *s_a, int *s_b);
void	three_b_a(t_lst **stack_a, t_lst **stack_b, int *s_a, int *s_b);
void	first_b_a(t_lst **stk_a, t_lst **stk_b, int *s_a, int *s_b);
int		optimal(t_lst **stk_a, t_lst **stk_b);
int		elm_lwr(t_lst *lst, int cont);
int		elm_bgr(t_lst *lst, int cont);
void	aux_sort_ba(t_lst **stk_a, t_lst **stk_b, int *s_a, int *n_r);
void	aux_sort_ab(t_lst **stk_a, t_lst **stk_b, int *s_b, int *n_r);
int		check_doubles(t_lst *stack);

#endif
