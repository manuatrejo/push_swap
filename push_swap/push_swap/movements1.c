/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manguita <manguita@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:30:50 by manguita          #+#    #+#             */
/*   Updated: 2024/12/06 22:44:10 by manguita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(int c, t_list *head_a, t_list *head_b)//estas variables tendría  sentido hacerlas estáticas
{
	void	*temp_head;
	
	if (c)//si c entonces push_a
	{
		temp_head = head_a->next;
		head_b = head_a;
		head_a = temp_head;
	}
	else//push_b
	{
		temp_head = head_b->next;
		head_a = head_b;
		head_b = temp_head;
	}
}

void	swap(int c, t_list *head_a, t_list *head_b)
{
	int	temp_value;
	if (c == 0 || c == 1)
	{
		temp_value = head_a->content;
		head_a->content = head_a->next->content;
		head_a->next->content = temp_value;
	}
	else if (c == 0 || c == 2)
	{
		temp_value = head_b->content;
		head_b->content = head_b->next->content;
		head_b->next->content = temp_value;
	}
	
}

void	rotate(int c, t_list *head_a, t_list *head_b)
{
	t_list	*lst_address;
	
	if ((c == 0 || c == 1) && head_a->next != NULL)
	{
		lst_address = head_a;
		while (lst_address->next != NULL)
			lst_address = lst_address->next;
		lst_address->next = head_a;
		head_a->next = NULL;
	}
	else if ((c == 0 || c == 2) && head_b->next != NULL)
	{
		lst_address = head_b;
		while (lst_address->next != NULL)
			lst_address = lst_address->next;
		lst_address->next = head_b;
		head_b->next = NULL;
	}
}

void	reverse_rotate(int c, t_list *head_a, t_list *head_b)
{
	t_list	*lst_address;
	
	if ((c == 0 || c == 1) && head_a->next != NULL)
	{
		lst_address = head_a;
		while (lst_address->next->next != NULL)
			lst_address = lst_address->next;
		lst_address->next->next = head_a;
		lst_address->next = NULL;
	}
	else if ((c == 0 || c == 2) && head_b->next != NULL)
	{
		lst_address = head_b;
		while (lst_address->next->next != NULL)
			lst_address = lst_address->next;
		lst_address->next->next = head_b;
		lst_address->next = NULL;
	}
}
